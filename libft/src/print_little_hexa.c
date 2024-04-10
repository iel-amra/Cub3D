/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_little_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:05:53 by iel-amra          #+#    #+#             */
/*   Updated: 2023/02/06 15:24:08 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_long_hexa(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_little_hexa(va_list args, char *flags, int fd)
{
	long int	nb;
	int			len;
	int			prec;

	nb = (long int) va_arg(args, unsigned int);
	len = len_long_hexa(nb);
	prec = preci(flags);
	while (prec > len)
	{
		(void)!write(fd, "0", 1);
		len++;
	}
	ft_putulong_hexa((unsigned long) nb, 87, fd);
	return (0);
}

int	len_print_little_hexa(va_list args, char *flags)
{
	va_list		dup_args;
	long int	nb;
	int			len;
	int			prec;

	va_copy(dup_args, args);
	nb = va_arg(dup_args, unsigned int);
	va_end(dup_args);
	len = len_long_hexa(nb);
	prec = preci(flags);
	while (prec > len)
		len++;
	return (len);
}
