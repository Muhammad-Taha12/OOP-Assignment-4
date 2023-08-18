#include "Item.cpp"
#include "Cart.h"

int Cart::total_items = 0;

Cart::Cart()
{
	EggNum = 0;
	BreadNum = 0;
	PenNum = 0;
	SockNum = 0;
	Egg = NULL;
	Breads = NULL;
	Pen = NULL;
	Socks = NULL;
}


Cart::Cart(Cart& copy)
{
	EggNum = copy.EggNum;
	BreadNum = copy.BreadNum;
	PenNum = copy.PenNum;
	SockNum = copy.SockNum;
	total_items += EggNum;
	total_items += BreadNum;
	total_items += PenNum;
	total_items += SockNum;
	Egg = new Eggs[EggNum];
	Breads = new Bread[BreadNum];
	Pen = new Pens[PenNum];
	Socks = new Sock[SockNum];
	for (int item = 0; item < EggNum; item++)
	{
		Egg[item] = copy.Egg[item];
	}
	for (int item = 0; item < BreadNum; item++)
	{
		Breads[item] = copy.Breads[item];
	}
	for (int item = 0; item < PenNum; item++)
	{
		Pen[item] = copy.Pen[item];
	}
	for (int item = 0; item < SockNum; item++)
	{
		Socks[item] = copy.Socks[item];
	}
}

int Cart::getTotalItems()
{
	int total = 0;
	for (int item = 0; item < EggNum; item++)
	{
		total += Egg[item].getUnits();
	}
	for (int item = 0; item < BreadNum; item++)
	{
		total += Breads[item].getUnits();
	}
	for (int item = 0; item < PenNum; item++)
	{
		total += Pen[item].getUnits();
	}
	for (int item = 0; item < SockNum; item++)
	{
		total += Socks[item].getUnits();
	}
	return total;
}

void Cart::deleteMemory()
{
	delete []Egg;
	delete []Breads;
	delete []Pen;
	delete []Socks;
}

bool Cart::Discount()
{
	int sales = 0;
	for (int item = 0; item < EggNum; item++)
	{
		if (Egg[item].sale())
		{
			sales++;
		}
	}
	for (int item = 0; item < BreadNum; item++)
	{
		if (Breads[item].sale())
		{
			sales++;
		}
	}
	for (int item = 0; item < PenNum; item++)
	{
		if (Pen[item].sale())
		{
			sales++;
		}
	}
	for (int item = 0; item < SockNum; item++)
	{
		if (Socks[item].sale())
		{
			sales++;
		}
	}
	if (sales >= 3)
	{
		return true;
	}
	return false;
}

float Cart::price()
{
	float total = 0;
	for (int item = 0; item < EggNum; item++)
	{
		total += Egg[item].price();
	}
	for (int item = 0; item < BreadNum; item++)
	{
		total += Breads[item].price();
	}
	for (int item = 0; item < PenNum; item++)
	{
		total += Pen[item].price();
	}
	for (int item = 0; item < SockNum; item++)
	{
		total += Socks[item].price();
	}
	if (Discount())
	{
		float reduce = total * 12.5/100;
		total -= reduce;
	}
	return total;
}

Cart Cart::operator+(Eggs& newEgg)
{
	Cart Temp(*this);
	Temp += newEgg;
	return Temp;
}

Cart Cart::operator+(Bread& newBread)
{
	Cart Temp(*this);
	Temp += newBread;
	return Temp;
}

Cart Cart::operator+(Pens& newPen)
{
	Cart Temp(*this);
	Temp += newPen;
	return Temp;
}

Cart Cart::operator+(Sock& newSock)
{
	Cart Temp(*this);
	Temp += newSock;
	return Temp;
}

Cart& Cart::operator+=(Eggs& newEgg)
{
	total_items += 2;
	Cart Temp(*this);
	EggNum = EggNum + 1;
	delete[] Egg;
	Egg = new Eggs[EggNum];
	for (int copy = 0; copy < EggNum - 1; copy++)
	{
		Egg[copy] = Temp.Egg[copy];
	}
	Egg[EggNum - 1] = newEgg;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	return *this;
}

Cart& Cart::operator+=(Bread& newBread)
{
	total_items += 2;
	Cart Temp(*this);
	BreadNum = BreadNum + 1;
	delete[] Breads;
	Breads = new Bread[BreadNum];
	for (int copy = 0; copy < BreadNum - 1; copy++)
	{
		Breads[copy] = Temp.Breads[copy];
	}
	Breads[BreadNum - 1] = newBread;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	return *this;
}

