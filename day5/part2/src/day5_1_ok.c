#include "../includes/day5_1.h"
#include <limits.h>

long  **create_almanac(int nb_seeds)
{
  int i = -1;
  long **almanac;
  almanac = (long **)malloc(sizeof(long *) * 8);
  while (++i < 8)
    almanac[i] = (long *)malloc(sizeof(long) * nb_seeds);
  return (almanac);
}

int	main(void)
{	
	FILE *fp = fopen("sample.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  bool seed_flag = true;
  char **temp;
  long **almanac = NULL;
  long *temp_map;
  int nb_seeds = 0;
  int map_pos = 0;
  int line_n = 0;
  int i = -1;
  int j = -1;
  int k;

	while (getline(&line, &len, fp) != -1)
	{
    line_n++;
    if (seed_flag && line_n == 1)
    {
      while (line[i] != ':')
			  i++;
      temp = ft_split(line + i + 1, ' ');
      while (temp[nb_seeds])
        nb_seeds++;
      ft_free_smatrix(temp);
      seed_flag = false;
      printf("seeds:%d\n", nb_seeds);
      almanac = create_almanac(nb_seeds);
      while (++j < 8)
      {
        k = -1;
        while(++k < nb_seeds)
          almanac[j][k] = -1;
      }
      almanac[0] = (long *)ft_split_ints(line + i + 1, ' ');
    }
    else if (ft_isalpha(line[0]))
      map_pos++;
    else if (ft_isdigit(line[0]))
    {
      i = -1;
      int temp_n = -1;
      temp_map = (long *)ft_split_longs(line, ' '); // working correctly
      while (++i < nb_seeds)
      {
        if (almanac[map_pos][i] == -1)
        {
          temp_n = -1;
          if (((int)almanac[map_pos - 1][i] >= (int)temp_map[1]) && ((int)almanac[map_pos - 1][i] <= ((int)temp_map[1] + (int)temp_map[2])))
            temp_n = temp_map[0] + (almanac[map_pos - 1][i] - temp_map[1]); 
          if (temp_n != -1 && temp_n >= (int)temp_map[0] && (temp_n <= ((int)temp_map[0] + (int)temp_map[2])))
            almanac[map_pos][i] = temp_n;
        }
      }
    }
    else if (line[0] == '\n')
    {
      i = -1;
      while (++i < nb_seeds)
      {
        if ((int)almanac[map_pos][i] == -1)
          almanac[map_pos][i] = almanac[map_pos - 1][i];
      }
    }
	}
  i = -1;
  while (++i < nb_seeds)
  {
    if ((int)almanac[map_pos][i] == -1)
      almanac[map_pos][i] = almanac[map_pos - 1][i];
  }
  ft_print_imatrix((int **)almanac, (int)8, (int)nb_seeds);
	fclose(fp);
	free(line);
	//printf("Sum: %d\n", data.final_cards);
}
