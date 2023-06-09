#include <iostream>
using namespace std;

int main ()
{
	int n1,n2,result;

	cout <<"First Hex Number :";
	cin >> hex >> n1;

	cout << endl;

	cout <<"First Hex Number :";
	cin >> hex >> n2;

	result = n1*n2;

	cout << hex << n1 << endl;
	cout << hex << n2 << endl;
	cout << hex << result<< endl;

	return 0;
}