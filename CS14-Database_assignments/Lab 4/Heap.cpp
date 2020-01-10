#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include "Heap.h"
#include "PrintJob.h"

using namespace std;

  Heap::Heap() : numItems(0) {}

  void Heap::enqueue (PrintJob* x)
  {
    if (numItems == MAX_HEAP_SIZE)
     return;

    ++numItems;
    int index = numItems-1;
    int parentIndex = (index-1)/2;

    arr[index] = x;
    cout << "index: " << index << endl;
    cout << "arr[index] is " << arr[index] -> getPriority() << endl;
    cout << "parentIndex is " << parentIndex << endl;
    cout << "numItems is " << numItems << endl;

    while (arr[index] -> getPriority()> arr[parentIndex]->getPriority())
    {
        swap (arr[index], arr[parentIndex]);
        index = parentIndex;
    }

  }

  void Heap::dequeue()
  {
    if (numItems == 0)
    {
      cout << "empty" << endl;
      return;
    }
      

    --numItems;
    trickleDown(0);

  }

  PrintJob* Heap::highest()
  {
    if (numItems == 0)
        return NULL;

    return arr[0];

  }

  void Heap::print()
  {
    if (numItems == 0)
      return;
    
    
        cout << "Priority: " << arr[0]->getPriority()
        << ", Job Number: " << arr[0]->getJobNumber()
        << ", Number of Pages: " << arr[0]->getPages() << endl;
  }

  void Heap::trickleDown(int index)
  {
    int Child = 2*index + 1; //assign the values of the children 
    PrintJob* value = arr[index];
    while (Child < 10)
    {
      PrintJob* maxValue = value;
      int maxIndex = -1;
      for (int i = 0; i < 2 && i + Child < 10; i++)
      {
        if (arr[i + Child] > maxValue)
        {
          maxValue = arr[i + Child];
          maxIndex  = i + Child;
        }
      }
      if (maxValue == value)
      {
        return;
      }
      else
      {
        swap(arr[index],arr[maxIndex]);
        index = maxIndex;
        Child = 2 * index +1;
      }
      

    }
  }
