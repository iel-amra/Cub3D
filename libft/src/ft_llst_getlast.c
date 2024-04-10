/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_getlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <iel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:59 by iel-amra          #+#    #+#             */
/*   Updated: 2022/06/21 11:32:33 by iel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst	*ft_llst_getlast(t_llst *list)
{
	if (list)
	{
		while (list->next)
			list = list->next;
	}
	return (list);
}
