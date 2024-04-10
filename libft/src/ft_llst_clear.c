/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:34:28 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/24 18:21:37 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It clears a linked list
 * 
 * @param list the list to clear
 * @param f a function that will be called on each element of the list.
 * 
 * @return Always EXIT_SUCCESS (0)
 */
int	ft_llst_clear(t_llst **list, void (*f)(void *))
{
	t_llst	*tmp;

	while (list && *list)
	{
		tmp = (*list)->next;
		if (f)
			f((*list)->data);
		free(*list);
		*list = tmp;
	}
	return (EXIT_SUCCESS);
}
