#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i = 1;

	fd = open("tests/test_txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("(linha -> %zu)", i++);
		printf("%s", line);
		free(line);
	}
	return (0);
}