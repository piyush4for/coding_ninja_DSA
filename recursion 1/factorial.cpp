#include <iostream>
using namespace std;

int factorial(int n)
{
	int smalloutput;
	if (n == 0)
	{
		return 1;
	}
	smalloutput = factorial(n - 1);
	return n * smalloutput;
}
int main()
{
	int n;
	cin >> n;
	cout << factorial(n);
}
