#include <bits/stdc++.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;
string clr, cpy;
int cn;
void PrintScramble()
{
    cn = 0;
    cpy = clr;
    int ran1, ran2, c = 100;
    string scramble = "RLUDFB";
    srand(time(0));
    for (int i = 0; i < 20; i++)
    {
        ran1 = rand() % 6;
        if (c != ran1)
        {
            ran2 = rand() % 3;
            cout << scramble[ran1];
            cpy += scramble[ran1];
            if (ran2 % 3 != 0)
            {
                cn++;
                cout << (ran2 % 3 == 1 ? "'" : "2");
                ran2 % 3 == 1 ? cpy += '\'' : cpy += '2';
            }
            cout << " ";
            cpy += ' ';
            c = ran1;
        }
        else
            i--;
    }
    cout << endl
         << endl;
}
int aline(double all)
{
    int cc = 10;
    if (all >= 10)
        cc--;
    if (all >= 100)
        cc--;
    if (all >= 1000)
        cc--;
    if (all >= 10000)
        cc--;
    if (all >= 100000)
        cc--;
    if (all >= 1000000)
        cc--;
    return cc;
}
void PrintInFile(int i, double all, double best, double worest, double avarage, double bestao5)
{
    ofstream f;
    f.open("store.txt", ios::out | ios::app);
    int c = 0, rep = i;
    while (rep)
    {
        rep /= 10;
        c++;
    }
    c = 6 - c;
    while (c--)
        f << " ";
    f << i << "          " << cpy;
    for (int ii = 1; ii <= (aline(all) + 20 - cn); ii++)
        f << " ";
    f << fixed << setprecision(2) << all;
    for (int ii = 1; ii <= aline(best) - 3; ii++)
        f << " ";
    f << best;
    for (int ii = 1; ii <= aline(worest) - 3; ii++)
        f << " ";
    f << worest;
    for (int ii = 1; ii <= aline(avarage) - 3; ii++)
        f << " ";
    f << avarage;
    for (int ii = 1; ii <= aline(bestao5) - 3; ii++)
        f << " ";
    f << bestao5 << endl
      << endl;
    f.close();
}

double getavarage(double in1, double in2, double in3, double in4, double in5)
{
    multiset<double> ms;
    double avarage;

    ms.insert(in1);
    ms.insert(in2);
    ms.insert(in3);
    ms.insert(in4);
    ms.insert(in5);

    auto it = ms.begin();
    avarage = ((*++it) + (*++it) + (*++it)) / 3;

    return avarage;
}

void timer()
{
    system("cls");
    double all[100000], best, worest, bestao5, avarage;
    int i, cnt, x = -471, check = 10;

    ifstream inf;
    inf.open("store.txt");
    inf.seekg(-138, ios::end);
    inf >> i;
    inf.seekg(-45, ios::end);
    inf >> best >> worest >> bestao5 >> bestao5;
    for (cnt = 0; cnt < 4; cnt++)
    {
        inf.seekg(x, ios::end);
        inf >> all[cnt];
        x += 138;
    }
    inf.close();

    cnt--;

    while (check != -1)
    {
        i++;
        cnt++;
        PrintScramble();
        clock_t st, en;
        cout << "Press Enter to start (Ctrl+Z to exit)...";
        check = cin.get();
        if (check != -1)
        {
            st = clock();
            cout << "Press any key to stop...";
            getch();
            en = clock();
            all[cnt] = (double)(en - st) / (CLOCKS_PER_SEC);

            avarage = getavarage(all[cnt], all[cnt - 1], all[cnt - 2], all[cnt - 3], all[cnt - 4]);

            if (best > all[cnt])
                best = all[cnt];
            if (worest < all[cnt])
                worest = all[cnt];
            if (avarage < bestao5)
                bestao5 = avarage;

            PrintInFile(i, all[cnt], best, worest, avarage, bestao5);
            system("cls");
            cout << "Time needed in solve no " << i << " is ";
            printf("%0.2lf\n\n", all[cnt]);
            cout << "last 5 solve: " << all[cnt - 4] << ", " << all[cnt - 3] << ", " << all[cnt - 2] << ", " << all[cnt - 1] << ", " << all[cnt] << endl
                 << "Avarage is: ";
            printf("%0.2lf\n\n", avarage);
            cout << "Best time recorded ";
            printf("%0.2lf\n", best);
            cout << "Worest time recorded ";
            printf("%0.2lf\n\n\n", worest);
            cout << "Press any key to continue...";
            getch();
            system("cls");
        }
    }
}
void deletelast()
{
    ifstream inf("store.txt");
    ofstream of("tteemmpp.txt");
    int i, t, cntfile = -1;
    inf.seekg(-138, ios::end);
    inf >> i;
    inf.seekg(ios::beg);
    string ins;
    while (1)
    {
        cntfile++;
        inf.seekg(cntfile * 138, ios::beg);
        inf >> t;
        inf.seekg(cntfile * 138, ios::beg);
        if (t != i)
        {
            getline(inf, ins);
            of << ins << endl
               << endl;
        }
        else
            break;
    }
    inf.close();
    of.close();
    remove("store.txt");
    rename("tteemmpp.txt", "store.txt");
}
int main()
{
    //timer();
    //deletelast();
}