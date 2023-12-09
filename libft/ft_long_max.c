/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:36:10 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/12/09 18:28:59 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Get max value between two longs 'x' and 'y'. */
long	ft_long_max(long x, long y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}
