/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:49:21 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/12 14:04:29 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct img
{
	void	*img;
	int		img_width;
	int		img_height;
	int		i;
	char	*relative_path;
}			t_image;

typedef struct playerr
{
	int		x;
	int		y;
}			t_player;

typedef struct elements
{
	int		p;
	int		c;
	int		e;
}			t_elements;

typedef struct mlx
{
	void *mlx;
	void *win;
	t_player *player;
	char **map;
} t_mlx;


size_t		ft_strlen(char *str);
size_t		ft_countwords(char *s, char c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*str_join(char *s1, char *s2);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, int start, size_t len);
int			yposition(char **map);
int			xposition(char **map);
int			line_size(char **ptr);
int			lines_number(char **ptr);
int			checkextention(char **av);
int			checkwalls(char **str);
int			checkwalls2(char **str);
int			checkmostatil(char **str);
int			epc_m9ssoma(t_elements *element, char c);
int			epc(char **str);
int			epc2(char **str);
void		error_print(char *str);
int			check_empty_line(char *str);
char		**map_to_str(int fd);
void		chaeckmap(char **av, char **map);
void		flodfil(char **map, int x, int y);
void		freedoubleptr(char **map);
void		ft_putmap(char **, t_mlx *);