#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct DateTime
{
	int year, month, day;
	int hours, minutes, seconds;
};

int compare(DateTime* date1, DateTime* date2)
{
	//иницилизирум и заполняем массив значений, которые будем сравнивать, из структуры
	int* compared1[6] =
	{
		&date1->year,
		&date1->month,
		&date1->day,
		&date1->hours,
		&date1->minutes,
		&date1->seconds
	};

	int* compared2[6] =
	{
		&date2->year,
		&date2->month,
		&date2->day,
		&date2->hours,
		&date2->minutes,
		&date2->seconds
	};

	for (int i = 0; i < 6; i++)
	{
		if (*compared1[i] < *compared2[i]) // если i-тый элемент массива данный из первой структуры больше i-того элемента массива данный из второй структры
		{
			return -1; // то вохвращаеться -1 (не нашел)
		}
		else if (*compared1[i] > *compared2[i]) // если i-тый элемент массива данный из первой структуры меньше i-того элемента массива данный из второй структры
		{
			return 1; // то возвращает 1 (нашел)
		}
	}
	return 0;
}

DateTime* min(DateTime* arr, int count) // нахождение минимальной структуры из масссива структур
{
	int min = 0; // считаем, что самое минимальная структура, это самая первая структура в массиве
	for (int i = 1; i < count; i++)
	{
		if (compare(&arr[min], &arr[i]) == 1) // Передаем в функцию compare адрес на структуру под индексом min(0) и под индексом i (1)
		{
			min = i; // присваиваем переменной min значение переменной i, если compare предал 1
		}
	}
	return &arr[min];
}

void printDateTime(DateTime* date) // выводим структуру в текстовый файл
{
	ofstream out("output.txt");
	{
		out << date->year << " "
			<< date->month << " "
			<< date->day << " "
			<< date->hours << " "
			<< date->minutes << " "
			<< date->seconds;
	}
	out.close();
}

int main()
{
	int n;
	ifstream in("input.txt", ios::in);
	in >> n;
	DateTime* dates = new DateTime[n];

	for (int i = 0; i < n; i++)
	{
		in >> dates[i].year;
		in >> dates[i].month;
		in >> dates[i].day;
		in >> dates[i].hours;
		in >> dates[i].minutes;
		in >> dates[i].seconds;
	}
	in.close();

	DateTime* min_dates = min(dates, n);
	printDateTime(min_dates);
}
