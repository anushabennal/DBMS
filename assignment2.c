#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int *size, int element, int index) {
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert new element.\n");
        return;
    }
    if (index < 0 || index > *size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[index] = element; // Insert the element
    (*size)++;
}
void delete(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    (*size)--; // Decrease the size
}
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index
        }
    }
    return -1; // Element not found
}
int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current size of the array
    // Insert elements
    insert(arr, &size, 10, 0);
    insert(arr, &size, 20, 1);
    insert(arr, &size, 30, 2);
    insert(arr, &size, 25, 2); // Inserting 25 at index 2
    display(arr, size);
    // Delete an element
    delete(arr, &size, 1); // Deleting element at index 1
    display(arr, size);
    // Search for an element
    int element = 25;
    int index = search(arr, size, element);
    if (index != -1) {
        printf("Element %d found at index %d.\n", element, index);
    } else {
        printf("Element %d not found in the array.\n", element);
    }
      // Search for a non-existent element
    element = 20;
    index = search(arr, size, element);
    if (index != -1) {
        printf("Element %d found at index %d.\n", element, index);
    } else {
        printf("Element %d not found in the array.\n", element);
    }
    return 0;
}
