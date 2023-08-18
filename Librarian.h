#ifndef SRC_LIBRARIAN_H_
#define SRC_LIBRARIAN_H_

class Librarian : public Library
{
	int SNum;
	int FNum;
	Student* SList;
	Faculty* FList;
	Library* Same;
	public:
		Librarian();
		Librarian(Library& Add);
		Librarian(Librarian& copy);
		void AddStudent(Student& newS);
		void AddFaculty(Faculty& newF);
		int getSNum();
		int getFNum();
		Student& getS(int index);
		Faculty& getF(int index);
		Library& getL();
		friend ostream& operator<<(ostream& out, Librarian& Print);
		~Librarian();
};

#endif
