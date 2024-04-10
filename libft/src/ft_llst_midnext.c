/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_midnext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:03:14 by iel-amra          #+#    #+#             */
/*   Updated: 2022/07/25 18:29:32 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_midnext(t_llst **list)
{
	t_llst	*e;

	e = *list;
	*list = e->next;
	return (e);
}
