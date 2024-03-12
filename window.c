#include "solong.h"




int	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	ft_loadhouse_image(void *mlx, void *win, int *l, int *j)
{
	t_image	house;

	house.relative_path = "img/house.xpm";
	house.img = mlx_xpm_file_to_image(mlx, house.relative_path,
			&house.img_width, &house.img_height);
	mlx_put_image_to_window(mlx, win, house.img, *l, *j);
}

void	ft_lodwalls_image(void *mlx, void *win, int *l, int *j)
{
	t_image	walls;

	walls.relative_path = "img/walls.xpm";
	walls.img = mlx_xpm_file_to_image(mlx, walls.relative_path,
			&walls.img_width, &walls.img_height);
	mlx_put_image_to_window(mlx, win, walls.img, *l, *j);
}

void	ft_lodcollect_image(void *mlx, void *win, int *l, int *j)
{
	t_image	collect;

	collect.relative_path = "img/collect.xpm";
	collect.img = mlx_xpm_file_to_image(mlx, collect.relative_path,
			&collect.img_width, &collect.img_height);
	mlx_put_image_to_window(mlx, win, collect.img, *l, *j);
}

void	ft_lodlard_image(t_mlx *mlx, int *l, int *j)
{
	t_image	lard;

	lard.relative_path = "img/lard.xpm";
	lard.img = mlx_xpm_file_to_image(mlx->mlx, lard.relative_path, &lard.img_width,
			&lard.img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, lard.img, *l, *j);
}

void	ft_lodcharac_image(t_mlx *mlx, int *l, int *j)
{
	t_image	charac;

	charac.relative_path = "img/charac.xpm";
	charac.img = mlx_xpm_file_to_image(mlx->mlx, charac.relative_path,
			&charac.img_width, &charac.img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, charac.img, *l, *j);
}

void move_up(t_mlx *mlx)
{
	printf("pos_x: %d: pos_y: %d", mlx->player->x - 1, mlx->player->y);
	if (mlx->map[mlx->player->x - 1][mlx->player->y] == '1')
		return ;
	else
	{
		mlx->player->x--;
		ft_lodcharac_image(mlx,&mlx->player->x, &mlx->player->y);
		ft_lodlard_image(mlx, &mlx->player->x+1, &mlx->player->y);
	}
}

void	ft_drawmap(char **map, t_mlx *mlx)
{
	int	i, j;

	i = j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			int x,y;
			x = i * 90;
			y = j * 90;
			if (map[i][j] == '1')
				ft_lodwalls_image(mlx->mlx, mlx->win, &y, &x);
			else if(map[i][j] == 'E')
				ft_loadhouse_image(mlx->mlx, mlx->win, &y, &x);
			else if(map[i][j] == 'P')
				ft_lodcharac_image(mlx, &y, &x);
			else if(map[i][j] == 'C')
				ft_lodcollect_image(mlx->mlx, mlx->win, &y, &x);
			else if(map[i][j] == '0')
				ft_lodlard_image(mlx, &y, &x);
			j++;
		}
		i++;
	}
}


int	keys(int key, t_mlx *mlx)
{
	printf("%d\n",key);
	if (key == 53)
		exit(1);
	else if (key == 126 || key == 13)
		move_up(mlx);
	// else if(key == 0 || key == 123)
	// 	move_left();
	// else if(key == 2 || key == 124)
	// 	move_right();
	// else if(key == 1 || key == 125)
	// 	move_down();
	return (0);
}

void	ft_putmap(char **map, t_mlx *mlx)
{

    int l;
    int h;

    l = line_size(map) * 90;
    h = lines_number(map) * 90;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, l, h, "Solong");
    ft_drawmap(map, mlx);

	mlx_key_hook(mlx->win, keys, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
}
