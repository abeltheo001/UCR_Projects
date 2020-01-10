#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T> unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned smallest = index; 

    for (unsigned i = index; i < vals.size(); i++)
    {
        if (vals[i] < vals[smallest])
        {
            smallest = i;
        }
    }
    return smallest;
}

template<typename T> void selection_sort(vector<T> &vals)
{   
    for (unsigned i = 0; i < vals.size(); i++)
    {
        unsigned smallestValue = min_index(vals, i);
         
        T temp = vals[smallestValue]; 
        vals[smallestValue] = vals[i];
        vals[i] = temp;
    }

    return;

}

template<typename T> T getElement(vector<T> vals, int index)
{
        return vals.at(index);   
} 


vector<char> createVector()
{
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}


int main()
{
     srand(time(0));
     vector<int>size;
     int vectorSize = 0; 
     while (vectorSize == 0)
        {    
        cout << "Input size greater than 0:" << endl; 
         cin >> vectorSize;
        }


    //input for integers
    cout << "Output a sorted string of integers" << endl;
    vector <int> newVals; 
    for (int i = 0; i < vectorSize; i++)
    {

        newVals.push_back(rand()%10);
        
    }

    selection_sort(newVals);

    for (int j = 0; j < newVals.size(); j++)
    {
        cout << newVals[j] << " ";
    }
    cout << endl;

    //input for doubles
    vector <double> newVals2; 
    double input;
    for (int i = 0; i < vectorSize; i++)
    {
        cout << "Input a number with a decimal" << endl;
        cin >> input;
        newVals2.push_back(input);
        
    }

    selection_sort(newVals2);

    for (int j = 0; j < newVals2.size(); j++)
    {
        cout << newVals2[j] << " ";
    }
    cout << endl;

    //input for strings
    vector <string> newVals3; 
    string input2;
    for (int i = 0; i < vectorSize; i++)
    {
        cout << "Input a word" << endl;
        cin >> input2;
        newVals3.push_back(input2);
        
    }
    selection_sort(newVals3);
    for (int j = 0; j < newVals3.size(); j++)
    {
        cout << newVals3[j] << " ";
    }
    cout << endl;


     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;

            try
            {
                curChar = getElement(vals,index);
                cout << "Element located at " << index << ": is " << curChar << endl;
            }
            catch(const std::out_of_range& excpt)
            {
                cout << "out of range exception occured" << endl;
            } 
         
    }

    selection_sort(vals);
    for (int i = 0; i < 10; i++)
    {
        cout << vals[i] << " ";
    }
    cout << endl;

    return 0;
}