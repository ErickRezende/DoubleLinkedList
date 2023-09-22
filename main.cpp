#include <iostream>
#include "list.hpp"
using namespace std;

int main() {  
    // Just some tests
  
    List<int> list;

    list.push(54);
    list.push(32);
    list.push(43);
    list.push(56);

    list.push(1234, 3);

    for(int i = 0; i < list.size(); i++){
        cout << list.at(i) << endl;
    }

    list.purge(1);

    cout << endl;

    for(int i = 0; i < list.size(); i++){
        cout << list.at(i) << endl;
    }

    cout << endl << "First element: " << list.first()->data << endl;
    cout << "Last element: " << list.last()->data << endl;
    cout << "List size: " << list.size() << endl;

    return EXIT_SUCCESS;
}

/*
    inline const_reference operator[](index_type n) const
	{
*/

/*
    try {
        copydb(x);
    } catch (...) {
        this->abort_txn();
        throw;
    }
*/