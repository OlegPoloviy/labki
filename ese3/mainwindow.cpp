// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString xString = ui->lineEdit->text();
    QString epsString = ui->lineEdit_2->text();
    bool ok;
    float x = xString.toFloat(&ok);
    if (!ok) {
        // Обробка некоректного вводу для x
        return;
    }
    float eps = epsString.toFloat(&ok);
    if (!ok) {
        // Обробка некоректного вводу для eps
        return;
    }

    Dialog dialog(x, eps);
    dialog.exec();
}
