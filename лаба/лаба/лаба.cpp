#include <iostream>
#include <cmath>

using namespace std;

double f(double x)  //функція
{
    return x - 2 + sin(1 / x);
}

double f1(double x)    // перша похідна функції, f'
{
    return 1 - (cos(1 / x)) / pow(x, 2);
}

double f2(double x)    //друга похідна функції, f''
{
    return -(sin(1 / x) - 2 * cos(1 / x) * x) / pow(x, 4);
}

int main()
{
    double a = 0.9, b = 2, x, xn, xn1;
    if (f(a) * f2(a) > 0)
    {
        x = a;
    }
    else
    {
        x = b;
    }
    xn = x - f(x) / f1(x);
    xn1 = xn - f(xn) / f1(xn);
    while (fabs(xn - xn1) >= 0.0001)
    {
        xn = xn1;
        xn1 = xn - f(xn) / f1(xn);
    }
    cout << "x = " << xn1 << endl << "f(x) = " << f(xn1) << endl;
    return 0;
}