/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_isall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:30:59 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/11 17:25:48 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llst_isall(t_llst *list, void *ref, int (*f)(void *, void *))
{
	while (list)
	{
		if (!f(list, ref))
			return (0);
		list = list->next;
	}
	return (1);
}
