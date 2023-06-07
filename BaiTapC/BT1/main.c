#include <stdio.h>
#include <stdint.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tangdan(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printSoLan(int arr[], int n) {
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        } else {
            printf("so %d: Xuat hien %d\n", arr[i], count);
            count = 1;
        }
    }
}

int main() {
    int arr[] = {1, 5, 2,2, 2, 3, 5, 6, 9, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    tangdan(arr, n);
    printSoLan(arr, n);

    return 0;
}
