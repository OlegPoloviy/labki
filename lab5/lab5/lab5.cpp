#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers;  // створення вектора для зберігання чисел

    // відкриття файлу для читання
    std::ifstream infile("C:/Users/Lenovo/Desktop/oop/lab 4/output.txt");

    // зчитування чисел з файлу та додавання їх до вектора
    int num;
    while (infile >> num) {
        numbers.push_back(num);
    }

    // сортування чисел у векторі
    std::sort(numbers.begin(), numbers.end());

    // виведення відсортованих чисел у консоль
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // закриття файлу
    infile.close();

    return 0;
}
