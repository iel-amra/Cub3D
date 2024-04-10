/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_ndel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:29:40 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/21 19:03:43 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It deletes n elements from a linked list, starting from the element pointed 
 * to by e
 * 
 * @param list the list to delete from
 * @param e the element to start deleting from
 * @param n the number of elements to delete
 * @param f the function to be called on each element of the list
 * 
 * @return The element after the last element that was deleted.
 */
t_llst	*ft_llst_ndel(t_llst **list, t_llst *e, int n, void (*f)(void *))
{
	if (!e)
		return (NULL);
	while (n-- && e)
		e = ft_llst_del(list, e, f);
	return (e);
}
