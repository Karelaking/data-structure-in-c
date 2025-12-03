// Online C compiler to run C program online
#include <stdio.h>

// Function to perform selection sort iteratively
void selectionSortIterative(int arr[], int n){
  for (int i = 0; i < n - 1; i++) {
    for (int j = i+ 1; j < n; j++) {
        if (arr[j] < arr[i]) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  }
}

// Function to perform selection sort recursively
void selectionSort(int arr[], int start, int n) {
    if (start == n - 1) return;

    int minIndex = start;

    // Find minimum element index recursively (inside the same function)
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap if needed
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Recursive call for the remaining array
    selectionSort(arr, start + 1, n);
}

int main() {
    int arr[] = {40, 20, 50, 60, 30, 10};
    int n= sizeof(arr)/sizeof(int);
    selectionSort(arr, 0, n);
    for (int i = 0; i < n; i++){
    printf("%d, ", arr[i]);
    }
    return 0;
}