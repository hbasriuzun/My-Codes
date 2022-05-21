#include <iostream>
#include <algorithm>

void swap( int & a, int & b ) {
    int temp = std::move( a );
    a = std::move(b);       
    b = std::move(temp);
}

void insertionSort(int *ar, int size){
 int j;
 for (int i=1; i < size; i++)
 for ( j=i-1; 0 <= j and ar[j] > ar[j+1]; j--)
 swap(ar[j], ar[j+1]);
 
 }

int main(int argc, char const *argv[])
{
    int arr[60] = {4,7,2,8,3,0,5,2,6,8,6,4,3,6,8,5,32,1,34,5,7,90,9,7,45,2,3,5,7,8,5,2,3,4,8,7,5,4,6,764746,746,5745,745,6,546,546,456,45,6,546,546,546,4,654,6,456,456,54,645,6};
    
     int j;
    for (int i=1; i < 60; i++)
    for ( j=i-1; 0 <= j and arr[j] > arr[j+1]; j--)
    swap(arr[j], arr[j+1]);
  
  
  
  
    insertionSort(arr,60);
    return 0;
}
