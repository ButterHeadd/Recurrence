#include "items.h"

Item::Item(const string& name, const string& type, const string& description, int quantity = 0) : name(name), type(type), description(description), quantity(quantity) {}

void Item::printItemDetails() const {
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Description: " << description << endl;
	cout << "Quantity: " << quantity << endl;
}

void Item::printItem() const {
	cout << "Name: " << name << endl;
	cout << "Quantity: " << quantity << endl;
}

void Inventory::initialiseItems() {
	items["Gold"] = Item("Gold", "Currency", "A shiny piece of gold.");
	items["Rotten Flesh"] = Item("Rotten Flesh", "Material", "A rotting piece of meat.");
}

void Inventory::addItem(const string& itemName, int quantity) {
	if(items.find(itemName))
}