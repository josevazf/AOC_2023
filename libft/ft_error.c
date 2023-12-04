/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:16:28 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/10/27 14:37:24 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return an error with message 'msg' and given exit code. */
void	ft_error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}
