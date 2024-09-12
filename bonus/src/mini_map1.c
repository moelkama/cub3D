/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:50:07 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_protection_x(int *start_x, int *end_x, t_info *data)
{
	if (*start_x < 0 || *end_x > ft_strlen(data->my_map[0]))
	{
		if (*start_x < 0)
		{
			*start_x = 0;
			*end_x = 8 * 2;
			if (*end_x > ft_strlen(data->my_map[0]))
				*end_x = ft_strlen(data->my_map[0]);
		}
		else
		{
			*end_x = ft_strlen(data->my_map[0]);
			*start_x = *end_x - (8 * 2);
			if (*start_x < 0)
				*start_x = 0;
		}
	}
}

void	ft_protection_y(int *start_y, int *end_y, t_info *data)
{
	if (*start_y < 0 || *end_y > ft_len_line(data->my_map))
	{
		if (*start_y < 0)
		{
			*start_y = 0;
			*end_y = 8 * 2;
			if (*end_y > ft_len_line(data->my_map))
				*end_y = ft_len_line(data->my_map);
		}
		else
		{
			*end_y = ft_len_line(data->my_map);
			*start_y = *end_y - (8 * 2);
			if (*start_y < 0)
				*start_y = 0;
		}
	}
}

void	give_mini_map_value(t_mini_map *mini, t_info *data)
{
	mini->i = 0;
	mini->x_mini_map = data->move->x / data->size;
	mini->y_mini_map = data->move->y / data->size;
	mini->start_x = mini->x_mini_map - 8;
	mini->end_x = mini->x_mini_map + 8;
	mini->start_y = mini->y_mini_map - 8;
	mini->end_y = mini->y_mini_map + 8;
	ft_protection_x(&mini->start_x, &mini->end_x, data);
	ft_protection_y(&mini->start_y, &mini->end_y, data);
	mini->tmp = mini->start_x;
	mini->y = 1;
}

void	ft_put_color(t_info *data, t_mini_map *mini)
{
	if (mini->start_x == mini->x_mini_map
		&& mini->start_y == mini->y_mini_map && mini->i == 0)
	{
		mini->i++;
		mini->x_mini_map = mini->x;
		mini->y_mini_map = mini->y;
	}
	else if (data->my_map[mini->start_y][mini->start_x] == '1')
		ft_mlx_put_pixel(data, mini->x * 10, mini->y * 10, 6451);
	else if (data->my_map[mini->start_y][mini->start_x] == ' ')
		ft_mlx_put_pixel(data, mini->x * 10, mini->y * 10, 0x00FF000080);
	else
		ft_mlx_put_pixel(data, mini->x * 10, mini->y * 10, 8886451);
}
