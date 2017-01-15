#include <stdio.h>
#include <stdlib.h>

void swap(int *data, int i, int j)
{
	// printf("\n===========================\n");

	// printf("%d\n", *(data + i));
	// printf("%d\n", *(data + j));

	// printf("\n===========================\n");
	int tmp = *(data + i);
	*(data + i) = *(data + j);
	*(data + j) = tmp;

	// printf("%d\n", *(data + i));
	// printf("%d\n", *(data + j));
	// printf("\n===========================\n");



}

void maxheapify(int *data, int i, int length)
{
	int l = (i * 2 + 1);
	int r = (i * 2 + 1) + 1;
	int largest = i;

	if (l < length && (*(data + l) > *(data + i))) {
		largest = l;
	}

	if (r < length && (*(data + r) > *(data + largest))) {
		largest = r;
	}

	if (largest != i) {
		swap(data, i, largest);
		maxheapify(data, largest, length);
	}
}


void build_max_heap(int *data, int length)
{
	for(int i = length/2 ; i > -1; i--){
		maxheapify(data, i, length);
	}
}


int main()
{
	FILE *fp;
	fp = fopen("IntegerArray.txt", "r");
	int recordCount = 10;
	int data[recordCount];
	for(int i = 0; i < recordCount; i++) {
		fscanf(fp, "%d", &data[i]);
	}

	for(int i = 0; i < recordCount; i++) {
		printf("%d\n", data[i]);
	}


	for (int i = 0; i < recordCount; i++) {
		build_max_heap(data, recordCount - i);
		swap(data, 0, recordCount - i) ;
	}

	for(int i = 0; i < recordCount; i++) {
		printf("%d\n", data[i]);
	}






	printf("\n======================\n");
	for(int i = 0; i < recordCount; i++) {
		printf("%d\n", data[i]);
	}


	return 0;
}

// make -e PROG="programname"
