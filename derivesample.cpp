#include "derivesample.h"
#include "math.h"

//using namespace std;

derivesample::derivesample(Canvas* canvas, QVector2D doteDr, QVector3D circleDr)
{
    curCanvas = canvas;
    dote[0] = doteDr.x();
    dote[1] = doteDr.y();
    circle[0] = circleDr.x();
    circle[1] = circleDr.y();
    circle[2] = circleDr.z();
    for (int i = 0; i < 5; i++){
      line[i] = 0;
    }
    for (int i = 0; i < 5; i++){
      line2[i] = 0;
    }
    //line = newLine;
    flag = 0;
    if (calcDist(dote[0], dote[1], circle[0], circle[1]) > circle[2]){
        secCircle[0] = (circle[0] + dote[0]) / 2;
        secCircle[1] = (circle[1] + dote[1]) / 2;
        secCircle[2] = calcDist(secCircle[0], secCircle[1], circle[0], circle[1]);
        float xc = 0, yc = 0, x = secCircle[0] - circle[0], y = secCircle[1] - circle[1];
        float q = (pow((pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y, 2))/ ( 2 * y), 2) - pow(circle[2], 2)) / (1 + pow(x,2) / pow(y, 2));
        float p = - (x * (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x,2) + pow(y,2)))/ pow(y,2) / (1 + pow(x,2) / pow(y, 2)), x1, x2, y1, y2;
        if ( pow((p/2), 2) - q > 0){
            x1 = -(p/2) + sqrt(pow((p/2), 2) - q);
            x2 = -(p/2) - sqrt(pow((p/2), 2) - q);
            if(x1 != x2){
                y1 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x1;
                y2 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x2;
            }else{
                y1 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x1;
                y2 = -y1;
            }
            line[0] = x1 + circle[0];
            line[1] = y1 + circle[1];
            line[2] = dote[0];
            line[3] = dote[1];
            line2[0] = x2 + circle[0];
            line2[1] = y2 + circle[1];
            line2[2] = dote[0];
            line2[3] = dote[1];
            flag = 1;
        };
    }
    if (flag == 1){
        addLinesToCanvas();
        curCanvas->addCircle(circle[0], circle[1], circle[2]);
        curCanvas->addDote(dote[0], dote[1]);
        curCanvas->drawCoordinateSystemFigurse();
    }else{
        curCanvas->addLine(1, 1, 4, 7);
    }
    /*}else{
        //emit sampleError();
    }*/
}

QString derivesample::strAnswer(){
   QString ans;
   if (flag == 1){
   ans = "tangent 1   x: " + QString::number(line[0]) + " y: " + QString::number(line[1])  + "\n";
   ans += "tangent 2   x: " + QString::number(line2[0]) + " y: " + QString::number(line2[1]) + "\n";
   }else{
       ans = "ERROR Incorrect elements data";
   }
   return ans;
}

void derivesample::newFigures(QVector2D newdDoteDr, QVector3D newCircleDr){
    dote[0] = newdDoteDr.x();
    dote[1] = newdDoteDr.y();
    circle[0] = newCircleDr.x();
    circle[1] = newCircleDr.y();
    circle[2] = newCircleDr.z();
    for (int i = 0; i < 5; i++){
      line[i] = 0;
    }
    //float dotex = doteDr.x(), dotey = doteDr.y(), circx = circleDr.x(), circy = circleDr.y(), radius = circleDr.z();
    secCircle[0] = (circle[0] + dote[0]) / 2;
    secCircle[1] = (circle[1] + dote[1]) / 2;
    secCircle[2] = calcDist(secCircle[0], secCircle[1], circle[0], circle[1]);
    float xc = 0, yc = 0, x = secCircle[0] - circle[0], y = secCircle[1] - circle[1];
    float q = (pow((pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y, 2))/ ( 2 * y), 2) - pow(circle[2], 2)) / (1 + pow(x,2) / pow(y, 2));
    float p = - (x * (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x,2) + pow(y,2)))/ pow(y,2) / (1 + pow(x,2) / pow(y, 2)), x1, x2, y1, y2;
    flag = 0;
    if (calcDist(dote[0], dote[1], circle[0], circle[1]) > circle[2]){
        secCircle[0] = (circle[0] + dote[0]) / 2;
        secCircle[1] = (circle[1] + dote[1]) / 2;
        secCircle[2] = calcDist(secCircle[0], secCircle[1], circle[0], circle[1]);
        float xc = 0, yc = 0, x = secCircle[0] - circle[0], y = secCircle[1] - circle[1];
        float q = (pow((pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y, 2))/ ( 2 * y), 2) - pow(circle[2], 2)) / (1 + pow(x,2) / pow(y, 2));
        float p = - (x * (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x,2) + pow(y,2)))/ pow(y,2) / (1 + pow(x,2) / pow(y, 2)), x1, x2, y1, y2;
        if ( pow((p/2), 2) - q > 0){
            x1 = -(p/2) + sqrt(pow((p/2), 2) - q);
            x2 = -(p/2) - sqrt(pow((p/2), 2) - q);
            if(x1 != x2){
                y1 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x1;
                y2 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x2;
            }else{
                y1 = ( (pow(circle[2], 2) - pow(secCircle[2], 2) + pow(x, 2) + pow(y,2)) / (2 * y) ) - (x/y)*x1;
                y2 = -y1;
            }
            line[0] = x1 + circle[0];
            line[1] = y1 + circle[1];
            line[2] = dote[0];
            line[3] = dote[1];
            line2[0] = x2 + circle[0];
            line2[1] = y2 + circle[1];
            line2[2] = dote[0];
            line2[3] = dote[1];
            flag = 1;
        };
    }
    if (flag == 1){
        addLinesToCanvas();
        curCanvas->addCircle(circle[0], circle[1], circle[2]);
        curCanvas->addDote(dote[0], dote[1]);
        curCanvas->drawCoordinateSystemFigurse();
    }else{
        //curCanvas->addLine(1, 1, 4, 7);
    }

}


void derivesample::setNewCanvas(Canvas* newCanvas){
    delete curCanvas;
    curCanvas = newCanvas;
}

void derivesample::addLinesToCanvas(){
    curCanvas->addLine(line[0], line[1], line[2], line[3]);
    curCanvas->addLine(line2[0], line2[1], line2[2], line2[3]);
}


float derivesample::calcDist(float x1, float y1, float x2, float y2){
    return (sqrt(pow((x1 - x2),2) + pow((y1-y2), 2) ));
}

float** derivesample::matrixMult(float** matr1, float** matr2, int rowsC1, int rowsC2, int colsC1, int colsC2){
    int rows2 = rowsC2;
    int cols1 = colsC1;
    int cols2 = colsC2;
    int rows1 = rowsC1;
    if (cols1 != rows2){
        return nullptr;
    }
    float **matrix2D = new float*[rows1];
        for (int row = 0; row < rows1; row++){
            matrix2D[row] = new float [cols2];
        }
    float curVal = 0;
    for (int row1 = 0; row1 < rows1; row1++){
        for (int col2 = 0; col2 < cols2; col2++){
            curVal = 0;
            for (int col1 = 0; col1 < cols1; col1++){
                curVal += matr1[row1][col1] * (matr2[col1][col2]);
            }
            matrix2D[row1][col2] = curVal;
        }
    }
    return matrix2D;
 }






