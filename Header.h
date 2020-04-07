#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <search.h>
#include <string>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

struct TakeBooks		// Container1 «Студенты, взявшие книги в библиотеке БГУ»,
{
public:
	int  count;	// last time the book was taken
	char name[50];
	char address[50];

	friend istream& operator >> (istream&, TakeBooks&);	// method of insert, operator overload >> like friendly functions
	friend ostream& operator << (ostream&, TakeBooks&);	// method of insert, operator overload << like friendly functions
	TakeBooks& operator = (const TakeBooks&);
	friend bool operator == (const TakeBooks, const TakeBooks);
};

struct ReturnBooks		// Container2 «Читатели, вернувшие все книги»)
{
public:
	char name[50];
	char address[50];

	friend istream& operator >> (istream&, ReturnBooks&);	// method of insert, operator overload >> like friendly functions
	friend ostream& operator << (ostream&, ReturnBooks&);	// method of insert, operator overload << like friendly functions
	ReturnBooks& operator = (const ReturnBooks&);
	friend bool operator == (const ReturnBooks, const ReturnBooks);
};

struct NotReturnBooks	// Container3 «Студенты, не сдавшие книги».
{
public:
	int    count;
	double price;
	char   name[50];
	char   address[50];

	friend istream& operator >> (istream&, NotReturnBooks&);	// method of insert, operator overload >> like friendly functions
	friend ostream& operator << (ostream&, NotReturnBooks&);	// method of insert, operator overload << like friendly functions
	NotReturnBooks& operator = (const NotReturnBooks&);
	friend bool operator == (const NotReturnBooks, const NotReturnBooks);
};


template<class T>
class Student
{
private:
	int count;
	T* M;
public:
	Student(void) : M(new T[100]), count(NULL) {}	// default constructor
	Student(Student <T>& r)	// copy constructor (A(B))
	{
		count = r.count;
		M = r.M;
	}
	~Student(void)			// default destructor
	{
		delete[] M;	count = 0;
	}

	int GetCount(void) { return count; }
	void SetCount(int k) { count = k; }

	void InputBinaryData(char*)			// input from binary file
	{


	}


	void OutputTextFile(string path)	// вывод в текстовый поток (файл) массива данных )
	{
		ofstream out;
		out.open(path);
		if (!out.is_open())
			cout << "Open file failed.\n";
		else
		{
			out << "number of class objects: " << count << endl;
			int i = 0;
			while (i != count)
			{
				out << M[i] << endl;
				i++;
			}
			out << "--------------------------------------------------------------------------------------" << endl;

		}
	}

	void OutputTextConsole(void)		// output in text file (вывод на консоль массива данных)
	{
		cout << "number of class objects: " << count << endl;
		int i = 0;
		while (i != count)
		{
			cout << M[i] << endl;
			i++;
		}
		printf("--------------------------------------------------------------------------------------\n");
	}

	void InputTextData(string path)		// input from text stream (ввод из текстового потока)
	{
		ifstream in;
		in.open(path);
		if (!in.is_open())
			cout << "Open file failed.\n";
		else
		{
			M = new T[100];
			int i = 0;
			in.seekg(0, ios::beg);
			while (!in.eof())
			{
				in >> M[i];
				i++;
			}
			count = i;
			in.close();
		}
		/*
		void InputTextData(string path)	// input from text stream (ввод из текстового потока)
		{
			ifstream in;
			in.open(path);
			if (!in.is_open())
			{
				cout << "Open file failed.\n";
			}
			else
			{
				char* line = new char[256], * simbol = new char[256], * pch;
				string kindOfStruct = (string)typeid(M).name();
				strcpy(simbol, ";: ");
				M = new T[100];
				int i = 0, j = 0;
				while (!in.eof())
				{
					in >> M[i];
					pch = strtok(line, simbol);
					try
					{
						while (pch != NULL)
						{
							if (kindOfStruct == "struct NotReturnBooks")
							{
								if (j == 0)
									strcpy(M[i].name, pch);
								else if (j == 1)
									strcpy(M[i].address, pch);
								else if (j == 2)
								{
									if (atoi(pch) == 0)		// number check
										throw;
									M[i].count = atoi(pch);
								}
								else if (j == 3)
								{
									if ((double)atof(pch) == 0)	// number check
										throw;
									M[i].price = (double)atof(pch);
								}
							}
							else if (kindOfStruct == "struct ReturnBooks")
							{
								if (j == 0)
									strcpy(M[i].name, pch);
								else if (j == 1)
									strcpy(M[i].address, pch);
								else if (j == 2)
								{
									if (atoi(pch) == 0)
										throw;
									M[i].count = atoi(pch);
								}
							}
							else if (kindOfStruct == "struct TakeBooks")
							{
								if (j == 0)
									strcpy(M[i].name, pch);
								else if (j == 1)
									strcpy(M[i].address, pch);
							}
							j++;
							pch = strtok(NULL, simbol); // берет следующее значение в строке
						}
					}
					catch (...)
					{
						cout << "Error reading file! Chech " << i << " line and " << j << " word" << endl;
					}
					i++;
					j = 0;
				}
				count = i - 1;
				in.close();
			}
		}
	*/
	}

};
