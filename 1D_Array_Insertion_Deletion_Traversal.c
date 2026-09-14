#include <stdio.h>

#define MAX 100

void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int pos, int value) {
    if (n == MAX || pos < 0 || pos > n) {
        printf("Invalid insertion.\n");
        return n;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    if (n == 0 || pos < 0 || pos >= n) {
        printf("Invalid deletion.\n");
        return n;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int n = 4;

    traverse(arr, n);

    // Insert 25 at index 2
    n = insert(arr, n, 2, 25);
    traverse(arr, n);

    // Delete element at index 3
    n = deleteElement(arr, n, 3);
    traverse(arr, n);

    return 0;
}