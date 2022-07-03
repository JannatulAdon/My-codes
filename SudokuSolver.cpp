#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// 3 0 5 4 0 2 0 9 6 
// 6 0 0 0 3 0 0 5 2 
// 2 0 0 6 5 1 0 8 3 
// 1 0 2 3 0 6 5 7 8 
// 7 0 3 0 0 0 2 6 1 
// 8 5 6 2 1 7 9 3 4 
// 0 2 7 8 6 0 3 1 5 
// 0 3 8 1 2 0 6 4 7 
// 0 6 1 0 0 3 8 2 9 
// this sudoki cannot be solved. have to find logics here
//https://www.tutorialspoint.com/sudoku-solver-in-cplusplus

bool validation(vector<int> pas, int a);
bool line(vector<vector<int>> in, int i, int j, int num);
bool colum(vector<vector<int>> in, int i, int j, int num);
bool block(vector<vector<int>> in, int i, int j, int num);
bool check(vector<vector<int>> in, int i, int j, int num);

void first_stage(vector<vector<int>> &in);
void second_stage(vector<vector<int>> &in);

int main()
{
    system("cls");
    cout << "Input the sudoku :\n(Input '0' for each empty cell, put a 'sapce' between every number and type 'enter' after end of a line)\n\n";
    vector<vector<int>> in(11, vector<int>(11));
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            cin >> in[i][j];
    int sum;
    while (sum != 405)
    {
        sum = 0;
        first_stage(in);
        second_stage(in);
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                sum += in[i][j];
    }
    system("cls");
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            cout << in[i][j] << " ";
        cout << endl;
    }
    getch();
}

bool validation(vector<int> pas, int a)
{
    for (int i = 1; i <= 9; i++)
        if (pas[i] == a)
            return false;
    return true;
}
bool line(vector<vector<int>> in, int i, int j, int num)
{
    return validation(in[i], num);
}
bool colum(vector<vector<int>> in, int i, int j, int num)
{
    vector<int> temp;
    temp.push_back(0);
    for (i = 1; i <= 9; i++)
        temp.push_back(in[i][j]);
    return validation(temp, num);
}
bool block(vector<vector<int>> in, int i, int j, int num)
{
    vector<int> temp;
    temp.push_back(0);
    i--, j--;

    i /= 3, i *= 3, i++;
    int li = i + 2;

    j /= 3, j *= 3, j++;
    int lj = j + 2;

    for (; i <= li; i++)
        for (j = lj - 2; j <= lj; j++)
            temp.push_back(in[i][j]);
    return validation(temp, num);
}
bool check(vector<vector<int>> in, int i, int j, int num)
{
    return (line(in, i, j, num) && colum(in, i, j, num) && block(in, i, j, num));
}
void first_stage(vector<vector<int>> &in)
{
    for (int num = 1; num <= 9; num++)
        for (int i = 1; i <= 9; i++)
        {
            int si = 0, sj = 0;
            int count_true = 0;
            for (int j = 1; j <= 9; j++)
            {
                if (in[i][j] == num)
                    break;
                else if (in[i][j] != 0)
                    continue;
                if (check(in, i, j, num))
                {
                    si = i, sj = j, count_true++;
                }
            }
            if (count_true == 1)
            {
                in[si][sj] = num;
            }
        }
}
void second_stage(vector<vector<int>> &in)
{
    for (int i = 1; i <= 9; i++)
    {

        for (int j = 1; j <= 9; j++)
        {
            int snum = 0;
            int count_true = 0;
            for (int num = 1; num <= 9; num++)
            {
                if (in[i][j] != 0)
                    break;
                if (check(in, i, j, num))
                {
                    snum = num, count_true++;
                }
            }
            if (count_true == 1)
            {
                in[i][j] = snum;
            }
        }
    }
}