#include <iostream>
#include <cstring>
using namespace std;
#include "Item.h"
#include "Eggs.cpp"
#include "Bread.cpp"
#include "Pens.cpp"
#include "Sock.cpp"

Item::Item()
{
	Name = "";
	Type = "";
	Price = 0;
}

Item::Item(Item& copy)
{
	Name = copy.Name;
	Price = copy.Price;
	Type = copy.Type;
}

void Item::setName(string name)
{
	Name = name;
}

void Item::setType(string type)
{
	Type = type;
}

void Item::setPrice(float price)
{
	Price = price;
}

string Item::getName()
{
	return Name;
}

string Item::getType()
{
	return Type;
}

float Item::getPrice()
{
	return Price;
}

Item::~Item()
{
	Name = "";
	Type = "";
	Price = 0;
}
