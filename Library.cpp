#include "Book.cpp"
#include "Library.h"
#include "Student.cpp"
#include "Faculty.cpp"
#include "Librarian.cpp"

Library::Library()
{
	bookNum = 0;
	List = NULL;
}

Library::Library(Library& copy)
{
	bookNum = copy.bookNum;
	List = new Book[bookNum];
	for (int copyy = 0; copyy < bookNum; copyy++)
	{
		List[copyy] = copy.List[copyy];
	}
}


void Library::AddBook(Book& newBook)
{
	bool Add = true;
	for (int check = 0; check < bookNum; check++)
	{
		if (newBook.getID() == List[check].getID())
		{
			cout << "This Book is already in the Library" << endl;
			Add = false;
		}
	}
	if (Add)
	{
		Library Temp(*this);
		bookNum++;
		List = new Book[bookNum];
		for (int copy = 0; copy < bookNum - 1; copy++)
		{
			List[copy] = Temp.List[copy];
		}
		List[bookNum - 1] = newBook;
	}
}

void Library::RemoveBook(int bID)
{
	for (int remove = 0; remove < bookNum; remove++)
	{
		if (List[remove].getID() == bID)
		{
			List[remove].setAvail(false);
		}
	}
}

void Library::ReAddBook(int bID)
{
	for (int remove = 0; remove < bookNum; remove++)
	{
		if (List[remove].getID() == bID)
		{
			List[remove].setAvail(true);
		}
	}
}


void Library::SearchBook(int bID)
{
	bool found = false;
	for (int search = 0; search < bookNum; search++)
	{
		if (List[search].getID() == bID && !found)
		{
			cout << "Book Found" << endl;
			cout << "ID: " <<  List[search].getID() << endl;
			cout << "Name: " << List[search].getName() << endl;
			cout << "Author: " << List[search].getAuthor() << endl;
			cout << "Type: " <<  List[search].getType() << endl;
			cout << "Edition: " << List[search].getEdition() << endl;
			cout << "Purchase Date: " <<  List[search].getDate() << endl;
			cout << "Is available: ";
			if (List[search].getAvail())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			found = true;
		}
	}
	if (!found)
	{
		cout << "Book not found" << endl;
	}
}

Book& Library::getList(int index)
{
	return List[index];
}

Book& Library::operator[](int find)
{
	return List[find];
}

int Library::getBookNum()
{
	return bookNum;
}

Library::~Library()
{
	delete []List;
	List = NULL;
}

