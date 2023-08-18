#include "Librarian.h"

Librarian::Librarian()
{
	SNum = 0;
	FNum = 0;
	SList = NULL;
	FList = NULL;
	Same = NULL;
}

Librarian::Librarian(Library& Add)
{
	SNum = 0;
	FNum = 0;
	SList = NULL;
	FList = NULL;
	Same = &Add;
}

Librarian::Librarian(Librarian& copy)
{
	SNum = copy.SNum;
	FNum = copy.FNum;
	SList = new Student[SNum];
	for (int sCopy = 0; sCopy < SNum; sCopy++)
	{
		SList[sCopy] = copy.SList[sCopy];
	}
	FList = new Faculty[FNum];
	for (int fCopy = 0; fCopy < FNum; fCopy++)
	{
		FList[fCopy] = copy.FList[fCopy];
	}
	Same = copy.Same;
}

void Librarian::AddStudent(Student& newS)
{
	Librarian Temp(*this);
	SNum++;
	SList = new Student[SNum];
	for (int sCopy = 0; sCopy < SNum - 1; sCopy++)
	{
		SList[sCopy] = Temp.SList[sCopy];
	}
	SList[SNum - 1] = newS;
}

void Librarian::AddFaculty(Faculty& newF)
{
	Librarian Temp(*this);
	FNum++;
	FList = new Faculty[FNum];
	for (int fCopy = 0; fCopy < FNum - 1; fCopy++)
	{
		FList[fCopy] = Temp.FList[fCopy];
	}
	FList[FNum - 1] = newF;
}

int Librarian::getSNum()
{
	return SNum;
}

int Librarian::getFNum()
{
	return FNum;
}

Student& Librarian::getS(int index)
{
	return SList[index];
}

Faculty& Librarian::getF(int index)
{
	return FList[index];
}

Library& Librarian::getL()
{
	return *Same;
}

ostream& operator<<(ostream& out, Librarian& Print)
{
	for (int s = 0; s < Print.getSNum(); s++)
	{
		out << "Student: " << endl;
		out << Print.getS(s) << endl;
	}
	for (int f = 0; f < Print.getFNum(); f++)
	{
		out << "Faculty: " << endl;
		out << Print.getF(f) << endl;
	}
	return out;
}

Librarian::~Librarian()
{
	delete[] SList;
	SList = NULL;
	delete[] FList;
	FList = NULL;
}
