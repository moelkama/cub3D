/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fall_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:15:32 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/02 17:02:15 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sky(t_info *info, int a, int *i, int size)
{
	char	*dst;
	int		end;
	int		x;
	int		y;

	end = (info->window->hight - a) / 2;
	while (*i < end)
	{
		x = *i * info->img->line_bytes;
		y = size * (info->img->pixel_bits / 8);
		dst = info->img->buffer + x + y;
		*((unsigned int *)dst) = info->sky_color;
		(*i)++;
	}
}

void	ft(t_info *info, t_new d, int *i, int size)
{
	float	x;
	int		a;
	int		b;

	x = (float)d.f - info->window->hight;
	if (d.f <= info->window->hight)
		d.l = (((float)*i - d.b) / d.f) * d.texture->width;
	else
		d.l = (x / 2 + *i) / d.f * d.texture->width;
	if (d.m >= 0 && d.m < d.texture->hight)
	{
		if (d.l < 0 || (int )d.l > d.texture->width)
			return ;
		a = *i * info->img->line_bytes;
		b = size * (info->img->pixel_bits / 8);
		d.dst = info->img->buffer + a + b;
		a = (int )d.l * d.texture->line_bytes;
		b = d.m * (d.texture->pixel_bits / 8);
		d.rst = d.texture->buffer + a + b;
		*((unsigned int *)d.dst) = *((unsigned int *)d.rst);
	}
}

void	put_walls(t_info *info, t_intersection *position, int *i, int size)
{
	t_new	d;

	d.a = info->window->hight * info->zooom / position->ray;
	d.f = d.a;
	d.b = *i;
	d.texture = get_texture(info, position);
	d.m = get_m(info, position, d.texture->hight);
	while (d.a > 0)
	{
		if (*i < info->window->hight)
			ft(info, d, i, size);
		(*i)++;
		d.a--;
	}
}

void	put_floor(t_info *info, int *i, int size)
{
	char	*dst;
	int		x;
	int		y;

	while (*i < info->window->hight)
	{
		x = *i * info->img->line_bytes;
		y = size * (info->img->pixel_bits / 8);
		dst = info->img->buffer + x + y;
		*((unsigned int *)dst) = info->floor_color;
		(*i)++;
	}
}

void	fall_img(t_info *info, t_intersection *position, int size)
{
	int	a;
	int	i;

	i = 0;
	a = info->window->hight * info->zooom / position->ray;
	put_sky(info, a, &i, size);
	put_walls(info, position, &i, size);
	put_floor(info, &i, size);
}
