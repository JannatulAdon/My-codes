#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;
int out[200000];
int main()
{
	int in1[100000], in2[100000], length1, length2;
	int r, v, koma;
	char input1[100000], input2[100000];
	cout << "Enter the first number: ";
	cin >> input1;
	cout << "Enter the second number: ";
	cin >> input2;

	clock_t start, end;
	start = clock();

	length1 = strlen(input1);
	length2 = strlen(input2);
	for (int i = 0; i < length1; i++)
	{
		in1[i] = input1[i] - 48;
	}
	for (int i = 0; i < length2; i++)
	{
		in2[i] = input2[i] - 48;
	}
	for (int i = length1 - 1; i >= 0; i--)
	{
		for (int j = length2 - 1; j >= 0; j--)
		{
			out[i + j] += (in1[i] * in2[j]);
		}
	}
	for (int i = length1 + length2 - 2; i > 0; i--)
	{
		r = out[i] % 10;
		v = out[i] / 10;
		out[i] = r;
		out[i - 1] += v;
	}
	cout << endl;
	cout << input1 << " * " << input2 << endl
		 << endl
		 << "\t=   ";
	koma = (length1 + length2 - 2) % 3;
	for (int i = 0; i <= length1 + length2 - 2; i++)
	{
		cout << out[i];
	}
	cout << endl;
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl
		 << "Time : " << time << endl;

	cout << "\n\n\n";
	return 0;
}