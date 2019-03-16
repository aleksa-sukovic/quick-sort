#include <stdio.h>
#include <stdlib.h>

int* newIntArray(int length)
{
    return (int*) malloc(sizeof(int) * length);
}

int* loadArray(int length)
{
    int* array = newIntArray(length);

    int i;
    for (i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    return array;
}

void printArray(int* array, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void swap(int* array, int i, int j)
{
    int helper = array[i];
    array[i] = array[j];
    array[j] = helper;
}

int partition(int* array, int low, int high, int (*comparator)(int, int))
{
    int pivot = array[high];
    int boundary = low - 1;
    int counter;

    for (counter = low; counter < high; counter++) {
        if ((*comparator)(array[counter], pivot)) {
            swap(array, counter, ++boundary);
        }
    }

    swap(array, high, ++boundary);
    return boundary;
}

void quickSort(int* array, int low, int high, int (*comparator)(int, int))
{
    if (low < high) {
        int pivot = partition(array, low, high, comparator);

        quickSort(array, low, pivot - 1, comparator);
        quickSort(array, pivot + 1, high, comparator);
    }
}

int ascendingComparator(int value, int pivot)
{
    return value < pivot;
}

int descendingComparator(int value, int pivot)
{
    return value > pivot;
}

int main()
{
    // Initialization
    int length;
    int order;

    printf("Unesite duzinu niza: ");
    scanf("%d", &length);

    printf("Unesite redosled sortiranja (1 = ASC, 2 = DESC): ");
    scanf("%d", &order);

    printf("Unesite %d elemenata niza: \n", length);
    int* array = loadArray(length);

    // Sorting
    quickSort(
        array,
        0, // low
        length - 1, // high
        order == 1 ? ascendingComparator : descendingComparator // ordering
    );

    // Printing result
    printf("Sorted array:\n");
    printArray(array, length);
}