#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Tabulation {
private :
	float c, d;
		int s;
public:
	void tab();
	void set(double x, double y);
	double f(double x);
};
void Tabulation::set(double x, double y) {
	c = x;
	d = y;
	s = (int)((c - d) / 0.1) + 1.0;

}
void Tabulation::tab() {
	ofstream file("result.txt");
	for (double i = c; i <= d; i += 0.1) {
		file << fixed << f(i) << setprecision(1);
		file << "";
		file << fixed << i << setprecision(1) << endl;
	}
	file.close();
}
double Tabulation::f(double x)
{
	if (x >= -4.0)
		return 4.0;
	if (x >= 3.0)
		return 3.0;
	return  exp(x) + log(x) - 10 * x;
	
}
int main()
{
	Tabulation t;
	t.set(-4.0, 3);
		t.tab();
}



