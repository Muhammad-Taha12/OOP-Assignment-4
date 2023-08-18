#ifndef LIBRARY_H_
#define LIBRARY_H_

class Library
{
	int bookNum;
	Book* List;
	public:
		Library();
		Library(Library& copy);
		void AddBook(Book& newBook);
		void RemoveBook(int bID);
		void ReAddBook(int bID);
		void SearchBook(int bID);
		Book& getList(int index);
		Book& operator[](int find);
		int getBookNum();
		~Library();
};



#endif
