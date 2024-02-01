#include <stdio.h>
#include "employee.h"
#include "heap.h"
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[]) {
	// Define list of employees
	Employee *staff = (Employee*) malloc(MAX_EMPLOYEES * sizeof(Employee));
	
	// Get user input employees
	for(int i = 0; i < MAX_EMPLOYEES; i++) {
		// Get name
		char n[MAX_NAME_LEN];
		printf("Name: ");
		scanf("%s", n);
		strcpy(staff[i].name, n);

		// Get salary
		int s = 0;
		printf("Salary: ");
		scanf("%d", &s);
		printf("\n");
		staff[i].salary = s;
	}

	// Heapsort the list
	heapSort(staff, MAX_EMPLOYEES);

	// Print out the list of employees
	printList(staff, MAX_EMPLOYEES);

	// Clean up the heap
	free(staff);
	staff = NULL;

	return 0;
}
