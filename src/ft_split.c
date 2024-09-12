/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:10:05 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/02 17:02:15 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_sizestr(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (j);
}

static char	**result(char *s, char **arr, char c)
{
	int	j;
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			j++;
		}
		if (count < ft_sizestr(s, c))
			arr[count++] = ft_substr(s, i - j, j);
		if (!arr)
			ft_free(arr);
	}
	arr[count] = 0;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**a;

	if (!s)
		return (NULL);
	a = (char **)malloc((ft_sizestr(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	return (result(s, a, c));
}
