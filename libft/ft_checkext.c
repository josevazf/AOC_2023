/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:24:14 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:37:16 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if file name 'str' has the given extension 'ext'. */
int	ft_checkext(char *str, char *ext)
{
	int	str_len;

	str_len = ft_strlen(str);
	return (ft_strncmp(str + str_len - ft_strlen(ext), ext, str_len));
}
