/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:38:39 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 13:23:18 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_map_lines(char *map, t_program *prog)
{
	(void)prog;
	while (*map == '\n')
		map++;
	while (*map && (*map != '\n' || *(map + 1) != '\n'))
		map++;
	if (*map)
		map++;
	while (*map && *map == '\n')
		map++;
	if (*map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_map_chars(char *map, t_program *prog)
{
	int	p;

	p = 0;
	while (*map)
	{
		if (!(*map == CHAR_EMPTYSPC || *map == CHAR_WALL || *map == CHAR_P_O_N
				|| *map == CHAR_P_O_E || *map == CHAR_P_O_O
				|| *map == CHAR_P_O_S
				|| *map == CHAR_SPC || *map == '\n'))
			ft_errifnul(NULL, ERR_MAP_UNKNOWCHAR, cleanandexit, prog);
		if (*map == CHAR_P_O_N || *map == CHAR_P_O_E || *map == CHAR_P_O_O
			|| *map == CHAR_P_O_S)
			p++;
		map++;
	}
	ft_errorif(p == 0, ERR_MAP_NOPLAYER, cleanandexit, prog);
	ft_errorif(p > 1, ERR_MAP_TOOMUCHPLAYER, cleanandexit, prog);
}

void	check_map_wall(char **map, t_program *prog)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!(map[y][x] == CHAR_SPC || map[y][x] == CHAR_WALL))
			{
				if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1]
					|| x >= ft_strlen(map[y - 1]) || x >= ft_strlen(map[y + 1]))
					ft_errifnul(NULL, ERR_MAP_INVALIDWALL, cleanandexit, prog);
				if (map[y][x + 1] == CHAR_SPC || map[y + 1][x] == CHAR_SPC)
					ft_errifnul(NULL, ERR_MAP_INVALIDWALL, cleanandexit, prog);
				if (map[y - 1][x] == CHAR_SPC || map[y][x - 1] == CHAR_SPC)
					ft_errifnul(NULL, ERR_MAP_INVALIDWALL, cleanandexit, prog);
			}
		}
	}
}
