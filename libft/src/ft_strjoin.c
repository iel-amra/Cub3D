/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:41:24 by glemoine          #+#    #+#             */
/*   Updated: 2022/11/28 16:49:38 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjoin_cpy(char *dst, char *src)
{
	int	i;

	if (!src)
		return (0);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	return (i);
}

/**
 * It joins three strings together, and frees them if you want it to
 * 
 * @param s1 The first string to join.
 * @param s2 The string to be appended to s1.
 * @param s3 The string to be appended to the end of the new string.
 * @param opt 1 = free s1, 2 = free s2, 4 = free s3
 * 
 * @return A pointer to a string.
 */
char	*ft_strjoin(char *s1, char *s2, char *s3, t_bool opt)
{
	char	*dst;
	size_t	size1;
	size_t	size2;
	size_t	size3;
	size_t	i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size3 = ft_strlen(s3);
	dst = ft_errifnul(malloc((size1 + size2 + size3 + 1) \
	* sizeof(char)), "malloc error", NULL, NULL);
	i = 0;
	i += ft_strjoin_cpy(dst, s1);
	i += ft_strjoin_cpy(dst + i, s2);
	i += ft_strjoin_cpy(dst + i, s3);
	dst[size1 + size2 + size3] = '\0';
	if (s1 && opt & 1)
		free(s1);
	if (s2 && opt & 2)
		free(s2);
	if (s3 && opt & 4)
		free(s3);
	return (dst);
}
