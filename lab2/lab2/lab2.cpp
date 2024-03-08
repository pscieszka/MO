#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double func(double x) {
    double result = 0;
    return (1.0 - exp(-x)) / x;
}

int main() {
    ifstream data("dane_do_laboratorium_2.txt");
    ofstream results("results.txt");
    string line;
    if (data.is_open() && results.is_open()) {
        for (int i = 0; i < 5; ++i) {
            getline(data, line);
        }
        while (getline(data, line)) {
            istringstream stream(line);

            double x, log_value, exp_value;
            stream >> log_value >> x >> exp_value;
            double e = (func(x) - exp_value) / exp_value;
            results << scientific << setprecision(20) << log_value << " " << scientific << setprecision(20) << log10(abs(e)) << endl;
        }
    }
    double num1 = 1.00000000000000000003e-030;
    cout<<func(1.00000000000000000003e-30)<<endl;

    data.close();
    results.close();
}
