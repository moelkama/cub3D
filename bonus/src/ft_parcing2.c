/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:11:30 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/06 15:29:39 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*ft_alloc(char *str)
{
	int		i;
	char	*str_ret;

	str_ret = malloc(ft_strlen(str) + 1);
	if (!str_ret)
		return (NULL);
	i = -1;
	while (str[++i])
		str_ret[i] = str[i];
	str_ret[i] = '\0';
	return (str_ret);
}

char	**ft_return_map(char **line)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (ft_len_line(line) - 6 + 1));
	if (!map)
		return (NULL);
	i = 5;
	j = 0;
	while (line && line[++i])
		map[j++] = ft_alloc(line[i]);
	map[j] = NULL;
	return (map);
}

char	*get_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == ' ' || str[i + 1] == '1'))
		{
			j = i + 1;
			while (str[j] == ' ' || str[j] == '1')
			{
				if (str[j + 1] == '\n')
					return (str + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

int	check_newline(char *str)
{
	int		i;
	char	*str_check;

	i = -1;
	str_check = get_line(str);
	while (str_check[++i])
		if (str_check[i] == '\n' && str_check[i + 1] == '\n')
			return (free(str), 0);
	return (free(str), 1);
}
