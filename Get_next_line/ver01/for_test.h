#include "get_next_line.h"
#include <stdio.h>

void	print_vector(t_vector *vec)
{
	printf("vector : \t");
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
	printf("\tsize(%zu), capacity(%zu)", vec->size, vec->capacity);
	printf("\n");
}

void	print_backup(char *backup, size_t buf_size)
{
	printf("backup : \t");
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
	printf("\n");
}
