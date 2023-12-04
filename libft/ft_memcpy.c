/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:33:11 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:44:02 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies the values of 'len' bytes from the location pointed to by 'src' 
   directly to the memory block pointed to by 'dest'. */
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < len)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
