/*******************************************************************************

	Solution:
	build a list by multiplying prime numbers with the already calculated
	ugly numberlist and add them to a min heap. min heap gurantee when extract
	the number is the minumum of the numbers in the heap. Adding to a min heap
	runs in O(log(n)) running time, and extracting is O(1).

	Note: When extracting we have to make sure the extracted number is not in
	the ugly array since the data added to the heap contain duplicated values.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void printarr(int *data, int len)
{

	printf("\n|");
	for(int i = 0; i < len; i++){
		printf(" %d |", *(data + i));
	}
	printf("\n\n");

}

/*************************************
	Swap values in two nodes in heap
*************************************/
void swap(int *heap, int i, int j)
{
	int tmp = *(heap + i);
	*(heap + i) = *(heap + j);
	*(heap + j) = tmp;
}

/****************************************************
	build the min heap using recursive
****************************************************/
void minHeapify(int *heap, int index, int *heapLength)
{
	int left = (index * 2) + 1; // +1 is for index correction
	int right = (index * 2) + 1 + 1;
	int smalest= index;

	if (left < (*heapLength) && (*(heap + left) < *(heap + index))) {
		smalest = left;
	}

	if (right < (*heapLength) && (*(heap + right) < *(heap + smalest))){
		smalest = right;
	}

	if (smalest != index) {
		swap(heap, smalest, index);
		minHeapify(heap, smalest, heapLength);
	}
}

/***************************************
	Heapify the min heap
***************************************/
void heapify(int *heap, int *heapLength)
{
	for(int i = (*heapLength)/2; i > -1; i--){
		minHeapify(heap, i, heapLength);
	}
}


void increase(int **heap, int len)
{
	*heap = (int *)realloc(*heap, sizeof(int) * len);
}

/********************************************************************
	Add a value to min heap
*********************************************************************/
void addtoheap(int *heap, int value, int *heapIndex, int *arraylength)
{
	/* Resize the heap size when needed */
	if (*heapIndex >= *arraylength) {
		(*arraylength) += 16;
		increase(&heap, *arraylength);
	}

	*(heap + (*heapIndex)) = value;
	(*heapIndex)++;
	heapify(heap, heapIndex);
}

/*********************************************************************
	Extract the root value from the heap (minimum value in min heap)
**********************************************************************/
int extractMin(int *heap, int *heapIndex, int *arraylength)
{
	if (*(heapIndex) < 1){
		printf("Add something to heap before extract\n");
		return 0;
	}

	int value = *(heap + 0);
	*(heap + 0) = *(heap + *(heapIndex) -1);
	*(heap + *(heapIndex) -1) = 0;
	(*heapIndex)--;
	heapify(heap, heapIndex);
	return value;
}

/***********************************************************
	Build the super ugly number array
***********************************************************/
int nthSuperUglyNumber(int n, int* primes, int primesSize) {

	int arraylength = n;
	int heapIndex = 0;
	int nthCount = 0;
	int *heap = (int *)malloc(sizeof(int) * arraylength);
	int uglyNumbers[n];
	int found = 0;
	int value;
	uglyNumbers[nthCount] = 1;
	while (nthCount < n){
		for(int i = 0; i < primesSize; i++){
			addtoheap(
				heap,
				(*(primes + i) * uglyNumbers[nthCount]), // build the ugly number
				&heapIndex,
				&arraylength
			);
		}
		do { // This loop taking care of duplicated ugly numbers
			found = 0;
			value = extractMin(heap, &heapIndex, &arraylength);
			for (int i = 0; i < nthCount; i++){
				if (value == uglyNumbers[nthCount]) {
					found = 1;
					break;
				}
			}
		}while(found == 1);

		nthCount++;
		uglyNumbers[nthCount] = value;
	}
	free(heap);
	printf("\n\nUgly number list: ");
	printarr(uglyNumbers, nthCount);
	return uglyNumbers[nthCount - 1];
}


int main()
{
	int primes[4] = {2, 7, 13, 19}; // Prime list
	int primesSize = int(sizeof(primes)/sizeof(int));
	int N = 12; // nth Ugly Number you want
	int val = nthSuperUglyNumber(N, primes, primesSize);
	printf("%dth Ugly number is = %d\n", N, val);
	return 0;
}






