#include <stdio.h>
#include <stdlib.h>

/*
    Print data
*/
void arrayPrint(int *data, int count)
{
    printf("[ ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(data + i));
    }
    printf("]\n");
}


/*
    Insert data x in to set S
*/
// insert(S, x)


/*
    Read the maximum value in set S
*/
// maximum(S)

/*
    Extract the maximum value from S
*/
// extract_maximum()

/*
    Increase the value of x to k in S
*/
// increase_key(S, x, k)

/*
    Initialize the heap array
*/
int *initializeHeap(int *readCount)
{
    FILE *file = fopen("IntegerArray.txt", "r");
    int *data = (int *)malloc(sizeof(int) * (*readCount));
    for (int i = 0; i < *readCount; i++) {
        fscanf(file, "%d", (data + i));
    }
    return data;
}

void swap(int *root, int x, int y)
{
    int tmp = *(root + x);
    *(root + x) = *(root + y);
    *(root + y) = tmp;
}


void maxHeapify(int *root, int r, int len)
{
    int left = 2*r + 1;
    int right = 2*r + 2;
    int big = r;
    if (left <= len) {
        if (*(root + left) > *(root + r)) {
            big = left;
        }
    }

    if (right <= len) {
        if (*(root + right) > *(root + big)) {
            big = right;
        }
    }

    if (r != big) {
        swap(root, r, big);
        maxHeapify(root, big, len);
    }

}
void heapify(int *root, int len)
{
    for (int i = len; i >= 0; i--) {
        maxHeapify(root, i, len);
    }
}

int maximum(int *root)
{
    return *(root + 0);
}

void insert(int *root, int *len, int newval)
{
    root= (int *)realloc(root, sizeof(int) * (*len));
    *(root + *len) = newval;
    (*len)++;
}

int main()
{
    int initialCount = 10;
    int *count = &initialCount;
    int *data = initializeHeap(count);
    arrayPrint(data, *count);
    heapify(data, initialCount);
    arrayPrint(data, *count);
    printf("The max value in the heap is %d\n", maximum(data));
    int newval = 30000;
    insert(data, count, newval);
    arrayPrint(data, *count);
    insert(data, count, 300);
    arrayPrint(data, *count);

}
