/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:10 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:46:53 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a copy of ’s1’ with the characters specified in ’set’ removed
   from the beginning and the end of the string. */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (*s1 && ft_strrchr(set, s1[i]))
		i--;
	str = ft_substr(s1, 0, i + 1);
	return (str);
}
