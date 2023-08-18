#ifndef SOCK_H_
#define SOCK_H_

class Sock : public Item
{
	int Units;
	bool Sale;
	bool Gift;
	public:
		Sock(int units, float price, bool sale, bool gift);
		Sock(Sock& copy);
		float price();
		bool sale();
		bool gift();
		int getUnits();
		bool operator==(Sock& Compare);
		friend ostream& operator<<(ostream &out, const Sock& Print);
};



#endif
