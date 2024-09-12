/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:06:48 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/06 15:14:31 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_vector(t_info *info)
{
	t_intersection	*position;
	void			*img;
	float			alpha;
	float			next;
	int				size;

	img = info->img->img;
	alpha = info->move->teta - M_PI / 6;
	size = info->window->width;
	next = (info->move->teta + M_PI / 6 - alpha) / size--;
	while (size >= 0)
	{
		position = get_intersection(info, alpha);
		position->ray *= fabs(cos(info->move->teta - alpha));
		fall_img(info, position, size);
		size--;
		alpha += next;
		free(position);
	}
	mlx_clear_window(info->mlx, info->window->win);
	mlx_put_image_to_window(info->mlx, info->window->win, img, 0, 0);
}

void	init_textures(t_info *info)
{
	info->img->img = mlx_new_image(info->mlx,
			info->window->width, info->window->hight);
	info->img->buffer = mlx_get_data_addr(info->img->img,
			&info->img->pixel_bits, &info->img->line_bytes, &info->img->endian);
	info->ea->buffer = mlx_get_data_addr(info->ea->img, &info->ea->pixel_bits,
			&info->ea->line_bytes, &info->ea->endian);
	info->no->buffer = mlx_get_data_addr(info->no->img, &info->no->pixel_bits,
			&info->no->line_bytes, &info->no->endian);
	info->so->buffer = mlx_get_data_addr(info->so->img, &info->so->pixel_bits,
			&info->so->line_bytes, &info->so->endian);
	info->we->buffer = mlx_get_data_addr(info->we->img, &info->we->pixel_bits,
			&info->we->line_bytes, &info->we->endian);
}

int	destroy_win(t_info *info)
{
	(void)info;
	exit (0);
	return (0);
}

int	main(int c, char **v)
{
	t_info	*info;

	if (c == 2)
	{
		info = handling_map(v[1]);
		info->zooom = 60;
		info->size = 60;
		info->move_up = 0;
		info->move_down = 0;
		begin_status(info);
		init_textures(info);
		put_vector(info);
		mlx_loop_hook(info->mlx, do_event, info);
		mlx_hook(info->window->win, 3, 0, remove_move, info);
		mlx_hook(info->window->win, 2, 0, move, info);
		mlx_hook(info->window->win, 17, 0, destroy_win, info);
		mlx_loop(info->mlx);
	}
	else
		write(2, "Error te programe need two argument\n", 37);
}
