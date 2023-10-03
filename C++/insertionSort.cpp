// Insertion Sort Algorithm :- In this sorting algorithm we have to check each element starting from 1st index to last and if we found any element which is smaller then elements which are in left side of that element then we swap them.

#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[] , int arrSize)
{
    for (int i = 1; i < arrSize; i++)
    {
        int key = arr[i]; //selecting 1st element so that we can start comparison.
        int j = i-1;      //selecting left side elements (to compare with key).

        while (j>=0 && key<arr[j])  //j>=0 is a corner case , we have to take care of it.
        {
            arr[j+1]  = arr[j];     //swapping key with left side elements if key is smalle.
            j--;                    //decrementing j so that we can check all left side elements.
        }

        arr[j+1] = key;           
        
    }

    //printing sorted array
    for (int  i = 0; i < arrSize; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
   int arr[] = {44,33,55,22,11};
   int arrSize = sizeof(arr)/sizeof(int);


    cout<<"Th array before sorting"<<endl;
   for (int i = 0; i < arrSize; i++)
   {
    cout<<arr[i]<<" ";
   }

   cout<<endl<<"The array after sorting using Insertion Sort"<<endl;
   insertionSort(arr , arrSize);
   

   return 0;
}