#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSessionManager>
#include <QPlainTextEdit>
#include <QApplication>

#include "graphicswidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadFile(const QString);

private:
    void createActions(); //Создание меню и панели инструментов
    void createStatusBar();
    graphicsWidget *graphW;

private slots:
    void newSlot();
    void exportSol();
    void importSlot();
    void creatorSlot();

};
#endif // MAINWINDOW_H
