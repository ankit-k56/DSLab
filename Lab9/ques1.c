#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the minimum element with the first element in the unsorted part
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter the integer numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubble_sort(numbers, n);
                printf("Array after Bubble Sort:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;
            case 2:
                selection_sort(numbers, n);
                printf("Array after Selection Sort:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;
            case 3:
                insertion_sort(numbers, n);
                printf("Array after Insertion Sort:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", numbers[i]);
                }
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;

}