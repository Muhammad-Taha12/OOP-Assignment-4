#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

class Student
{
	int ID;
	string Name;
	string Address;
	string Phone;
	int issuedBooks;
	int issueDate[3];
	Book* Issued;
	Library* Shared;
	public:
		Student();
		Student(int sID, string sName, string sAddress, string sPhone, Library& L);
		Student(Student& S);
		void issueBook(int bID);
		void returnBook(int bID);
		int getIssued();
		int getDate(int index);
		void setDate(int index, int date);
		int getID();
		Library& getShared();
		Book& operator[](int find);
		friend ostream& operator<<(ostream& out, const Student& Print);
		~Student();
};

#endif
