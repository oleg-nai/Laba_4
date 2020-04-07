#include "Header.h"

/*
// --------------------------------------------------------------------------------------
							4 Лабораторная работа
				Функции-шаблоны. Классы-шаблоны. Потоки.

Найдович Олег		7 группа
					4 вариант

Объяснение работы:

	Для каждой структуры определены меторы:
		- ввода с консоли всех данных структуры (реализовано через перегрузку оператора >> )
		- вывод на консоль всех данных структуры (реализовано через перегрузку оператора << )
		- присваивания (реализовано через перегрузку оператора = )
		- равенства (реализовано через перегрузку оператора == )

	Для класса шаблона определены методы:
		- конструктор, диструктор, конструктор копирования
		- ввод из текстового потока (реализован через функцию InputTextData )
		-


// --------------------------------------------------------------------------------------
*/

int main(void)
{

	Student<NotReturnBooks> firstCourse;
	firstCourse.InputTextData("NotReturnBooksInput.txt");
	firstCourse.OutputTextConsole();
	firstCourse.OutputTextFile("NotReturnBooksOutput.txt");

	Student<TakeBooks> secondCourse;
	secondCourse.InputTextData("TakeBooksInput.txt");
	secondCourse.OutputTextConsole();
	secondCourse.OutputTextFile("TakeBooksOutput.txt");

	Student<ReturnBooks> thirdCourse;
	thirdCourse.InputTextData("ReturnBooksInput.txt");
	thirdCourse.OutputTextConsole();
	secondCourse.OutputTextFile("ReturnBooksOutput.txt");

	return 0;

	//Student<NotReturnBooks> firstCourse;
	//firstCourse.NotReturnBooks("NotReturnBooks.txt");
	//Student<ReturnBooks> second;
	//second.ReadTextData("ReturnBooks.txt");
	//return 0;


	//firstCourse.OutputTextData();
	//TakeBooks Oleg, Kirill;
	//cin >> Oleg >> Kirill;
	//cout << Oleg << Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;
	//Oleg = Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;

	//ReturnBooks Oleg, Kirill;
	//cin >> Oleg >> Kirill;
	//cout << Oleg << Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;
	//Oleg = Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;
	//return 0;

	//NotReturnBooks Oleg, Kirill;
	//cin >> Oleg >> Kirill;
	//cout << Oleg << Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;
	//Oleg = Kirill;
	//if (Oleg == Kirill)
	//	cout << "Oleg == Kirill" << endl;
	//else
	//	cout << "Oleg != Kirill" << endl;

	//string path = "WriteDataBinary.txt";
}