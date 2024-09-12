/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:33:09 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_weapon	*new_weapon(void)
{
	t_weapon	*ptr;

	ptr = malloc(sizeof(t_weapon));
	if (!ptr)
		return (NULL);
	ptr->w1 = new_img();
	ptr->w2 = new_img();
	ptr->w3 = new_img();
	ptr->w4 = new_img();
	return (ptr);
}

void	ft_do_event(t_info *data)
{
	static int	c;

	c++;
	if (c == 2)
		mlx_put_image_to_window(data->mlx,
			data->window->win, data->weapon->w2->img,
			(data->window->width - 128) / 2, data->window->hight - 128);
	else if (c == 4)
		mlx_put_image_to_window(data->mlx, data->window->win,
			data->weapon->w3->img, (data->window->width - 128) / 2,
			data->window->hight - 128);
	else if (c == 6)
		mlx_put_image_to_window(data->mlx, data->window->win,
			data->weapon->w4->img, (data->window->width - 128) / 2,
			data->window->hight - 128);
	else if (c == 9)
	{
		mlx_put_image_to_window(data->mlx, data->window->win,
			data->weapon->w1->img, (data->window->width - 128) / 2,
			data->window->hight - 128);
		data->event_p = 0;
		c = 0;
	}
}

int	do_event(t_info *data)
{
	if (data->move_up == 1)
		move_up(data, data->move->teta);
	if (data->move_down == 1)
		move_up(data, data->move->teta + M_PI);
	if (data->move_right == 1)
		move_up(data, data->move->teta + M_PI / 2);
	if (data->move_left == 1)
		move_up(data, data->move->teta - M_PI / 2);
	if (data->rotation_right == 1)
		move_theta(data, 1);
	if (data->rotation_left == 1)
		move_theta(data, -1);
	if (data->event_p == 1)
	{
		put_vector(data);
		ft_do_event(data);
	}
	return (0);
}

void	ft_putplayer_img(t_info *data)
{
	data->weapon->w1->img = mlx_xpm_file_to_image(data->mlx,
			"bonus/photo xpm/weapon/weapon_0.xpm",
			&data->weapon->w1->width, &data->weapon->w1->hight);
	data->weapon->w2->img = mlx_xpm_file_to_image(data->mlx,
			"bonus/photo xpm/weapon/weapon_1.xpm",
			&data->weapon->w2->width, &data->weapon->w2->hight);
	data->weapon->w3->img = mlx_xpm_file_to_image(data->mlx,
			"bonus/photo xpm/weapon/weapon_2.xpm",
			&data->weapon->w3->width, &data->weapon->w3->hight);
	data->weapon->w4->img = mlx_xpm_file_to_image(data->mlx,
			"bonus/photo xpm/weapon/weapon_3.xpm",
			&data->weapon->w4->width, &data->weapon->w4->hight);
}

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
