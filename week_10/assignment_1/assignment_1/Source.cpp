#include <iostream>
#include <algorithm>
using namespace std;

// leetcode 4. Median of Two Sorted Arrays

double findMedianSortedArrays(int* A, int* B, int sizeA,int sizeB) {
    int m = sizeA;
    int n = sizeB;
    if (m > n) { 
        int* temp = A; 
        A = B; 
        B = temp;
        int tmp = m; 
        m = n; 
        n = tmp;
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < iMax && B[j - 1] > A[i]) {
            iMin = i + 1; 
        } else if (i > iMin && A[i - 1] > B[j]) {
            iMax = i - 1; 
        } else { 
            int maxLeft = 0;
            if (i == 0) { 
                maxLeft = B[j - 1]; 
            } else if (j == 0) { 
                maxLeft = A[i - 1]; 
            } else { 
                maxLeft = max(A[i - 1], B[j - 1]); 
            }
            if ((m + n) % 2 == 1) { 
                return maxLeft; 
            }
            int minRight = 0;
            if (i == m) { 
                minRight = B[j]; 
            } else if (j == n) { 
                minRight = A[i]; 
            } else { 
                minRight = min(B[j], A[i]); 
            }

            return ((double)maxLeft + (double)minRight) / 2.0;
        }
    }
    return 0.0;
}

int* input(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
    return arr;
}

/*
    test case

    case 1: 
            2
            1 3
            1
            2
    output: 2.0
    
    case 2:
            2
            1 2
            2
            3 4
    output: 2.5

    case 3:
            2
            0 0
            2
            0 0
    output: 0.0

*/

int main() {
    int sizeA, sizeB;
    cin >> sizeA;
    int* arr1 = input(sizeA);
    cin >> sizeB;
    int* arr2 = input(sizeB);
    cout << findMedianSortedArrays(arr1, arr2, sizeA, sizeB);
	return 0;
}