/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:50:20 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/06 15:41:02 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	next_move(t_info *info, float alpha)
{
	t_intersection	*position;

	position = get_intersection(info, alpha);
	if ((int )position->ray <= 10)
		return (free(position), 0);
	return (free(position), 1);
}

void	move_up(t_info *info, float alpha)
{
	if (next_move(info, alpha))
	{
		info->move->x += cos(alpha) * info->move->vites;
		info->move->y -= sin(alpha) * info->move->vites;
	}
	put_vector(info);
}

void	move_theta(t_info *info, int k)
{
	info->move->teta += k * info->move->teta_vites;
	if (info->move->teta >= 2 * M_PI)
		info->move->teta -= 2 * M_PI;
	else if (info->move->teta <= -2 * M_PI)
		info->move->teta += 2 * M_PI;
	put_vector(info);
}

int	move(int key, t_info *info)
{
	if ((key == 13 || key == 126))
		info->move_up = 1;
	else if ((key == 1 || key == 125))
		info->move_down = 1;
	else if (key == 0)
		info->move_right = 1;
	else if (key == 2)
		info->move_left = 1;
	else if (key == 123)
		info->rotation_right = 1;
	else if (key == 124)
		info->rotation_left = 1;
	else if (key == 53)
		exit (0);
	return (0);
}
