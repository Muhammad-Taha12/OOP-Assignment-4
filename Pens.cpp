#include "Pens.h"

Pens::Pens(int units = 0, float price = 0, bool sale = false, bool gift = false)
{
	Units = units;
	setPrice(price);
	Sale = sale;
	Gift = gift;
	setName("Pens");
	setType("Supplies");
}

Pens::Pens(Pens& copy)
{
	Units = copy.Units;
	Sale = copy.Sale;
	Gift = copy.Gift;
	setPrice(copy.getPrice());
	setName(copy.getName());
	setType(copy.getType());
}

float Pens::price()
{
	if (Sale)
	{
		float newPrice = getPrice()* 25/100;
		newPrice = getPrice() - newPrice;
		return Units * newPrice;
	}
	return Units * getPrice() ;
}

bool Pens::sale()
{
	return Sale;
}

bool Pens::gift()
{
	return Gift;
}

int Pens::getUnits()
{
	return Units;
}

bool Pens::operator==(Pens& Compare)
{
	if (getName() == Compare.getName() && getPrice() == Compare.getPrice() && getType() == Compare.getType())
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream &out, Pens& Print)
{
	out << Print.getName() << " " << Print.getPrice() << " " << Print.getUnits() << " " << Print.sale() << " " << Print.gift() << ", Price: " << Print.price() << " Rs." << endl;
	return out;
}
