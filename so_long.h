/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:59:45 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/22 18:34:21 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/includes/ft_printf.h"

typedef enum s_keys
{
	ESC = 65307,
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	SPACE = 32,
	HOSPITAL = 104,
	ARROW_UP = 65362,
	ARROW_DOWN = 65364,
	ARROW_LEFT = 65361,
	ARROW_RIGHT = 65363,
}	t_keys;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		length;
	int		height;
	int		c;
	int		e;
	int		p;
	int		px;
	int		py;
	int		p2x;
	int		p2y;
	int		ex;
	int		ey;
	int		opening;
}	t_map;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*pointer;
	t_vector	*size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_obj
{
	t_image	floor;
	t_image	wall;
	t_image	collect;
	t_image	exit1;
	t_image	exit2;
	t_image player2;
	t_image	player;
	t_image	fire1;
	t_image	fire2;
	t_image	fire3;
	t_image notfire;
	t_image player2notfire;
	t_image playernotfire;
	t_image bucket;
	int		fire;
}	t_obj;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		po;
	int		po2;
	t_map	map;
	t_obj	obj;
	int		moves;
}	t_game;

int		main(int argc, char **argv);
char	**ft_create_matrix(char *string, t_map map);
int		ft_mapchecker(t_map map);
int		ft_strlengnl(char *string);
int		ft_count_rows(char *string);
int		ft_right_quantity(t_map map);
int		ft_rightobj(t_map map);
t_map	ft_matrix_hendler(char **argv);
int		ft_count_collectibles(t_map map);
void	ft_printmap(void *mlx, void *win, t_obj obj, t_map map);
void	ft_printingfloor(void *mlx, void *win, t_obj obj, t_map map);
int		ft_keypress(int keycode, t_game *game);
void	ft_moveup(t_map *map, t_game *game);
void	ft_movedown(t_map *map, t_game *game);
void	ft_moveleft(t_map *map, t_game *game);
void	ft_moveright(t_map *map, t_game *game);
t_map	ft_findplayer(t_map map);
int		move_helper(t_map *map, t_game *game);
void	check_opening(t_map *map, t_game *game);
void	ft_create_enemy(void *mlx, void *win, t_obj obj, t_map map);
void	ft_createfloortoenemy(void *mlx, void *win, t_obj obj, t_map map);
void	ft_freematrix(t_map map);
void	ft_writemoves(t_game *game);
int		ft_close(t_game *game);
void	ft_updatemap(void *mlx, void *win, t_obj obj, t_map map);

//p2

void	ft_moveright2(t_map *map, t_game *game);
void	ft_movedown2(t_map *map, t_game *game);
void	ft_moveup2(t_map *map, t_game *game);
void	ft_moveleft2(t_map *map, t_game *game);

#endif
