/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:12:23 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/21 20:27:51 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Inserts a new node after the actual node
 * 
 * @param actual the actual t_llst element
 * @param new the new node to be inserted
 */

int	ft_llst_insert(t_llst *actual, t_llst *new)
{
	if (!actual || !new)
		return (EXIT_FAILURE);
	if (actual->next)
	{
		actual->next->prev = new;
		new->next = actual->next;
	}
	actual->next = new;
	new->prev = actual;
	return (EXIT_SUCCESS);
}
