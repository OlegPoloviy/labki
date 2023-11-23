#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers;  // ��������� ������� ��� ��������� �����

    // �������� ����� ��� �������
    std::ifstream infile("C:/Users/Lenovo/Desktop/oop/lab 4/output.txt");

    // ���������� ����� � ����� �� ��������� �� �� �������
    int num;
    while (infile >> num) {
        numbers.push_back(num);
    }

    // ���������� ����� � ������
    std::sort(numbers.begin(), numbers.end());

    // ��������� ������������ ����� � �������
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // �������� �����
    infile.close();

    return 0;
}
