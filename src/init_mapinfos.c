/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:35:05 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 13:48:31 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#define NBR_MAP_INFOS 6

int	init_color_info(t_program *prog, void *args)
{
	char	**data;
	int		*value;

	data = (char **)args;
	if (**data == 'F')
		value = &prog->color_floor;
	else if (**data == 'C')
		value = &prog->color_ceilling;
	else
		return (0);
	ft_errorif(*value != -1, ERR_PARSING_MAPINFOSTOOMUCH, cleanandexit, prog);
	if (!*(data + 1) || (*(data + 2)))
		return (EXIT_FAILURE);
	data[1][ft_strlen(data[1]) - 1] = '\0';
	prog->colorinfos = ft_errifnul(ft_split(*(data + 1), ','), ERR_MALLOC,
			cleanandexit, prog);
	ft_errorif(!*prog->colorinfos || !*(prog->colorinfos + 1)
		|| !*(prog->colorinfos + 2) || *(prog->colorinfos + 3),
		ERR_PARSING_COLOR, cleanandexit, prog);
	*value = convert_from_rgb(ft_atoi_basique_max(*prog->colorinfos, 255), \
	ft_atoi_basique_max(*(prog->colorinfos + 1), 255), \
	ft_atoi_basique_max(*(prog->colorinfos + 2), 255));
	ft_errorif(*value == -1, ERR_PARSING_COLOR, cleanandexit, prog);
	ft_mid_free_array(&prog->colorinfos, 0);
	return (0);
}

int	init_texture_info(t_program *prog, void *args)
{
	char	**data;
	t_img	*img;

	data = args;
	ft_errorif(!(*(data + 1)) || *(data + 2), ERR_PARSING_MAPINFOS,
		cleanandexit, prog);
	data[1][ft_strlen(data[1]) - 1] = '\0';
	img = &prog->sprites[(unsigned long)get_mappedfunction(prog,
			(t_dict_item *)g_mapinfosspritesindex,
			*data)];
	ft_errorif(img->sprite_ptr != NULL, ERR_PARSING_MAPINFOSTOOMUCH,
		cleanandexit, prog);
	img->sprite_ptr = ft_errifnul(mlx_xpm_file_to_image(prog->mlx, \
		*(data + 1), &img->width, &img->height), ERR_OPEN_TEXTURE, \
		cleanandexit, prog);
	img->addr = ft_errifnul(mlx_get_data_addr(img->sprite_ptr, \
		&img->bit_per_pixel, &img->size_line, &img->endian), \
			ERR_OPEN_TEXTURE, cleanandexit, prog);
	return (0);
}

int	init_mapinfos(t_program *prog, int fd)
{
	int	i;

	prog->color_ceilling = -1;
	prog->color_floor = -1;
	i = 0;
	while (i < NBR_MAP_INFOS)
	{
		prog->line = get_next_line(fd);
		if (!prog->line)
			break ;
		if ((prog->line && *prog->line == '\n' && ft_mid_free_int(&prog->line,
					1)) || ++i < 0)
			continue ;
		prog->mapinfos = ft_errifnul((void *)ft_split(prog->line, ' '),
				ERR_MALLOC, cleanandexit, prog);
		if (call_mappedfct(prog, (t_dict_item *)g_mapinfosfunctions,
				*prog->mapinfos, prog->mapinfos) != 0)
			ft_errorif(ft_mid_free_int(&prog->line, 1), ERR_PARSING_MAPINFOS, \
			cleanandexit, prog);
		ft_mid_free_array(&prog->mapinfos, 0);
		ft_free(&prog->line);
	}
	ft_errorif(i != NBR_MAP_INFOS, ERR_PARSING_NBRMAPINFOS, cleanandexit, prog);
	return (EXIT_SUCCESS);
}
