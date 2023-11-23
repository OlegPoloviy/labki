#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    double b = ui->lineEdit_2->text().toDouble();

    Dialog dialog;
    dialog.calculate(a, b);
    dialog.exec();
}
//bevae
