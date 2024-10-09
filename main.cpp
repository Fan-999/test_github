#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
    // ui->statusbar->showMessage(qobject_cast<QPushButton *>(sender())->text()+"btn clicked");
