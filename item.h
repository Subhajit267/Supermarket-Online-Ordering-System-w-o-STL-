#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
private:
    int _id;
    char _name[50];
    double _rPrice;
    int _quantity;

public:
    Item();
    Item(int id, const char* name, double rPrice, int quantity);
    
    void print(std::ostream& out) const;
    double total() const;
    int setQuantity(int q);
    int getQuantity() const;
    void setRPrice(double r);
    void setData(int id, const char* name);
    bool compare(const Item& item) const;
};

#endif
