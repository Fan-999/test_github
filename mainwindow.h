#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel * flabCurFile;
    QProgressBar * progressBar;
    QSpinBox * spinFontSize;
    QFontComboBox * comboFont;

    void iniUI();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_actb_triggered(bool checked);//粗体的槽函数

    void on_actunder_triggered(bool checked);//下划线的槽函数

    void on_action_5_triggered(bool checked);//斜体的槽函数

    void on_actAbout_triggered();//关于的槽函数

    void on_textEdit_selectionChanged();

    void on_MainWindow_toolButtonStyleChanged(const Qt::ToolButtonStyle &toolButtonStyle);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
