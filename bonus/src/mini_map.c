/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:58:39 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mlx_put_pixel(t_info *data, int x, int y, int color)
{
	int	old_y;
	int	old_x;

	old_y = y;
	old_x = x;
	while (y <= old_y + 10)
	{
		x = old_x;
		while (x <= old_x + 10)
		{
			mlx_pixel_put(data->mlx, data->window->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_put_ray(float *i, float *j, float alpha, t_info *data)
{
	*i += cos(alpha);
	*j -= sin(alpha);
	mlx_pixel_put(data->mlx, data->window->win,
		(int)*i, (int)*j, 0XFFCB47);
}

void	ft_give_v(int *y, int *x, float *x_player, float *y_player)
{
	*y += (10 / 2);
	*x += (10 / 2);
	*y_player = *y - 3;
	*x_player = *x - 2;
}

void	put_player(t_info *data, int x, int y, int color)
{
	float	x_player;
	float	y_player;
	float	i;
	float	j;
	float	alpha;

	ft_give_v(&y, &x, &x_player, &y_player);
	while (++y_player < y + 2)
	{
		x_player = x - 2;
		while (x_player < x + 2)
			mlx_pixel_put(data->mlx, data->window->win,
				x_player++, y_player, color);
	}
	alpha = data->move->teta - M_PI / 6;
	while (alpha < data->move->teta + M_PI / 6)
	{
		i = x;
		j = y;
		while ((int )sqrt(pow(i - x, 2) + pow(j - y, 2)) < 10)
			ft_put_ray(&i, &j, alpha, data);
		alpha += 0.1;
	}
}

void	ft_putmini_map(t_info *data)
{
	t_mini_map	mini;

	give_mini_map_value(&mini, data);
	while (mini.start_y < mini.end_y)
	{
		mini.start_x = mini.tmp;
		mini.x = 1;
		while (mini.start_x < mini.end_x)
		{
			ft_put_color(data, &mini);
			mini.x++;
			mini.start_x++;
		}
		mini.y++;
		mini.start_y++;
	}
	ft_mlx_put_pixel(data, mini.x_mini_map * 10, mini.y_mini_map * 10, 8886451);
	put_player(data, mini.x_mini_map * 10, mini.y_mini_map * 10, 167769);
}
