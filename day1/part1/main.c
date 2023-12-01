#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{	
	FILE	*fp = fopen("input.txt", "r");
	char	*line = NULL;
	char	*str = NULL;
	size_t	len = 0;
	char	*numbers = "0123456789";
	int		count = 0;
	int		value1 = 0;
	int		value2 = 0;

	while (getline(&line, &len, fp) != -1)
	{
		str = strpbrk(line, numbers);
		value1 = str[0] - 48;
		value2 = value1;
		while (str)
		{
			value2 = atoi(str);
			str = strpbrk(++str, numbers);			
		}
		count += ((value1 * 10) + value2);
	}
	fclose(fp);
	free(str);
	free(line);
	printf("Sum: %d\n", count);
}