#include "quicksort.h"

int quicksort(int *array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r); // Partition the subarray around the pivot, which ends up in A[q].

        quicksort(array, p, q - 1);
        quicksort(array, p + 1, r);

        return 0;
    }
    else
    {
        return -1;
    }
}

int partition(int *array, int p, int r)
{
    int x = *(array + r);       // the pivot
    int i = p - 1;              // highest index into the low side
    for (int j = p; j < r; j++) // process each element other than the pivot
    {
        if (*(array + j) <= x) // does this element belong on the low side?
        {
            i++; // index of a new slot in the low side
            int temp = *(array + i);
            *(array + i) = *(array + j); // put this element there
            *(array + j) = temp;
        }
    }
    int temp = *(array + i + 1);
    *(array + i + 1) = *(array + r); // pivot goes just to the right of the low side
    *(array + r) = temp;

    return i + 1; // new index of the pivot
}
