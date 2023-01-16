#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QVector3D>
#include <QVector4D>
#include <QVector2D>
#include <QVector>

class Canvas : public QWidget
{
    Q_OBJECT

//public slots:
    //void newDrSlot();
public:

    Canvas(QWidget *parent);
    ~Canvas();

    void drawCircle(qreal x, qreal y, qreal radius);
    void drawLine(qreal x1, qreal y1, qreal x2, qreal y2);
    void drawDote(qreal x, qreal y);
    void setMaxXY(qreal maxXVal, qreal maxYVal);
    void addCircle(qreal x, qreal y, qreal radius);
    void addLine(qreal x1, qreal y1, qreal x2, qreal y2);
    void addDote(qreal x1, qreal y1);
    void removeAllFigures();
    void exportPng(QString);

    void drawCoordinateSystemFigurse();

private:
    QVBoxLayout *mainLayout;

    QGraphicsView *mainGrView;
    QGraphicsScene *mainScene;
    QPen coordPen;
    QPen linesPen;
    QPen minLinesPen;
    QPen circlePen;
    QPen dotePen;
    QPen linePen;
    QBrush noBrushF;
    QBrush doteBrush;
    QGraphicsEllipseItem *dote = nullptr;
    QGraphicsLineItem *line = nullptr;
    qreal maxX;
    qreal maxY;
    qreal mesNum;

    qreal height;
    qreal width;

    QVector<QVector3D> circleVector;
    QVector<QVector4D> lineVector;
    QVector<QVector2D> doteVector;

    void resizeEvent(QResizeEvent *);

    void calcMaxXY();

signals:
    void ready();
};

#endif // CANVAS_H
