/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorifnull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:23:02 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:30:54 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_errifnul(void *res_funct, char *error_name, \
	void (*f_free) (void *), void *data_free)
{
	if (!res_funct)
	{
		ft_putstr_fd(error_name, 2);
		if (data_free)
			f_free(data_free);
		exit(EXIT_FAILURE);
	}
	return (res_funct);
}

void	ft_errorif(int condition, char *error_name, \
	void (*f_free) (void *), void *data_free)
{
	if (condition)
		ft_errifnul(NULL, error_name, f_free, data_free);
}
