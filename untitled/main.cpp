#include <QApplication>
#include <QMainWindow>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_point_data.h>
#include <qwt_symbol.h>
#include <qwt_series_data.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a new QMainWindow
    QMainWindow mainWindow;

    // Add a new QwtPlot widget to the central widget
    QwtPlot *plot = new QwtPlot(&mainWindow);
    mainWindow.setCentralWidget(plot);

    // Load the experimental data into two QVectors
    QVector<double> temp = { 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
    QVector<double> Pb = { 19.254, 21.098, 21.733, 24.346, 27.244, 28.863, 32.637, 34.428, 37.596, 41.723, 44.593, 46.092, 49.966, 53.036, 56.051, 58.531, 62.009 };

    // Use the least-squares method to find the coefficients a0 and a1
    double N = temp.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < N; i++) {
        sumX += temp[i];
        sumY += Pb[i];
        sumXY += temp[i] * Pb[i];
        sumX2 += temp[i] * temp[i];
    }
    double a1 = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
    double a0 = (sumY - a1 * sumX) / N;

    // Tabulate the values of the approximating expression for the specified temperature range
    QVector<double> Pb_approx;
    for (int i = 0; i < temp.size(); i++) {
        double t = temp[i];
        double l = a0 + a1 * t;
        Pb_approx.append(l);
    }

    // Create a new QwtPlotCurve to hold the experimental data
    QwtPlotCurve *curveData = new QwtPlotCurve("Experimental Data");
    curveData->setPen(Qt::blue, 2); // Set the line color and width

    // Create a new QwtPlotCurve to hold the approximating line
    QwtPlotCurve *curveApprox = new QwtPlotCurve("Approximating Line");
    curveApprox->setPen(Qt::red, 2, Qt::DashLine); // Set the line color, width, and style

    // Create a new QwtPlotCurve to hold the black points
    QwtPlotCurve *curvePoints = new QwtPlotCurve("Black Points");
    curvePoints->setSymbol(new QwtSymbol(QwtSymbol::Rect, Qt::black, Qt::NoPen, QSize(8, 8))); // Set the symbol for the points

    // Set the samples for the curves
    curveData->setSamples(new QwtPointSeriesData(temp.toVector()));
    curveApprox->setSamples(new QwtPointSeriesData(temp.toVector()));
    curvePoints->setSamples(new QwtPointSeriesData(temp.toVector()));

    // Attach the curves to the plot
    curveData->attach(plot);
    curveApprox->attach(plot);
    curvePoints->attach(plot);

    // Set the title and axis labels
    plot->setTitle("Plumbium Thermal Expansion");
    plot->setAxisTitle(QwtPlot::xBottom, "Temperature (°C)");
        plot->setAxisTitle(QwtPlot::yLeft, "Expansion (10^-6/K)");

    // Show the main window
    mainWindow.show();

    return a.exec();
}
