#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile DstyleSheetFile(":qdarkstyle/dark/style.qss");
        if (!DstyleSheetFile.exists())   {
            printf("Unable to set stylesheet, file not found\n");
        }
        else   {
            DstyleSheetFile.open(QFile::ReadOnly | QFile::Text);
            QTextStream ts(&DstyleSheetFile);
            qApp->setStyleSheet(ts.readAll());
        }
    MainWindow w;
    w.show();
    return a.exec();
}
