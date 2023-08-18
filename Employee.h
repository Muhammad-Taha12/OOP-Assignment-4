#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee
{
	string Name;
	Project* Work;
	public:
		Employee();
		void setName(string Name);
		void setProject(string Title);
		void allocateManager(Manager* Man);
		void print();
		~Employee();
};



#endif
