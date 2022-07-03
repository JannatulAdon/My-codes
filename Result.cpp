#include <bits/stdc++.h>
#include <fstream>
#include <limits>

std::fstream &GotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}
using namespace std;
class person
{
public:
    string name;
    int roll;
    char section;
    int ban, en, math;
    int aban, aen, amath;
    float gpa;
    int total;
    int atotal;
};
bool compare1(person a, person b)
{
    if (a.gpa == b.gpa)
    {
        if (a.atotal == b.atotal)
        {
            if (a.total == b.total)
                return a.math > b.math;
            else
                return a.total > b.total;
        }
        else
            return a.atotal > b.atotal;
    }
    else
        return a.gpa > b.gpa;
}
bool compare2(person a, person b)
{
    if (a.gpa == b.gpa)
    {
        if (a.total == b.total)
        {
            if (a.atotal == b.atotal)
                return a.math > b.math;
            else
                return a.atotal > b.atotal;
        }
        else
            return a.total > b.total;
    }
    else
        return a.gpa > b.gpa;
}
int main()
{
    fstream in("result.txt");//store the result as a txt file in result.txt
    ofstream out("with_assignment.txt");
    ofstream out2("without_assignment.txt");
    string in1, in2;
    person result[150];
    for (int i = 0; i <= 127; i++)
    {
        cout << i;
        string s, n;
        GotoLine(in, i * 42 + 12);
        in >> s;
        in >> s;
        in >> s;
        while (s != "CLASS")
        {
            n += s;
            n += " ";
            in >> s;
        }
        result[i + 1].name = n;
        cout << n << endl;
        in >> s;
        result[i + 1].section = s.back();
        in >> s >> s >> s >> s >> s >> s >> s;
        in >> result[i + 1].roll;

        GotoLine(in, i * 42 + 18);
        int cq, mcq;
        in >> s >> s;
        in >> cq >> mcq >> result[i + 1].aban;
        result[i + 1].ban = cq + mcq;

        GotoLine(in, i * 42 + 19);
        in >> s >> s;
        in >> result[i + 1].en >> result[i + 1].aen;

        GotoLine(in, i * 42 + 20);
        in >> s >> s;
        in >> cq >> mcq >> result[i + 1].amath;
        result[i + 1].math = cq + mcq;

        GotoLine(in, i * 42 + 21);
        in >> s >> s >> s >> s >> s >> s >> s;
        in >> result[i + 1].gpa;
        result[i + 1].total = result[i + 1].ban + result[1 + i].en + result[i + 1].math;
        result[i + 1].atotal = result[i + 1].total + result[i + 1].aban + result[1 + i].aen + result[i + 1].amath;
        in.seekg(0);
    }

    sort(result + 1, result + 128, compare1);
    for (int i = 1; i <= 128; i++)
    {
        out << i << ": " << left << setw(30) << result[i].name << "\t\t(" << result[i].section << "-" << right << setw(2) << result[i].roll << ") => (" << right << setw(2) << result[i].ban << ", " << right << setw(2) << result[i].aban << ")\t(" << right << setw(2) << result[i].en << ", " << right << setw(2) << result[i].aen << ")\t(" << result[i].math << ", " << right << setw(2) << result[i].amath << ")"
            << " => " << left << setw(3) << result[i].atotal + 30 << "\t(" << result[i].gpa << ")" << endl;
    }
    sort(result + 1, result + 128, compare2);
    for (int i = 1; i <= 128; i++)
    {
        out2 << i << ": " << left << setw(30) << result[i].name << "\t\t(" << result[i].section << "-" << right << setw(2) << result[i].roll << ") => (" << right << setw(2) << result[i].ban << ", " << right << setw(2) << result[i].aban << ")\t(" << right << setw(2) << result[i].en << ", " << right << setw(2) << result[i].aen << ")\t(" << result[i].math << ", " << right << setw(2) << result[i].amath << ")"
             << " => " << left << setw(3) << result[i].total << "\t(" << result[i].gpa << ")" << endl;
    }
}