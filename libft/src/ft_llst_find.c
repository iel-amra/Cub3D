/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:04:04 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/22 11:10:56 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Finds the first element in the list that matches the data
 * 
 * @param list The list to search through.
 * @param data the data to find
 * @param cmp a function that takes two void pointers and returns an int.
 * 
 * @return A pointer to the first node in the list that matches the data.
 */

t_llst	*ft_llst_find(t_llst *list, void *data, int (*cmp)(void *, void *))
{
	while (list)
	{
		if (cmp(list->data, data))
			return (list);
		list = list->next;
	}
	return (NULL);
}
