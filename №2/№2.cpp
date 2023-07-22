#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Error(int* hour, int* minute, int* second) // возвращаем в значения структуры -1
{
	*hour = -1;
	*minute = -1;
	*second = -1;
}

void CheckTime(int* hour, int* minute, int* second, int* flag)
{
	if (*hour < 0 || *hour > 23 || *minute < 0 || *minute > 59 || *second < 0 || *second > 59)
	{
		*flag = 0;
		return Error(hour, minute, second);
	}
}

int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds)
{
	int hours, minutes, seconds;
	int flag;

	switch (sscanf_s(iStr, "%02d:%02d:%02d", &hours, &minutes, &seconds))
	{
		case 2:
			seconds = 0;
			flag = 1;
			break;
		case 3:
			flag = 1;
			break;
		default:
			flag = 0;
	}

	CheckTime(&hours, &minutes, &seconds, &flag);
	if (!flag)
	{
		Error(&hours, &minutes, &seconds);
	}
	
	*oHours = hours;

	if (*oMinutes != NULL)
	{
		*oMinutes = minutes;
		if (*oSeconds != NULL)
		{
			*oSeconds = seconds;
		}
	}
	return flag;
}

int Len()
{
	int count = 0;
	char c;
	ifstream in("input.txt", ios::in);
	while ((c = in.get()) != EOF)
	{
		count++;
	}
	count++;
	in.close();
	return count;
}

int main()
{
	int count = Len();
	char* time_string = new char[count];
	int hour, minute, second, flag;
	int* phour = &hour, * pminute = &minute, * psecond = &second, * pflag = &flag;
	ifstream in("input.txt", ios::in);
	in.getline(time_string, count);
	in.close();

	flag = readTime(time_string, phour, pminute, psecond);
	ofstream out("output.txt");
	out << flag << " " << hour << " " << minute << " " << second << endl;
	out << flag << " " << hour << " " << minute << endl;
	out << flag << " " << hour << endl;	
	out.close();
}
