# Supermarket Online Ordering System



**A comprehensive C++ implementation of a supermarket inventory management system with dynamic item storage and value calculation**

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Class Architecture](#-class-architecture)
- [Installation](#-installation)
- [Usage](#-usage)
- [Code Structure](#-code-structure)
- [Sample Output](#-sample-output)
- [Technical Details](#-technical-details)

## 🚀 Overview

The **Supermarket Online Ordering System** is a C++ application designed to manage supermarket inventory efficiently. It implements a three-tier class hierarchy to handle individual items, collections of items, and complete inventory management with automatic quantity merging and total value calculation.

## ✨ Features

### 🏪 Inventory Management
- **Dynamic Item Storage**: Automatic array expansion when capacity is reached
- **Quantity Merging**: Duplicate items automatically merge quantities
- **Total Value Calculation**: Real-time inventory value computation
- **Item Comparison**: Smart item identification and comparison

### 🔧 Technical Features
- **Object-Oriented Design**: Clean separation of concerns
- **Memory Management**: Proper handling of dynamic arrays
- **Deep Copy Semantics**: Copy constructors and assignment operators
- **Const Correctness**: Appropriate use of const methods

### 📊 Reporting Capabilities
- **Formatted Output**: Professional inventory reports
- **Item Details**: Comprehensive item information display
- **Inventory Summary**: Total value calculation with proper formatting

## 🏗️ Class Architecture

### Class Hierarchy
```
Item → ItemVector → Inventory
```

### 1. Item Class
**Purpose**: Represents a single supermarket item

**Attributes**:
- `_id`: Unique item identifier (integer)
- `_name`: Item name (char array, 50 characters)
- `_rPrice`: Retail price (double)
- `_quantity`: Stock quantity (integer)

**Key Methods**:
- `total()`: Calculate item value (quantity × price)
- `compare()`: Compare two items for equality
- `setQuantity()`: Update stock quantity
- `print()`: Display item details

### 2. ItemVector Class
**Purpose**: Manages a dynamic collection of items

**Attributes**:
- `_max`: Maximum capacity (integer)
- `_count`: Current item count (integer)
- `_items`: Dynamic array of Item objects

**Key Methods**:
- `addItem()`: Add item (merges quantities if exists)
- `_expand()`: Increase storage capacity dynamically
- `exists()`: Check if item already exists
- `itemAt()`: Access item at specific index

### 3. Inventory Class
**Purpose**: High-level inventory management

**Attributes**:
- `_inventory`: ItemVector containing all items

**Key Methods**:
- `addToInventory()`: Add item to inventory
- `inventoryTotal()`: Calculate total inventory value
- `itemInInventory()`: Check item existence
- `print()`: Display complete inventory

## 📥 Installation

### Prerequisites
- C++11 compatible compiler (GCC, Clang, MSVC)
- Standard C++ library
- Make utility (optional)

### Compilation Instructions

```bash
# Compile all source files
g++ -std=c++11 -o supermarket main.cpp item.cpp itemvector.cpp inventory.cpp

# Or use separate compilation
g++ -std=c++11 -c item.cpp
g++ -std=c++11 -c itemvector.cpp
g++ -std=c++11 -c inventory.cpp
g++ -std=c++11 -c main.cpp
g++ -o supermarket main.o item.o itemvector.o inventory.o
```

### File Structure
```
supermarket/
├── item.h              # Item class declaration
├── item.cpp            # Item class implementation
├── itemvector.h        # ItemVector class declaration
├── itemvector.cpp      # ItemVector class implementation
├── inventory.h         # Inventory class declaration
├── inventory.cpp       # Inventory class implementation
├── main.cpp           # Main program and test cases
└── README.md          # This file
```

## 🚀 Usage

### Basic Execution
```bash
./supermarket
```

### Program Flow
1. **Initialization**: Creates default items and containers
2. **Testing**: Runs comprehensive test cases
3. **Inventory Management**: Demonstrates add/merge operations
4. **Reporting**: Displays formatted inventory reports

### Customization
Modify `main.cpp` to add your own test cases or integrate with other systems:

```cpp
// Example: Adding custom items
Item customItem(9999, "Custom Product", 15.99, 25);
Inventory myInventory;
myInventory.addToInventory(customItem);
myInventory.print(std::cout);
```

## 📁 Code Structure

### Header Files Overview

#### item.h
```cpp
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
    // Constructors, methods...
};
#endif
```

#### itemvector.h
```cpp
#ifndef ITEMVECTOR_H
#define ITEMVECTOR_H
#include "item.h"

class ItemVector {
private:
    int _max, _count;
    Item* _items;
    int _expand(int increment);
public:
    // Constructors, methods...
};
#endif
```

#### inventory.h
```cpp
#ifndef INVENTORY_H
#define INVENTORY_H
#include "itemvector.h"

class Inventory {
private:
    ItemVector _inventory;
public:
    // Methods...
};
#endif
```

### Key Implementation Details

#### Dynamic Array Expansion
```cpp
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
```

#### Smart Item Addition with Merging
```cpp
int ItemVector::addItem(const Item& i) {
    int existingIndex = exists(i);
    if (existingIndex != -1) {
        // Merge quantities if item exists
        Item& existingItem = _items[existingIndex];
        int newQuantity = existingItem.getQuantity() + i.getQuantity();
        existingItem.setQuantity(newQuantity);
        return existingIndex;
    }
    // Expand array if needed, then add new item
    if (_count >= _max) _expand(5);
    _items[_count] = i;
    return _count++;
}
```

## 📊 Sample Output

### Test Execution Output
```
Tests Started
Test 1========================================
Test create and print default Item
00000 none   0 @ $  0.00 = $    0.00

Test 2.1========================================
Test create and print specific Items
01231 item1    100 @ $  3.45 = $  345.00
01232 item2     45 @ $ 11.99 = $  539.55
01233 item3     12 @ $  2.99 = $   35.88

Test 5.2========================================
Test create and print Inventory with items
Inventory:
00321 item1    100 @ $  3.45 = $  345.00
00323 item2     45 @ $ 11.99 = $  539.55
00324 item3     12 @ $  2.99 = $   35.88
 Total = $  920.43

Tests Completed
```

### Inventory Report Format
- **Item ID**: 5-digit zero-padded number
- **Item Name**: 8-character width, left-aligned
- **Quantity**: 3-digit right-aligned
- **Prices**: Fixed 2-decimal precision, proper alignment
- **Total Value**: Clean formatted calculation

## 🔧 Technical Details

### Memory Management
- **Dynamic Arrays**: Manual memory management with `new`/`delete`
- **Deep Copy**: Proper copy constructors and assignment operators
- **Array Expansion**: Efficient capacity doubling strategy

### Design Patterns
- **Composition**: Inventory contains ItemVector contains Items
- **RAII**: Proper resource management in constructors/destructors
- **Encapsulation**: Private data members with public interfaces

### Error Handling
- **Bounds Checking**: Safe array access with default returns
- **String Safety**: Bounded string copying with null termination
- **Capacity Management**: Automatic expansion prevents overflow

## 🎯 Key Algorithms

### Item Comparison
```cpp
bool Item::compare(const Item& item) const {
    return (_id == item._id &&
            strcmp(_name, item._name) == 0 &&
            _rPrice == item._rPrice);
}
```

### Inventory Total Calculation
```cpp
double Inventory::inventoryTotal() const {
    double total = 0.0;
    for (int i = 0; i < _inventory.getCount(); i++) {
        total += _inventory.itemAt(i).total();
    }
    return total;
}
```

## 🔄 Expansion Possibilities

### Potential Enhancements
- **File I/O**: Save/load inventory from disk
- **SQL Integration**: Database backend for persistence
- **GUI Interface**: Graphical user interface
- **Network Capabilities**: Multi-store inventory synchronization
- **Advanced Reporting**: Sales trends, profit calculations

### Code Improvements
- **Templates**: Make ItemVector generic
- **STL Containers**: Use std::vector instead of raw arrays
- **Smart Pointers**: Modern memory management
- **Exception Handling**: Robust error management

## 🐛 Troubleshooting

### Common Issues
1. **Compilation Errors**: Ensure C++11 standard is enabled
2. **Memory Leaks**: Use valgrind or similar tools to check
3. **Formatting Issues**: Verify terminal supports the output encoding

### Debugging Tips
- Enable compiler warnings: `-Wall -Wextra`
- Use debugger for memory issues
- Test with small datasets first

## 📄 License

This project is open source and available under the MIT License.

## 🤝 Contributing

Contributions are welcome! Areas for improvement:
- Code optimization
- Additional features
- Documentation enhancements
- Testing expansion

## 👨‍💻 Author

**Subhajit Halder**  
- Object-Oriented Programming enthusiast
- Focus on practical C++ applications
- Inventory management systems specialist

---

<div align="center">

**🛒 Ready to manage your supermarket inventory efficiently!**

*"Good code is its own best documentation." - Steve McConnell*

</div>

## 📞 Support

For questions or issues:
1. Review the code comments for detailed explanations
2. Check the sample output for expected behavior
3. Examine the test cases in main.cpp for usage examples

---

**Happy Coding!** 🚀
