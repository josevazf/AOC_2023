/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:00:39 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:41:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convertbase(char c, char *base)
{
	int	i;

	i = 0;
	if (c >= 'A' && c <= 'F')
		c = c + 32;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

/* Converts a string 'str' from a given base up to 16 to an 
	integer in decimal base. */
int	ft_atoi_base(const char *str, int str_base)
{
	char	*base;
	int		nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	base = "0123456789abcdef";
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (str[i] && ft_isinbase(str[i], str_base, base))
	{
		nb = nb * str_base;
		nb = nb + ft_convertbase(str[i], base);
		i++;
	}
	return (nb * sign);
}
