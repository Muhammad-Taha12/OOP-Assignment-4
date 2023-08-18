#include <iostream>
using namespace std;
#include "Manager.h"

Manager::Manager(string Man = "")
{
	Name = Man;
}

string Manager::getManager()
{
	return Name;
}

Manager::~Manager()
{
	Name = "";
}
