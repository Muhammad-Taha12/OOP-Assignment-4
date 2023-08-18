#ifndef BREAD_H_
#define BREAD_H_

class Bread : public Item
{
	int Units;
	bool Sale;
	bool Gift;
	public:
		Bread(int units, float price, bool sale, bool gift);
		Bread(Bread& copy);
		float price();
		bool sale();
		bool gift();
		int getUnits();
		bool operator==(Bread& Compare);
		friend ostream& operator<<(ostream &out, const Bread& Print);
};



#endif
