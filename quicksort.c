#include <stdio.h>

void quicksort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left + 1;
        int j = right;
        while (i <= j) {
            while (i <= j && pivot > arr[i])
                i++;
            while (i <= j && pivot < arr[j])
                j--;
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        arr[left] = arr[j];
        arr[j] = pivot;
        quicksort(arr, left, j - 1);
        quicksort(arr, j + 1, right);
    }
}

int main(void) {
    int arr[] = {0, 3, 9, 1, 2, 6};
    quicksort(arr, 0, 5);
    int i;
    for (i=0; i<6; ++i) {
    	printf("%d ", arr[i]);
	}
    return 0;
}
