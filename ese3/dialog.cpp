// dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <cmath>

using namespace std;

float F(float x) {
    return pow(x , 2);
}

float f(float x) {
    return 2 * x;
}

Dialog::Dialog(float x, float eps, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    float dx;
    do {
        dx = F(x) / f(x);
        x = x - dx;
    } while (fabs(dx) > eps);

    QString output = "x = " + QString::number(x) + "\n";
    output += "f(x) = " + QString::number(F(x)) + "\n";
    ui->label->setText(output);
}

Dialog::~Dialog()
{
    delete ui;
}
