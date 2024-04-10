/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:19:17 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/22 12:36:13 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It extracts a sublist from a list, and returns the extracted sublist
 * including begin and excluding end.
 * 
 * @param llst the address of the pointer to the first element of the list
 * @param begin the first element of the list to extract
 * @param end the last element of the list to extract
 * 
 * @return A pointer to the first element of the extracted list.
 */
t_llst	*ft_llst_extract(t_llst **llst, t_llst *begin, t_llst *end)
{
	t_llst	*tmp;

	if (!begin || !llst || begin == end)
		return (NULL);
	if (*llst == begin)
		*llst = end;
	else
		begin->prev->next = end;
	tmp = begin->prev;
	begin->prev = NULL;
	if (!end)
		return (begin);
	end->prev->next = NULL;
	end->prev = tmp;
	return (begin);
}
