#ifndef INVENTORY_H
#define INVENTORY_H

#include "itemvector.h"

class Inventory {
private:
ItemVector _inventory;

public:
void print(std::ostream& out) const;
int addToInventory(const Item& i);
bool itemInInventory(const Item& i) const;
double inventoryTotal() const;
};

#endif
