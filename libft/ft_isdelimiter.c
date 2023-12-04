/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdelimiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:59:48 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:37:50 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if character 'c' is the same as char 's'. */
int	ft_isdelimiter(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}
