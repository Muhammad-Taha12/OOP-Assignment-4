#ifndef CART_H_
#define CART_H_

class Cart
{
	int EggNum;
	int BreadNum;
	int PenNum;
	int SockNum;
	Eggs* Egg;
	Bread* Breads;
	Pens* Pen;
	Sock* Socks;
	public:
		static int total_items;
		Cart();
		Cart(Cart& copy);
		int getTotalItems();
		bool Discount();
		float price();
		void deleteMemory();
		Cart operator+(Eggs& newEgg);
		Cart operator+(Bread& newBread);
		Cart operator+(Pens& newPens);
		Cart operator+(Sock& newSock);
		Cart& operator+=(Eggs& newEgg);
		Cart& operator+=(Bread& newBread);
		Cart& operator+=(Pens& newPens);
		Cart& operator+=(Sock& newSock);
		Cart operator-(Eggs& newEgg);
		Cart operator-(Bread& newBread);
		Cart operator-(Pens& newPens);
		Cart operator-(Sock& newSock);
		Cart& operator-=(Eggs& newEgg);
		Cart& operator-=(Bread& newBread);
		Cart& operator-=(Pens& newPens);
		Cart& operator-=(Sock& newSock);
		operator string();
		friend ostream& operator<<(ostream &out, Cart& Print);
		~Cart();
};

#endif
