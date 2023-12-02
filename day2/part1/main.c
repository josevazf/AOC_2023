#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RED 12
#define	MAX_GREEN 13
#define MAX_BLUE 14 

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

int	check_max(char *str, int value)
{
	if (!ft_strncmp(str, "red", 3) && value <= MAX_RED)
		return (1);
	if (!ft_strncmp(str, "blue", 4) && value <= MAX_BLUE)
		return (1);
	if (!ft_strncmp(str, "green", 5) && value <= MAX_GREEN)
		return (1);
	return (0);
}

int	main(void)
{	
	FILE	*fp = fopen("input.txt", "r");
	size_t	len = 0;
	char	*line = NULL;
	bool	valid;
	int		i;
	int		number;
	int		game = 0;
	int		count = 0;

	while (getline(&line, &len, fp) != -1)
	{
		game++;
		number = 0;
		valid = true;
		i = -1;
		while (line[i] != ':')
			i++;
		while (line[++i])
		{
			while (!isdigit(line[i]) && line[i])
				i++;
			if (!line[i])
				break;
			number = atoi(line + i);
			while (!isalpha(line[i]) && line[i])
				i++;
			if (!check_max((line + i), number))
			{
				valid = false;
				break;
			}
		}
		if (valid)
			count += game;
	}
	fclose(fp);
	free(line);
	printf("Sum: %d\n", count);
}