/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:02:59 by iel-amra          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:35 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

#define ERR_ATOI_OVERFLOW "the number is bigger than INT_MAX"
#define ERR_ATOI_OTHERCHAR "numbers to be converted need to only have digits"
#define ERR_ATOI_TOOMUCH "the number is too much"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	nb = 0;
	neg = -1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 - str[i] + 48;
		i++;
	}
	nb *= neg;
	return (nb);
}

int	ft_atoi_basique(char *str)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		ft_errorif(!(str[i] >= 48 && str[i] <= 57), \
		ERR_ATOI_OTHERCHAR, NULL, NULL);
		nb = nb * 10 - str[i] + 48;
		ft_errorif(nb > INT_MAX, ERR_ATOI_OVERFLOW, NULL, NULL);
		i++;
	}
	return (nb);
}
