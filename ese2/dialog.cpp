#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    double f;
    f = exp(x) + log(x) - 10 * x;
    return f;
}

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

void Dialog::calculate(double a, double b)
{
    double c, d, e, x;
    int k;
    c = a, d = b, e = 0.1;

    QString output;

    output += "c = " + QString::number(c) + "\n";
    output += "d = " + QString::number(d) + "\n";

    if (f(c) * f(d) < 0){
        k = 0;
        while(1){
            x = (c + d) / 2;
            k = k + 1 ;
            if (fabs(f(x)) < e) break;
            if (f(c) * f(x) < 0){
                c = c , d = x;
            }
            else
            {
                c = x, d = d;
            }
        }

        output += "x = " + QString::number(x) + "\n";
        output += "k = " + QString::number(k) + "\n";
        output += "f(x) = " + QString::number(f(x)) + "\n";
    }
    else{
        output += "error\n";
    }

    ui->label->setText(output);
}
