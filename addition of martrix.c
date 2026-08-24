#include <stdio.h>

int main() {
    int rows, cols;

    // Step 1: Get matrix dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare 2D arrays based on user dimensions
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int sum[rows][cols];

    // Step 2: Input elements for the first matrix
    printf("\nEnter elements for the 1st matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Step 3: Input elements for the second matrix
    printf("\nEnter elements for the 2nd matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Step 4: Perform element-wise addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Step 5: Print the resultant matrix
    printf("\nResultant Matrix (Sum):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]); // \t creates spacing between columns
        }
        printf("\n"); // Moves to the next line after finishing a row
    }

    return 0;
}
