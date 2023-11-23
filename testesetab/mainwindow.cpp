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
    QString aStr = ui->lineEdit->text();
    QString bStr = ui->lineEdit_2->text();
    QString dxStr = ui->lineEdit_3->text();

    bool ok;
    double a = aStr.toDouble(&ok);
    if (!ok) {

        return;
    }

    double b = bStr.toDouble(&ok);
    if (!ok) {

        return;
    }

    double dx = dxStr.toDouble(&ok);
    if (!ok) {

        return;
    }


    Dialog* dialog = new Dialog(this);
    dialog->setParameters(a, b, dx);
    dialog->exec();
}
