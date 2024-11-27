#include <iostream>
using namespace std;

// Function to find the maximum number in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Helper function to perform counting sort on the array based on a specific digit
void countingSort(int arr[], int n, int exp, bool ascending) {
    const int RADIX = 10;
    int output[n];
    int count[RADIX] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % RADIX]++;
    }

    if (!ascending) {
        for (int i = 1; i < RADIX; i++) {
            count[i] += count[i - 1];
        }
    } else {
        for (int i = RADIX - 2; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (!ascending) {
            output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
            count[(arr[i] / exp) % RADIX]--;
        } else {
            output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
            count[(arr[i] / exp) % RADIX]++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort in both ascending and descending order
void radixSort(int arr[], int n, bool ascending) {
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp, ascending);
    }
}

int main() {
    int arr[] = {45, 12, 67, 23, 90, 56, 89, 34, 11, 76, 49, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ascending Sort
    radixSort(arr, n, true);
    cout << "Array Sorted in Ascending Order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Descending Sort
    radixSort(arr, n, false);
    cout << "Array Sorted in Descending Order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
