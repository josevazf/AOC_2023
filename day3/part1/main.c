#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct s_map
{
  int width;
  int height;
  char **map;
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
  data->map = (char **)malloc(sizeof(char *) * (data->height + 2));
  while (++i < data->height + 2)
    data->map[i] = (char *)malloc(sizeof(char) * (data->width + 2));
  i = -1;
  while (++i < data->height + 2)
  {
    j = -1;
    while (++j < data->width + 2)
      data->map[i][j] = 'n';
  }
}

int validsym(char c)
{
  if (!isalnum(c) && c != '.')
    return (1);
  return (0);
}

void  check_numbers(t_map *data)
{
  int i = 0;
  int j = 0;
  int number = 0;
  char *snumber;
  bool valid;

  while (++i < data->height + 1)
  {
    j = 0;
    while (++j < data->width + 1)
    {
      valid = false;
      snumber = malloc(sizeof(char) * 1);
      snumber[0] = '\0';
      if (!isnumber(data->map[i][j]) && data->map[i][j] != 'n')
        j++;
      while (isnumber(data->map[i][j]))
      {
        snumber = ft_strjoin(snumber, &data->map[i][j]);
        number = atoi(snumber);
        if (validsym(data->map[i - 1][j - 1]) || validsym(data->map[i - 1][j]) || validsym(data->map[i - 1][j + 1]) ||
        validsym(data->map[i][j - 1]) || validsym(data->map[i][j]) || validsym(data->map[i][j + 1]) ||
        validsym(data->map[i + 1][j - 1]) || validsym(data->map[i + 1][j]) || validsym(data->map[i + 1][j + 1]))
          valid = true;
        j++;
      }
      if (valid)
        data->count += number;
      free(snumber);
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

  data.width = 0;
  data.height = 0;
  data.count = 0;
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
      data.map[j][i] = line[i - 1];
  }
  check_numbers(&data);
  fclose(fp);
  free(line);
  printf("Sum: %d\n", data.count);
}