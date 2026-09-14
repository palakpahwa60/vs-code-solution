#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   // Element found
    }
    return -1;          // Element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key, position;

    printf("Enter element to search: ");
    scanf("%d", &key);

    position = linearSearch(arr, n, key);

    if (position == -1)
        printf("%d is not present in the array.\n", key);
    else
        printf("%d found at index %d.\n", key, position);

    return 0;
}