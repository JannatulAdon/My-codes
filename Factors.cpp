#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long in;
	while (1)
	{
		int cnt = 0;
		a = scanf("%lld", &in);
		for (int i = 1; i <= sqrt(in); i++)
			if (in % i == 0)
			cnt++;
				out<< << "\t" << i << " * " << in / i << endl;
		//cout << "\n\n\n\n";
	}
	return 0;
}
