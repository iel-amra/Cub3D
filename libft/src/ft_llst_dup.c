/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:59:30 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:29:06 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_dup(t_llst *src, void *(*fdup)(void *), void (*fr)(void *))
{
	t_llst	*new;

	new = (void *)0;
	while (src)
	{
		if (ft_llst_addback(&new, ft_llst_new(fdup(src->data), fr)))
		{
			ft_llst_clear(&new, fr);
			return (NULL);
		}
		src = src->next;
	}
	return (new);
}
