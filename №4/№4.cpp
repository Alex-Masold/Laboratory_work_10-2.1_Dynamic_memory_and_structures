#include <fstream>
#include <iostream>

using namespace std;

struct Label
{
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
};  

struct NameStats {
    int cntTotal = 0; //сколько всего подписей
    int cntLong = 0; //сколько подписей с именами длиннее 10 букв
};

struct AgeStats {
    int cntTotal = 0 ; //сколько всего подписей
    int cntAdults = 0; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids = 0; //сколько подписей детей (меньше 14 лет)
};

void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges)
{
    oNames->cntTotal += cnt;
    oAges->cntTotal += cnt;

    while (cnt-- > 0)
    {
        if (strlen(arr->name) > 10) 
        {
            oNames->cntLong++;
        }
        if (arr->age >= 18)
        {
            oAges->cntAdults++;
        }
        else if (arr->age < 14)
        {
            oAges->cntKids++;
        }
        arr++;
    }
}

void printStat(NameStats* oNames, AgeStats* oAges)
{
    ofstream out("output.txt");
    out << "names: total = " << oNames->cntTotal << endl
        << "names: long = " << oNames->cntLong << endl
        << "ages: total = " << oAges->cntTotal << endl
        << "ages: adult = " << oAges->cntAdults << endl
        << "ages: kid = " << oAges->cntKids;
    out.close();
}

int main()
{
    int n;
    string trash;
    NameStats oNames;
    AgeStats oAges;
    ifstream in("input.txt", ios::in);
    in >> n;
    Label* labels = new Label[n];
    for (int i = 0; i < n; i++)
    {
        in >> labels[i].name >> labels[i].age >> trash;
    }
    in.close();
    calcStats(labels, n, &oNames, &oAges);
    printStat(&oNames, &oAges);
}
