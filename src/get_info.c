/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:58:40 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/02 17:45:21 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_position(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'N')
	{
		info->move->teta = M_PI / 2;
		info->map[i][j] = '0';
		return (0);
	}
	else if (info->map[i][j] == 'S')
	{
		info->move->teta = -M_PI / 2;
		info->map[i][j] = '0';
		return (0);
	}
	else if (info->map[i][j] == 'E')
	{
		info->move->teta = 0;
		info->map[i][j] = '0';
		return (0);
	}
	else if (info->map[i][j] == 'W')
	{
		info->move->teta = M_PI;
		info->map[i][j] = '0';
		return (0);
	}
	return (1);
}

void	begin_status(t_info *info)
{
	int	i;
	int	j;

	info->move->vites = 10;
	info->move->teta_vites = M_PI / 24;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			info->move->x = j * info->size + info->size / 2;
			info->move->y = i * info->size + info->size / 2;
			if (!get_position(info, i, j++))
				return ;
		}
		i++;
	}
}
