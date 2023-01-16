#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H

#include <QAbstractItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include<QWidget>

#include "canvas.h"
#include "derivesample.h"

class graphicsWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *mainLayout;
    QHBoxLayout *doteLayout, *circleLayout, *circleRadLayout;
    QPushButton *addElementsBtn;
    QLabel *doteXLabel, *doteYLabel, *circleXLabel, *circleYLabel, *circleRadLabel;
    QLineEdit *doteXEdit, *doteYEdit, *circleXEdit, *circleYEdit, *circleRadEdit;
    QTextEdit* ansEdit;

    Canvas *canvasW;
    derivesample *calcSamp;
    QVector2D * theDote;
    QVector3D * theCircle;
    QVector4D * theLine;
    QString errorMessage;
    bool maybeExport();
    bool saveAs(const QString &);
    bool loadFile(const QString &);

private slots:
    void setNewFigurseBtn();
    void ansTextSlot();
public:
    graphicsWidget(QWidget *parent = nullptr);
    ~graphicsWidget();
    bool exportSolution();
    bool import();
    bool importFile(QString);


public slots:
    void newSlot();
    void importSlot();
};

#endif // GRAPHICSWIDGET_H
