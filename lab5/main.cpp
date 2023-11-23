//Задание 5
/*
Написать программу, которая считывает английский текст из файла и выводит его на экран, 
заменив прописной каждую первую букву слов, начинающихся с гласной буквы.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream input("input.txt");

    if (input.is_open())
    {
        cout << "File has been opened." << endl;
        while (getline(input, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')
                {
                    if (line[i + 1] == 'e' or line[i + 1] == 'y' or line[i + 1] == 'i' or
                        line[i + 1] == 'o' or line[i + 1] == 'a' or line[i + 1] == 'u')
                    {
                        line[i + 1] -= 32;
                    }
                }
                if (i == 0)
                {
                    if (line[i] == 'e' or line[i] == 'y' or line[i] == 'i' or
                        line[i] == 'o' or line[i] == 'a' or line[i] == 'u')
                    {
                        line[i] -= 32;
                    }
                }
            }

            cout << line << endl;
        }
    }

    input.close();
    cout << "Files are closed.\nPush any button to exit." << endl;
}
