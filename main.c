/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:49:46 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/12 16:10:51 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	freedoubleptr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	checkkk(int ac, char **av)
{
	if (ac != 2)
		error_print("empty argument\n");
	if (checkextention(av) == -1)
		error_print("extention error\n");
}

char **doublePointerCopy(char **map)
{
	int i = 0;
	char **test;
	while (map[i])
	{
		i++;
	}
	test = (char **)ft_calloc(i, strlen(map[0]));
	i = 0;
	while (map[i])
	{
		test[i] = strdup(map[i]);
		i++;
	}
	test[i] = 0;
	return test;
}

int	main(int ac, char **av)
{
	int			fd;
	char		*str;
	char		**map;
	char		**mapcpy;
	t_player	player;
	t_mlx mlx;
	
	checkkk(ac, av);
	str = av[1];
	fd = open(str, O_RDWR);
	if (fd == -1 || !fd)
		error_print("can not open the file");
	map = map_to_str(fd);
	mlx.map = map;
	mapcpy = doublePointerCopy(map);
	chaeckmap(av, map);
	player.x = xposition(map);
	player.y = yposition(map);
	printf("%d \n %d \n",player.x,player.y);
	mlx.player = &player;
	flodfil(mapcpy, player.x, player.y);
	if (epc2(mapcpy) == -1)
		error_print("player can not reach one ore more than element\n");
	ft_putmap(map, &mlx);
	freedoubleptr(map);
	return (0);
}
