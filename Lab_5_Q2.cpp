#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

int main(){
  int sz;
  cout << "Enter the size of array::";
  cin >> sz;

  int arr[sz];

  for(int i = 0; i < sz; i++){
    cout << "Enter the value " << i+1 << " : ";
    cin >> arr[i];
  }

  for(int i = 0; i < sz; i++){
    float m;
    int tempArr[i+1]; 
    for(int j = 0; j < i+1; j++){
        tempArr[j] = arr[j];
    }

    insertionSort(tempArr, i+1);

    if((i+1) % 2 == 0){
        m = float(tempArr[(i+1) / 2] + tempArr[(i-1) / 2]) / 2;
    }
    else {
        m = tempArr[i/2];
    }

    printArray(tempArr, i+1);
    cout << "median : " << fixed << setprecision(1) << m << endl;
    cout << "\n";
  }
  return 0;
}
