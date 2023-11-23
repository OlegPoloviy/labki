#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

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
    QString N = ui->lineEditN->text();
    QString a = ui->lineEdit_a->text();
    QString b = ui->lineEdit_b->text();
    Dialog* dialog = new Dialog(this);
    dialog->setValues(N.toFloat(), a.toFloat(), b.toFloat());
    dialog->exec();
}
