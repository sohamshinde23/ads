#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int N, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}

void buildHeap(int arr[], int N) {
    int startIdx = (N / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

int deleteRoot(int arr[], int* N) {
    if (*N <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int root = arr[0];

    arr[0] = arr[*N - 1];
    (*N)--; 

    heapify(arr, *N, 0);

    return root;
}

void printHeap(int arr[], int N) {
    printf("Array representation of Heap is:\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, key;
    int arr[100]; 
    int N = 0;   

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert All\n");
        printf("2. Delete\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the number of elements to be inserted: ");
                scanf("%d", &N);
                printf("Enter the elements: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &arr[i]);
                }
                buildHeap(arr, N);
                printf("Inserted all elements into the heap.\n");
                break;
            }
            case 2:
                key = deleteRoot(arr, &N);
                if (key != -1) {
                    printf("Deleted root element: %d\n", key);
                }
                break;
            case 3:
                printHeap(arr, N);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
