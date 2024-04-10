/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:07:38 by glemoine          #+#    #+#             */
/*   Updated: 2022/07/28 14:32:24 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_free() frees a pointer and sets it to NULL.
 * 
 * @param ptr The pointer to the pointer to the data you want to free.
 * 
 * @return A pointer to a pointer to a void.
 */
void	ft_free(void *ptr)
{
	void	**data;

	data = (void **)ptr;
	if (!*data)
		return ;
	free(*data);
	*data = NULL;
}

int	ft_mid_free_int(void *ptr, int res)
{
	ft_free(ptr);
	return (res);
}
