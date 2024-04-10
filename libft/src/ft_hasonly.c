/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasonly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:17:09 by glemoine          #+#    #+#             */
/*   Updated: 2022/08/11 15:11:15 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns 1 if the data is all the same value, and 0 otherwise
 * 
 * @param data the data to be checked
 * @param value the value to check for
 * @param len_data the length of the data
 * @param size_value the size of the value you're looking for
 * 
 * @return 1 if the data has only the value, 0 otherwise.
 */
int	ft_hasonly(void *data, void *value, size_t len_data, size_t size_value)
{
	size_t	i;

	if (len_data % size_value != 0)
		return (0);
	i = 0;
	while (i < len_data)
	{	
		if (ft_memcmp(data + i, value, size_value) != 0)
			return (0);
		i += size_value;
	}
	return (1);
}
