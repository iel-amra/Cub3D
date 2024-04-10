/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:29:50 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:46:23 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It adds a new node to the front of a doubly linked list.
 * 
 * @param lst a pointer to a pointer to a t_llst.
 * @param new The new node to add to the list.
 */

int	ft_llst_addfront(t_llst **lst, t_llst *new)
{
	if (!new)
		return (EXIT_FAILURE);
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	return (EXIT_SUCCESS);
}
