/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:20:10 by glemoine          #+#    #+#             */
/*   Updated: 2022/07/25 18:32:40 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	int		len;
	char	*dst;

	len = ft_strlen(src);
	if (n < len)
		len = n;
	dst = ft_errifnul(malloc((len + 1) * sizeof(char)), \
			"ft_strndup malloc error\n", NULL, NULL);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
