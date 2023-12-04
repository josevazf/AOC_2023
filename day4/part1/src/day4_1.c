#include "../includes/day4_1.h"

int	main(void)
{	
	FILE *fp = fopen("input.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  char **game;
  char **win;
  char **play;
	int		i;
  int   j;
	int		number;
	int		g_count;
  int   f_count = 0;

	while (getline(&line, &len, fp) != -1)
	{
		number = 0;
    g_count = 0;
		i = -1;
		while (line[i] != ':')
			i++;
    game = ft_split(line + i + 1, '|');
    win = ft_split(game[0], ' ');
    play = ft_split(game[1], ' ');
    i = -1;
    while (play[++i])
    {
      j = -1;
      number = atoi(play[i]);
      while (win[++j])
      {
        if (atoi(win[j]) == number && g_count == 0)
          g_count++;
        else if (atoi(win[j]) == number)
          g_count *= 2;
      }
    }
    f_count += g_count;
	}
	fclose(fp);
	free(line);
  ft_free_smatrix(game);
  ft_free_smatrix(win);
  ft_free_smatrix(play);
	printf("Sum: %d\n", f_count);
}