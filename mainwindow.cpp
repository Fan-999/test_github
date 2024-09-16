#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QFile>
#include    <QFileDialog>
#include    <QTextStream>
#include    <QFontDialog>
#include    <QCoreApplication>
#include    <Qlabel>
#include    <QTextCharFormat>
#include    <QMessageBox>
void MainWindow::iniUI()
{
    flabCurFile=new QLabel;
    flabCurFile->setMidLineWidth(150);
    flabCurFile->setText("当前文件：");
    ui->statusbar->addWidget(flabCurFile);

    progressBar=new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize=new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());//初始值
    spinFontSize->setMinimumWidth(50);//设置组件最小宽度
    ui->toolBar->addWidget(new QLabel("字体大小 ")); //不引用的Label无需定义变量
    ui->toolBar->addWidget(spinFontSize); //SpinBox添加到工具栏
    ui->toolBar->addSeparator(); //工具栏上增加分隔条

    comboFont=new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(comboFont);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    // 连接“关于”按钮的信号到槽函数
    connect(ui->actAbout, &QAction::triggered, this, &MainWindow::on_actAbout_triggered);
    setCentralWidget(ui->textEdit);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//粗体按下去的状态
void MainWindow::on_actb_triggered(bool checked)
{
    QTextCharFormat fmt; //格式
    fmt=ui->textEdit->currentCharFormat();//获取当前选择文字的格式
    if (checked) // 相当于调用ui->actFontBold->isChecked();读取Action的check状态
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}
void MainWindow::on_action_5_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actunder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat(); //获取文字的格式

    ui->action_5->setChecked(fmt.fontItalic()); //是否斜体
    ui->actb->setChecked(fmt.font().bold()); //是否粗体
    ui->actunder->setChecked(fmt.fontUnderline()); //是否有下划线

}

void MainWindow::on_actAbout_triggered()
{
    QMessageBox aboutBox;
    aboutBox.setWindowTitle(tr("About"));
    aboutBox.setText(tr("姓名：Xyx\n学号：2022414040234\n班级：22软件工程2班"));
    aboutBox.exec();
}

