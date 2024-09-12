/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:30:03 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/02 17:02:15 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (free(str1), NULL);
	i = -1;
	if (!str)
		return (NULL);
	while (str1 && str1[++i])
		str[i] = str1[i];
	j = 0;
	while (str2 && str2[j])
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	return (str);
}

char	*ft_readfile(int fd)
{
	int		x;
	char	*buffer;
	char	*str_ret;

	if (fd < 0)
		return (NULL);
	x = 1;
	buffer = malloc(10);
	str_ret = malloc(1);
	*str_ret = '\0';
	while (1337)
	{
		x = read(fd, buffer, 9);
		if (x == -1)
			return (free(str_ret), free(buffer), NULL);
		if (x == 0)
			break ;
		buffer[x] = '\0';
		str_ret = ft_strjoin(str_ret, buffer);
	}
	return (free(buffer), str_ret);
}
