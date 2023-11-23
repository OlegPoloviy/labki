#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
class data {
public:
    float xMin, xMax, c, esp;
    float fun(float x) {
        return exp(x) - logl(x) - 10 * x;
    }
    void cycle() {
        while ((xMax - xMin) > esp) {
            c = (xMin + xMax) / 2;
            if (fun(c) * fun(xMin) < 0) {
                xMax = c;

            }
            if (fun(c) * fun(xMax) < 0) {
                xMin = c;

            }


        }
        cout << "x = " << c << endl << "fun(x) = " << fun(c) << endl;
    }

};
int main() {
    data newObj;
    newObj.esp = 0.0001;
    newObj.xMin = 3.5;
    newObj.xMax = 3.6;
    newObj.cycle();

}