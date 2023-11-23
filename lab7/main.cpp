//Задача 7 вариант 14
/*
Имеется набор данных, состоящий из пар положительных целых чисел. Необходимо выбрать из каждой пары ровно одно число так, 
чтобы шестнадцатеричная запись суммы всех выбранных чисел НЕ оканчивалась на A и при этом была максимально возможной. Гарантируется,
что искомую сумму получить можно. Программа должна напечатать одно число – максимально возможную сумму, соответствующую условиям задачи.
Входные данные: 
Даны два входных файла: 
файл A (27-27a.txt)
файл B (27-27b.txt)
каждый из которых содержит в первой строке количество пар N (1 ≤ N ≤ 100000).
Каждая из следующих N строк содержит два натуральных числа, не превышающих 10 000.

Пример входного файла:
6
3 5
5 10
6 8
5 4
7 9
5 1

Для указанных входных данных значением искомой суммы должно быть число 41, которое в шестнадцатеричной системе счисления записывается как 29.
В ответе укажите два числа: сначала значение искомой суммы для файла А, затем для файла B.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int func(string fileName)
{
    string line;
    ifstream in(fileName);
    int max = 0, min = 0;

    if (in.is_open())
        cout << fileName << " is open." << endl;

    getline(in, line);
    int n = stoi(line);

    for (int i = 0; i < n; i++)
    {
        string sA, sB;
        getline(in, sA, ' ');
        getline(in, sB);
        int a = stoi(sA);
        int b = stoi(sB);


        if (a > b)
            max += a;
        else
            max += b;

        if ((min > abs(a-b) and (a-b) != 0 and (a - b) != 16) or min == 0)
        {
            min = abs(a - b);
        }
    }

    if (max % 16 == 10)
    {
        cout << "max = " << max << endl;
        cout << "as long as max % 16 == 10 (A in hex), new max -= min = " << max << " - " << min << " => " << max - min << endl;
        max -= min;
    }
    cout << "min = " << min << endl;
    in.close();
    return max;
}

int main()
{
    string file1 = "27-27a.txt";
    string file2 = "27-27b.txt";
    cout << "max summ number = " << func(file1) << endl << endl;
    cout << "max summ number = " << func(file2) << endl;

    return 0;
}
