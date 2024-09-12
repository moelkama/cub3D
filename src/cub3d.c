/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:05:22 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 14:53:14 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_color(char **tab, char *str)
{
	int	i;
	int	j;

	i = -1;
	if (!tab || !(*tab))
		return (0);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
				return (free(str), 0);
		if (!(ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 255))
			return (free(str), 0);
	}
	if (i != 3)
		return (0);
	j = -1;
	i = 0;
	while (str[++j])
		if (str[j] == ',')
			i++;
	if (i != 2)
		return (free(str), 0);
	return (free(str), 1);
}

void	ft_open_img(t_info **data, char **file)
{
	char	*a;
	char	*b;
	char	*e;
	char	*d;

	a = ft_search_line(file, "NO");
	b = ft_search_line(file, "SO");
	e = ft_search_line(file, "WE");
	d = ft_search_line(file, "EA");
	(*data)->no->img = mlx_xpm_file_to_image((*data)->mlx,
			a, &(*data)->no->hight, &(*data)->no->width);
	(*data)->so->img = mlx_xpm_file_to_image((*data)->mlx,
			b, &(*data)->so->hight, &(*data)->so->width);
	(*data)->we->img = mlx_xpm_file_to_image((*data)->mlx,
			e, &(*data)->we->hight, &(*data)->we->width);
	(*data)->ea->img = mlx_xpm_file_to_image((*data)->mlx,
			d, &(*data)->ea->hight, &(*data)->ea->width);
	free(a);
	free(b);
	free(e);
	free(d);
}

void	ft_give_value(t_info **data, char **file)
{
	char	**floor;
	char	**ceiling;
	char	*f;
	char	*c;

	(*data)->map = ft_return_my_map((*data)->my_map, "11");
	(*data)->my_map = ft_return_my_map((*data)->my_map, "  ");
	c = ft_search_line(file, "C");
	f = ft_search_line(file, "F");
	floor = ft_split(f, ',');
	ceiling = ft_split(c, ',');
	(*data)->window->width = 800;
	(*data)->window->hight = 600;
	if (!ft_check_color(floor, f) || !ft_check_color(ceiling, c))
		ft_write_err("Error in floor or ceiling (need (R,G,B) type)\n");
	else
		ft_give_value2(data, floor, ceiling);
	ft_free(floor);
	ft_free(ceiling);
}

void	handling_map2(char **file, t_info *data, char *str)
{
	if (!(*file))
		ft_write_err("Error the file is empty\n");
	data->my_map = ft_return_map(file);
	if (!check_newline(str))
	{
		write(2, "Error the map has a new line\n", 29);
		exit(1);
	}
	if (handle_caracteres(data->my_map, "01 ", "NSEW") != 1)
	{
		if (handle_caracteres(data->my_map, "01 ", "NSEW") == -1)
			write(2, "Error there is more than one player\n", 36);
		else if (handle_caracteres(data->my_map, "01 ", "NSEW") == -2)
			write(2, "Error the game need one player\n", 31);
		else
			write(2, "Error one or more characters is not not allowed\n", 48);
		exit(1);
	}
	ft_give_value(&data, file);
	if (!handling_wall(data->my_map))
		ft_write_err("Error the map is not closed by walls\n");
}

t_info	*handling_map(char *map1)
{
	int		fd;
	char	*str;
	char	**file;
	t_info	*data;

	data = new_info();
	if (!ft_handling_map_name(map1))
		ft_write_err("Error fix the map name\n");
	fd = open(map1, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	str = ft_readfile(fd);
	file = ft_split(str, '\n');
	handling_map2(file, data, str);
	data->mlx = mlx_init();
	data->window->win = mlx_new_window(data->mlx,
			data->window->width, data->window->hight, "cub3d");
	ft_open_img(&data, file);
	if (!data->no->img || !data->so->img
		|| !data->we->img || !data->ea->img)
		ft_write_err("Error can't open path of image\n");
	return (ft_free(file), data);
}
