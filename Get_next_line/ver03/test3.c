#include <unistd.h>
#include <fcntl.h>
#include "for_test.h"

int main()
{
	
	int fd = open("test2.txt", O_RDONLY);
	char tmp[100];
	read(fd, tmp, 6);
	print_data(tmp, 6);
}
