/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:16:00 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*get_string(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str1[i] == str2[i])
		i++;
	while (str1[i] == ' ')
		i++;
	str = malloc(ft_strlen(str1) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (str1[i])
		str[j++] = str1[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_search_line(char **map, char *str)
{
	int		x;
	char	**line;
	int		i;
	char	*path_img;

	x = -1;
	while (map && map[++x])
	{
		line = ft_split(map[x], ' ');
		i = -1;
		if (ft_strcmp(line[0], str) == 0)
		{
			path_img = get_string(map[x], str);
			return (ft_free(line), path_img);
		}
		ft_free(line);
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	unsigned long	rs;
	int				s;
	int				i;

	s = 1;
	i = 0;
	rs = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs = rs * 10 + (str[i] - 48);
		if (rs > 9223372036854775807 && s == 1)
			return (-1);
		if (rs > 9223372036854775807 && s == -1)
			return (0);
		i++;
	}
	return (s * rs);
}
