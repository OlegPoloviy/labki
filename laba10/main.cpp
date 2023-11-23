#include <QApplication>
#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <Qpen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Створення головного вікна
    QMainWindow window;
    window.setWindowTitle("Qwt Plot Example");

    // Створення об'єкту графіка QwtPlot
    QwtPlot *plot = new QwtPlot(&window);
    plot->setTitle("Теплове розширення скла");
    plot->setCanvasBackground(Qt::white);

    // Завантаження експериментальних даних у вектори
    std::vector<double> temp = { 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
    std::vector<double> gl = {5.931, 6.108, 6.668, 7.016, 8.361, 9.056, 10.304, 11.289, 12.456, 13.162, 14.196, 15.017, 16.559, 17.495, 18.555, 19.018, 20.458 };

    // Використання методу найменших квадратів для знаходження коефіцієнтів a0 і a1
    double N = temp.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < N; i++) {
        sumX += temp[i];
        sumY += gl[i];
        sumXY += temp[i] *gl[i];
        sumX2 += temp[i] * temp[i];
    }
    double a1 = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
    double a0 = (sumY - a1 * sumX) / N;

    // Табулювання значень апроксимуючого виразу для вказаного діапазону температур
    std::vector<double> gl_approx;
    for (int i = 0; i < temp.size(); i++) {
        double t = temp[i];
        double l = a0 + a1 * t;
        gl_approx.push_back(l);
    }

    // Створення кривої графіка для експериментальних даних
    QwtPlotCurve *curveData = new QwtPlotCurve();
    curveData->setTitle("Experimental Data");
    curveData->setPen(QPen(Qt::blue));
    curveData->setSamples(temp.data(), gl.data(), temp.size());
    curveData->attach(plot);

     //Створення кривої графіка для апроксимованої лінії
    QwtPlotCurve *curveApprox = new QwtPlotCurve();
   curveApprox->setTitle("Approximation");
    curveApprox->setPen(QPen(Qt::red));
   curveApprox->setSamples(temp.data(), gl_approx.data(), temp.size());
    curveApprox->attach(plot);

    // Налаштування вісей графіка
    plot->setAxisTitle(QwtPlot::xBottom, "Темпаратура (°C)");
    plot->setAxisTitle(QwtPlot::yLeft, "Розширення (10^-6/K)");

    // Відображення графіка
    plot->replot();

    // Відображення головного вікна
    window.setCentralWidget(plot);
    window.resize(800, 600);
    window.show();

    return a.exec();
}
