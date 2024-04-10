/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:13:32 by glemoine          #+#    #+#             */
/*   Updated: 2022/07/20 15:43:49 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * It closes a file descriptor, but only if it's not 0, 1, or 2
 * 
 * @param fd The file descriptor of the file to close.
 * 
 * @return The return value of close() is 0 on success, or -1 on error.
 */
int	ft_close(int fd)
{
	if (fd != -1 && fd != 0 && fd != 1 && fd != 2)
		return (close(fd));
	return (0);
}
