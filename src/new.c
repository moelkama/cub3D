/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:11:52 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/06 15:07:41 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_window	*new_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof (t_window));
	if (window)
		return (window);
	return (NULL);
}

t_move	*new_move(void)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (move)
		return (move);
	return (NULL);
}

t_img	*new_img(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof (t_img));
	if (img)
		return (img);
	return (NULL);
}

t_intersection	*new_intersection(void)
{
	t_intersection	*intersection;

	intersection = (t_intersection *)malloc(sizeof (t_intersection));
	if (intersection)
	{
		intersection->direct = 0;
		return (intersection);
	}
	return (NULL);
}

t_info	*new_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof (t_info));
	info->window = new_window();
	info->move = new_move();
	info->no = new_img();
	info->so = new_img();
	info->ea = new_img();
	info->we = new_img();
	info->img = new_img();
	info->door = new_img();
	return (info);
}
