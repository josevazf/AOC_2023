#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	if (i < size)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

int	ncompare(char *str)
{
	if (!ft_strncmp(str, "one", 3))
		return (1);
	if (!ft_strncmp(str, "two", 3))
		return (2);
	if (!ft_strncmp(str, "three", 5))
		return (3);
	if (!ft_strncmp(str, "four", 4))
		return (4);
	if (!ft_strncmp(str, "five", 4))
		return (5);
	if (!ft_strncmp(str, "six", 3))
		return (6);
	if (!ft_strncmp(str, "seven", 5))
		return (7);
	if (!ft_strncmp(str, "eight", 5))
		return (8);
	if (!ft_strncmp(str, "nine", 4))
		return (9);
	return (-1);
}

int	main(void)
{	
	FILE	*fp = fopen("input.txt", "r");
	size_t	len = 0;
	bool	vstart;
	bool	vend;
	char	*line = NULL;
	int		i;
	int		count = 0;
	int		v1 = 0;
	int		v2 = 0;

	while (getline(&line, &len, fp) != -1)
	{
		i = -1;
		vstart = false;
		vend = false;
		while (line[++i])
		{
			if (isdigit(line[i]) && !vstart)
			{
				v1 = line[i] - 48;
				vstart = true;
			}
			else if (ncompare(line + i) != -1 && !vstart)
			{
				v1 = ncompare(line + i);
				vstart = true;
			}
			else if (isdigit(line[i]) && vstart)
			{
				v2 = line[i] - 48;
				vend = true;
			}
			else if (ncompare(line + i) != -1 && vstart)
			{
				v2 = ncompare(line + i);
				vend = true;
			}
			if (!vend)
				v2 = v1;
		}
		count += ((v1 * 10) + v2);
	}
	fclose(fp);
	free(line);
	printf("Sum: %d\n", count);
}