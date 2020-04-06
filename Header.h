#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <search.h>
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
public:
	int count;
	T* M;

	Student(void): M(new T[sizeof(T)]), count(NULL) {}	// default constructor
	Student(Student <T> & r)	// copy constructor (A(B))
	{
		count = r.count;
		M = r.M;
	}
	~Student(void)			// default destructor
	{
		delete[] M;
		count = 0;
	}

	void Input()
	{
		cin >> *M;
	}

	int GetCount(void)		{return count;}
	void SetCount(int k)	{count = k;}

	void OutputDataBinary(char*);	// output binary
	void OutputTextData(char*);		// output in text file

	void InputBinaryData(char*);	// input from binary file
	void InputTextData(string path)	// input from text stream (ввод из текстового потока)
	{
		fstream in;
		in.open(path, ofstream::in);
		if (!in.is_open())
		{
			cout << "Open file failed.\n";
		}
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
			count = i - 1;
			in.close();
		}
	}


	/*void Print(string)
	{
		cout << "hello";
	}*/

//	friend istream& operator >> (istream&, Student<T>&);

};

//template <class T> class Formatter
//{
//	T* m_t;
//public:
//	Formatter(T* t) : m_t(t) { }
//	void print()
//	{
//		cout << *m_t << endl;
//	}
//};

