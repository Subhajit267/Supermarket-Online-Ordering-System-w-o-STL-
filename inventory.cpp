/*
    A simple supermarket ordering system without STL
    inventory.cpp
    Author: SUBHAJIT HALDER 
       DATE: 13/09/2025
*/
#include "inventory.h"
#include <iomanip>

void Inventory::print(std::ostream& out) const {
    out << "Inventory:" << std::endl;
    if (_inventory.getCount() == 0) {
        out << "ItemVector empty" << std::endl;
    } else {
        _inventory.print(out);
    }
    out << "    Total = $" << std::fixed << std::setprecision(2) 
        << std::setw(8) << inventoryTotal() << std::endl << std::endl;
}

int Inventory::addToInventory(const Item& i) {
    return _inventory.addItem(i);
}

bool Inventory::itemInInventory(const Item& i) const {
    return _inventory.exists(i) != -1;
}

double Inventory::inventoryTotal() const {
    double total = 0.0;
    for (int i = 0; i < _inventory.getCount(); i++) {
        total += _inventory.itemAt(i).total();  
    }
    return total;
}

