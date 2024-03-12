#include <iostream>

using namespace std;

int main()
{
    float epsilon_float = 1.0f;
    int liczba_bitow = 0;

    while (epsilon_float + 1.0f > 1.0f)
    {
		epsilon_float = epsilon_float / 2.0f;
		liczba_bitow++;
		
	}
	liczba_bitow--;
	epsilon_float = epsilon_float * 2.0f;
    cout << "Liczba bitow mantysy dla float: " << liczba_bitow << endl;
	cout << "Epsilon maszynowy dla float: " << epsilon_float << endl;

	double epsilon_double = 1.0;
	liczba_bitow = 0;

	while (epsilon_double + 1.0 > 1.0)
	{
		epsilon_double = epsilon_double / 2.0;
		liczba_bitow++;
	}
	liczba_bitow--;
	epsilon_double = epsilon_double * 2.0;

	cout << "Liczba bitow mantysy dla double: " << liczba_bitow << endl;
	cout << "Epsilon maszynowy dla double: " << epsilon_double << endl;

	
	
	return 0;	

}

// prezycja arytmetyki = 2^(-(t+1)), epsilon = 2*2^(-(t+1)) => epsilon = 2^(-t)
