#include<iostream>
#include<string>
#include<locale>
#include<Windows.h>
using namespace std;
class Loh {
public:
	int age;
	string name;
	string adress;
	void Console()
	{
		cout << "Ім'я : " << name << "\nадреса : " << adress << "\nвік :  " << age << endl;
	}


};
class Point 
{
	private:
	int x;
	int y;
public:
	int GetX() {
		return x;
	}
	void SetX(int ValueX) {

		x = ValueX;
	}
	int GetY() {
		return y;
	}
	void SetY(int ValueY) {
		y = ValueY * 3;
	}
	void Print() {
		cout << "x = " << x << endl << " y = " << y << endl;
	}
};
	int main()
	{
		Point a;
		a.SetX(5);
		a.SetY(3);


		a.Print();
		int resultY = a.GetY();
		cout << "y result is " << resultY << endl;
		int result = a.GetX();
		cout << "x result is " << result << endl;
		
	
		return 0;
	}