#pragma once
#include <iostream>
#include <fstream>
#include <string>

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
	friend bool operator < (const TakeBooks, int );
	friend bool operator > (const TakeBooks, int );
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
	friend bool operator < (const ReturnBooks, const ReturnBooks);
	friend bool operator > (const ReturnBooks, const ReturnBooks);
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
	friend bool operator == (const NotReturnBooks, const TakeBooks);
	friend bool operator != (const NotReturnBooks, const ReturnBooks);
};



// search function (Х, st);  функция-шаблон, 
// function - template
template<class T>
void Search(T& r)
{
	bool NONE = true;
	bool rightNumber = false;
	cout << "\nSearching for studends\n";
	int k = 0;
	do
	{
		try
		{
			cout << "Enter the number of books: ";
			cin >> k;
			if (cin.fail())
				throw "\tYou've written wrong number/symbol, try again";
			cout << "\n";
			rightNumber = true;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cin.clear();			// return cin to 'normal' mode
			cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
		}
	} while (rightNumber != true);

	cout << "\nSearching for studends, who have more then " << k << " books" << endl << endl;
	int i = 0;
	while (i < r.count)
	{
		if (r.M[i] > k)
		{ 
			NONE = false;
			cout << r.M[i] << endl;
		}
		i++;
	}
	if (NONE == true)
		cout << "NONE\n";
	cout << "--------------------------------------------------------------------------------------" << endl << endl;
};

template<class T>
class Student
{
public:
	int count;
	T* M;
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

	//friend ostream& operator << (ostream&, Student&)	// method of insert, operator overload << like friendly functions
	//{
	//}
	//friend istream& operator >> (istream&, Student&)	// method of insert, operator overload >> like friendly functions
	//{
	//}

	void OutputBinaryData(string path)	// output in binary text file (вывод в бинарный поток (файл) массива данных)
	{
		fstream out;
		out.open(path, ofstream::out | ofstream::binary);
		if (!out.is_open())
		{
			cout << "Open file failed.\n";
		}
		else
		{
			int i = 0;
			while (i < count)
			{
				out.write((char*)&M[i], sizeof(T));
				i++;
			}
			out.close();
		}
	}
	void OutputTextFile(string path)	// output in text file (вывод в текстовый поток (файл) массива данных)
	{
		ofstream out;
		out.open(path);
		if (!out.is_open())
			cout << "Open file failed.\n";
		else
		{
			out << "number of class objects: " << count << endl;
			int i = 0;
			while (i < count)
			{
				out << M[i] << endl;
				i++;
			}
			out << "--------------------------------------------------------------------------------------" << endl;
		}
	}
	void OutputTextConsole(void)		// output in console (вывод на консоль массива данных)
	{
		cout << "number of class objects: " << count << endl;
		int i = 0;
		while (i < count)
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

	Student& operator = (const Student& r)
	{
		int i = 0;
		while (i < r.count)
		{
			M[i] = r.M[i];
			i++;
		}
		count = r.count;
		return *this;
	}
	T& operator [] (int index)
	{
		return M[index];
	}

	//  X.Sortfunction3();//какой контейнер X (М, К, R)  - указано в индивидуальном варианте
	void Sort()	
	{
		cout << endl << "----------------------Sorsing massive conteiner by address------------------------------" << endl << endl;
		T t;
		for (int i = 0; i < count; i++)
			for (int j = i + 1; j < count; j++)
			{
				if (M[i] > M[j])
				{
					t = M[i];
					M[i] = M[j];
					M[j] = t;
				}
			}
	}
	
	// R.function(K,M); //Функция внутри класса-шаблона 
	template<class T1, class T2>
	void Cheaker(const Student<T1>& a, const Student<T2>&b)	// a - Container1(TakeBooks), b - Container2(ReturnBooks), NotReturnBooks = TakeBooks, NotReturnBooks != ReturnBooks 
	{
		Student<NotReturnBooks> last;
		int q = 0;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < a.count; j++)
			{
				for (int k = 0; k < b.count; k++)
				{
					if (M[i] == a.M[j] && M[i] != b.M[k])
					{
						last.M[q++] = M[i];
						break;
					}
				}
			}
		}
		last.count = q-1;
		*this = last;
	}
};