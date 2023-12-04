#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct s_val
{
  char  c;
  int   parts;
  int   g_ratio;
  int   lastn;
} t_val;

typedef struct s_map
{
  int width;
  int height;
  t_val **map;
  int count;
} t_map;

char	*ft_strjoin(char const *s1, char const *s2)
{
  char *join;
  size_t i = -1;
  size_t j = -1;

  join = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
  if (!join)
    return (NULL);
  while (s1[++i])
    join[i] = s1[i];
  while (s2[++j])
    join[j + i] = s2[j];
  join[i + j] = '\0';
  return (join);
}

void  create_map(t_map *data)
{
  int i = -1;
  int j = -1;
  data->map = (t_val **)malloc(sizeof(t_val *) * (data->height + 2));
  while (++i < data->height + 2)
    data->map[i] = (t_val *)malloc(sizeof(t_val) * (data->width + 2));
  i = -1;
  while (++i < data->height + 2)
  {
    j = -1;
    while (++j < data->width + 2)
      data->map[i][j].c = 'n';
  }
}

int validsym(char c, int i, int j, int number, t_map *data)
{
  if (c == '*')
  {
    if (data->map[i][j].parts == 2)
      return (1);
    if (data->map[i][j].parts <= 2 && data->map[i][j].lastn != number)
    {
      data->map[i][j].parts++;
      data->map[i][j].g_ratio *= number;
      data->map[i][j].lastn = number;
    }
    return (1);
  }
  return (0);
}

void  check_numbers(t_map *data)
{
  int i = 0;
  int j = 0;
  int k;
  int number = 0;
  char *snumber;
  bool valid;

  while (++i < data->height + 1)
  {
    j = 0;
    while (++j < data->width + 1)
    {
      k = 0;
      snumber = malloc(sizeof(char) * 1);
      snumber[0] = '\0';
      if (!isnumber(data->map[i][j].c) && data->map[i][j].c != 'n')
        j++;
      while (isnumber(data->map[i][j + k].c))
      {
        snumber = ft_strjoin(snumber, &data->map[i][j + k].c);
        number = atoi(snumber);
        k++;
      }
      while (isnumber(data->map[i][j].c))
      {
        if (validsym(data->map[i - 1][j - 1].c, i - 1, j - 1, number, data) || validsym(data->map[i - 1][j].c, i - 1, j, number, data) || validsym(data->map[i - 1][j + 1].c, i - 1, j + 1, number, data) ||
        validsym(data->map[i][j - 1].c, i, j - 1, number, data) || validsym(data->map[i][j + 1].c, i, j + 1, number, data) ||
        validsym(data->map[i + 1][j - 1].c, i + 1, j - 1, number, data) || validsym(data->map[i + 1][j].c, i + 1, j, number, data) || validsym(data->map[i + 1][j + 1].c, i + 1, j + 1, number, data))
          valid = true;
        j++;
      }
      number = 0;
      free(snumber);
    }
  }
}
void get_gears(t_map *data)
{
  int i = 0;
  int j = 0;

  while (++i < data->height + 1)
  {
    j = 0;
    while (++j < data->width + 1)
    {
      if (data->map[i][j].parts == 2)
        data->count += data->map[i][j].g_ratio;
    }
  }
}
int	main(void)
{	
  FILE *fp = fopen("input.aoc", "r");
  size_t len = 0;
  char *line = NULL;
  t_map data;
  int i = 0;
  int j = 0;

  while (getline(&line, &len, fp) != -1 && ++i)
    data.width = strlen(line);
  data.height = i;
	fclose(fp);
  create_map(&data);
  i = 0;
  fp = fopen("input.aoc", "r");
  while (getline(&line, &len, fp) != -1 && ++j)
  {
    i = 0;
    while (++i < data.width + 1)
    {
      data.map[j][i].c = line[i - 1];
      data.map[i][j].g_ratio = 1;
      data.map[i][j].parts = 0;
      data.map[i][j].lastn = -1;
    }
  }
  check_numbers(&data);
  get_gears(&data);
  fclose(fp);
  free(line);
  printf("Sum: %d\n", data.count);
}