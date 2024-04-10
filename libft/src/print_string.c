/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:58:17 by iel-amra          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:10 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"

static void	ft_putnstr(char *str, int n, int fd)
{
	while (*str && n != 0)
	{
		(void)!write (fd, str, 1);
		str++;
		n--;
	}
}

int	preci(char *flags)
{
	if (!ft_strchr(flags, '.'))
		return (-1);
	while (*flags && *flags != '.')
		flags++;
	flags++;
	return (ft_atoi(flags));
}

int	print_string(va_list args, char *flags, int fd)
{
	char	*str;
	int		precision;

	(void) flags;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	precision = preci(flags);
	ft_putnstr(str, precision, fd);
	return (0);
}

int	len_print_string(va_list args, char *flags)
{
	char	*str;
	int		len;
	int		precision;
	va_list	dup_args;

	(void) flags;
	va_copy(dup_args, args);
	str = va_arg(dup_args, char *);
	va_end(dup_args);
	if (!str)
		str = "(null)";
	precision = preci(flags);
	len = ft_strlen(str);
	if (precision < len && precision >= 0)
		return (precision);
	return (ft_strlen(str));
}
