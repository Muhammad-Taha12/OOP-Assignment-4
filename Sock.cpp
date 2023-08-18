#include "Sock.h"

Sock::Sock(int units = 0, float price = 0, bool sale = false, bool gift = false)
{
	Units = units;
	setPrice(price);
	Sale = sale;
	Gift = gift;
	setName("Sock");
	setType("Clothes");
}

Sock::Sock(Sock& copy)
{
	Units = copy.Units;
	Sale = copy.Sale;
	Gift = copy.Gift;
	setPrice(copy.getPrice());
	setName(copy.getName());
	setType(copy.getType());
}

float Sock::price()
{
	if (Sale)
	{
		float newPrice = getPrice()* 25/100;
		newPrice = getPrice() - newPrice;
		return Units * newPrice;
	}
	return Units * getPrice() ;
}

bool Sock::sale()
{
	return Sale;
}

bool Sock::gift()
{
	return Gift;
}

int Sock::getUnits()
{
	return Units;
}

bool Sock::operator==(Sock& Compare)
{
	if (getName() == Compare.getName() && getPrice() == Compare.getPrice() && getType() == Compare.getType())
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream &out, Sock& Print)
{
	out << Print.getName() << " " << Print.getPrice() << " " << Print.getUnits() << " " << Print.sale() << " " << Print.gift() << ", Price: " << Print.price() << " Rs." << endl;
	return out;
}
