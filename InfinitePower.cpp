#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stdio.h>
using namespace std;

int gun[100000000];
int num[100000000];
int main()
{
	char in[100000];
	int power;
	cout << "Enter the number (0 to clear the terminal): ";
	cin >> in;
	if (in[0] == '0')
	{
		system("cls");
		return 0;
	}
	cout << "Enter the power: ";
	cin >> power;
	cout << endl;
	int input[100000], lin, lm, r, ch, koma;
	lin = strlen(in) - 1;
	lm = strlen(in) - 1;

	clock_t start, end;
	double time1, time2;
	start = clock();
	for (int i = 0; i <= lin; i++)
	{
		input[i] = in[i] - 48;
		num[i] = in[i] - 48;
	}
	for (int z = 1; z < power; z++)
	{
		for (int i = lin; i >= 0; i--)
		{
			for (int j = lm; j >= 0; j--)
			{
				gun[i + j] += input[i] * num[j];
			}
		}
		lm += lin;
		if (gun[0] > 9)
		{
			lm++;
			num[lm] = 0;
			for (int i = lm; i >= 1; i--)
			{
				num[i] += gun[i - 1] % 10;
				num[i - 1] = gun[i - 1] / 10;
				gun[i - 1] = 0;
				if (num[i] > 9)
				{
					ch = num[i];
					num[i] = num[i] % 10;
					num[i - 1] += ch / 10;
				}
			}
		}
		else
		{
			num[lm] = 0;
			r = gun[0];
			for (int i = lm; i >= 1; i--)
			{
				num[i] += gun[i] % 10;
				num[i - 1] = gun[i] / 10;
				gun[i] = 0;
				if (num[i] > 9)
				{
					ch = num[i];
					num[i] = num[i] % 10;
					num[i - 1] += ch / 10;
				}
			}
			num[0] += r;
			gun[0] = 0;
		}

		if (num[0] > 9)
		{
			lm++;
			for (int i = lm; i >= 2; i--)
			{
				num[i] = num[i - 1];
			}
			r = num[0] % 10;
			num[0] /= 10;
			num[1] = r;
		}
	}
	end = clock();
	time1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	if (power < 0)
		cout << "Invalid power";
	else
	{
		cout << endl
			 << "\t" << in << " ^ " << power << endl
			 << "\t=  ";
		koma = lm % 3;
		if (power == 0)
			cout << "1";
		else
		{
			for (int i = 0; i <= lm; i++)
			{
				printf("%d", num[i]);
				// if (i % 3 == koma && i < lm)
				// 	printf(",");
			}
		}
	}
	cout << endl;
	end = clock();
	time2 = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl
		 << "Total numbers in the answer is: " << lm + 1 << endl
		 << "Time needed for calculation: " << time1 << endl
		 << "Time needed to print: " << time2 << endl;
}
