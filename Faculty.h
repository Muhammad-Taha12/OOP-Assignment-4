#ifndef SRC_FACULTY_H_
#define SRC_FACULTY_H_

class Faculty
{
	int ID;
	string Name;
	string Address;
	string Phone;
	int issuedBooks;
	int issueDate[5];
	Book* Issued;
	Library* Shared;
	public:
		Faculty();
		Faculty(int fID, string fName, string fAddress, string fPhone, Library &L);
		Faculty(Faculty& S);
		void issueBook(int bID);
		void returnBook(int bID);
		int getIssued();
		int getDate(int index);
		int getID();
		Library& getShared();
		Book& operator[](int find);
		friend ostream& operator<<(ostream& out, const Faculty& Print);
		~Faculty();
};



#endif
