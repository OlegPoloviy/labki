#include "mainwindow.h"
#include "ui_mainwindow.h"

void leastSquaresMethod(QVector<double> x,QVector<double> y, double &a0, double &a1) {
    int n = x.size();
    double S1 = 0, S2 = 0, S3 = 0, S4 = 0;

    // Обчислення сум величин, які входять до системи лінійних рівнянь
    for (int i = 0; i < n; i++) {
        S1 += x[i];
        S2 += y[i];
        S3 += x[i] * x[i];
        S4 += x[i] * y[i];
    }

    // Розв'язання системи лінійних рівнянь методом Крамера
    double det = n * S3 - S1 * S1;
    a0 = (S2 * S3 - S1 * S4) / det;
    a1 = (n * S4 - S1 * S2) / det;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(0,155);
    ui->widget->yAxis->setRange(0,65);
    ui->widget->addGraph();

    A = {5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
    B = {17.891, 19.291, 21.181, 21.295, 24.440, 28.714, 31.269, 33.270, 36.362, 40.607, 43.405, 45.434, 49.713, 52.189, 54.280, 58.574, 60.725};
    // C = {17.598, 19.0935, 20.589, 22.0844, 25.0754, 28.0664, 31.0573, 34.0483, 37.0392, 40.0302, 43.0212, 46.0121, 49.0031, 51.994, 54.985, 57.976, 60.9669};
    //лінія
    double a0, a1;
    leastSquaresMethod(A, B, a0, a1);

    int t = 5;
    for (int i = 0; i <17; i++){
        while ( t <= 150) {
            double lt = a0 + a1 * t;
            qv_x.push_back (t);
            qv_y.push_back (lt);
            if (t<16){
                t+=5;
            } else t+=10;
        }
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(qv_x, qv_y);
        ui->widget->replot();
    }
    //точки
    for (int i=0; i<17; i++){
        ui->widget->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        qv_x.append(A[i]);
        qv_y.append(B[i]);
        ui->widget->graph(1)->setData(qv_x, qv_y);
        ui->widget->replot();
        ui->widget->update();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

