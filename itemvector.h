#ifndef ITEMVECTOR_H
#define ITEMVECTOR_H

#include "item.h"

class ItemVector {
private:
    int _max;
    int _count;
    Item* _items;
    
    int _expand(int increment);

public:
    ItemVector();
    ~ItemVector();
    ItemVector(const ItemVector& other);
    ItemVector& operator=(const ItemVector& other);
    
    void print(std::ostream& out) const;
    int addItem(const Item& i);
    int exists(const Item& i) const;
    int getCount() const;
    Item& itemAt(int loc);
    const Item& itemAt(int loc) const;  // Added const version
};

#endif
