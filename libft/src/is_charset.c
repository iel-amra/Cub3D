/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:06:22 by iel-amra          #+#    #+#             */
/*   Updated: 2022/08/21 16:46:30 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_charset(char c, char *charset)
{
	if (!charset)
		return (0);
	while (*charset)
	{
		if (c == *(charset++))
			return (1);
	}
	return (0);
}
