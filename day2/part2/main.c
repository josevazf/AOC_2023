#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}	t_color;

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

int	check_max(char *str, int value, t_color *clr)
{
	if (!ft_strncmp(str, "red", 3))
	{
		if (value > clr->red)
			clr->red = value;
		return (1);
	}
	if (!ft_strncmp(str, "blue", 4))
	{
		if (value > clr->blue)
			clr->blue = value;
		return (1);
	}
	if (!ft_strncmp(str, "green", 5))
	{
		if (value > clr->green)
			clr->green = value;
		return (1);
	}
	return (0);
}

int	main(void)
{	
	FILE	*fp = fopen("input.txt", "r");
	size_t	len = 0;
	char	*line = NULL;
	t_color	clr;
	int		i;
	int		number;
	int		count = 0;

	while (getline(&line, &len, fp) != -1)
	{
		i = -1;
		clr.red = 0;
		clr.green = 0;
		clr.blue = 0;
		number = 0;
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
			check_max((line + i), number, &clr);
		}
		number = clr.red * clr.green * clr.blue;
		count += number;
	}
	fclose(fp);
	free(line);
	printf("Sum: %d\n", count);
}