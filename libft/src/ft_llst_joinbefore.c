/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_joinbefore.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:28:30 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/16 17:19:16 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It joins a linked list to another linked list before a given element
 * 
 * @param llst the first element of the linked list
 * @param actual the element before which you want to insert the new element
 * @param new the new list to join
 * 
 * @return 1 if no new else 0.
 */
int	ft_llst_joinbefore(t_llst **llst, t_llst *actual, t_llst *new)
{
	t_llst	*last_new;

	if (!new)
		return (EXIT_FAILURE);
	last_new = ft_llst_getlast(new);
	if (actual->prev)
		actual->prev->next = new;
	last_new->next = actual;
	new->prev = actual->prev;
	actual->prev = last_new;
	if (*llst == actual)
		*llst = new;
	return (EXIT_SUCCESS);
}
