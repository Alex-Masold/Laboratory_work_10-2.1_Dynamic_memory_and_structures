#include <fstream>
#include <iostream>
using namespace std;

void Myswap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(char* start, int len)
{
	char* end = start + len - 1;
	while (start < end)
	{
		Myswap(start, end);
		start++;
		end--;
	}
}

void Print_revers_str(char* str)
{
	ofstream out("output.txt", ios::app);
	out << str << endl;
	out.close();
}

int main()
{
	char str[101];
	int n;
	ofstream out("output.txt");
	out.close();
	ifstream in("input.txt", ios::in);
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> str;
		reverse(str, strlen(str));
		Print_revers_str(str);
	}
	
	in.close();
}