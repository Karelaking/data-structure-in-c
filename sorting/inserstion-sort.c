#include <stdio.h>

void insertionSort(int arr[], int n) {
    // Base case: when array size is 1, it's sorted
    if (n <= 1)
        return;

    // Recursively sort first n-1 elements
    insertionSort(arr, n - 1);

    // Insert last element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("");
    return 0;
}
