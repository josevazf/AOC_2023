/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:30 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:38:30 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if given char 'c' is in given base */
int	ft_isinbase(char c, int str_base, char *base)
{
	int	i;

	i = 0;
	while (i < str_base)
	{
		if (c >= 'A' && c <= 'F')
			c = c + 32;
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}
