#ifndef FOR_TEST_H
# define FOR_TEST_H

#include "get_next_line.h"
#include <stdio.h>

void	print_vector(t_vector *vec)
{
	printf("---------------------\n");
	printf("[ vector ] \n");
	for (size_t i=0; i<vec->capacity; ++i)
	{
		char tmp = ((char*)(vec->data))[i];
		if (tmp == '\n')
			printf("\\n");
		else if (tmp != 0)
			printf("%c", tmp);
		else
			printf("%d", tmp);
	}
	printf("\tsize(%zu), capacity(%zu)\n", vec->size, vec->capacity);
	printf("---------------------\n");
	printf("\n");
}

void	print_data(char *backup, size_t buf_size)
{
	printf("---------------------\n");
	printf("[ buffer ]\n");;
	for (size_t i=0; i<buf_size; ++i)
	{
		char tmp = backup[i];
		if (tmp == '\n')
			printf("\\n");
		else if (tmp != 0)
			printf("%c", tmp);
		else
			printf("%d", tmp);
	}
	printf("\n---------------------\n");
	printf("\n");
}

#endif
