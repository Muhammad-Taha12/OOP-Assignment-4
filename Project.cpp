#include "Manager.cpp"
#include "Project.h"

Project::Project()
{
	Title = "";
	Leader = new Manager;
}

string Project::getTitle()
{
	return Title;
}

void Project::setTitle(string Title)
{
	Project::Title = Title;
}

Manager*& Project::getManager()
{
	return Leader;
}

void Project::setManager(Manager*& Man)
{
	Leader = Man;
}

Project::~Project()
{
	delete[] Leader;
	Leader = NULL;
}
