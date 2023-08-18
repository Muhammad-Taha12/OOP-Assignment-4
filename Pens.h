#ifndef PENS_H_
#define PENS_H_

class Pens : public Item
{
	int Units;
	bool Sale;
	bool Gift;
	public:
		Pens(int units, float price, bool sale, bool gift);
		Pens(Pens& copy);
		float price();
		bool sale();
		bool gift();
		int getUnits();
		bool operator==(Pens& Compare);
		friend ostream& operator<<(ostream &out, const Pens& Print);
};



#endif
