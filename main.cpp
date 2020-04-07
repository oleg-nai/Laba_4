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
	cout << "Press enter to start" << endl;


	/*NotReturnBooks kirill;
	cin >> kirill;*/


	//Student<NotReturnBooks> Kirill;
	//Kirill.Print();

	Student<NotReturnBooks> firstCourse;
	firstCourse.InputTextData("test.txt");
	firstCourse.OutputTextData();
	
	
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

	return 0;
}