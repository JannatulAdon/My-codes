#include <bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start, end;
    double time;

    start = clock();
    cout << "PRited):";
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl
         << "Time : " << time << endl;
}