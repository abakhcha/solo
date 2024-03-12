/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:05:23 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/10 12:07:47 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checkwalls(char **str)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = lines_number(str) - 1;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (-1);
		j++;
	}
	i = l;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (-1);
		j++;
	}
	return (1);
}

int	checkwalls2(char **str)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = lines_number(str) - 1;
	while (str[i])
	{
		if (str[i][j] != '1')
			return (-1);
		i++;
	}
	i = 0;
	j = line_size(str) - 1;
	while (str[i])
	{
		if (str[i][j] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	checkmostatil(char **str)
{
	int	m;
	int	l;

	m = line_size(str);
	l = lines_number(str);
	if (m == -1 || m == l)
		return (-1);
	return (1);
}

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
				return (-1);
		}
		i++;
	}
	if (str[0] == '\n')
		return (-1);
	return (1);
}
