#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Time
{
	int h;
	int m;
	int s;
};

void printTime(int *h, int *m, int *s)
{
	char buf[10];
	int res;
	string str = "error!";
	res = snprintf(buf, sizeof(buf), "%02d:%02d:%02d", h, m, s);
	if (res >= 0 && res < sizeof(buf))
		str = buf;
	ofstream out("output.txt");
	out << str << endl;
	out.close();
}

int main()
{
	int n;
	Time time;
	ifstream in("input.txt", ios::in);
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> time.h;
		in >> time.m;
		in >> time.s;
		printTime(&time.h, &time.m, &time.s);
	}
	in.close();
           
}