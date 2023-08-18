#ifndef ITEM_H_
#define ITEM_H_

class Item
{
	string Name;
	string Type;
	float Price;
	public:
		Item();
		Item(Item& copy);
		void setName(string name);
		void setType(string type);
		void setPrice(float price);
		string getName();
		string getType();
		float getPrice();
		~Item();
};



#endif
