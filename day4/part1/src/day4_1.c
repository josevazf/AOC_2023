#include "../includes/day4_1.h"

int	main(void)
{	
	FILE *fp = fopen("sample.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  char **game;
  //int win_nbrs;
  //int  *my_nbrs = NULL;
	int		i;
  int   j;
	int		number;
	//int		multi = 1;
	int		count = 0;

	while (getline(&line, &len, fp) != -1)
	{
		number = 0;
		i = -1;
		while (line[i] != ':')
			i++;
    j = -1;
    game = ft_split(line + i + 1, ' ');
    while (!ft_strncmp(game[++j], "|", 1))
    {
      number = atoi(game[0]);
      printf("%d ", number);
    }
	}
	fclose(fp);
	free(line);
	printf("Sum: %d\n", count);
}