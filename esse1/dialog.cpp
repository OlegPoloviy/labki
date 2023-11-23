#include "dialog.h"
#include "ui_dialog.h"
#include <cmath>
float f(float x)
{
    return exp(x) + logl(x) - 10 * x ;
}
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


void Dialog::setValues(float N, float a, float b)
{

    float s = (f(a) + f(b)) / 2;
    double h = (b - a) / N;
    for (int i = 0; i < N; i++)
    {
        s += f(a + i * h);
    }

    QString result = QString("I = %1").arg(h * s);
    ui->labelResult->setText(result);
}
Dialog::~Dialog()
{
    delete ui;
}

