#include <stdio.h>

// Function to perform binary search iteratively
int binary_search(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    // Check if target is present at mid
    if (arr[mid] == target) {
      return mid; // Target found
    }
    // If target is greater, ignore left half
    else if (arr[mid] < target) {
      left = mid + 1;
    }
    // If target is smaller, ignore right half
    else {
      right = mid - 1;
    }
  }
  return -1; // Target not found
}

// Function to perform binary search recursively
int binary_search_recursive(int arr[], int left, int right, int target) {
  if (left > right) {
    return -1; // Target not found
  }
  int mid = left + (right - left) / 2;

  // Check if target is present at mid
  if (arr[mid] == target) {
    return mid; // Target found
  }
  // If target is greater, search in the right half
  else if (arr[mid] < target) {
    return binary_search_recursive(arr, mid + 1, right, target);
  }
  // If target is smaller, search in the left half
  else {
    return binary_search_recursive(arr, left, mid - 1, target);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(int);
  int target = 7;

  int result_iterative = binary_search(arr, size, target);
  int result_recursive = binary_search_recursive(arr, 0, size - 1, target);

  printf("Target %d found at index %d (iterative)\n", target, result_iterative);
  printf("Target %d found at index %d (recursive)\n", target, result_recursive);
return 0;
}