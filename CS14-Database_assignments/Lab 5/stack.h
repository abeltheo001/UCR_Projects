#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 20;

template<typename T>
class stack
{
    private: 
        T data[MAX_SIZE];
        int size;

    public:

        stack()
        {
            size = 0;
        }
        void push(T val)
        {
            if (size == MAX_SIZE)
            {
                throw overflow_error("Called push on full stack.");
                
            }
            else
            {
                data[size++] = val;
            }
            
        }
        T pop()
        {
            T temp; 
            if (empty())
            {
                throw out_of_range("Called pop on empty stack.");
                return temp;
                 
            }
            else
            {
                return data[size--];
            }
        }

        T top()
        {
            T temp;
            if (empty())
            {
                throw underflow_error("Called top on empty stack.");
                return temp;
            }
            return data[size -1];
        }
        bool empty()
        {
            if (size <= 0)
                return true;
            else
            {
                return false;
            }
            
        } 
    
};