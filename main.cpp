#include "Header.h"

int main(void)
{
	cout << "Press enter to start" << endl;


	/*NotReturnBooks kirill;
	cin >> kirill;*/


	//Student<NotReturnBooks> Kirill;
	//Kirill.Print();

	Student<NotReturnBooks>Oleg;
	Oleg.Input();
	cout << *Oleg.M;
	Oleg.InputTextData("test.txt");

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