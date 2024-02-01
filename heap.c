/*
 * heapsort.c
 *
 *  Created on: January 30, 2024
 *      Author: Percy Proctor
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// BuildHeap on the heap
	buildHeap(A, n);

	// Heapsorting time
	while(n >= 1) {
		// Swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(A+(n-1), A);

		// A[n-1] now sorted in place, so decrement n
		n--;

		// Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
		for(int i = 0; i <= n-1; i++) {
			heapify(A, i, n);
		}
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n) {
	// heapify() every element from A[n/2] down-to A[0]
	for(int i = n/2; i >= 0; i--) {
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n) {
	// Get index of left child of element i
	int leftChild;
	if(i*2+1 < n) {
		leftChild = (i*2)+1;
	}

	// Get index of right child of element i
	int rightChild;
	if(i*2+2 < n) {
		rightChild = (i*2)+2;
	}

	// Continue recursion as long as i is within range AND either rightChild or leftChild are still within range.
	if(!(i < n && ((rightChild < n && rightChild >= 0) || (leftChild < n && leftChild >= 0)))) {
		return;
	}

	// Determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	int smaller;
	if(((rightChild < n && rightChild >= 0)) && (A[rightChild].salary < A[leftChild].salary)) {
		smaller = rightChild;
	} else {
		smaller = leftChild;
	}

	// Check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	if(A[i].salary > A[smaller].salary) {
		swap(A+i, A+smaller);
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2) {
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++) {
		printf("[id=%s sal=%d], ", (A[i]).name, (A[i]).salary);
	}
}
