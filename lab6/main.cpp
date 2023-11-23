//Задание к лабораторной работе №6
/*.
Написать программу, которая при запуске запрашивает имя пользователя. 
После ввода имени, она сверяет наличие этого имени в базе 
(текстовом файле, имя которого соответствует ФИО студента, сдающего работу),
если такое имя есть – программа сообщает пользователю, что он уже заходил в нее столько-то раз,
затем увеличивает счетчик входов этого пользователя на 1 (в том же файле) и прекращает работу.
Если же имени пользователя нет в базе (файле),
то программа заносит это имя (регистрирует пользователя, о чем сообщает ему на экране) и ставит счетчик посещений 1, после чего прекращает работу.
На защиту лабораторной выносятся: файл с кодом работающей программы и текстовый файл с данными пользователей,
где уже будут сделаны несколько записей имен и количество запусков или программы.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>


using namespace std;

void fileExist(string fileName, string fileName2)
{
	fstream in(fileName);
	if (in.is_open())
	{
		cout << fileName << " exists. It is open." << endl;;
	}
	else
	{
		ofstream in(fileName);
		cout << "No " << fileName << " found. Creating new one." << endl;;

		if (in.is_open())
			cout << "New " << fileName << " is open." << endl;
		in << "0" << endl;
	}
	ofstream out(fileName2);
}

void func(string fileName, string fileName2)
{
	fstream in(fileName);
	fstream out(fileName2);

	string name, opsCount;
	getline(in, opsCount);
	int opiCount = stoi(opsCount);
	out << opiCount + 1;

	if (in.is_open())
		cout << "Function has opened <" << fileName << "> " << opiCount + 1 << "th time" << endl;

	string userName;
	cout << "Enter user name:" << endl;
	cin >> userName;
	bool userExists = false;
	
	if (opiCount == 0)
	{
		out << endl << userName << "=1";
		cout << "New user added:" << endl << userName << "=1\n";
	} else 
	{
		while (!in.eof())
		{
			string name, sCount;
			getline(in, name, '=');
			getline(in, sCount, '\n');
			int iCount = stoi(sCount);
			if (userName == name)
			{
				iCount++;
				userExists = true;
				out << endl << name << "=" << iCount;
				cout << "<" << userName << "> exists. His count of Enter increased to " << iCount << "+1" << endl;
				
			}
			else
				out << endl << name << "=" << iCount;
		}
	}
	
	if (!userExists and opiCount != 0)
	{
		cout << "User does not exists.\nNew user added:";
		out << endl << userName << "=1";
		cout << endl << userName << "=1" << endl;
	}
	opiCount++;
}

int main()
{
	char fileName1[] = "Hello.txt";
	char fileName2[] = "Hello2.txt";
	fileExist(fileName1, fileName2);
	func(fileName1, fileName2);
	remove(fileName1);
	int success = rename(fileName2, fileName1);
	if (success == 0)
	{
		cout << "File changed successfully.";
	}
    return 0;
}
