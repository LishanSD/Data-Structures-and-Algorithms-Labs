#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

/*
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

*/

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSortIterative(int arr[], int l, int h)
{

    int stack[h - l + 1];

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {

        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main()
{
    int sz;
    cout << "Enter the size of array::";
    cin >> sz;
    int randArray[sz];
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100; // Generate number between 0 to 99
    int size = sizeof(randArray) / sizeof(randArray[0]);
    vector<int> values(10000);
    auto f = []() -> int
    { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();

    quickSortIterative(randArray, 0, size - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}