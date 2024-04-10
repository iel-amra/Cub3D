/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_del_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:42:50 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:27:36 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llst_del_if(t_llst **list, int (*cmp)(void *, void *),
		void *data_tocmp)
{
	t_llst	*e;
	t_llst	*next;

	e = *list;
	while (e)
	{
		next = e->next;
		if (cmp(e->data, data_tocmp))
			ft_llst_del(list, e, free);
		e = next;
	}
}
