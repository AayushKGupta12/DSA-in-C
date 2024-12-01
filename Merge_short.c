#include<stdio.h>
void conquer(int A[], int s, int mid, int e) {
    int merged[e - s + 1];  // Temporary array to store merged elements
    int i = s;              // Starting index for the left subarray
    int j = mid + 1;        // Starting index for the right subarray
    int k = 0;              // Index for the merged array

    // Merge the two subarrays into merged[]
    while (i <= mid && j <= e) {
        if (A[i] <= A[j]) {
            merged[k++] = A[i++];
        } else {
            merged[k++] = A[j++];
        }
    }

    // Copy the remaining elements from the left subarray, if any
    while (i <= mid) {
        merged[k++] = A[i++];
    }

    // Copy the remaining elements from the right subarray, if any
    while (j <= e) {
        merged[k++] = A[j++];
    }

    // Copy the merged elements back to the original array
    for (int a = 0; a < (e - s + 1); a++) {
        A[s + a] = merged[a];
    }
}

void divide(int A[], int s, int e) {
    if (s >= e) {
        return;  // Base case: when the subarray has one or no element
    }

    int mid = (s + e) / 2;
    divide(A, s, mid);     // Recursively sort the left subarray
    divide(A, mid + 1, e); // Recursively sort the right subarray
    conquer(A, s, mid, e); // Merge the two sorted subarrays
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    divide(A, 0, n - 1); // Call the divide function

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf(" %d ",A[i]);
    }
    return 0;
}