Cart& Cart::operator+=(Pens& newPens)
{
	total_items += 2;
	Cart Temp(*this);
	PenNum = PenNum + 1;
	delete []Pen;
	Pen = new Pens[PenNum];
	for (int copy = 0; copy < PenNum - 1; copy++)
	{
		Pen[copy] = Temp.Pen[copy];
	}
	Pen[PenNum - 1] = newPens;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	return *this;
}

Cart& Cart::operator+=(Sock& newSock)
{
	total_items += 2;
	Cart Temp(*this);
	SockNum = SockNum + 1;
	delete []Socks;
	Socks = new Sock[SockNum];
	for (int copy = 0; copy < SockNum - 1; copy++)
	{
		Socks[copy] = Temp.Socks[copy];
	}
	Socks[SockNum - 1] = newSock;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	return *this;
}

Cart Cart::operator-(Eggs& newEgg)
{
	Cart Temp(*this);
	Temp -= newEgg;
	return Temp;
}

Cart Cart::operator-(Bread& newBread)
{
	Cart Temp(*this);
	Temp -= newBread;
	return Temp;
}

Cart Cart::operator-(Pens& newPens)
{
	Cart Temp(*this);
	Temp -= newPens;
	return Temp;
}

Cart Cart::operator-(Sock& newSock)
{
	Cart Temp(*this);
	Temp -= newSock;
	return Temp;
}

Cart& Cart::operator-=(Eggs& newEgg)
{
	total_items -= EggNum;
	Cart Temp(*this);
	EggNum = 0;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	Temp.Egg = NULL;
	return *this;
}

Cart& Cart::operator-=(Bread& newBread)
{
	total_items -= BreadNum;
	Cart Temp(*this);
	BreadNum = 0;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	Temp.Breads = NULL;
	return *this;
}

Cart& Cart::operator-=(Pens& newPens)
{
	total_items -= PenNum;
	Cart Temp(*this);
	PenNum = 0;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	Temp.Pen = NULL;
	return *this;
}

Cart& Cart::operator-=(Sock& newSock)
{
	total_items -= SockNum;
	Cart Temp(*this);
	SockNum = 0;
	delete []Temp.Egg;
	delete []Temp.Breads;
	delete []Temp.Pen;
	delete []Temp.Socks;
	Temp.Socks = NULL;
	return *this;
}

Cart::operator string()
{
	string out;
	if (total_items == 0)
	{
		out += "Still no item in the cart\n";
	}
	else
	{
		for (int item = 0; item < EggNum; item++)
		{
			out += "Egg\n";
		}
		for (int item = 0; item < BreadNum; item++)
		{
			out += "Bread\n";
		}
		for (int item = 0; item < PenNum; item++)
		{
			out += "Pen\n";
		}
		for (int item = 0; item < SockNum; item++)
		{
			out += "Socks\n";
		}
		out += "Total Price: ";
		out += price();
		out += " Rs.\n";
	}
	return out;
}

ostream& operator<<(ostream &out, Cart& Print)
{
	if (Print.total_items == 0)
	{
		out << "Still no item in the cart" << endl;
	}
	else
	{
		out << "Cart Contains" << endl;
		for (int item = 0; item < Print.EggNum; item++)
		{
			out << Print.Egg[item];
		}
		for (int item = 0; item < Print.BreadNum; item++)
		{
			out << Print.Breads[item];
		}
		for (int item = 0; item < Print.PenNum; item++)
		{
			out << Print.Pen[item];
		}
		for (int item = 0; item < Print.SockNum; item++)
		{
			out << Print.Socks[item];
		}
		out << "Cart is discounted: ";
		if (Print.Discount())
		{
			out << "Yes" << endl;
		}
		else
		{
			out << "No" << endl;
		}
		out << "Total Price: " << Print.price() << " Rs." << endl;
	}
	return out;
}

Cart::~Cart()
{
	total_items -= EggNum;
	total_items -= BreadNum;
	total_items -= PenNum;
	total_items -= SockNum;
}

int main()
{
	// example of non sale item.
	Bread p1(12, 3);
	cout << p1 << endl;
	// example of sale item
	Eggs p2(15, 1, true);
	// example of sale item with gift card
	Sock p3(20, 2.0, true, true);
	Cart c1;
	c1 += p1; //add bread to cart
	c1 += p1;
	c1 += p2; //add eggs to cart
	c1 += p3; //add socks to cart
	cout << c1 << endl;
	c1 -= p1;//= c1 - p1; // Delete all the unit of type bread
	cout << c1 << endl;
	Cart c2;
	c2 = c1 + p2; // Add item of type eggs
	cout << c2 << endl;
	// Delete all the units of eggs type food from the cart.
	c2 -= p2;
	cout << c2;
	cout << Cart :: total_items << endl; //displays number of all items in all carts.










	c1.deleteMemory();
	c2.deleteMemory();
	return 0;
}
