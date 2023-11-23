#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double age, height;
    string result;
    cout << "Введите ваш возраст: " << endl;
    cin >> age;
    cout << "Введите ваш рост: " << endl;
    cin >> height;
    if (age > 18 && height < 160) {
        result = "карлик ебать";
    }
    else if (age < 18 && height > 160) {
        result = "как погодка наверху?";
    }
    else if (age < 18 && height < 160) {
        result = "Норм штрих";
    }
    else if (age > 18 && height > 160) {
        result = "Норм штрих, так держать";
    }
    cout << "ти " << result << endl;
    return 0;
}
