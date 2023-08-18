#include <iostream>
using namespace std;
#include "Book.h"

Book::Book(int bID = 0, string bname = "", string bauthor = "", string btype = "", int bedition = 0, string bdate = "", bool bavailable = false)
{
	ID = bID;
	name = bname;
	author = bauthor;
	type = btype;
	edition = bedition;
	date = bdate;
	available = bavailable;
}

Book::Book(Book& copy)
{
	ID = copy.ID;
	name = copy.name;
	author = copy.author;
	type = copy.type;
	edition = copy.edition;
	date = copy.date;
	available = copy.available;
}

int Book::getID()
{
	return ID;
}

string Book::getName()
{
	return name;
}

string Book::getAuthor()
{
	return author;
}

string Book::getType()
{
	return type;
}

int Book::getEdition()
{
	return edition;
}

string Book::getDate()
{
	return date;
}

bool Book::getAvail()
{
	return available;
}

void Book::setAvail(bool ava)
{
	available = ava;
}

ostream& operator<<(ostream& out, const Book print)
{
	out << "ID: " << print.ID << endl;
	out << "Name: " << print.name << endl;
	out << "Author: " << print.author << endl;
	out << "Type: " << print.type << endl;
	out << "Edition: " << print.edition << endl;
	out << "Purchase Date: " << print.date << endl;
	return out;
}
