#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const double epsilon = 2.22045e-16;
double func(double x) {
    return (1.0 - exp(-x)) / x;
}

double func2(double x, double res) { 
    double result = 0.0;
    double taylor = 1.0;
    int n = 2;
    while (abs(result - res) > epsilon) { 
        result += taylor;
        taylor *= -x / n;
        n++;
        if (taylor == 0) {
			break;
		}
    }
    return result;
}


double errorLog10(double x, double y) {
	return log10(abs(x - y) / y);
}
int main() {
    ifstream data("dane_do_laboratorium_2.txt");
    ofstream results("dane.txt");
    ofstream results2("dane2.txt");
    ofstream results3("dane3.txt");
    string line;
    if (data.is_open() && results.is_open()) {
        for (int i = 0; i < 5; ++i) {
            getline(data, line);
        }
        while (getline(data, line)) {
            istringstream stream(line);

            double x, log_value, exp_value;
            stream >> log_value >> x >> exp_value;
            double e = errorLog10(func(x), exp_value);

            results << scientific << setprecision(20)<< log_value << " " << scientific<<setprecision(20)<< e << endl;
            results2 << scientific << setprecision(20)<< log_value << " " << scientific<<setprecision(20)<< errorLog10(func2(x,exp_value), exp_value) << endl;
            if (x < 0.0) {
				results3 << scientific << setprecision(20)<< log_value << " " << scientific<<setprecision(20)<< errorLog10(func2(x, exp_value), exp_value) << endl;
			}
            else {
                results3 << scientific << setprecision(20)<< log_value << " " << scientific<<setprecision(20)<< errorLog10(func(x), exp_value) << endl;
            }
        }
    }


    data.close();
    results.close();
    results2.close();
    results3.close();
}


