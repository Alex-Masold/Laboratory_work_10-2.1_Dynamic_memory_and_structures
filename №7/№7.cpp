#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include<fstream> 
#include <string> 
using namespace std;

struct Tokens 
{
    int num; //количество слов в строке
    char** arr; //массив слов (каждый элемент –- строка, т.е. char*)
};

//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
void tokensSplit(Tokens* tokens, const char* str, const char* delims) 
{
    int count = 0;
    int  n = strlen(str); // кол-во символов

    if (tokens[0].arr == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (strchr(delims, str[i]))
            {
                if (count > 0)
                    tokens[0].num++; // считаем слова 
                count = 0;
            }
            else
            {
                count++; // счмтаем букавки в слове
            }
        }
        if (count > 0)
        {
            tokens[0].num++; // счиатем слова
        }
    }
    else // делим слова
    {
        int j = 0; 
        for (int i = 0; i < n; i++)
        {
            if (strchr(delims, str[i]))
            {
                if (count != 0)
                {
                    tokens[0].arr[j] = new char[count + 2];
                    strncpy(tokens[0].arr[j], str - count + i, count); 

                    tokens[0].arr[i][count] = '\0';
                    j++;
                }
                count = 0l;
            }
            else
            {
                count++;
            }
        }
    }
}

//удаляет все ресурсы внутри tokens
void tokensFree(Tokens* tokens) 
{

    free(tokens[0].arr);
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
    Tokens token = { 0, NULL };
    char* split_str = new char[Len() + 2];
    ifstream in("input.txt", ios::in);
    in >> split_str;
    cout << split_str;
    in.close();
    tokensSplit(&token, split_str, ":;,.");
    printf("%d\n", token.num);
    token.arr = new char*[token.num];

    tokensSplit(&token, split_str, ":;,.");
    for (int i = 0; i < token.num; i++) {
        cout << token.arr[i] << "\n";
    }
    tokensFree(&token);
}
