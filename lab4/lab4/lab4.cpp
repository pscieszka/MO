#include <iostream>

using namespace std;

double f1(double x, double y, double z) {
    return x * x + y * y + z * z - 2;
}
double f2(double x, double y) {
	return x * x + y * y  - 1;
}
double f3(double x, double y) {
    return x*x - y;
}

double delta1(double x, double y) {
    return (2 * x * x * y - y * y + x * x - 1) / (4 * x * y + 2 * x);
}
double delta2(double x, double y) {
    return (y * y + y - 1) / (1 + 2 * y);
}
double delta3(double z) {
	return (z*z-1)/(2*z);
}
void newton(double x, double y, double z) {
	double x1, y1, z1;
	
	for (int i = 0; i < 100; i++) {
		x1 = x - delta1(x, y);
		y1 = y - delta2(x, y);
		z1 = z - delta3(z);
		x = x1;
		y = y1;
		z = z1;


		if (abs(delta1(x, y)) <= DBL_EPSILON && abs(delta2(x, y)) <= DBL_EPSILON && abs(delta3(z)) <= DBL_EPSILON) {
			cout << "\nPrzerwano po " << i << " iteracjach. Z kryterium dokladnosci wyznaczania xn." << endl;
			break;
		}

		if (abs(f1(x1, y1, z1)) <= DBL_EPSILON && abs(f2(x1, y1)) <= DBL_EPSILON && abs(f3(x1, y1)) <= DBL_EPSILON) {
			cout<<"\nPrzerwano po "<<i<<" iteracjach. Z kryterium wiarygodnosci xn jako przyblizenie pierwiastka."<<endl;
			break;
		}

		if (i == 99) {
			cout<<"\nPrzerwano po 100 iteracjach."<<endl;
		}

		cout << "Iteracja: " << i+1 << endl;

		cout << "x = " << x  << "\ty = " << y  << " \tz = " << z << endl;
		
		cout << "f1 = " << f1(x, y, z) << "\tf2 = " << f2(x, y) << "\tf3 = " << f3(x, y) << endl;

		cout << "delta1 = " << delta1(x, y) << "\tdelta2 = " << delta2(x, y) << "\tdelta3 = " << delta3(z) << endl << endl;
		
	}

}

int main()
{
    newton(2, 3, 4);
}

