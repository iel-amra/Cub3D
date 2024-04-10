/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:31:51 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:46:20 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It adds a new node to the end of a list
 * 
 * @param lst a pointer to a pointer to a t_llst.
 * @param new The new node to be added to the list.
 */

int	ft_llst_addback(t_llst **lst, t_llst *new)
{
	t_llst	*last;

	if (!new)
		return (EXIT_FAILURE);
	last = ft_llst_getlast(*lst);
	if (last)
		ft_llst_insert(last, new);
	else
		ft_llst_addfront(lst, new);
	return (EXIT_SUCCESS);
}
