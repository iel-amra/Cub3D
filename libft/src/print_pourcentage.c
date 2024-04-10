/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pourcentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:14:00 by iel-amra          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:03 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pourcentage(va_list args, char *flags, int fd)
{
	(void) args;
	(void) flags;
	(void)!write(fd, "%", 1);
	return (0);
}

int	len_print_pourcentage(va_list args, char *flags)
{
	(void) args;
	(void) flags;
	return (1);
}
