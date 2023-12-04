/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:20:44 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:44:15 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies the values of 'len' bytes from the location pointed by 'src' 
   to the memory block pointed by 'dest'. */
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
		d = ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (d);
}
