/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:06:32 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/04 16:07:11 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (-1);
	i = 0;
	while (str2[i] && str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_handling_map_name(char *map_name)
{
	int	i;

	if (!map_name || ft_strlen(map_name) <= 4)
		return (0);
	i = ft_strlen(map_name) - 1;
	while (i > 0 && map_name[i] != '.')
		i--;
	if (ft_strcmp(".cub", (map_name + i)) != 0)
		return (0);
	return (1);
}

int	ft_check_str(char *str1, char *str2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str1[++i])
	{
		while (str2[++j])
			if (str2[j] == str1[i])
				return (1);
		i++;
		j = -1;
	}
	return (0);
}

int	ft_check(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	handle_caracteres(char **map, char *str1, char *str2)
{
	int	i;
	int	j;
	int	p;

	j = -1;
	p = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (!ft_check(str1, map[j][i]))
			{
				if (ft_check(str2, map[j][i]))
					p++;
				else
					return (0);
			}
		}
	}
	if (p > 1)
		return (-1);
	else if (p == 0)
		return (-2);
	return (1);
}
