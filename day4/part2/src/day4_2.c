#include "../includes/day4_2.h"

typedef struct s_card
{
  int game;
  int matches;
  int units;
  bool winner;
} t_card;

typedef struct s_game
{
  int final_cards;
  int init_cards;
  t_card **card;
} t_game;

void  create_game(t_game *data)
{
  int i = -1;
  while (++i < data->init_cards)
    data->card[i] = (t_card *)malloc(sizeof(t_card) * data->init_cards);
}

void  get_cards(t_game *data)
{
  int i = -1;
  int j;
  while (++i < data->init_cards)
  {
    if (data->card[i]->winner)
    {
      j = 0;
      while (++j <= data->card[i]->matches)
        data->card[i + j]->units += (data->card[i]->matches * data->card[i]->units);
    }
  }
  i = -1;
  while (++i < data->init_cards)
    data->final_cards += data->card[i]->units;
}

int	main(void)
{	
	FILE *fp = fopen("input.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  t_game data;
  char **game;
  char **win;
  char **play;
	int		i;
  int   j;
  int   k = 0;
	int		number;

  data.init_cards = 0;
  while (getline(&line, &len, fp) != -1)
    data.init_cards++;
  fclose(fp);
  create_game(&data);
	fp = fopen("sample.aoc", "r");
	while (getline(&line, &len, fp) != -1)
	{
		i = -1;
		number = 0;
    data.card[k]->game = k;
    data.card[k]->units = 1;
    data.card[k]->matches = 0;
    data.card[k]->winner = false;
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
        if (atoi(win[j]) == number)
          data.card[k]->matches++;
      }
    }
    if (data.card[k]->matches != 0)
      data.card[k]->winner = true;
	}
  get_cards(&data);
	fclose(fp);
	free(line);
  ft_free_smatrix(game);
  ft_free_smatrix(win);
  ft_free_smatrix(play);
	printf("Sum: %d\n", data.final_cards);
}