#include <iostream>
using namespace std;

/*
    quick sort implementation!!!
*/

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    { 
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

void print_array(int* arr, int size)
{
    int i;
    cout << endl << "[ ";
    for (i = 0; i < size; i++) {
        if (i == size - 1)
        {
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;
}

int* input_array(int size) {
    int* array = new int[size];
    int i = 0;
    while (i < size)
    {
        cout << "Enter value in the array at " << i << " index : "; // 1 -2, 3, 0, 20
        cin >> array[i];
        i++;
    }
    return array;
}

int main() {
    start :
    int size;
    cout << "Enter an array size : "; // 5
    cin >> size;
    if (size <= 0)
    {
        cout << "Invalid Input Please Try Again." << endl;
        goto start;
    };
    int* array = input_array(size);
    quick_sort(array, 0, size - 1);
    print_array(array, size);

    return 0;
}

