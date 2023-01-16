#ifndef DERIVESAMPLE_H
#define DERIVESAMPLE_H

#include <QAbstractItemModel>
#include "canvas.h"
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QTextEdit>

class derivesample
{

    //Q_OBJECT
public:
    derivesample(Canvas*, QVector2D, QVector3D);
    void newFigures(QVector2D, QVector3D);
    void setNewCanvas(Canvas*);
    void addLinesToCanvas();
    QString strAnswer();
private:
    int flag ;
    float dote[2];
    float circle[3];
    float secCircle[3];
    float line[4];
    float line2[4];
    float ** rotMatrix;
    //float circleX;
    //float circleY;
    //float radius;
    Canvas *curCanvas;
    float calcDist(float, float, float, float);
    float** matrixMult(float**, float**, int, int, int, int);

//signals:
   // void sampleError();
};

#endif // DERIVESAMPLE_H
