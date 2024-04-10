/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_sizeif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:44:28 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:30:19 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llst_sizeif(t_llst *list, int (*cmp)(void *, void *), void *data_tocmp)
{
	int	size;

	size = 0;
	while (list)
	{
		if (cmp(list->data, data_tocmp))
			size++;
		list = list->next;
	}
	return (size);
}
