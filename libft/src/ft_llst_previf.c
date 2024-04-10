/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_previf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:33:19 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/15 20:35:25 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_previf(t_llst *llst, int (*cmp)(void *, void *), void *ref)
{
	if (!llst || !llst->prev || !cmp || !ref)
		return (NULL);
	llst = llst->prev;
	while (llst && cmp(llst, ref))
		llst = llst->prev;
	return (llst);
}
