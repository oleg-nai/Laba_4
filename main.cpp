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
	setlocale(LC_ALL, "rus");
	// Search  - only for container1 - TakeBooks
	// Sort	   - only for container2 - ReturnBooks
	// Cheaker - only for container3 - NotReturnBooks

	cout << "TakeBooks:\n\n";
	Student<TakeBooks> secondCourse;
	secondCourse.InputTextData("TakeBooksInput.txt");
	secondCourse.OutputTextConsole();
	secondCourse.OutputTextFile("TakeBooksOutput.txt");
	Search(secondCourse);

	cout << "ReturnBooks:\n\n";
	Student<ReturnBooks> thirdCourse;
	thirdCourse.InputTextData("ReturnBooksInput.txt");
	thirdCourse.OutputTextConsole();
	thirdCourse.OutputTextFile("ReturnBooksOutput.txt");
	thirdCourse.Sort();
	thirdCourse.OutputTextConsole();

	cout << "NotReturnBooks:\n\n";
	Student<NotReturnBooks> firstCourse, testCourse;
	firstCourse.InputTextData("NotReturnBooksInput.txt");
	firstCourse.OutputTextConsole();
	firstCourse.OutputTextFile("NotReturnBooksOutput.txt");
	firstCourse.OutputBinaryData("NotReturnBooksOutputBinaryData.txt");
	cout << "This is check for operator =\n";
	testCourse = firstCourse;
	testCourse.OutputTextConsole();

	cout << "Проверка на наличие совпадение структур NotReternBooks(Container3) и TakeBooks(Container1)\n И НЕсовпадения структур NotReternBooks(Container3) и ReturnBooks(Container2)\n\n";
	firstCourse.Cheaker(secondCourse, thirdCourse);
	firstCourse.OutputTextConsole();


	return 0;
}