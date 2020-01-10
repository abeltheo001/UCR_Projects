#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <time.h>

using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

int genRandInt(int low, int high) 
{
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[])
{
    for (int i = 0; i < NUMBERS_SIZE; ++i)
    {
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
int partition(int numbers[], int i, int k) 
{
   int l = 0;
   int h = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;

   pivot = numbers[(i+k)/2];
   
   l = i;
   h = k;
   
   while (!done) 
   {
    
      while (numbers[l] < pivot)
      {
         ++l;
      }
      
      while (pivot < numbers[h]) 
      {
         --h;
      }
      
      if (l >= h) 
      {
         done = true;
      }
      else 
      {
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}


void Quicksort_midpoint(int numbers[], int i, int k)
{
    int j = 0;
    
    if (i >= k) 
    {
        return;
        
    }
    
    j = partition(numbers, i, k);
    
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);

}

int partition_medianOfThree(int numbers[], int i, int k)
{
    int l = 0;
    int h = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;
   int a = numbers[i];
   int b = numbers[i+(k-i)/2];
   int c = numbers[k];
   if (a < b && b < c)
    {
       pivot = b;
    }
    else if (a < b && a > c)
    {
       pivot = a;
    }
    else
    {
       pivot = c;
    }


    l = i;
    h = k;
    
    while (!done) 
    {
      while (numbers[l] < pivot)
      {
         ++l;
      }
      
      while (pivot < numbers[h]) 
      {
         --h;
      }
      
      if (l >= h) 
      {
         done = true;
      }
      else 
      {

         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;

}

void Quicksort_medianOfThree(int numbers[], int i, int k)
{
    int j = 0;
    
    if (i >= k) 
    {
        return;
    }
    
    j = partition_medianOfThree(numbers, i, k);
    
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);

}



void InsertionSort(int numbers[], int numbersSize)
{
    int i, j, temp = 0;

    for (i = 1; i < numbersSize; ++i)
    {
        j = i;
        while (j > 0 && numbers[j] < numbers[j-1])
        {
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            --j;

        }  

    }

}

int main()
{
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    int i = 0; 
    int k = NUMBERS_SIZE-1;
    fillArrays(arr1, arr2, arr3);
    
    clock_t Start = clock();
    Quicksort_medianOfThree(arr1,i,k);
    clock_t End = clock();
    int elapsedTime1 = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Total time for Quicksort_medianOfThree is " << elapsedTime1  << " milliseconds."<< endl;
 
    clock_t Start2 = clock();
    Quicksort_midpoint(arr2,i,k);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Total time for Quicksort_midpoint is " << elapsedTime2 << " milliseconds."<< endl;

    clock_t Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Total time for Insertion Sort is " << elapsedTime3<< " milliseconds."<< endl;

    return 0;
}