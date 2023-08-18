#include "Faculty.h"

Faculty::Faculty()
{
	ID = 0;
	Name = "";
	Address = "";
	Phone = "";
	issuedBooks = 0;
	for (int init = 0; init < 5; init++)
	{
		issueDate[init] = 60;
	}
	Issued = NULL;
	Shared = NULL;
}

Faculty::Faculty(int fID, string fName, string fAddress, string fPhone, Library &L)
{
	ID = fID;
	Name = fName;
	Address = fAddress;
	Phone = fPhone;
	issuedBooks = 0;
	for (int init = 0; init < 5; init++)
	{
		issueDate[init] = 60;
	}
	Issued = NULL;
	Shared = &L;
}

Faculty::Faculty(Faculty& F)
{
	ID = F.ID;
	Name = F.Name;
	Address = F.Address;
	Phone = F.Phone;
	issuedBooks = F.issuedBooks;
	Issued = new Book[issuedBooks];
	for (int copy = 0; copy < issuedBooks; copy++)
	{
		issueDate[copy] = F.issueDate[copy];
		Issued[copy] = F.Issued[copy];
	}
	Shared = F.Shared;
}

void Faculty::issueBook(int bID)
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
		if (issuedBooks == 5)
		{
			cout << "Maximum number of books already issued" << endl;
		}
		else
		{
			Faculty Temp(*this);
			issuedBooks++;
			issueDate[issuedBooks] = 60;
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

void Faculty::returnBook(int bID)
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
		cout << "This faculty member doesn't have a book with that ID" << endl;
	}
	else
	{
		if (issueDate[index] <= 0)
		{
			cout << "This book is being returned late, please pay 100 Rs. as fine" << endl;
		}
		Faculty Temp(*this);
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

int Faculty::getIssued()
{
	return issuedBooks;
}

int Faculty::getDate(int index)
{
	return issueDate[index];
}

int Faculty::getID()
{
	return ID;
}

Library& Faculty::getShared()
{
	return *Shared;
}

Book& Faculty::operator[](int find)
{
	return Issued[find];
}

ostream& operator<<(ostream& out, const Faculty& Print)
{
	out << "ID: " << Print.ID << endl;
	out << "Name: " << Print.Name << endl;
	out << "Address: " << Print.Address << endl;
	out << "Phone Number: " << Print.Phone << endl;
	out << "Books Issued: " << Print.issuedBooks << endl;
	return out;
}


Faculty::~Faculty()
{
	delete[] Issued;
	Issued = NULL;
}
