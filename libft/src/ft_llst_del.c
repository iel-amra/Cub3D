/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:35:10 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/21 19:01:23 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It deletes the element `e` from the list `list` and returns the next 
 * element in the list
 * 
 * @param list a pointer to the list
 * @param e the element to delete
 * @param f a function that will be called on the data of the element 
 * to be deleted.
 * 
 * @return The next element in the list.
 */
t_llst	*ft_llst_del(t_llst **list, t_llst *e, void (*f)(void *))
{
	t_llst	*tmp;

	if (!list || !e || !*list)
		return (NULL);
	if (e->prev)
		e->prev->next = e->next;
	if (e->next)
		e->next->prev = e->prev;
	tmp = e->next;
	if (e == *list)
		*list = tmp;
	if (f)
		f(e->data);
	free(e);
	return (tmp);
}
