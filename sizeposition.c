/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeposition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:22:07 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/12 16:13:30 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	*yposition(char **map)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				y = j;
				return (y);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	*xposition(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				x = i;
				return (x);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	line_size(char **ptr)
{
	int	len;
	int	leninitial;
	int	j;

	len = 0;
	leninitial = ft_strlen(ptr[0]);
	j = 0;
	while (ptr[j])
	{
		len = ft_strlen(ptr[j]);
		if (len != leninitial)
			return (-1);
		j++;
	}
	return (leninitial);
}

int	lines_number(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		j += 1;
		i++;
	}
	return (j);
}
