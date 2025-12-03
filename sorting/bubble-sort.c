// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

// Function to perform bubble sort using iteration
void bubbleSortIterative(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform bubble sort using recursion
void bubbleSort(int arr[], int n) {
    bool isSwap = false;
    if (n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            isSwap = true;
        }
    }
    if (!isSwap) return;
    bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {40, 20, 50, 60, 30, 10};
    int n= sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
    printf("%d, ", arr[i]);
    }
    return 0;
}