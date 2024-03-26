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
void printEtapy(double x, double fx, double n, double en) {
    cout << setiosflags(ios::left);
    cout << "x = " << setw(12) << x << " \tf(x) = " << setw(12) << fx << " \tEn= " << setw(12) << en << " \tn = "   << n << endl;

}
double picard(double x0, function < double(double x) > f, int n, double TOLX, double TOLF) {
	double x = x0;
    for (int i = 0; i < n; i++) {
		double x1 = f(x);
		printEtapy(x1, f(x1), i, abs(x1 - x));
        if (abs(x1 - x) < TOLX) {
            cout << "Przerwano z kryterium dokladnosci TOLX" << endl;
			return x1;
		}
        if (abs(f(x1) - f(x)) < TOLF) {
            cout << "Przerwano z kryterium wiarygodnosci xn jako przyblizenia pierwiastka TOLF" << endl;
            return x1;
        }
		x = x1;
	}
    cout << "Przerwano z powodu przekroczenia liczby iteracji" << endl;

	return x;
}

double bisekcja(double a, double b, function < double(double x) > f, int n, double TOLX, double TOLF) {

    for (int i = 0; i < n; i++) {
        
        double c = (a + b) / 2.0;

        printEtapy(c, f(c), i, (b - a) / 2.0);
        if (f(c) == 0 || abs((b - a) / 2.0) < TOLX ) {
            cout << "Przerwano z kryterium dokladnosci TOLX" << endl;
            return c;
        }
        if (abs(f(c)) < TOLF) {
			cout << "Przerwano z kryterium wiarygodnosci xn jako przyblizenia pierwiastka TOLF" << endl;
			return c;
		}
        if (f(c) * f(a) < 0.0) {
            b = c;
        }
        else {
            a = c;
        }
        
    }
    cout << "Przerwano z powodu przekroczenia liczby iteracji" << endl;

    return (a + b) / 2.0;
}

double newtona(double x0, function < double(double x) > f, function < double(double x) > df, int n, double TOLX, double TOLF) {
	double x = x0;
    for (int i = 0; i < n; i++) {
		double x1 = x - (f(x) / df(x));
		printEtapy(x1, f(x1), i, abs(x1 - x));
        if (abs(x1 - x) < TOLX) {
            cout << "Przerwano z kryterium dokladnosci TOLX" << endl;
			return x1;
		}
        if (abs(f(x1) - f(x)) < TOLF) {
			cout << "Przerwano z kryterium wiarygodnosci xn jako przyblizenia pierwiastka TOLF" << endl;
        }
		x = x1;
	}
    cout << "Przerwano z powodu przekroczenia liczby iteracji" << endl;
	return x;
}
double sieczne(double x0, double x0_2, function < double(double x) > f, int n, double TOLX, double TOLF) {
	double x = x0;
	double x1 = x0_2;
    for (int i = 0; i < n; i++) {
		double x2 = x1 - f(x1) * (x1 - x) / (f(x1) - f(x));
		printEtapy(x2, f(x2), i, abs(x2 - x1));
        if (abs(x2 - x1) < TOLX) {
            cout<<"Przerwano z kryterium dokladnosci TOLX"<<endl;   
			return x2;
		}
        if (abs(f(x2) - f(x1)) < TOLF) {
			cout<<"Przerwano z kryterium wiarygodnosci xn jako przyblizenia pierwiastka TOLF"<<endl;   
			return x2;
		}

		x = x1;
		x1 = x2;
	}
    cout<<"Przerwano z powodu przekroczenia liczby iteracji"<<endl;
	return x;
}


int main()
{
    int const n = 50;
    double const TOLX = DBL_EPSILON;
    double const TOLF = DBL_EPSILON;
    cout << "Picard funkcja 1" << endl;
    picard(5.0, functionA_picard, n, TOLX, TOLF);
    cout << "\nBisekcja funkcja 1" << endl;
    bisekcja(2.0,-3.0, functionA, n, TOLX, TOLF);
    cout << "\nNewtona funkcja 1" << endl;
    newtona(2.0, functionA, [](double x) { return 0.25 * sin(x / 2.0)-1; }, n, TOLX, TOLF);
    cout << "\nSieczne funkcja 1" << endl;
    sieczne(4.0, 6.0, functionA, n, TOLX, TOLF);

    cout << "\nPicard funkcja 2" << endl;
    picard(1.0, functionB, n, TOLX, TOLF);
    cout << "\nBisekcja funkcja 2" << endl;
    bisekcja(0.4, 0.7, functionB, n, TOLX, TOLF);
    cout << "\nNewtona funkcja 2" << endl;
    newtona(0.4, functionB, [](double x) { return 2.0 / (cos(2 * x) * cos(2 * x)) - 1; }, n, TOLX, TOLF);
    cout << "\nSieczne funkcja 2" << endl;
    sieczne(0.4, 0.7, functionB, n, TOLX, TOLF);

}
