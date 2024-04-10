/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_nextif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:24:41 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/15 20:29:55 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_nextif(t_llst *llst, int (*cmp)(void *, void *), void *ref)
{
	if (!llst || !cmp || !ref)
		return (NULL);
	llst = llst->next;
	while (llst && cmp(llst, ref))
		llst = llst->next;
	return (llst);
}
