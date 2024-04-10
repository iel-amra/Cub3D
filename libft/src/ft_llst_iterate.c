/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_iterate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:07:25 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:29:21 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llst_iterate(t_llst *list, void (*f)(void *))
{
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}
