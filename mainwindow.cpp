#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_1, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::digit_pressed);
    connect(ui->pushButton_adi, &QPushButton::released, this, &MainWindow::operation_pressed);
    connect(ui->pushButton_sub, &QPushButton::released, this, &MainWindow::operation_pressed);
    connect(ui->pushButton_x, &QPushButton::released, this, &MainWindow::operation_pressed);
    connect(ui->pushButton_di, &QPushButton::released, this, &MainWindow::operation_pressed);
    connect(ui->pushButton_por, &QPushButton::released, this, &MainWindow::operation_pressed);
    connect(ui->pushButton_receba, &QPushButton::released, this, &MainWindow::on_pushButton_receba_released);
    connect(ui->pushButton_c, &QPushButton::released, this, &MainWindow::on_pushButton_c_released);
    connect(ui->pushButton_dot, &QPushButton::released, this, &MainWindow::on_pushButton_dot_released);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString buttonValue = button->text();
    QString displayValue = ui->label->text();

    if (displayValue == "0" || userIsTypingSecondNumber) {
        ui->label->setText(buttonValue);
        userIsTypingSecondNumber = false;
    } else {
        ui->label->setText(displayValue + buttonValue);
    }
}

void MainWindow::operation_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    pendingOperation = button->text();
    firstNum = ui->label->text().toDouble();
    ui->label->setText("0");
    userIsTypingSecondNumber = true;
}

void MainWindow::on_pushButton_receba_released()
{
    double secondNum = ui->label->text().toDouble();
    double result = 0.0;

    if (pendingOperation.isEmpty()) {
        return;
    }

    if (pendingOperation == "+") {
        result = firstNum + secondNum;
    } else if (pendingOperation == "-") {
        result = firstNum - secondNum;
    } else if (pendingOperation == "×") {
        result = firstNum * secondNum;
    } else if (pendingOperation == "÷") {
        if (secondNum != 0.0) {
            result = firstNum / secondNum;
        } else {
            ui->label->setText("Error");
            return;
        }
    } else if (pendingOperation == "%") {
        result = static_cast<int>(firstNum) % static_cast<int>(secondNum);
    }

    ui->label->setText(QString::number(result));
    pendingOperation.clear();
    userIsTypingSecondNumber = false;
}

void MainWindow::on_pushButton_c_released()
{
    ui->label->setText("0");
    firstNum = 0.0;
    pendingOperation.clear();
    userIsTypingSecondNumber = false;
}

void MainWindow::on_pushButton_dot_released()
{
    QString displayValue = ui->label->text();
    if (!displayValue.contains('.')) {
        ui->label->setText(displayValue + ".");
    }
}