int main()
{
	int choice, book, sorf;
	bool student = false, faculty = false, remove = false;
	char option = 'Y';
	Book B1(1, "Harry Potter", "JK Rowling", "Magazine", 1, "26/6/1997", true);
	Book B2(2, "Thomas Calculus", "Thomas", "Study Book", 2, "2/7/1995", true);
	Book B3(3, "Guiness Book of World Records", "Craig Gendlay", "Magazine", 4, "19/11/2020", true);
	Book B4(4, "Dictionary", "UK", "Study Book", 2, "1/4/1988", true);
	Book B5(5, "Batman", "Bob Kane", "Magazine", 7, "7/4/1915", true);
	Book B6(6, "Romeo and Juliet", "Shakespear", "Journal", 1, "2/7/1959", true);
	Book B7(7, "Hunter X Hunter", "Togashi", "Magazine", 1, "25/10/2011", true);
	Book B8(8, "One Piece", "Oda", "Journal", 2, "1/4/1999", true);
	Book B9(9, "Spell Bound", "F.T Lukens", "Study Book", 5, "12/3/2022", true);
	Book B10(10, "Differential Equations", "John", "Study Book", 9, "4/1/1969", true);
	Book B11(11, "Hamlet", "Shakepear", "Journal", 6, "10/2/1960", true);
	Library Lib;
	Librarian L(Lib);
	Student S1(1, "Taha", "Islamabad", "555", L.getL());
	Student S2(2, "Umair", "Peshawar", "656", L.getL());
	Student S3(3, "Saad", "Lahore", "323", L.getL());
	Faculty F1(4, "Imran Shahzad", "Islamabad", "112", L.getL());
	Faculty F2(5, "Ali Mirza", "Australia", "246", L.getL());
	L.AddStudent(S1);
	L.AddStudent(S2);
	L.AddStudent(S3);
	L.AddFaculty(F1);
	L.AddFaculty(F2);
	L.getL().AddBook(B11);
	L.getS(1).issueBook(11);
	L.getS(1).setDate(0, 0);
	while (option == 'Y' || option == 'y')
	{
		student = false;
		faculty = false;
		remove = false;
		cout << "What do you want to do: " << endl;
		cout << "1 - Add a new Book" << endl;
		cout << "2 - Search for a Book" << endl;
		cout << "3 - Issue a Book" << endl;
		cout << "4 - Look at Issued Books" << endl;
		cout << "5 - Return an Issued Book" << endl;
		cout << "6 - Display all Books currently at the Library" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Enter the ID of the book you want to add: " << endl;
				cout << B1 << endl;
				cout << B2 << endl;
				cout << B3 << endl;
				cout << B4 << endl;
				cout << B5 << endl;
				cout << B6 << endl;
				cout << B7 << endl;
				cout << B8 << endl;
				cout << B9 << endl;
				cout << B10 << endl;
				cin >> book;
				switch (book)
				{
					case 1:
						L.getL().AddBook(B1);
						break;
					case 2:
						L.getL().AddBook(B2);
						break;
					case 3:
						L.getL().AddBook(B3);
						break;
					case 4:
						L.getL().AddBook(B4);
						break;
					case 5:
						L.getL().AddBook(B5);
						break;
					case 6:
						L.getL().AddBook(B6);
						break;
					case 7:
						L.getL().AddBook(B7);
						break;
					case 8:
						L.getL().AddBook(B8);
						break;
					case 9:
						L.getL().AddBook(B9);
						break;
					case 10:
						L.getL().AddBook(B10);
						break;
					default:
						cout << "Invalid Input" << endl;
				}
				break;
			case 2:
				cout << "Enter the ID of the book you want to search: " << endl;
				cin >> book;
				L.getL().SearchBook(book);
				break;
			case 3:
				cout << "Enter the ID of the student or faculty you want to issue a book to: " << endl;
				cout << L;
				cin >> sorf;
				for (int check = 0; check < L.getSNum(); check++)
				{
					if (sorf == L.getS(check).getID())
					{
						sorf = check;
						student = true;
						break;
					}
				}
				if (!student)
				{
					for (int check = 0; check < L.getFNum(); check++)
					{
						if (sorf == L.getF(check).getID())
						{
							sorf = check;
							faculty = true;
							break;
						}
					}
				}
				if (!student && !faculty)
				{
					cout << "ID doesn't match any student or faculty member" << endl;
					break;
				}
				cout << "Enter the ID of the book you want to issue: " << endl;
				if (L.getL().getBookNum() == 0)
				{
					cout << "No Books currently in the Library" << endl;
				}
				for (int out = 0; out < L.getL().getBookNum(); out++)
				{
					cout << L.getL()[out];
					cout << "Is Available: ";
					if (L.getL()[out].getAvail())
					{
						cout << "Yes" << endl << endl;
					}
					else
					{
						cout << "No" << endl << endl;
					}
				}
				cin >> book;
				if (student)
				{
					L.getS(sorf).issueBook(book);
				}
				if (faculty)
				{
					L.getF(sorf).issueBook(book);
				}
				break;
			case 4:
				cout << "Enter the ID of the student or faculty you want check issued books of: " << endl;
				cout << L;
				cin >> sorf;
				for (int check = 0; check < L.getSNum(); check++)
				{
					if (sorf == L.getS(check).getID())
					{
						sorf = check;
						student = true;
						break;
					}
				}
				if (!student)
				{
					for (int check = 0; check < L.getFNum(); check++)
					{
						if (sorf == L.getF(check).getID())
						{
							sorf = check;
							faculty = true;
							break;
						}
					}
				}
				if (!student && !faculty)
				{
					cout << "ID doesn't match any student or faculty member" << endl;
					break;
				}
				if (student)
				{
					if (L.getS(sorf).getIssued() == 0)
					{
						cout << "No Books currently issued to this student" << endl;
					}
					for (int out = 0; out < L.getS(sorf).getIssued(); out++)
					{
						if (L.getS(sorf).getDate(out) > 0)
						{
							cout << "The due date is " << L.getS(sorf).getDate(out) << " days from Today" << endl << endl;
						}
						else
						{
							cout << "This book has passed its due date" << endl << endl;
						}
					}
				}
				if (faculty)
				{
					if (L.getF(sorf).getIssued() == 0)
					{
						cout << "No Books currently issued to this faculty member" << endl;
					}
					for (int out = 0; out < L.getF(sorf).getIssued(); out++)
					{
						if (L.getF(sorf).getDate(out) > 0)
						{
							cout << "The due date is " << L.getF(sorf).getDate(out) << " days from Today" << endl << endl;
						}
						else
						{
							cout << "This book has passed its due date" << endl << endl;
						}
					}
				}
				break;
			case 5:
				cout << "Enter the ID of the student or faculty you want check issued books of: " << endl;
				cout << L;
				cin >> sorf;
				for (int check = 0; check < L.getSNum(); check++)
				{
					if (sorf == L.getS(check).getID())
					{
						sorf = check;
						student = true;
						break;
					}
				}
				if (!student)
				{
					for (int check = 0; check < L.getFNum(); check++)
					{
						if (sorf == L.getF(check).getID())
						{
							sorf = check;
							faculty = true;
							break;
						}
					}
				}
				if (!student && !faculty)
				{
					cout << "ID doesn't match any student or faculty member" << endl;
					break;
				}
				if (student)
				{
					if (L.getS(sorf).getIssued() == 0)
					{
						cout << "No Books currently issued to this student" << endl;
					}
					for (int out = 0; out < L.getS(sorf).getIssued(); out++)
					{
						cout << L.getS(sorf)[out];
						if (L.getS(sorf).getDate(out) > 0)
						{
							cout << "The due date is " << L.getS(sorf).getDate(out) << " days from Today" << endl;
						}
						else
						{
							cout << "This book has passed its due date" << endl;
						}
					}
					cout << "Enter ID of Book you want to return: ";
					cin >> book;
					for (int out = 0; out < L.getS(sorf).getIssued(); out++)
					{
						if (L.getS(sorf)[out].getID() == book)
						{
							L.getS(sorf).returnBook(book);
							remove = true;
						}
					}
					if (!remove)
					{
						cout << "This student doesn't have a book with this ID" << endl << endl;
					}
				}
				if (faculty)
				{
					if (L.getF(sorf).getIssued() == 0)
					{
						cout << "No Books currently issued to this faculty member" << endl;
					}
					for (int out = 0; out < L.getF(sorf).getIssued(); out++)
					{
						cout << L.getF(sorf)[out];
						if (L.getF(sorf).getDate(out) > 0)
						{
							cout << "The due date is " << L.getF(sorf).getDate(out) << " days from Today" << endl;
						}
						else
						{
							cout << "This book has passed its due date" << endl;
						}
					}
					cout << "Enter ID of Book you want to return";
					cin >> book;
					for (int out = 0; out < L.getF(sorf).getIssued(); out++)
					{
						if (L.getF(sorf)[out].getID() == book)
						{
							L.getF(sorf).returnBook(book);
							remove = true;
						}
					}
					if (!remove)
					{
						cout << "This faculty member doesn't have a book with this ID" << endl << endl;
					}
				}
				break;
			case 6:
				if (L.getL().getBookNum() == 0)
				{
					cout << "No Books currently in the Library" << endl;
				}
				for (int out = 0; out < L.getL().getBookNum(); out++)
				{
					cout << L.getL()[out];
					cout << "Is Available: ";
					if (L.getL()[out].getAvail())
					{
						cout << "Yes" << endl << endl;
					}
					else
					{
						cout << "No" << endl << endl;
					}
				}
				break;
			default:
				cout << "Invalid Input" << endl;
		}
		cout << "Press 'Y' or 'y' to continue: ";
		cin >> option;
	}
}
