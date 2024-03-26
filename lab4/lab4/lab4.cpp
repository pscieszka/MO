#include <iostream>
#include <iomanip>

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
	double Enx, Eny, Enz;
	
	for (int i = 0; i < 100; i++) {
		x1 = x - delta1(x, y);
		y1 = y - delta2(x, y);
		z1 = z - delta3(z);
		Enx = abs(x1 - x);
		Eny = abs(y1 - y);
		Enz = abs(z1 - z);
		x = x1;
		y = y1;
		z = z1;


		if (abs(Enx) <= DBL_EPSILON && abs(Eny) <= DBL_EPSILON && abs(Enz) <= DBL_EPSILON) {
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
		cout << setiosflags(ios::left);

		cout << "Iteracja: "  << i+1 << endl<<endl;

		cout << "x = " << setw(12) << x  << "\ty = " << setw(12) << y  << " \tz = " << setw(12) << z << endl;
		
		cout << "f1 = " << setw(12) << f1(x, y, z) << "\tf2 = " << setw(12) << f2(x, y) << "\tf3 = " << setw(12) << f3(x, y) << endl;

		cout << "delta1 = " << setw(12) << delta1(x, y) << "\tdelta2 = " << setw(12) << delta2(x, y) << "\tdelta3 = " << setw(12) << delta3(z) << endl;
		
		cout << "En(x) =  " << setw(12) << abs(Enx) << "\tEn(y) =  " << setw(12) << abs(Eny) << "\tEn(z) =  " << setw(12) << abs(Enz) << endl << endl << endl;

		
	}

}

int main()
{
    newton(2, 3, 4);
}

