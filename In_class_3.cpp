#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
// #include <chrono>
// #include <vector>
using namespace std;
using namespace std::chrono;

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

/*void insertionSort1(int n, vector<int> arr) {
    int x = arr[n-1];
    for (int i = (n-2); i >= 0; i--) {
        if (x < arr[i]) {
            arr[i+1] = arr[i];
            for (int j : arr) {
                cout << j << " ";
            }
            cout << '\n';
        }

        else if (x >= arr[i]) {
            arr[i+1] = x;
            for (int j : arr) {
                cout << j << " ";
            }
            break;
        }

        else if (i == 0) {
            arr[0] = x;
            for (int j : arr) {
                cout << j << " ";
            }
            break;
        }
    }
}*/

// perform bubble sort
void bubbleSort(int array[], int size)
{

    // loop to access each array element
    for (int step = 0; step < size; ++step)
    {

        // loop to compare array elements
        for (int i = 0; i < size - step; ++i)
        {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1])
            {

                // swapping elements if elements
                // are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// perform bubble sort
void OpbubbleSort(int array[], int size)
{

    // loop to access each array element
    for (int step = 0; step < (size - 1); ++step)
    {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); ++i)
        {

            // compare two array elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1])
            {

                // swapping occurs if elements
                // are not in intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;
            }
        }

        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0)
            break;
    }
}

// function to swap the the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}

int main()
{
    int sz;
    cout << "Enter the size of array::";
    cin >> sz;
    int randArray[sz];
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100;
    int size = sizeof(randArray) / sizeof(randArray[0]);
    vector<int> values(10000);
    auto f = []() -> int
    { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();

    selectionSort(randArray, size);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}