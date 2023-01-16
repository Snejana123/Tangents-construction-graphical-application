#include "graphicswidget.h"

#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFileDialog>


graphicsWidget::graphicsWidget(QWidget *parent)
    : QWidget(parent)
{
    //setStyleSheet("background: #CCFFFF;");
    setMinimumSize(520, 600);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //QRegularExpression lineVal("([0][\.][0-9]+) | ([1-9]+[0-9]*[\.][0-9]+) | ([1-9]+[0-9]*)");
    QRegularExpression lineVal("(([-]?[0][\.][0-9]+)|([-]?[1-9]+[0-9]*([\.][0-9]+)?))|([0])");
    QRegularExpression positiveVal("(([0][\.][0-9]+)|([1-9]+[0-9]*([\.][0-9]+)?))|([0])");
    QRegularExpressionValidator  * val = new QRegularExpressionValidator(lineVal);
    QRegularExpressionValidator  * positVal = new QRegularExpressionValidator(positiveVal);
    QString lineEdStyle = "QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #EEFBFF; selection-background-color: blue; height: 22px; font-size:18px;}";
    QString labelStyle = "QLabel {font-size: 18px;}";

    mainLayout = new QVBoxLayout;
    canvasW = new Canvas(this);
    theDote = new QVector2D(1,1);
    theCircle = new QVector3D(4,5,1);
    theLine = new QVector4D(0,0,0,0);
    calcSamp = new derivesample(canvasW, *theDote, *theCircle);
    canvasW->setStatusTip("Drawing");
    mainLayout->addWidget(canvasW);

    doteLayout = new QHBoxLayout;
    doteLayout->setAlignment(Qt::AlignLeft);
    doteLayout->setSpacing(20);
    //doteLayout->
    doteLayout->setSpacing(7);
    doteXLabel = new QLabel("Dote x coordinate:", this);
    doteXLabel->setAlignment(Qt::AlignLeft);
    doteXLabel->setStyleSheet(labelStyle);
    doteLayout->addWidget(doteXLabel);

    doteXEdit =  new QLineEdit(this);
    doteXEdit->setMaximumWidth(200);
    doteXEdit->setAlignment(Qt::AlignLeft);
    doteXEdit->setValidator(val);
    doteXEdit->setStyleSheet(lineEdStyle);
    doteXEdit->setStatusTip("Dote x coordinate value");
    doteLayout->addWidget(doteXEdit);

    doteYLabel = new QLabel("Dote y coordinate:", this);
    doteYLabel->setAlignment(Qt::AlignLeft);
    doteYLabel->setStyleSheet(labelStyle);
    doteLayout->addWidget(doteYLabel);

    doteYEdit =  new QLineEdit(this);
    doteYEdit->setMaximumWidth(200);
    doteYEdit->setAlignment(Qt::AlignLeft);
    doteYEdit->setValidator(val);
    doteYEdit->setStyleSheet(lineEdStyle);
    doteYEdit->setStatusTip("Dote y coordinate value");
    doteLayout->addWidget(doteYEdit);

    circleLayout =  new QHBoxLayout;
    circleLayout->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    circleLayout->setSpacing(7);

    circleXLabel = new QLabel("Circle center x coordinate:", this);
    circleXLabel->setAlignment(Qt::AlignLeft);
    circleXLabel->setStyleSheet(labelStyle);
    circleLayout->addWidget(circleXLabel);

    circleXEdit = new QLineEdit(this);
    circleXEdit->setMaximumWidth(200);
    circleXEdit->setAlignment(Qt::AlignLeft);
    circleXEdit->setValidator(val);
    circleXEdit->setStyleSheet(lineEdStyle);
    circleXEdit->setStatusTip("Circle center x coordinate value");
    circleLayout->addWidget(circleXEdit);

    circleYLabel = new QLabel("Circle center y coordinate:", this);
    circleYLabel->setAlignment(Qt::AlignLeft);
    circleYLabel->setStyleSheet(labelStyle);
    circleLayout->addWidget(circleYLabel);

    circleYEdit = new QLineEdit(this);
    circleYEdit->setMaximumWidth(200);
    circleYEdit->setAlignment(Qt::AlignLeft);
    circleYEdit->setValidator(val);
    circleYEdit->setStyleSheet(lineEdStyle);
    circleYEdit->setStatusTip("Circle center y coordinate value");
    circleLayout->addWidget(circleYEdit);

    circleRadLayout = new QHBoxLayout;
    circleRadLabel = new QLabel("Circle radius:", this);
    circleRadLabel->setStyleSheet(labelStyle);
    circleRadLayout->addWidget(circleRadLabel);
    circleRadEdit = new QLineEdit(this);
    circleRadEdit->setMaximumWidth(200);
    circleRadEdit->setValidator(positVal);
    circleRadEdit->setStyleSheet(lineEdStyle);
    circleRadEdit->setStatusTip("Circle radius value");
    circleRadLayout->addWidget(circleRadEdit);

    QString btnStyle = "QPushButton {background: #FFB256; border-radius: 10px; border: 2px solid gray; height: 25px; width: 100px; font-size: 18px;}";
    addElementsBtn = new QPushButton("Add elements");
    addElementsBtn->setStatusTip("Submit button");
    addElementsBtn->setStyleSheet(btnStyle);


    ansEdit = new QTextEdit;
    ansEdit->setMaximumHeight(50);
    ansEdit->setReadOnly(true);
    ansEdit->setText("Please, enter elements values");
    ansTextSlot();

    mainLayout->addItem(doteLayout);
    mainLayout->addItem(circleLayout);
    mainLayout->addItem(circleRadLayout);
    mainLayout->addWidget(addElementsBtn);
    mainLayout->addWidget(ansEdit);
    setLayout(mainLayout);

    connect(addElementsBtn, SIGNAL(pressed()), this, SLOT(setNewFigurseBtn()));
    connect(canvasW, SIGNAL(ready()), this, SLOT(ansTextSlot()));
}


