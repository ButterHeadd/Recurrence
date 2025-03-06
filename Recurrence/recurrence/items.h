#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Item {
public:
	Item(const string& name, const string& type, const string& description, int quantity = 0);
	string name;
	string type;
	string description;
	int quantity;

	void printItemDetails() const;
	void printItem() const;
};

class Inventory {
private:
	unordered_map<string, Item> items;

public:
	void initialiseItems();
	void addItem(const string& itemName, int quantity);
	void getItem(const string& itemName);
	void printInventory();
};

#endif
