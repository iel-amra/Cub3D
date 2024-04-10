/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:41 by glemoine          #+#    #+#             */
/*   Updated: 2022/07/28 19:33:14 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It frees an array of pointers, and returns a pointer res
 * 
 * @param ptr the pointer to the array of pointers to free
 * @param res the return value of the function
 * 
 * @return res, a pointer
 */
void	*ft_mid_free_array(void *ptr, void *res)
{
	void	***array;
	int		i;

	array = (void ***)ptr;
	i = 0;
	while (array && *array && (*array)[i])
		ft_free(*array + i++);
	if (array)
		ft_free(array);
	return (res);
}

void	*ft_mid_free(void **pvar, void *res)
{
	if (pvar)
		free(*pvar);
	*pvar = NULL;
	return (res);
}
