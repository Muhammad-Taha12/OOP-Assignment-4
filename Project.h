#ifndef PROJECT_H_
#define PROJECT_H_

class Project
{
	string Title;
	Manager* Leader;
	public:
		Project();
		string getTitle();
		void setTitle(string Title);
		Manager*& getManager();
		void setManager(Manager*& Man);
		~Project();
};

#endif