void graphicsWidget::importSlot(){
    import();
}


//Импорт текстового файла с именем fileName
bool graphicsWidget::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        //Если приложение не может прочитать файл, информирование пользователя об ошибке через диалоговое окно
        QMessageBox::warning(this, tr("Graph Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }
    //Импорт файла
    QTextStream in(&file);
    QString currentSt;
    float curFl;
    bool stat;
    for (int i = 0; i < 5; i++){
        in>>(currentSt);
        curFl = currentSt.toFloat(&stat);
        if(curFl){
            switch(i){
                case 0:
                    doteXEdit->setText(QString::number(curFl));
                break;
                case 1:
                    doteYEdit->setText(QString::number(curFl));
                break;
                case 2:
                    circleXEdit->setText(QString::number(curFl));
                break;
                case 3:
                    circleYEdit->setText(QString::number(curFl));
                break;
                case 4:
                    if (curFl < 0){
                       QMessageBox::warning(this, tr("Graph Application"), "Radius value must be positive. Absolute value will be taken.");
                    }
                    circleRadEdit->setText(QString::number(abs(curFl)));

                break;
            }
        }
    }
    canvasW->removeAllFigures();
    setNewFigurseBtn();
    return true;
}


/*
 * Слот для получения имени файла через диалоговое окно QFileDialog
 * Если пользователь выбрал файл для импортирования, имя файла передается в loadFile() для его загрузки в приложение
 * Добавлен фильтр для рассширений файлов (только txt)
 */
bool graphicsWidget::import() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("*.txt"));
    if (!fileName.isEmpty())
    {
    QTextStream in(&fileName);
    return loadFile(fileName);
    }
    return false;
}

/*
 * Тоже функция для импорта файла как и import.
 * Отличие в том, что функции передается предпологаемое имя текстового файла,
 * затем сразу идет проверка, что это действительно имя файла, затем проверка, что файл txt.
 * Функция используется для импорта при запуске приложения через командную строку
 */
