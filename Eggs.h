#ifndef EGGS_H_
#define EGGS_H_

class Eggs : public Item
{
	int Units;
	bool Sale;
	bool Gift;
	public:
		Eggs(int units, float price, bool sale, bool gift);
		Eggs(Eggs& copy);
		float price();
		bool sale();
		bool gift();
		int getUnits();
		bool operator==(Eggs& Compare);
		friend ostream& operator<<(ostream &out, const Eggs& Print);
};



#endif
