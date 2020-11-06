#include <iostream>
using namespace std;

// leetcode 977. Squares of a Sorted Array

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

void quick_sort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int* squaredArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = arr[i] * arr[i];
	}
	return arr;
}

int* input(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    return arr;
}

void output(int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << " ]";
}

/*

    test case:
    case 1   
    input: 5
          -4 -1 0 3 10
    output: [ 0, 1, 9, 16, 100 ]

    case 2
    input: 5
           -7 -3 2 3 11
    output: [ 4, 9, 9, 49, 121 ]

*/

int main() {
    int size;
    cin >> size;
    int* arr = input(size);
    squaredArray(arr, size);
    quick_sort(arr, 0, size - 1);
    output(arr, size);
	return 0;
}