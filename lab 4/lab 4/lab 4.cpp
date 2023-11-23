#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    std::ofstream file("output.txt");
    double a, b, x, f;
    a = -3;
    b = 0;
    for (x = a; x <= b; x += 0.1) {
        f = -x;
        file << x << " " << f << std::endl;
    }
    a = 0;
    b = 2;
    for (x = a; x <= b; x += 0.1) {
        f = x / 2 + 1;
        file << x << " " << f << std::endl;
    }
    file.close();
    return 0;
}
