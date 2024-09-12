/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:05:53 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/05 16:13:41 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_write_err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_give_value2(t_info **data, char **floor, char **ceiling)
{
	(*data)->floor_color = ft_atoi(floor[0])
		+ (ft_atoi(floor[1]) * 256) + (ft_atoi(floor[2]) * 65536);
	(*data)->sky_color = ft_atoi(ceiling[0])
		+ (ft_atoi(ceiling[1]) * 256) + (ft_atoi(ceiling[2]) * 65536);
	if ((*data)->floor_color == (*data)->sky_color)
		ft_write_err("Error ceiling color and floor they are similar\n");
}

char	*ft_putstrto_poiter(char *str, int len, char *chrct)
{
	int		i;
	char	*str_ret;

	str_ret = malloc(len + 1);
	if (!str_ret)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str_ret[i] = chrct[0];
		else
			str_ret[i] = str[i];
	}
	while (i < len)
		str_ret[i++] = chrct[1];
	str_ret[i] = '\0';
	return (str_ret);
}

char	**ft_return_my_map(char **map, char *chrct)
{
	int		x;
	int		y;
	int		len;
	char	**map_ret;

	if (!map)
		return (NULL);
	y = -1;
	len = ft_strlen(map[0]);
	while (map && map[++y])
		if (ft_strlen(map[y]) > len)
			len = ft_strlen(map[y]);
	map_ret = malloc(sizeof(char *) * (ft_len_line(map) + 1));
	if (!map_ret)
		return (NULL);
	x = -1;
	while (map[++x])
		map_ret[x] = ft_putstrto_poiter(map[x], len, chrct);
	map_ret[x] = NULL;
	if (ft_strcmp(chrct, "  ") == 0)
		ft_free(map);
	return (map_ret);
}

int	ft_len_line(char **str)
{
	int	i;

	i = 0;
	if (!(*str))
		return (0);
	while (str[i])
		i++;
	return (i);
}
