/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:04:47 by glemoine          #+#    #+#             */
/*   Updated: 2022/01/08 15:35:09 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

int	ft_open(char *path, int file_descriptors, int rights)
{
	int	fd;

	fd = open(path, file_descriptors, rights);
	if (fd < 0)
		ft_errifnul(NULL, path, NULL, NULL);
	return (fd);
}
