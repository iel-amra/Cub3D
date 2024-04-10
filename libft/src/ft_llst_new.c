/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:10:59 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:29:56 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_new(void *data, void (*f)(void *))
{
	t_llst	*new;

	if (!data)
		return (NULL);
	new = malloc(sizeof(t_llst));
	if (!new)
	{
		f(data);
		return (NULL);
	}
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
