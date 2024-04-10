/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_reverse_iterate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:08:26 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:30:05 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llst_reverse_iterate(t_llst *list, void (*f)(void *))
{
	if (list)
	{
		ft_llst_reverse_iterate(list->prev, f);
		f(list->data);
	}
}
