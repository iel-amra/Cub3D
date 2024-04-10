/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:59:35 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:24 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freeall(char **res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free (res);
	return (NULL);
}

static char	*split_strndup(char *dst, char *src, int size)
{
	int	i;

	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (ft_errifnul(NULL, "split_strndup malloc error\n", NULL, NULL));
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_wordlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		i = ft_wordlen(str, c);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

char	**ft_split(char const *str, char c)
{
	char		**dest;
	int			size;
	int			i;
	int			j;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_wordcount(str, c);
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (0);
	while (i < size)
	{
		while (*str == c)
			str++;
		j = ft_wordlen(str, c);
		dest[i] = split_strndup(dest[i], (char *) str, j);
		if (!dest[i])
			return (ft_freeall(dest, i));
		str += j;
		i++;
	}
	dest[size] = 0;
	return (dest);
}
