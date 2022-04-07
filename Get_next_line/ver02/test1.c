#include <stdio.h>
#include "get_next_line.h"
#include "for_test.h"
/* NOTE : tests for data structure */


int main()
{
	t_vector *arr = new_vector_malloc(5);
	push_back_vector(arr, 'h');
	push_back_vector(arr, 'e');
	push_back_vector(arr, 'l');
	push_back_vector(arr, 'l');
	push_back_vector(arr, 'o');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '!');
	push_back_vector(arr, '\n');
	print_vector(arr);

	return 0;
}
