#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
/*#ifdef Q_OS_ANDROID
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif*/

    QApplication app(argc, argv);
    app.setStyleSheet("QLineEdit {background: #CCFFFF;}");
    QCoreApplication::setOrganizationName("Leonova Amelia Graphics, group 9374");
    QCoreApplication::setApplicationName("Graphics lab_1");
    QCoreApplication::setApplicationVersion("0.1");

    //Класс QCommandLineParser предоставляет средства для обработки параметров командной строки.
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();

    /*
     * Опция для импорта файла в приложение. Пользователь должен ввести в командную строку
     * любое из имен опции (например --txt ли -f) и имя файла (или полный путь к файлу)
     */
    QCommandLineOption importfile_option(QStringList() << "f" << "file" << "txt",
                                         "Import expressions from the file. /nExample of the txt file: /ndote coordinates: 12.3 13.1/ncircle center: 34 51.3/ncircle radius: 10.2",
                                         "file");
    parser.addOption(importfile_option);



    parser.process(app);

    //Проверяем, вводил ли пользователь названия опций
    bool isImoportFile = parser.isSet(importfile_option);

    MainWindow mainWin;
   if (isImoportFile){
        mainWin.loadFile(parser.value("file"));
   }
    mainWin.show();
    return app.exec();
}
