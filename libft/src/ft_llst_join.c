/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <iel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:26:08 by iel-amra          #+#    #+#             */
/*   Updated: 2022/06/21 11:27:10 by iel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It joins two linked lists together
 * 
 * @param actual the actual element of the linked list
 * @param new the list to be joined after the actual element
 * 
 * @return The last element of the list.
 */

int	ft_llst_join(t_llst *actual, t_llst *new)
{
	t_llst	*last_new;

	if (!new)
		return (EXIT_FAILURE);
	last_new = ft_llst_getlast(new);
	if (actual->next)
	{
		actual->next->prev = last_new;
		last_new->next = actual->next;
	}
	actual->next = new;
	new->prev = actual;
	return (EXIT_SUCCESS);
}
