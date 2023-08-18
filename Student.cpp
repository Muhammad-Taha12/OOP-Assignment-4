#include "Student.h"

Student::Student()
{
	ID = 0;
	Name = "";
	Address = "";
	Phone = "";
	issuedBooks = 0;
	for (int init = 0; init < 3; init++)
	{
		issueDate[init] = 14;
	}
	Issued = NULL;
	Shared = NULL;
}

Student::Student(int sID, string sName, string sAddress, string sPhone, Library& L)
{
	ID = sID;
	Name = sName;
	Address = sAddress;
	Phone = sPhone;
	issuedBooks = 0;
	for (int init = 0; init < 3; init++)
	{
		issueDate[init] = 14;
	}
	Issued = NULL;
	Shared = &L;
}

Student::Student(Student& S)
{
	ID = S.ID;
	Name = S.Name;
	Address = S.Address;
	Phone = S.Phone;
	issuedBooks = S.issuedBooks;
	Issued = new Book[issuedBooks];
	for (int copy = 0; copy < issuedBooks; copy++)
	{
		issueDate[copy] = S.issueDate[copy];
		Issued[copy] = S.Issued[copy];
	}
	Shared = S.Shared;
}

void Student::issueBook(int bID)
{
	int location = 0;
	bool found = false, dupe = false;
	for (int find = 0; find < Shared->getBookNum(); find++)
	{
		if (bID == Shared->getList(find).getID())
		{
			location = find;
			found = true;
			if (Shared->getList(find).getAvail() == 0)
			{
				dupe = true;
			}
		}
	}
	for (int find = 0; find < issuedBooks; find++)
	{
		if (bID == Issued[find].getID())
		{
			dupe = true;
		}
	}
	if (found == false)
	{
		cout << "ID does not match any book in the library" << endl;
	}
	else if (dupe == true)
	{
		cout << "Book already issued" << endl;
	}
	else
	{
		if (issuedBooks == 2)
		{
			cout << "Maximum number of books already issued" << endl;
		}
		else
		{
			Student Temp(*this);
			issuedBooks++;
			issueDate[issuedBooks] = 14;
			Issued = new Book[issuedBooks];
			for (int copy = 0; copy < issuedBooks - 1; copy++)
			{
				Issued[copy] = Temp.Issued[copy];
			}
			Issued[issuedBooks - 1] = Shared->getList(location);
			Shared->RemoveBook(bID);
		}
	}
}

void Student::returnBook(int bID)
{
	int index = 0;
	bool found = false;
	for (int find = 0; find < issuedBooks; find++)
	{
		if (Issued[find].getID() == bID)
		{
			found = true;
			index = find;
		}
	}
	if (!found)
	{
		cout << "This student doesn't have a book with that ID" << endl;
	}
	else
	{
		if (issueDate[index] <= 0)
		{
			cout << "This book is being returned late, please pay 100 Rs. as fine" << endl;
		}
		Student Temp(*this);
		issuedBooks--;
		Issued = new Book[issuedBooks];
		for (int copy = 0, copy2 = 0; copy2 < issuedBooks + 1; copy++, copy2++)
		{
			if (copy != index)
			{
				Issued[copy] = Temp.Issued[copy2];
			}
			else
			{
				copy--;
			}

		}
		Shared->ReAddBook(bID);
	}
}

int Student::getIssued()
{
	return issuedBooks;
}

int Student::getDate(int index)
{
	return issueDate[index];
}

void Student::setDate(int index, int date)
{
	issueDate[index] = date;
}

int Student::getID()
{
	return ID;
}

Library& Student::getShared()
{
	return *Shared;
}

Book& Student::operator[](int find)
{
	return Issued[find];
}

ostream& operator<<(ostream& out, const Student& Print)
{
	out << "ID: " << Print.ID << endl;
	out << "Name: " << Print.Name << endl;
	out << "Address: " << Print.Address << endl;
	out << "Phone Number: " << Print.Phone << endl;
	out << "Books Issued: " << Print.issuedBooks << endl;
	return out;
}

Student::~Student()
{
	delete[] Issued;
	Issued = NULL;
}
