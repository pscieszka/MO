#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>
using namespace std;

double functionA(double x) {
    return sin(x/4.0) * sin(x/4.0) - x;
}

double functionA_picard(double x) {
    return sin(x/4.0) * sin(x/4.0);
}

double functionB(double x) {
    return tan(2 * x) - x - 1;
}
void printEtapy(double x, double fx, double n) {
    cout << setiosflags(ios::left);
    cout << "x = " << setw(12) << x << " \tf(x) = " << setw(12) << fx << " \tn = "   << n << endl;

}
double picard(double x0, function < double(double x) > f, int n, double TOLX, double TOLF) {
	double x = x0;
    for (int i = 0; i < n; i++) {
		double x1 = f(x);
		printEtapy(x1, f(x1), i);
        if (abs(x1 - x) < TOLX || abs(f(x1) - f(x)) < TOLF) {
			return x1;
		}
		x = x1;
	}
	return x;
}

double bisekcja(double a, double b, function < double(double x) > f, int n, double TOLX, double TOLF) {

    for (int i = 0; i < n; i++) {
        
        double c = (a + b) / 2.0;
        printEtapy(c, f(c), i);
        if (f(c) == 0 || (b - a) / 2.0 < TOLX || abs(f(c)) < TOLF) {
            return c;
        }
        if (f(c) * f(a) < 0.0) {
            b = c;
        }
        else {
            a = c;
        }
        
    }
    return (a + b) / 2.0;
}

double newtona(double x0, function < double(double x) > f, function < double(double x) > df, int n, double TOLX, double TOLF) {
	double x = x0;
    for (int i = 0; i < n; i++) {
		double x1 = x - f(x) / df(x);
		printEtapy(x1, f(x1), i);
        if (abs(x1 - x) < TOLX || abs(f(x1) - f(x)) < TOLF) {
			return x1;
		}
		x = x1;
	}
	return x;
}
double sieczne(double x0, double x1, function < double(double x) > f, int n, double TOLX, double TOLF) {
	double x = x0;
	double x_1 = x1;
    for (int i = 0; i < n; i++) {
		double x2 = x_1 - f(x_1) * (x_1 - x) / (f(x_1) - f(x));
		printEtapy(x2, f(x2), i);
        if (abs(x2 - x_1) < TOLX) {
            cout<<"Przerwano z kryterium dokladnosci TOLX"<<endl;   
			return x2;
		}
        if (abs(f(x2) - f(x_1)) < TOLF) {
			cout<<"Przerwano z kryterium wiarygodnosci xn jako przyblizenia pierwiastka TOLF"<<endl;   
			return x2;
		}

		x = x_1;
		x_1 = x2;
	}
    cout<<"Przerwano z powodu przekroczenia liczby iteracji"<<endl;
	return x;
}


int main()
{
    cout << "Picard" << endl;
    picard(5.0, functionA_picard, 100, DBL_EPSILON, DBL_EPSILON);
    cout << "Bisekcja" << endl;
    bisekcja(-5.0,2, functionA, 100, DBL_EPSILON, DBL_EPSILON);
    cout << "Newtona" << endl;
    newtona(5.0, functionA, [](double x) { return 0.25 * sin(x / 2.0) * sin(x / 2.0) - 1; }, 100, DBL_EPSILON, DBL_EPSILON);
    cout << "Sieczne" << endl;
    sieczne(5.0, 6.0, functionA, 100, DBL_EPSILON, DBL_EPSILON);

}
