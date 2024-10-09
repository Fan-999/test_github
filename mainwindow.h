#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;

    QString calculation(bool *ok=NULL);

private slots:
    void btnNumClicked();
    void btnBinaryOperatorClicked();    //多操作数
    void btnUnaryOperatorClicked();     //单操作数
    void on_btn_dot_clicked();
    void on_btn_delete_clicked();

    void on_btn_C_clicked();

    void on_btn_sum_clicked();

    void on_btn_CE_clicked();

    void on_btn_multiple_clicked();

private:
    Ui::MainWindow *ui;

    QLabel *statusMsgLabel;
};
#endif // MAINWINDOW_H
