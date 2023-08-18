#include "Project.cpp"
#include "Employee.h"

Employee::Employee()
{
	Name = "";
	Work = new Project;
}

void Employee::setName(string Name)
{
	Employee::Name = Name;
}

void Employee::setProject(string Title)
{
	Work->setTitle(Title);
}

void Employee::allocateManager(Manager* Man)
{
	Work->setManager(Man);
}

void Employee::print()
{
	cout << "__________________________________________" << endl;
	cout << "Employee Name: " << Name << endl;
	if (Work->getTitle() == "")
	{
		cout << "Not currently working on a project" << endl;
	}
	else if (Work->getManager()->getManager() == "")
	{
		cout << "Working on the Project: " << Work->getTitle() << endl;
		cout << "Not currently supervised by a Manager" << endl;
	}
	else
	{
		cout << "Working on the Project: " << Work->getTitle() << endl;
		cout << "Working under the Manager: " << Work->getManager()->getManager() << endl;
	}
}


Employee::~Employee()
{
	Work = NULL;
}

int main()
{
	Manager Man1("tyuio");
	Manager Man2("Dwight");
	Manager Man3("Jim");
	Manager Man4("Andy");
	Employee Workers[15];
	Workers[0].setName("Ryan");
	Workers[1].setName("Robert");
	Workers[2].setName("Stanley");
	Workers[3].setName("Pam");
	Workers[4].setName("Kevin");
	Workers[5].setName("Meredith");
	Workers[6].setName("Angela");
	Workers[7].setName("Oscar");
	Workers[8].setName("Roy");
	Workers[9].setName("Jan");
	Workers[10].setName("Toby");
	Workers[11].setName("Kelly");
	Workers[12].setName("Creed");
	Workers[13].setName("Darryl");
	Workers[14].setName("Erin");
	Workers[0].setProject("Pilot");
	Workers[0].allocateManager(&Man1);
	Workers[1].setProject("Health Care");
	Workers[1].allocateManager(&Man1);
	Workers[2].setProject("Basketball");
	Workers[2].allocateManager(&Man2);
	Workers[6].setProject("Drug Testing");
	Workers[6].allocateManager(&Man2);
	Workers[3].setProject("Initiation");
	Workers[3].allocateManager(&Man3);
	Workers[4].setProject("Safety Training");
	Workers[4].allocateManager(&Man3);
	Workers[5].setProject("Product Recall");
	Workers[5].allocateManager(&Man3);
	Workers[7].setProject("Launch Party");
	Workers[7].allocateManager(&Man3);
	Workers[8].setProject("Local Ad");
	Workers[8].allocateManager(&Man3);
	Workers[9].setProject("Tetris");
	Workers[12].setProject("Security");
	Workers[13].setProject("Customer Survey");
	Workers[13].allocateManager(&Man4);
	Workers[14].setProject("Stress Relief");
	Workers[14].allocateManager(&Man4);
	for (int print = 0; print < 15; print++)
	{
		Workers[print].print();
	}
}
