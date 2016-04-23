#include <stdio.h>
#include <stdlib.h>


void swap(int *data, int i, int j)
{
	int tmp = *(data + i);
	*(data + i) = *(data + j);
	*(data + j) = tmp;

}


void qsort(int *data, int start, int end)
{

	if(start < end) {
		// Pick the first element as the pivot
		int pivotIndex = start;
		// Move the pivot element to the end of the array

		// start = 0
		// end = 9

		swap(data, pivotIndex, end);

		for(int index = start; index < end; index++) {
			if (*(data + index) < *(data + end)) {
				swap(data, pivotIndex, index);
				pivotIndex++;
			}
		}

		swap(data, pivotIndex, end);
		qsort(data, start, pivotIndex - 1);
		qsort(data, pivotIndex + 1, end);
	}

}


int main()
{
	FILE *fp;
	int recordCount = 100000;
	fp = fopen("IntegerArray.txt", "r");

	int *data = (int *)malloc(sizeof(int) * recordCount);

	for(int i = 0; i < recordCount; i++) {
		fscanf(fp, "%d", (data + i));
	}

	qsort(data, 0, recordCount - 1);
	return 0;
}
