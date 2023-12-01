#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{	
	FILE	*fp = fopen("input.txt", "r");
	char	*line = NULL;
	size_t	len = 0;
	char	*numbers = "0123456789";
	int		stlen = 0;
	int		count = 0;
	int		value = 0;

	while (getline(&line, &len, fp) != -1)
	{
		stlen = strlen(line);
		value = (line[strcspn(line, numbers)]) - 48;
		count += value;
		printf("%s - %d\n", line, count);
	}
	fclose(fp);
	free(line);
}