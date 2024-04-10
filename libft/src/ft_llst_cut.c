/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:45:06 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/18 20:36:30 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It cuts a linked list at a given node, and returns the cutted part
 * 
 * @param node the node to start cutting from
 * @param nb the number of nodes to del
 * @param f a function that will be called on each node's data before deleting 
 * it.
 * 
 * @return A pointer to the first node of the list.
 */
t_llst	*ft_llst_cut(t_llst *node, int nb, void (*f)(void *))
{
	if (!node)
		return ((void *)0);
	if (node->prev)
	{
		node->prev->next = (void *)0;
		node->prev = (void *)0;
	}
	while (nb-- > 0)
		node = ft_llst_del(&node, node, f);
	return (node);
}
