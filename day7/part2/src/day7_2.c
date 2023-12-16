#include "../includes/day7_2.h"

#define FIVE_OAK 7
#define FOUR_OAK 6
#define FULL_HOUSE 5
#define THREE_OAK 4
#define TWO_PAIR 3
#define ONE_PAIR 2
#define HIGH_CARD 1

typedef struct s_hand {
  int rank;
  int bid;
  int type;
  char *cards;
} t_hand;

typedef struct s_game {
  int nb_hands;
  int total;
  t_hand **hand;
} t_game;

int switch_to_int(char c) {
  switch (c) {
    case 'J': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    case 'T': return 10; break;
    case 'Q': return 11; break;
    case 'K': return 12; break;
    case 'A': return 13; break;
  }
  return (EXIT_FAILURE);
}

void create_game(t_game *data) {
  int i = -1;

  data->hand = (t_hand **)malloc(sizeof(t_hand *) * (data->nb_hands));
  while (++i < data->nb_hands)
    data->hand[i] = (t_hand *)malloc(sizeof(t_hand) * 1);
}

int check_hand_type(char *hand) {
  char cardset[] = "AKQT98765432";
  int i = -1;
  int j = -1;
  int count;
  int pairs = 0;
  int oak3 = 0;
  int oak4 = 0;
  int oak5 = 0;

  while (cardset[++j]) {
    i = -1;
    count = 0;
    while (hand[++i]) {
      if (cardset[j] == hand[i])
        count++;
    }
    switch (count) {
      case 2: pairs++; break;
      case 3: oak3++; break;
      case 4: oak4++; break;
      case 5: oak5++; break;
    }
  }
  count = 0;
  j = -1;
  while (hand[++j])
  {
    if (hand[j] == 'J')
      count++;
  }
  if (oak5 == 1 || count == 5 || count == 4)
    return (FIVE_OAK);
  else if ((oak4 == 1 && count == 1) || (oak3 == 1 && count == 2) || (count == 3 && pairs == 1))
    return (FIVE_OAK);
  else if (oak4 == 1 || (oak3 == 1 && count == 1) || (pairs == 1 && count == 2) || count == 3)
    return (FOUR_OAK);
  else if ((oak3 == 1 && pairs == 1) || (pairs == 2 && count == 1))
    return (FULL_HOUSE);
  else if ((oak3 == 1 && pairs == 0) || (pairs == 1 && count == 1) || count == 2)
    return (THREE_OAK);
  else if (pairs == 2 && count == 0)
    return (TWO_PAIR);
  else if (pairs == 1 || count == 1)
    return (ONE_PAIR);
  else
    return (HIGH_CARD);
}

int check_high_card(char *hand1, char *hand2) {
  int i = -1;

  while (++i < 5) {
    if (switch_to_int(hand1[i]) == switch_to_int(hand2[i]))
      continue;
    else if (switch_to_int(hand1[i]) > switch_to_int(hand2[i]))
      return (1);
    else
      return (0);
  }
  return (0);
}

int	main(void)
{
	FILE *fp = fopen("input.aoc", "r");
	size_t len = 0;
	char *line = NULL;
  char **temp;
  t_game data;
  bool repeat = true;
  int tmp_pos = -1;
  int nb_hands = 0;
  int type = 0;
  int count = 0;
  int rank;
  int j;

	while (getline(&line, &len, fp) != -1)
    nb_hands++;
  data.nb_hands = nb_hands;
	fclose(fp);
  create_game(&data);
  fp = fopen("input.aoc", "r");
  j = -1;
  while (getline(&line, &len, fp) != -1) {
    j++;
    temp = ft_split(line, ' ');
    data.hand[j]->cards = temp[0];
    data.hand[j]->type = check_hand_type(data.hand[j]->cards);
    data.hand[j]->bid = atoi(temp[1]);
    data.hand[j]->rank = 0;
    if (data.hand[j]->type > type)
      type = data.hand[j]->type;
  }
  rank = nb_hands;
  type =  type + 1;
  while (rank > 0 && type > 0)
  {
    type--;
    tmp_pos = -1;
    repeat = true;
    while (repeat && rank > 0 && type > 0)
    {
      j = -1;
      while (++j < nb_hands)
      {
        if (data.hand[j]->type == type && data.hand[j]->rank == 0) 
        {
          if (tmp_pos == -1)
          {
            data.hand[j]->rank = rank;
            tmp_pos = j;
          }
          else if (check_high_card(data.hand[j]->cards, data.hand[tmp_pos]->cards))
          {
            data.hand[j]->rank = rank;
            data.hand[tmp_pos]->rank = 0;
            tmp_pos = j;
          }
        }
      }
      tmp_pos = -1;
      rank--;
      j = -1;
      repeat = false;
      while (++j < nb_hands)
      {
        if (data.hand[j]->type == type && data.hand[j]->rank == 0)
          repeat = true;
      }
    }
  }
  j = -1;
  while (++j < nb_hands)
    count += (data.hand[j]->bid * data.hand[j]->rank);
  fclose(fp);
  free(line);
	printf("Sum: %d\n", count);
}