#include "Header.h"

/*
// --------------------------------------------------------------------------------------
							4 Лабораторная работа
				Функции-шаблоны. Классы-шаблоны. Потоки.

Найдович Олег		7 группа
					4 вариант

Объяснение работы:

	Для каждой структуры определены меторы:
		- перегрузки оператора: <<
		- перегрузки оператора: >>
		- перегрузки оператора: ==
		- перегрузки оператора: !=
		- перегрузки оператора: >
		- перегрузки оператора: <
		- перегрузки оператора: =
		- переменные:   int		count;
						double	price;
						char	name[50];
						char	address[50];

	Для класса-шаблона определены методы:
		- конструктор, деструктор, конструктор копирования
		- перегрузки оператора: =

		- ввод из текстового потока						(реализован через функцию InputTextData )
		- вывод в бинарный поток (файл) массива данных	(реализован через функцию OutputBinaryData)
		- вывод в текстовый поток (файл) массива данных	(реализован через функцию OutputTextFile)
		- вывод на консоль массива данных				(реализован через функцию OutputTextConsole)
		- ввод из текстового потока						(реализован через функцию InputTextData)
		
		- функция сортировки по парамерту address;	!!!! только для структуры(контейнера) ReturnBooks !!!!
		- функция-шаблон Search вне класса-шаблона;	для поиска структур, у которых парамерт count > k (k вводится с консоли); 
													!!!!Только для структуры(контейнера) TakeBooks!!!!
		- функцию-шаблон Cheaker в классе-шаблон;	Проверка на наличие совпадение структур NotReternBooks(Container3) и TakeBooks(Container1)
							И НЕсовпадения структур NotReternBooks(Container3) и ReturnBooks(Container2)




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

	cout << "Проверка на наличие совпадение структур NotReternBooks(Container3) и TakeBooks(Container1)\nИ НЕсовпадения структур NotReternBooks(Container3) и ReturnBooks(Container2)\nпо имени и адресу\n\n";
	firstCourse.Cheaker(secondCourse, thirdCourse);
	firstCourse.OutputTextConsole();

	return 0;
}