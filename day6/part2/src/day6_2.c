#include "../includes/day6_2.h"

long  **create_races(int nb_races)
{
  int i = -1;
  long **races;
  races = (long **)malloc(sizeof(long *) * 3);
  while (++i < 3)
    races[i] = (long *)malloc(sizeof(long) * nb_races);
  return (races);
}

int	main(void)
{	
	FILE *fp = fopen("input.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  char **temp;
  long **races = NULL;
  int line_n = -1;
  int nb_races = 0;
  long hld_button;
  long distance;
  long ways2win;
  long count = 1;
  long i = -1;
  long j = -1;
  long k;

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
    races[line_n] = ft_split_longs(line + i, ' ');
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
  //ft_print_imatrix(races, 3, nb_races);
  printf("%ld\n", races[0][0]);
  printf("%ld\n", races[1][0]);
  printf("%ld\n", races[2][0]);
  i = -1;
  while (++i < nb_races)
    count *= races[2][i];
	printf("Sum: %ld\n", count);
}
