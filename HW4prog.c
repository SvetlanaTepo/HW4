#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include <stdio.h>



struct array* make_array()
{
	struct array* a = (struct array*)malloc(sizeof(struct array));
	assert(0 != a); // make sure memory allocation are made

	memset(a, 0, sizeof(struct array));
	a->size = 0;
	a->capacity = 2; 
	a->start = (element_type*)malloc(a->capacity * sizeof(element_type));
	assert(a->start != NULL); 

	return a;
}


void array_push_back(struct array* a, element_type e) // Add an element at the end of the array
{
	assert(a != NULL);

	
	if (a->size == a->capacity) { // Resize the array if  there is a need
		a->capacity *= 2; // Double the capacity
		a->start = realloc(a->start, a->capacity * sizeof(element_type));
		assert(a->start != NULL);
	}

	
	a->start[a->size] = e; // Add the new element
	a->size += 1;
}


void array_remove_last(struct array* a) // Remove the last element of the array
{
	assert(a != NULL);
	assert(a->size > 0); // make sure our array is not empty

	a->size -= 1;
	
}

// Insert an element 
void array_insert(struct array* a, size_type index, element_type e)
{
	assert(a != NULL);
	assert(index <= a->size); 

	// Resize if needed
	if (a->size == a->capacity) {
		a->capacity *= 2;
		a->start = realloc(a->start, a->capacity * sizeof(element_type));
		assert(a->start != NULL);
	}

	// Shift elements to the right to make space
	for (size_type i = a->size; i > index; --i) {
		a->start[i] = a->start[i - 1];
	}

	// Insert 
	a->start[index] = e;
	a->size += 1;
}


size_type array_size(struct array* a)// show the number of elements in the array
{
	assert(0 != a);
	return a->size;
}


size_type array_capacity(struct array* a)// show the capacity of the array
{
	assert(0 != a);
	return a->capacity;
}


void print_array(struct array* a) 
// Print the elements , their size, and capacity of the array
{
	assert(0 != a);
	for (size_type i = 0; i < a->size; ++i) {
		printf("%d ", a->start[i]);
	}
	printf("\nsize = %d", a->size);
	printf("\ncapacity = %d\n\n", a->capacity);
}


int array_empty(struct array* a) // Return 1 if the array is empty in other case 0
{
	assert(0 != a);
	return a->size == 0;
}
