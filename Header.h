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
	char name[50];
	char address[50];

	friend istream& operator >> (istream&, ReturnBooks&);	// method of insert, operator overload >> like friendly functions
	friend ostream& operator << (ostream&, ReturnBooks&);	// method of insert, operator overload << like friendly functions
	ReturnBooks& operator = (const ReturnBooks&);
	friend bool operator == (const ReturnBooks, const ReturnBooks);
};
struct NotReturnBooks	// Container3 «Студенты, не сдавшие книги».
{
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
	int count;
};