#include <fstream>
const double PI = 3.14159265358979323846;

int main() {
    std::ofstream out("heart.dat");
    for (double t = 0.0; t <= 2 * PI; t += 0.01) {
        double x = 16 * pow(sin(t), 3);
        double y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
        out << x << " " << y << std::endl;
    }
    out.close();
    return 0;
}
