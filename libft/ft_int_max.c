/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:36:10 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:37:32 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Get max value between 'x' and 'y'. */
int	ft_int_max(int x, int y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}
