/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:48:57 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/02 17:02:15 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checker1(t_info *info, int j, int i, float alpha)
{
	int	len;

	if (i < 0 || i / info->size >= arr_size(info->map))
		return (1);
	len = ft_strlen(info->map[i / info->size]);
	if (j < 0 || j / info->size >= len)
		return (1);
	if (cos(alpha) > 0)
	{
		if (info->map[i / info->size][j / info->size] == '1')
			return (1);
		if (info->map[i / info->size][j / info->size] == '2')
			return (2);
	}
	else
	{
		if (info->map[i / info->size][j / info->size - 1] == '1')
			return (1);
		if (info->map[i / info->size][j / info->size - 1] == '2')
			return (2);
	}
	return (0);
}

int	checker2(t_info *info, int j, int i, float alpha)
{
	int	len;

	if (i < 0 || i / info->size >= arr_size(info->map))
		return (1);
	len = ft_strlen(info->map[i / info->size]);
	if (j < 0 || j / info->size >= len)
		return (1);
	if (sin(alpha) > 0)
	{
		if (info->map[i / info->size - 1][j / info->size] == '1')
			return (1);
		if (info->map[i / info->size - 1][j / info->size] == '2')
			return (2);
	}
	else
	{
		if (info->map[i / info->size][j / info->size] == '1')
			return (1);
		if (info->map[i / info->size][j / info->size] == '2')
			return (2);
	}
	return (0);
}

t_intersection	*get_x(t_info *info, float alpha)
{
	t_intersection	*p;

	p = new_intersection();
	p->x = info->move->x;
	p->y = info->move->y;
	if (cos(alpha) > 0 && fmod(p->x, info->size) != 0)
		p->x += info->size - fmod(p->x, info->size);
	else
		p->x -= fmod(p->x, info->size);
	p->y = info->move->y - ((p->x - info->move->x) * tan(alpha));
	while (!checker1(info, p->x, p->y, alpha))
	{
		if (cos(alpha) > 0)
			p->x += info->size;
		else
			p->x -= info->size;
		p->y = info->move->y - (p->x - info->move->x) * tan(alpha);
	}
	p->direct = 2;
	if (cos(alpha) > 0)
		p->direct = 0;
	return (p);
}

t_intersection	*get_y(t_info *info, float alpha)
{
	t_intersection	*p;

	p = new_intersection();
	p->x = info->move->x;
	p->y = info->move->y;
	if (sin(alpha) < 0 && fmod(p->y, info->size) != 0)
		p->y += info->size - fmod(p->y, info->size);
	else
		p->y -= fmod(p->y, info->size);
	p->x = info->move->x + ((info->move->y - p->y) / tan(alpha));
	while (!checker2(info, p->x, p->y, alpha))
	{
		if (sin(alpha) > 0)
			p->y -= info->size;
		else
			p->y += info->size;
		p->x = info->move->x + ((info->move->y - p->y) / tan(alpha));
	}
	p->direct = 3;
	if (sin(alpha) > 0)
		p->direct = 1;
	return (p);
}

t_intersection	*get_intersection(t_info *info, float alpha)
{
	t_intersection	*p1;
	t_intersection	*p2;
	float			a;

	p1 = get_x(info, alpha);
	p2 = get_y(info, alpha);
	a = pow(p1->x - info->move->x, 2) + pow(p1->y - info->move->y, 2);
	p1->ray = sqrt(a);
	a = pow(p2->x - info->move->x, 2) + pow(p2->y - info->move->y, 2);
	p2->ray = sqrt(a);
	if (p1->ray < p2->ray)
		return (free(p2), p1);
	return (free(p1), p2);
}
