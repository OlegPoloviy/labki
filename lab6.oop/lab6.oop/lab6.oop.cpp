#include<iostream>
#include<fstream>
using namespace std;

int main() {
    float unsortedArray[40];
    float sortedArray[40];
    ifstream text("C:/Users/Lenovo/Desktop/oop/lab 4/lab 4/output.txt", ios::out);
    for (int i = 0; i < 40; i++) {
        text >> unsortedArray[i];
        sortedArray[i] = unsortedArray[i];
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (sortedArray[j] > sortedArray[j + 1]) {
                float temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
            }
        }
    }
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
    text.close();
    return 0;
}
