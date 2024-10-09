#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_num0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btn_num9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btn_plus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btn_subtract,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btn_multiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btn_divide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btn_1x,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btn_2x,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btn_dividenum,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btn_x2,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btn_jiajian,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=operands.front().toDouble();;
    if(operands.size()==2&&opcodes.size()>0)
    {
        //取操作数
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op=opcodes.front();
        opcodes.pop_front();

        //完成运算
        if(op=="+"){
            result=operand1+operand2;
        }
        else if(op=="-"){
            result=operand1-operand2;
        }
        else if(op=="×"){
            result=operand1*operand2;
        }
        else if(op=="÷"){
            result=operand1/operand2;
        }

        //将每次的计算结果记录保存
        operands.push_back(QString::number(result));
        //操作数和操作符已成功push进去并显示
        ui->statusbar->showMessage(QString("push sucess：op1 is %1,op2 is %2").arg(operands.size()).arg(opcodes.size()));
    }else{
        //查看操作数和操作符是否push进去
        ui->statusbar->showMessage(QString("op1 is %1,op2 is %2").arg(operands.size()).arg(opcodes.size()));
    }
    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton *>(sender())->text();
    if(digit=="0"&&operand=="0")
        digit="";
    if(operand=="0"&&digit!="0")
        operand="";
    operand+=digit;
    ui->display->setText(operand);
}


void MainWindow::on_btn_dot_clicked()
{
    if(!operand.contains("."))
        operand+=qobject_cast<QPushButton *>(sender())->text();
    ui->display->setText(operand);
}

void MainWindow::on_btn_delete_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}

void MainWindow::on_btn_CE_clicked()
{
    operands.clear();
    ui->display->setText("0");
}

void MainWindow::on_btn_C_clicked()
{
    operands.clear();
    operand.clear();
    opcodes.clear();
    opcode.clear();
    ui->display->setText("0");
}

void MainWindow::btnBinaryOperatorClicked()
{
    QString opcode=qobject_cast<QPushButton *>(sender())->text();
    if(operand!="")
    {
        operands.push_back(operand);
        operand="";

        opcodes.push_back(opcode);
    }

    QString result=calculation();
    ui->display->setText(result);

}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand!="")
    {
        double result=operand.toDouble();
        operand="";

        QString op=qobject_cast<QPushButton*>(sender())->text();
        if(op=="%"){
            result/=100.0;
        }
        else if(op=="¹/x"){
            result=1/result;
        }
        else if(op=="x²"){
            result=result*result;
        }
        else if(op=="²√x"){
            result=sqrt(result);
        }
        else if(op=="+/-"){
            result=-result;
        }
        ui->display->setText(QString::number(result));
    }
}
void MainWindow::on_btn_sum_clicked()
{
    if(operand!="")
    {
        operands.push_back(operand);
        operand="";
    }
    QString result=calculation();
    ui->display->setText(result);
    // 清空操作符队列，为下一次计算做准备
    opcodes.clear();
}




