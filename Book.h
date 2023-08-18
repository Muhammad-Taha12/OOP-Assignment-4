#ifndef BOOK_H_
#define BOOK_H_

class Book
{
	int ID;
	string name;
	string author;
	string type;
	int edition;
	string date;
	bool available;
	public:
		Book(int bID, string bname, string bauthor, string btype, int bedition, string bdate, bool bavailable);
		Book(Book& copy);
		int getID();
		string getName();
		string getAuthor();
		string getType();
		int getEdition();
		string getDate();
		bool getAvail();
		void setAvail(bool ava);
		friend ostream& operator<<(ostream& out, const Book print);
};




#endif
