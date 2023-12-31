/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:01:33 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/12/05 19:21:47 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strposi(char const *s, char c, int pos)
{
	size_t	i;
	char	*subs;

	i = pos;
	while (s[i] != '\0' && s[i] != c)
		i++;
	subs = ft_substr(s, pos, (i - pos));
	return (subs);
}

/* Returns an array of integers obtained by splitting ’s’ using the
   character ’c’ as a delimiter. */
int	*ft_split_ints(char const *s, char c)
{
	int	*out;
	int		i;
	int		j;

	i = 0;
	j = -1;
	out = malloc(sizeof(int *) * ft_count_words_del(s, c));
	if (!out)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			out[++j] = ft_atoi(ft_strposi(s, c, i));
			i = i + ft_nbrlen(out[j]);
		}
	}
	return (out);
}
