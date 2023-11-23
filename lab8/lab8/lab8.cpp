#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define pi 3.141592

double s(double t) {
    double T = 0.04;
    if ((t >= 0) && (t <= 0.4 * T)) {
        return 7 * t / (0.4 * T);
    }
    if ((t > 0.4 * T) && (t <= 0.6 * T)) {
        return 7 - 12.5 * (t - 0.4 * T) / (0.2 * T);
    }
    if ((t > 0.6 * T) && (t <= 0.8 * T)) {
        return -5 + 12.5 * (t - 0.6 * T) / (0.4 * T);
    }
    if ((t > 0.8 * T) && (t <= T)) {
        return 7 - 7 * (t - 0.8 * T) / (0.2 * T);
    }
    return 0;
}

void sygn() {
    ofstream file("result1.txt");
    const int N = 200;
    double h = 0.03 / N;
    double* t = new double[N + 1];
    double* l = new double[N + 1];
    for (int i = 0; i <= N; i++) {
        t[i] = i * h;
        l[i] = s(i * h);
        cout << l[i] << " " << t[i] << endl;
        file << t[i] << " " << l[i] << endl;
    }
    delete[] t;
    delete[] l;

    file.close();
}

double a0() {
    ifstream file("result1.txt");
    char t[200], s[200];

    double Sum = 0, a0, T = 0.03, h = T / 200;

    for (int i = 0; i <= 200; i++) {
        file >> t >> s;
        Sum += atof(s);
    }
    a0 = (2 * h * Sum) / T;
    file.close();
    return a0;
}

double ak(int idx) {
    ifstream file("result1.txt");
    double Sum, T = 0.03, N = 200, h = T / N, w = (2 * pi) / T, t[201], s[201], a[20];
    char v[200], b[200];

    for (int i = 0; i <= 200; i++) {
        file >> v >> b;
        t[i] = atof(v);
        s[i] = atof(b);
    }
    for (int k = 0; k <= 20; k++) {
        Sum = 0;

        for (int i = 0; i <= 200; i++) {

            Sum += s[i] * cos(k * w * t[i]);

        }
        a[k] = (2 * h * Sum) / T;
    }
    file.close();
    return a[idx];
}

double bk(int idx) {
    ifstream file("result1.txt");
    double Sum, T = 0.03, N = 200, h = T / N, w = (2 * pi) / T, t[201], s[201], a[20];
    char v[200], b[200];

    for (int i = 0; i <= 200; i++) {
        file >> v >> b;
        t[i] = atof(v);
        s[i] = atof(b);
    }
    for (int k = 0; k <= 20; k++) {
        Sum = 0;

        for (int i = 0; i <= 200; i++) {

            Sum += s[i] * sin(k * w * t[i]);

        }
        a[k] = (2 * h * Sum) / T;
    }
    file.close();
    return a[idx];
}

void tab() {
    ofstream file("result.txt");
    for (int i = 0; i <= 20; i++) {
        file << ak(i) << " " << bk(i) << endl;
    }
    file.close();
}
int main() {
    ifstream file("result.txt");
    ofstream wfile("result2.txt");

    double Sum, T = 0.03, N = 200, h = T / N, w = (2 * pi) / T, t, akArray[20], bkArray[20];
    char v[20], b[20];

    for (int k = 0; k < 20; k++) {
        file >> v >> b;
        akArray[k] = atof(v);
        bkArray[k] = atof(b);
    }


    for (int i = 0; i <= 200; i++) {
        Sum = a0() / 2;
        t = i * h;

        for (int k = 0; k <= 20; k++) {
            Sum += akArray[k] * cos(k * w * t) + bkArray[k] * sin(k * w * t);
        }

        wfile << t << " " << Sum << endl;
    }

    return 0;
}