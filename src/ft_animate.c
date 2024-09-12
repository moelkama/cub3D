/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:33:09 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:12:15 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handling_wall(char **map)
{
	int	y;
	int	x;

	if (!map)
		return (0);
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (ft_check("0NSEW", map[x][y]))
			{
				if (x == 0 || ft_len_line(map) - 1 == x)
					return (0);
				else if (!ft_check("10NSEW", map[x + 1][y])
					|| !ft_check("10NSEW", map[x - 1][y]) ||
						!ft_check("10NSEW", map[x][y + 1])
						|| !ft_check("10NSEW", map[x][y - 1]))
					return (0);
			}
		}
	}
	return (1);
}
