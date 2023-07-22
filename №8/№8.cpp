#include <iostream>
#include <fstream>

using namespace std;

void concat(string& pref, string& suff)
{
	pref += suff;
}

int main()
{
	int count;
	string str1;
	string str2;
	ifstream in("input.txt", ios::in);
	in >> count;
	in >> str1;
	for (int i = 1; i < count; i++)
	{
		in >> str2;
		concat(str1, str2);
	}
	in.close();

	cout << str1;
}