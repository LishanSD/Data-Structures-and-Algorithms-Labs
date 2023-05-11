#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int l = 2*root + 1;
   int r = 2*root + 2;
 
   if ((l < n) && (arr[l] > arr[root])){
      largest = l;
   }
 
   if ((r < n) && (arr[r] > arr[largest])){
      largest = r;
   }
 
   if (largest != root){
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i = n - 1; i > 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }  
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   cout << "Enter the size of array : ";
   cin >> n;

   int heap_arr[n];

   for(int i = 0; i < n; i++){
     cout << "Enter the value " << i+1 << " : ";
     cin >> heap_arr[i];
   }

   //int heap_arr[] = {4,17,3,12,9,6};
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}