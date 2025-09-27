#include "item.h"
#include <iomanip>
#include <cstring>  

Item::Item() : _id(0), _rPrice(0.0), _quantity(0) {
    strcpy(_name, "none");
}

Item::Item(int id, const char* name, double rPrice, int quantity) 
    : _id(id), _rPrice(rPrice), _quantity(quantity) {
    strncpy(_name, name, 49);
    _name[49] = '\0';
}

void Item::print(std::ostream& out) const {
    out << std::setw(5) << std::setfill('0') << _id << std::setfill(' ') 
        << "    " << std::left << std::setw(8) << _name 
        << std::right << std::setw(3) << _quantity << " @ $"
        << std::fixed << std::setprecision(2) << std::setw(6) << _rPrice
        << " = $" << std::setw(8) << total() << std::endl;
}

double Item::total() const {
    return _quantity * _rPrice;
}

int Item::setQuantity(int q) {
    _quantity = q;
    return _quantity;
}

int Item::getQuantity() const {
    return _quantity;
}

void Item::setRPrice(double r) {
    _rPrice = r;
}

void Item::setData(int id, const char* name) {
    _id = id;
    strncpy(_name, name, 49);
    _name[49] = '\0';  
}

bool Item::compare(const Item& item) const {
    return (_id == item._id && 
            strcmp(_name, item._name) == 0 && 
            _rPrice == item._rPrice);
}
