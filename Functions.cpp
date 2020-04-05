#include "Header.h"

// --------------------------------------------------------------------------------------
//										TakeBooks
// --------------------------------------------------------------------------------------

istream& operator >> (istream& os, TakeBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cin.ignore();
	cout << "name:\t ";		cin.getline(A.name, 50);
	cout << "address: ";	cin.getline(A.address, 50);
	do
	{
		try
		{
			cout << "count:\t ";	cin >> A.count;
			if (cin.fail())
				throw "\tYou've written wrong number/symbol, try again";
			cout << "\n";
			return os;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cin.clear();			// return cin to 'normal' mode
			cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
		}
	} while (true);
}

ostream& operator << (ostream& os, TakeBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cout << "name:\t "		<< A.name		<< endl;
	cout << "address: "		<< A.address	<< endl;
	cout << "count:\t "		<< A.count		<< endl;

	ofstream out("TakeBooks.txt"); // stream for recording
	
	out.open("TakeBooks.txt", ios::app); // open file for recording
	if (out.is_open() != true)
	{
		cout << "File open error" << endl;
		return os;
	}
	out << "name:\t " << A.name << endl;
	out << "address: " << A.address << endl;
	out << "count:\t " << A.count << endl;

	out.close(); 
	cout << "Record was successful!\n\n";
	return os;
}

TakeBooks& TakeBooks::operator = (const TakeBooks& r)
{
	strcpy(name, r.name);
	strcpy(address, r.address);
	count = r.count;
	return *this;
}

bool operator == (const TakeBooks a, const TakeBooks r)
{
	if ((strcmp(a.name, r.name) == 0) && (strcmp(a.address, r.address) == 0) && (a.count == r.count))
		return true;
	else
		return false;
}

// --------------------------------------------------------------------------------------
//										ReturnBooks
// --------------------------------------------------------------------------------------

istream& operator >> (istream& os, ReturnBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cout << "name:\t ";		cin.getline(A.name, 50);
	cout << "address: ";	cin.getline(A.address, 50);
	cout << "\n";
	return os;
}

ostream& operator << (ostream& os, ReturnBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cout << "name:\t " << A.name << endl;
	cout << "address: " << A.address << endl;

	ofstream out; // stream for recording
	out.open("ReturnBooks.txt", ios::app); // open file for recording
	if (out.is_open() != true)
	{
		cout << "File open error" << endl;
		return os;
	}
	out << "name:\t " << A.name << endl;
	out << "address: " << A.address << endl;

	out.close();
	cout << "Record was successful!\n\n";
	return os;
}

ReturnBooks& ReturnBooks::operator = (const ReturnBooks& r)
{
	strcpy(name, r.name);
	strcpy(address, r.address);
	return *this;
}

bool operator == (const ReturnBooks a, const ReturnBooks r)
{
	if ((strcmp(a.name, r.name) == 0) && (strcmp(a.address, r.address) == 0))
		return true;
	else
		return false;
}

// --------------------------------------------------------------------------------------
//										NotReturnBooks
// --------------------------------------------------------------------------------------

istream& operator >> (istream& os, NotReturnBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cin.ignore();
	cout << "name:\t ";		cin.getline(A.name, 50);
	cout << "address: ";	cin.getline(A.address, 50);
	bool repeat = false;
	do
	{
		try
		{
			cout << "count:\t ";	cin >> A.count;
			if (cin.fail())
				throw "\tYou've written wrong number/symbol, try again";
			repeat = false;
		}
		catch (const char* ex)
		{
			repeat = true;
			cout << ex << endl;
			cin.clear();			// return cin to 'normal' mode
			cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
		}
	} while (repeat == true);

	do
	{
		try
		{
			cout << "price:\t ";	cin >> A.price;
			if (cin.fail())
				throw "\tYou've written wrong number/symbol, try again";
			cout << "\n";
			return os;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cin.clear();			// return cin to 'normal' mode
			cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
		}
	} while (true);
}

ostream& operator << (ostream& os, NotReturnBooks& A)	// method of insert, operator overload >> like friendly functions	
{
	cout << "name:\t " << A.name << endl;
	cout << "address: " << A.address << endl;
	cout << "count:\t " << A.count << endl;
	cout << "price:\t" << A.price << endl;
	ofstream out; // stream for recording

	out.open("NotReturnBooks.txt", ios::app); // open file for recording
	if (out.is_open() != true)
	{
		cout << "File open error" << endl;
		return os;
	}
	out << "name:\t " << A.name << endl;
	out << "address: " << A.address << endl;
	out << "count:\t " << A.count << endl;
	out << "price:\t" << A.price << endl;

	out.close();
	cout << "Record was successful!\n\n";
	return os;
}

NotReturnBooks& NotReturnBooks::operator = (const NotReturnBooks& r)
{
	strcpy(name, r.name);
	strcpy(address, r.address);
	count = r.count;
	price = r.price;
	return *this;
}

bool operator == (const NotReturnBooks a, const NotReturnBooks r)
{
	if ((strcmp(a.name, r.name) == 0) && (strcmp(a.address, r.address) == 0) && (a.count == r.count) && (a.price == r.price))
		return true;
	else
		return false;
}

// --------------------------------------------------------------------------------------
//										NotReturnBooks
// --------------------------------------------------------------------------------------
