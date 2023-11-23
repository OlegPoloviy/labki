#include "dialog.h"
#include "ui_dialog.h"
#include <cmath>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setParameters(double a, double b, double dx)
{
    double x, fx;
    QString resultText;
    for (x = a; x <= b; x += dx)
    {
        fx = 0.1 * x * x  - 5 * x *logl(x) -1;
        QString xStr = QString::number(x);
        QString fxStr = QString::number(fx);
        resultText += "x = " + xStr + ", f(x) = " + fxStr + "\n";
    }
    ui->label->setText(resultText);
}
