/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:12:20 by akatfi            #+#    #+#             */
/*   Updated: 2023/08/05 19:57:11 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*newstring;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	if (!s)
		return (NULL);
	if (start <= ft_strlen(s))
		l = ft_strlen(s) - start;
	if (len < l)
		l = len;
	newstring = (char *)malloc((l + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (s[start] != '\0' && j < l)
		newstring[j++] = s[start++];
	newstring[j] = '\0';
	return (newstring);
}

int	remove_move(int key, t_info *info)
{
	if ((key == 13 || key == 126))
		info->move_up = 0;
	else if ((key == 1 || key == 125))
		info->move_down = 0;
	else if (key == 0)
		info->move_right = 0;
	else if (key == 2)
		info->move_left = 0;
	else if (key == 123)
		info->rotation_right = 0;
	else if (key == 124)
		info->rotation_left = 0;
	return (0);
}
