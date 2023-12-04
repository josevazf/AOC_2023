/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:32:25 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:41:22 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_i(long n, char *str, int *i)
{
	if (n >= 10)
	{
		ft_putnbr_i(n / 10, str, i);
		ft_putnbr_i(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

/* Converts an integer 'n' to a null-terminated string. */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = nbr * -1;
	}
	ft_putnbr_i(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
