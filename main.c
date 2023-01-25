#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char	*ex;

	ex = get_next_line(0);
	printf("-> gnl result : %s", ex);
	return (0);
}