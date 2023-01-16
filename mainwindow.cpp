#include "mainwindow.h"
#include <QtWidgets>



#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    const QIcon tangent = QIcon::fromTheme("GraphApp", QIcon(":/images/graphics.svg"));
    setWindowIcon(tangent);
    setWindowTitle("Tangents construction graph application");

    createActions();
    createStatusBar();

    //setStyleSheet("background: #FDD44F;");
    setStyleSheet("background: #CCFFCC");
    setUnifiedTitleAndToolBarOnMac(true);

    graphW = new graphicsWidget(this);
    setCentralWidget(graphW);


}

/*
 * Создание меню и панели инструментов
 */
void MainWindow::createActions()
{

    menuBar()->setStyleSheet("background: #FDDF7C;");
    //menuBar()->setStyleSheet("item:hover {color: red}");
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QString menuStyle = "QMenu::tear-off {font-size: 18px} QMenu::item { background: white; color: black; font-size: 18px; padding: 0 18px; width:160px;} QMenu::item:selected { background: white; color: blue;} QMenu::item:pressed {  background: white; color: blue;}";
    fileMenu->setStyleSheet(menuStyle);
    QToolBar *fileToolBar = addToolBar(tr("File"));
    fileToolBar->setStyleSheet("background: #FDDF7C");
    const QIcon newIcon = QIcon::fromTheme("&New expression", QIcon(":/images/new.svg"));
    QAction *newAct = new QAction(newIcon, tr("&New drawing"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("New drawing"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newSlot);

    fileToolBar->addAction(newAct);
    fileMenu->addAction(newAct);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->setStyleSheet(menuStyle);
    QIcon infoIcon = QIcon::fromTheme("Import", QIcon(":/images/info.svg"));
    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setShortcut(tr("CTRL+H"));
    aboutQtAct->setIcon(infoIcon);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

    QAction *aboutCreator = helpMenu->addAction(tr("About Creator"), this, &MainWindow::creatorSlot);
    aboutCreator->setShortcut(tr("CTRL+R"));
    aboutCreator->setStatusTip(tr("Show the client information"));


    QIcon importIcon = QIcon::fromTheme("Import", QIcon(":/images/import.svg"));
    QAction *importAct = new QAction(importIcon, tr("&Import"), this);
    importAct->setShortcut(tr("CTRL+I"));
    importAct->setStatusTip(tr("File import"));
    connect(importAct, &QAction::triggered, this, &MainWindow::importSlot);

    fileMenu->addAction(importAct);
    fileToolBar->addAction(importAct);

    QIcon exportIcon = QIcon::fromTheme("Export", QIcon(":/images/export.svg"));
    QAction *exportAct = new QAction(exportIcon, tr("&Export"), this);
    exportAct->setShortcut(tr("CTRL+E"));
    exportAct->setStatusTip(tr("File export"));
    connect(exportAct, &QAction::triggered, this, &MainWindow::exportSol);

    fileMenu->addAction(exportAct);
    fileToolBar->addAction(exportAct);

}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
    statusBar()->setStyleSheet("background: #FDDF7C");
}


void MainWindow::newSlot(){
    graphW->newSlot();
}

/*
 * Экспорт решения
 */
void MainWindow::exportSol(){
    graphW->exportSolution();
    statusBar()->showMessage(tr("File exported"), 2000);
}


void MainWindow::importSlot(){
    graphW->importSlot();
}

void MainWindow::loadFile(const QString fileName){
    graphW->importFile(fileName);
}

void MainWindow::creatorSlot(){
    QMessageBox::information(this, tr("Bézier Curves Graph Application"),
                      tr("Creator: Leonova Amelia Alexandrovna. GMAIL: amelia.leonova@gmail.com"));
}

MainWindow::~MainWindow()
{

}

