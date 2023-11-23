#include <iostream>
#include <math.h>

using namespace std;

int main() {

    double age, height;
    string result;
    cout << "Input your age: " << endl;
    cin >> age;
    cout << "Input your height: " << endl;
    cin >> height;
    if (age > 18 && height < 160) {
        result = "mini chel";
    }
    else if (age < 18 && height > 160) {
        result = "how it's going on Heavens?";
    }
    else if (age < 18 && height < 160) {
        result = "good boy";
    }
    else if (age > 18 && height > 160) {
        result = "good boy,ceep going";
    }
    cout <<result << endl;
    return 0;
}
