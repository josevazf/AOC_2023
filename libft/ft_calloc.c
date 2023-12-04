/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:13:56 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:33:10 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates a block of memory for an array of num elements
   each of them size bytes long, and initializes all its bits to zero. */
void	*ft_calloc(size_t number, size_t size)
{
	char	*ptr;

	ptr = malloc(number * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, number * size);
	return (ptr);
}
