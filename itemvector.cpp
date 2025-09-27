#include "itemvector.h"
#include <iostream>

ItemVector::ItemVector() : _max(10), _count(0) {
    _items = new Item[_max];
}

ItemVector::~ItemVector() {
    delete[] _items;
}

ItemVector::ItemVector(const ItemVector& other) : _max(other._max), _count(other._count) {
    _items = new Item[_max];
    for (int i = 0; i < _count; i++) {
        _items[i] = other._items[i];
    }
}

ItemVector& ItemVector::operator=(const ItemVector& other) {
    if (this != &other) {
        delete[] _items;
        
        _max = other._max;
        _count = other._count;
        _items = new Item[_max];
        
        for (int i = 0; i < _count; i++) {
            _items[i] = other._items[i];
        }
    }
    return *this;
}

int ItemVector::_expand(int increment) {
    _max += increment;
    Item* newItems = new Item[_max];
    
    for (int i = 0; i < _count; i++) {
        newItems[i] = _items[i];
    }
    
    delete[] _items;
    _items = newItems;
    return _max;
}

void ItemVector::print(std::ostream& out) const {
    if (_count == 0) {
        out << "ItemVector empty" << std::endl;
        return;
    }
    
    for (int i = 0; i < _count; i++) {
        _items[i].print(out);
    }
}

int ItemVector::addItem(const Item& i) {
    int existingIndex = exists(i);
    if (existingIndex != -1) {
        Item& existingItem = _items[existingIndex];
        int newQuantity = existingItem.getQuantity() + i.getQuantity();
        existingItem.setQuantity(newQuantity);
        return existingIndex;
    }
    
    if (_count >= _max) {
        _expand(5);
    }
    
    _items[_count] = i;
    return _count++;
}

int ItemVector::exists(const Item& i) const {
    for (int index = 0; index < _count; index++) {
        if (_items[index].compare(i)) {
            return index;
        }
    }
    return -1;
}

int ItemVector::getCount() const {
    return _count;
}

Item& ItemVector::itemAt(int loc) {
    if (loc < 0 || loc >= _count) {
        return _items[0];
    }
    return _items[loc];
}

const Item& ItemVector::itemAt(int loc) const {
    if (loc < 0 || loc >= _count) {
        return _items[0];
    }
    return _items[loc];
}
