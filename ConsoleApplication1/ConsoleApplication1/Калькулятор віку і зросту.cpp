#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double age, height;
    string result;
    cout << "������� ��� �������: " << endl;
    cin >> age;
    cout << "������� ��� ����: " << endl;
    cin >> height;
    if (age > 18 && height < 160) {
        result = "������ �����";
    }
    else if (age < 18 && height > 160) {
        result = "��� ������� �������?";
    }
    else if (age < 18 && height < 160) {
        result = "���� �����";
    }
    else if (age > 18 && height > 160) {
        result = "���� �����, ��� �������";
    }
    cout << "�� " << result << endl;
    return 0;
}