bool graphicsWidget::importFile(QString fileName){
    if (!fileName.isEmpty())
    {
        QFileInfo fi(fileName);
        if(! fi.isFile()) {
            QMessageBox::warning(this, tr("Graph Application"), "File not found. Please check the filename.");
            return false;
        }
        if (fi.completeSuffix() != "txt") {
            QMessageBox::warning(this, tr("Graph Application"), "Cannot open this file type. Please import txt file.");
            return false;
        }
        loadFile(fileName);
        //textEdit->insertPlainText(in.readAll());
    }
    return true;
}


void graphicsWidget::setNewFigurseBtn(){
    ansEdit->setText("Please, enter elements values");
    float dotex, dotey, circx,circy, circrad;
    if((doteXEdit->text().length() > 0) && (doteYEdit->text().length() > 0) && (circleXEdit->text().length() > 0) && (circleYEdit->text().length() > 0) && (circleRadEdit->text().length() > 0)){
        dotex = doteXEdit->text().toFloat();
        dotey = doteYEdit->text().toFloat();
        circx = circleXEdit->text().toFloat();
        circy = circleYEdit->text().toFloat();
        circrad = circleRadEdit->text().toFloat();
        theDote->setX(dotex);
        theDote->setY(dotey);
        theCircle->setX(circx);
        theCircle->setY(circy);
        theCircle->setZ(circrad);
        canvasW->removeAllFigures();
        canvasW->addDote(theDote->x(), theDote->y());
        canvasW->addCircle(theCircle->x(), theCircle->y(), theCircle->z());
        calcSamp->newFigures(*theDote, *theCircle);
        //calcSamp->addLinesToCanvas();
        canvasW->drawCoordinateSystemFigurse();
    }
}


void graphicsWidget::ansTextSlot(){
    ansEdit->setText(calcSamp->strAnswer());
}

void graphicsWidget::newSlot(){
    canvasW->removeAllFigures();
    ansEdit->setText("Please, enter elements values");
}

bool graphicsWidget::maybeExport(){
    if (ansEdit->toPlainText() == "" || ansEdit->toPlainText() == "Please, enter elements values" ){
        return false;
    }
    return true;
}

bool graphicsWidget::exportSolution(){
    if (maybeExport()) {
        QFileDialog dialog(this);
        dialog.setAcceptMode(QFileDialog::AcceptSave);
        dialog.setFileMode(QFileDialog::AnyFile);
        dialog.setNameFilter("*.png");
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save file as"), QDir::currentPath(), tr("*.png"));
        return saveAs(fileName);
    }
    QMessageBox::warning(this, tr("Graph Application"), "Nothing to export");
    return false;
}



/*
 * Экспорт решения в txt файл с именем fileName.
 * В случаях ошибок при попытке записать данные появиться диалоговое окно с errorMessage.
 */
bool graphicsWidget::saveAs(const QString &fileName) {
    if (fileName.isEmpty())
        errorMessage = tr("file address not specified");
    canvasW->exportPng(fileName);

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, tr("Graph Application"), errorMessage);
        errorMessage.clear();
        return false;
    }
    return true;
}



graphicsWidget::~graphicsWidget(){
    delete mainLayout;
    delete canvasW;
    delete doteLayout;
    delete doteXLabel;
    delete theDote;
    delete theCircle;
    delete theLine;
    delete calcSamp;

    delete doteLayout;
    delete circleLayout;
    delete circleRadLayout;
    delete addElementsBtn;
    delete doteXLabel;
    delete doteYLabel;
    delete circleXLabel;
    delete circleYLabel;
    delete circleRadLabel;
    delete doteXEdit;
    delete doteYEdit;
    delete circleXEdit;
    delete circleYEdit;
    delete circleRadEdit;
    delete ansEdit;

    delete canvasW;
    delete calcSamp;
    delete theDote;
    delete theCircle;
    delete theLine;
}
