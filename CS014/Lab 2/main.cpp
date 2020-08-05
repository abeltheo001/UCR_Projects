#include "IntList.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
using namespace std; 

int main()
{
    IntList list;
    cout << "push 2 to front of list" << endl;
    list.push_front(2);
    cout << list << endl;
    
    cout << "push 1 to front of list" << endl;
    list.push_front(1);
    cout << list << endl;
    
    cout << "push 3 to back of list" << endl;
    list.push_back(3);
    cout << list << endl;
    
    cout << "push 4 to back of list" << endl;
    list.push_back(4);
    cout << list << endl;
    
    cout << "push 5 to back of list." << endl;
    list.push_back(5);
    cout << list << endl;
    
    cout << "pop back." << endl;
    list.pop_back();
    cout << list << endl;
    
    cout << "pop front." << endl;
    list.pop_front();
    cout << list << endl;
    
    cout << "Print list in reverse." << endl;
    list.printReverse();
    cout << endl;
    
    cout << "Is list is empty?: ";
    if (!list.empty())
    {
        cout << "No" << endl;
        
    }
    else 
    {
        cout << "Yes." << endl;
    }
    
    cout << "Empty the list." << endl;
    for (int i = 0; i < 3; ++i)
    {
        list.pop_back();
    }
    
    cout << "Empty now?:" << endl;
    if (!list.empty())
    {
        cout << "No" << endl;
        
    }
    else 
    {
        cout << "yes." << endl;
    }


    list.pop_back();

    return 0;
}