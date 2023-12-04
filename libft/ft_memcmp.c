/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:38:09 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:43:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares the first 'len' bytes of the block of memory pointed by 'b1' 
   to the first num bytes pointed by 'b2', returning zero if they all match 
   or a value different from zero representing which is greater. */
int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)b1;
	str2 = (unsigned char *)b2;
	while (i < len && (str1[i] == str2[i]))
		i++;
	if (i < len)
		return (str1[i] - str2[i]);
	else
		return (0);
}
