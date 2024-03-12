/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:15:22 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/10 12:19:16 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	epc_m9ssoma(t_elements *element, char c)
{
	if (c == 'E')
		element->e += 1;
	else if (c == 'P')
		element->p += 1;
	else if (c == 'C')
		element->c += 1;
	else if (c != '1' && c != '0')
		return (-1);
	return (0);
}

int	epc(char **str)
{
	int			i;
	int			j;
	char		c;
	t_elements	element;

	element = (t_elements){0};
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			c = str[i][j];
			if (epc_m9ssoma(&element, c) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (element.e != 1 || element.p != 1 || element.c < 1)
		return (-1);
	return (1);
}

int	epc2(char **str)
{
	int			i;
	int			j;
	char		c;
	t_elements	element;

	element.e = 0;
	element.p = 0;
	element.c = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			c = str[i][j];
			if (c != '1' && c != '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	flodfil(char **map, int x, int y)
{
	if ((map[x][y] && map[x][y] == '1') || y > line_size(map)
		|| x > lines_number(map))
		return ;
	map[x][y] = '1';
	flodfil(map, x, y + 1);
	flodfil(map, x + 1, y);
	flodfil(map, x - 1, y);
	flodfil(map, x, y - 1);
}
