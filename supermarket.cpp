/*
    A simple supermarket ordering system without STL
    main.cpp
    Author: SUBHAJIT HALDER 
       DATE: 13/09/2025
*/

#include <iostream>
#include "item.h"
#include "itemvector.h"
#include "inventory.h"

using namespace std;

int main() {
    cout << "Tests Started" << endl;
    cout << "Test 1========================================" << endl;
    cout << "Test create and print default Item" << endl;
    Item i1;
    i1.print(cout);
    cout << "End Test 1========================================" << endl << endl;
    cout << "Test 2.1========================================" << endl;
    cout << "Test create and print specific Items" << endl;
    Item i2(1231, "item1", 3.45, 100);
    Item i3(1232, "item2", 11.99, 45);
    Item i4(1233, "item3", 2.99, 12);    
    i2.print(cout);
    i3.print(cout);
    i4.print(cout);
    cout << "End Test 2.1========================================" << endl << endl;
    cout << "Test 2.2========================================" << endl;
    cout << "Test get/set quantity from Item" << endl;
    i2.print(cout);
    cout << "i2.getQuantity()=" << i2.getQuantity() << endl;
    cout << "Set quantity to 10" << endl;
    i2.setQuantity(10);
    cout << "i2.getQuantity()=" << i2.getQuantity() << endl;
    cout << "End Test 2.2========================================" << endl << endl;
    cout << "Test 2.3========================================" << endl;
    cout << "Test get total from Item" << endl;
    i3.print(cout);
    cout << "i3.total()=" << i3.total() << endl;
    cout << "End Test 2.3========================================" << endl << endl;
    cout << "Test 2.4========================================" << endl;
    cout << "Test compare Item" << endl;
    Item i5(1233, "item3", 2.99, 12);
    Item i6(123, "item3", 2.99, 12);    
    i4.print(cout);
    i5.print(cout);
    i6.print(cout);    
    cout << "i4 == i5 (0->no, 1->yes): " << i4.compare(i5) << endl;
    cout << "i4 == i6 (0->no, 1->yes): " << i4.compare(i6) << endl;
    cout << "End Test 2.4========================================" << endl << endl;
    cout << "Test 3========================================" << endl;
    cout << "Test create and print default ItemVector" << endl;
    ItemVector iv1;
    iv1.print(cout);
    cout << "End Test 3========================================" << endl << endl;
    cout << "Test 4.1========================================" << endl;
    cout << "Test ItemVector with unique Items" << endl;
    ItemVector iv2;
    Item i7(456, "item1", 3.45, 100);
    Item i8(457, "item2", 11.99, 45);
    Item i9(458, "item3", 2.99, 12);    
    iv2.addItem(i7);
    iv2.addItem(i8);
    iv2.addItem(i9);
    iv2.print(cout);
    cout << "End Test 4.1========================================" << endl << endl;   
    cout << "Test 4.2========================================" << endl;
    cout << "Test ItemVector add existing Item" << endl;
    Item i10(457, "item2", 11.99, 15);
    iv2.addItem(i10);
    iv2.print(cout);
    cout << "End Test 4.2========================================" << endl << endl;
    cout << "Test 5.1========================================" << endl;
    cout << "Test create and print default Inventory" << endl;
    Inventory inv1;
    inv1.print(cout);
    cout << "End Test 5.1========================================" << endl << endl;
    cout << "Test 5.2========================================" << endl;
    cout << "Test create and print Inventory with items" << endl;
    Inventory inv2;
    Item i11(321, "item1", 3.45, 100);
    Item i12(323, "item2", 11.99, 45);
    Item i13(324, "item3", 2.99, 12);    
    inv2.addToInventory(i11);
    inv2.addToInventory(i12);
    inv2.addToInventory(i13);
    inv2.print(cout);
    cout << "End Test 5.2========================================" << endl << endl;    
    cout << "Tests Completed" << endl;    
    return 0;
}
