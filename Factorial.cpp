#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>
using namespace std;

int gun[100000000];
int input[100000000];
int num[100000000];

int cnt(int a)
{
    int r = 0, i = 0;
    while (1)
    {
        input[i] = a % 10;
        i++;
        a /= 10;
        if (a == 0)
            break;
        else
        {
            r++;
        }
    }
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    input[0] = 1;
    num[0] = 1;
    long long in;
    int count = 0, c, r, ch;
    cout << "Enter the number: ";
    cin >> in;

    clock_t start, end;
    double time1, time2;
    start = clock();

    for (int z = 1; z <= in; z++)
    {
        c = cnt(z);
        for (int i = c, x = 0; i >= 0; i--, x++)
        {
            for (int j = count; j >= 0; j--)
            {
                gun[i + j] += input[x] * num[j];
            }
        }
        count += c;
        if (gun[0] > 9)
        {
            count++;
            num[count] = 0;
            for (int i = count; i >= 1; i--)
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
            num[count] = 0;
            r = gun[0];
            for (int i = count; i >= 1; i--)
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
            count++;
            for (int i = count; i >= 2; i--)
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

    cout << endl;
    cout << "\t" << in << "!  =  " << endl
         << endl;
    int koma = count % 3;
    for (int i = 0; i <= count; i++)
    {
        printf("%d", num[i]);
        if (i % 3 == koma && i < count)
            printf(",");
    }
    cout << endl;
    end = clock();
    time2 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl
         << "Total numbers in the answer is: " << count + 1 << endl
         << "Time needed for calculation: " << time1 << endl
         << "Time needed to print: " << time2 << endl;
    return 0;
}