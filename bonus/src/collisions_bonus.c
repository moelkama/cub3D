/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:55:04 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		return (0);
	return (1);
}

void	collisions(t_info *info, float alpha)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	y1 = (int )info->move->x / info->size;
	x1 = (int )(info->move->y - info->move->vites) / info->size;
	x2 = (int )(info->move->y + info->move->vites) / info->size;
	if (sin(alpha) > 0 && check(info, x1, y1))
		info->move->y -= info->move->vites;
	else if (sin(alpha) < 0 && check(info, x2, y1))
		info->move->y += info->move->vites;
	x1 = (int )info->move->y / info->size;
	y1 = (int )(info->move->x + info->move->vites) / info->size;
	y2 = (int )(info->move->x - info->move->vites) / info->size;
	if (cos(alpha) > 0 && check(info, x1, y1))
		info->move->x += info->move->vites;
	else if (cos(alpha) < 0 && check(info, x1, y2))
		info->move->x -= info->move->vites;
}
