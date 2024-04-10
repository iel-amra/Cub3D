/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:16:24 by mapontil          #+#    #+#             */
/*   Updated: 2023/02/06 17:37:32 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	read_in_t_llst(t_llst *my_strings, int fd)
{
	int		read_return;
	t_llst	*travel;
	char	*content;

	read_return = 1;
	travel = my_strings;
	content = (char *)travel->data;
	while (!ft_strchr(content, '\n') && read_return > 0)
	{
		travel->next = ft_llst_new(ft_errifnul(malloc((BUFFER_SIZE + 1) * \
			sizeof(char)), "malloc error", NULL, NULL), free);
		if (!travel->next)
		{
			ft_llst_clear(&my_strings, free);
			return (1);
		}
		travel = travel->next;
		content = (char *)travel->data;
		read_return = read(fd, content, BUFFER_SIZE);
		if (read_return == -1 && !ft_llst_clear(&my_strings, free))
			return (1);
		content[read_return] = '\0';
	}
	return (0);
}

char	*ft_custom_strcpy(char *dst, char *src, int mode)
{
	int	i;

	i = 0;
	while (src[i] && (src[i] != '\n' || mode == 0))
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (dst + i);
}

char	*malloc_final(t_llst *my_strings)
{
	int		len;
	char	*sp_pos;
	char	*content;

	len = 1;
	while (my_strings)
	{
		content = my_strings->data;
		sp_pos = ft_strchr(content, '\n');
		if (!sp_pos)
			len += ft_strlen(content);
		else
			len += sp_pos - content + 1;
		my_strings = my_strings->next;
	}
	if (len == 1)
		return ((void *) 0);
	return (malloc(len));
}

char	*get_final(t_llst *my_strings)
{
	char	*final;
	char	*travel;

	final = malloc_final(my_strings);
	if (!final)
	{
		ft_llst_clear(&my_strings, free);
		return ((void *) 0);
	}
	travel = final;
	while (my_strings)
	{
		travel = ft_custom_strcpy(travel, (char *)my_strings->data, 1);
		my_strings = my_strings->next;
	}
	return (final);
}

char	*get_next_line(int fd)
{
	static char	ending[FOPEN_MAX][BUFFER_SIZE];
	t_llst		*my_strings;
	char		*final;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return ((void *) 0);
	my_strings = ft_llst_new(ft_errifnul(malloc((ft_strlen(ending[fd]) \
		+ 1) * sizeof(char)), "malloc error", NULL, NULL), free);
	if (!my_strings)
		return ((void *) 0);
	ft_custom_strcpy((char *)my_strings->data, ending[fd], 0);
	if (read_in_t_llst(my_strings, fd))
		return ((void *) 0);
	final = get_final(my_strings);
	if (!final)
		return ((void *) 0);
	ft_llst_ndel(&my_strings, my_strings, ft_llst_size(my_strings) - 1, free);
	if (ft_strchr((char *)my_strings->data, '\n'))
		ft_custom_strcpy(ending[fd],
			ft_strchr((char *)my_strings->data, '\n') + 1, 0);
	else
		ft_custom_strcpy(ending[fd], "\0", 0);
	ft_llst_clear(&my_strings, free);
	return (final);
}
