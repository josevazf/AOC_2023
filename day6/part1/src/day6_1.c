#include "../includes/day6_1.h"

int  **create_races(int nb_races)
{
  int i = -1;
  int **races;
  races = (int **)malloc(sizeof(int *) * 3);
  while (++i < 3)
    races[i] = (int *)malloc(sizeof(int) * nb_races);
  return (races);
}

int	main(void)
{	
	FILE *fp = fopen("input.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  char **temp;
  int **races = NULL;
  int line_n = -1;
  int nb_races = 0;
  int hld_button;
  int distance;
  int ways2win;
  int count = 1;
  int i = -1;
  int j = -1;
  int k;


	while (getline(&line, &len, fp) != -1)
	{
    i = 0;
    line_n++;
    while (!ft_isdigit(line[i]))
      i++;
    if (line_n == 0)
    {
      temp = ft_split(line + i, ' ');
      while (temp[nb_races])
        nb_races++;
      ft_free_smatrix(temp);
      races = create_races(nb_races);
      while (++j < 3)
      {
        k = -1;
        while(++k < nb_races)
          races[j][k] = -1;
      }
    }
    races[line_n] = ft_split_ints(line + i, ' ');
  }
	fclose(fp);
	free(line);
  i = -1;
  while (++i < nb_races)
  {
    j = -1;
    hld_button = 0;
    distance = 0;
    ways2win = 0;
    while (++hld_button <= races[0][i])
    {
      if (((races[0][i] - hld_button) * hld_button) > races[1][i])
        ways2win++;
    }
    races[2][i] = ways2win;
  }
  ft_print_imatrix(races, 3, nb_races);
  i = -1;
  while (++i < nb_races)
    count *= races[2][i];
	printf("Sum: %d\n", count);
}
