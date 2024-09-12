/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:12:14 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	rotate_with_mouse(int x, int y, t_info *data)
{
	static int	x_win;

	if ((x >= 0 && x <= data->window->width)
		&& (y >= 0 && y <= data->window->hight))
	{
		if (x < x_win)
			data->move->teta += 0.07;
		else if (x > x_win)
			data->move->teta -= 0.07;
		put_vector(data);
		ft_putmini_map(data);
	}
	x_win = x;
	return (0);
}
