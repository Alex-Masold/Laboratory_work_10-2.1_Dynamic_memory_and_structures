#include <fstream>
#include <iostream>

using namespace std;

bool Lower(char c)
{
	return c <= 'z' && c >= 'a';
}

bool Upper(char c)
{
	return c <= 'Z' && c >= 'A';
}

bool Digit(char c)
{
	return c <= '9' && c >= '0';
}

int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt)
{
	int len = 0;
	*oLowerCnt = 0;
	*oUpperCnt = 0;
	*oDigitsCnt = 0;
	while (*iStr != '\0')
	{
		*oLowerCnt += Lower(*iStr);
		*oUpperCnt += Upper(*iStr);
		*oDigitsCnt += Digit(*iStr);
		len++;
		iStr++;
	}
	return len;
}

void PrintLine(int num, int len, int lower, int upper, int digit)
{
	ofstream out("output.txt", ios::app);
	out << "Line " << num
		<< " has " << len
		<< " chars: " << lower + upper
		<< " are letters (" << lower
		<< " lower, " << upper << " upper"
		<< "), " << digit
		<< " are digits." << endl;
	out.close();
}

int main()
{
	char str[102];
	int lower = 0, upper = 0, digit = 0, line = 1, lenght;
	ofstream out("output.txt");
	out.close();
	ifstream in("input.txt", ios::in);
	while (in.getline(str, 102))
	{
		lenght = calcLetters(str, &lower, &upper, &digit);
		PrintLine(line, lenght, lower, upper, digit);
		line++;
	}
	in.close();


}