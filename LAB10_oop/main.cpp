#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
// Функція для обчислення коефіцієнтів a0 та a1 методом найменших квадратів
void leastSquaresMethod(vector<double> x, vector<double> y, double &a0, double &a1) {
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    vector<double> x = {5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
        vector<double> y = {17.891, 19.291, 21.181, 21.295, 24.440, 28.714, 31.269, 33.270, 36.362, 40.607, 43.405, 45.434, 49.713, 52.189, 54.280, 58.574, 60.725};

        // Обчислення коефіцієнтів a0 та a1 методом найменших квадратів
        double a0, a1;
        leastSquaresMethod(x, y, a0, a1);

        // Виведення результатів
        cout << "Коефіцієнти згладжуючого виразу: a0 = " << a0 << ", a1 = " << a1 << endl;

        // Обчислення та виведення значень апроксимуючого виразу для заданого діапазону температур
        cout << "Значення апроксимуючого виразу:\n";
        cout << "t\tl(t)\n";

        ofstream f("zn.txt");

        int t = 5;
        for (int i = 0; i <17; i++){
        while ( t <= 150) {
            double lt = a0 + a1 * t;
            cout << t << "\t" << lt << "\n";
            f << t << "\t" << lt << endl;
            x[i] = t;
            y[i] = lt;
            if (t<16){
                t+=5;
            } else t+=10;
        }
        }

    return a.exec();
}
