#include <iostream>
#include <cmath>

using namespace std;

float F(float x) {
    return exp(x) + logl(x) - 10 * x;
}

float f(float x) {
    return exp(x) + 1 / x - 10;
}

int main() {
    float x = 3.6, eps = 0.00001, dx;
    do
    {
        dx = F(x) / f(x);
        x = x - dx;
    } while (fabs(dx) > eps);
    cout << "x = " << x << "\n f(x) = " << F(x) << endl;
    return 0;
}