#include "Eggs.h"

Eggs::Eggs(int units = 0, float price = 0, bool sale = false, bool gift = false)
{
	Units = units;
	setPrice(price);
	Sale = sale;
	Gift = gift;
	setName("Eggs");
	setType("Food");
}

Eggs::Eggs(Eggs& copy)
{
	Units = copy.Units;
	Sale = copy.Sale;
	Gift = copy.Gift;
	setPrice(copy.getPrice());
	setName(copy.getName());
	setType(copy.getType());
}

float Eggs::price()
{
	if (Sale)
	{
		float newPrice = getPrice() * 25/100;
		newPrice = getPrice()- newPrice;
		return Units * newPrice;
	}
	return Units * getPrice();
}

bool Eggs::sale()
{
	return Sale;
}

bool Eggs::gift()
{
	return Gift;
}

int Eggs::getUnits()
{
	return Units;
}

bool Eggs::operator==(Eggs& Compare)
{
	if (getName() == Compare.getName() && getPrice() == Compare.getPrice() && getType() == Compare.getType())
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream &out, Eggs& Print)
{
	out << Print.getName() << " " << Print.getPrice() << " " << Print.getUnits() << " " << Print.sale() << " " << Print.gift() << ", Price: " << Print.price() << " Rs." << endl;
	return out;
}
