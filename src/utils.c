/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:43:27 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 13:32:33 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	call_mappedfct(t_program *prog, t_dict_item *tab, \
	char *id, void *args)
{
	int		i;
	int		(*f)(t_program *, void *);

	i = 0;
	while (tab[i].id)
	{
		if (!ft_strcmp(tab[i].id, id))
		{
			f = tab[i].data;
			return (f(prog, args));
		}
		i++;
	}
	return (-1);
}

void	*get_mappedfunction(t_program *prog, t_dict_item *tab, \
	char *id)
{
	int	i;

	(void) prog;
	i = 0;
	while (tab[i].id)
	{
		if (!ft_strcmp(tab[i].id, id))
			return (tab[i].data);
		i++;
	}
	return (NULL);
}

int	file_open(char *map_filename, t_program *prog)
{
	int	fd;

	ft_errorif(ft_strncmp(map_filename + ft_max((int)ft_strlen(map_filename) \
	- 4, 0), ".cub", 4) != 0, ERR_FILE_EXTENSION, cleanandexit, prog);
	fd = open(map_filename, O_RDONLY);
	ft_errorif(fd == -1, ERR_FILE_BAD, cleanandexit, prog);
	return (fd);
}

int	convert_from_rgb(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
		return (-1);
	return (((int)r << 16) | ((int)g << 8) | (int)b);
}

int	ft_atoi_basique_max(char *str, int max)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		nb = nb * 10 + str[i] - 48;
		if (nb > max || nb > INT_MAX)
			return (-1);
		i++;
	}
	return ((int) nb);
}
