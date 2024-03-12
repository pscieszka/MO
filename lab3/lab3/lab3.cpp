#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double functionA(double x) {
    return sin(x) * sin(x) - x;
}

double functionB(double x) {
    return tan(2 * x) - x - 1;
}

double bisekcja(double a, double b,double epsilon, function<double(double x)> f) {
    
    while ((b - a)/2 > epsilon) {

        double srodek = (a + b) / 2;

        if (f(srodek) == 0.0) {
            return srodek;

        }
        if (f(a) * f(srodek) < 0) {
            b = srodek;
        }
        else {
            a = srodek;
        }

    }
    return (a + b)/2 ;
}

int main()
{
    cout<<bisekcja(2.333,0.66,0.00001,[](double x) {return x*x-0.66; });
}
