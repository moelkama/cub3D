/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:42:59 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_img	*get_texture(t_info *info, t_intersection *position)
{
	if (position->direct == 0)
		return (info->ea);
	if (position->direct == 1)
		return (info->no);
	if (position->direct == 2)
		return (info->we);
	return (info->so);
}

int	get_m(t_info *info, t_intersection *position, int width)
{
	float	m;

	if (position->direct == 0 || position->direct == 2)
		m = (float)(fmod(position->y, info->size) / info->size);
	else
		m = (float)(fmod(position->x, info->size) / info->size);
	return (m * width);
}
