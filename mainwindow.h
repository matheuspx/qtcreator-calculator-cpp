#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double firstNum;
    QString pendingOperation;
    bool userIsTypingSecondNumber;
private slots:
    void digit_pressed();
    void operation_pressed();
    void on_pushButton_receba_released();
    void on_pushButton_c_released();
    void on_pushButton_dot_released();
};

#endif
