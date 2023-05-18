/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:33 by gfezzuog          #+#    #+#             */
/*   Updated: 2023/05/16 17:12:11 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freematrix(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
	exit(0);
}

int extinct_fire(t_map *map, int px, int py)
{
	int i = 1;
	if (map->map[py][px - 1] == 'N')
	{
		map->map[py][px - 1] = 'O';
		i = 0;
	}
	if (map->map[py][px + 1] == 'N')
	{
		map->map[py][px + 1] = 'O';
		i = 0;
	}
	if (map->map[py - 1][px] == 'N')
	{
		map->map[py - 1][px] = 'O';
		i = 0;
	}
	if (map->map[py + 1][px] == 'N')
	{
		map->map[py + 1][px] = 'O';
		i = 0;
	}
	return(i);
}

void check_object2(t_map *map, t_game *game)
{
	if (game->po2 == 1)
	{
		game->po2 = extinct_fire(map, map->p2x, map->p2y);
		return	;
	}
	if (map->map[map->p2y][map->p2x - 1] == 'B')
	{
		game->po2 = 1;
		map->map[map->p2y][map->p2x - 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					(map->p2x - 1) * 64, map->p2y * 64);
	}
	if (map->map[map->p2y][map->p2x + 1] == 'B')
	{
		game->po2 = 1;
		map->map[map->p2y][map->p2x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					(map->p2x + 1) * 64, map->p2y * 64);
	}
	if (map->map[map->p2y + 1][map->p2x] == 'B')
	{
		game->po2 = 1;
		map->map[map->p2y + 1][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, (map->p2y + 1) * 64);
	}
	if (map->map[map->p2y - 1][map->p2x] == 'B')
	{
		game->po2 = 1;
		map->map[map->p2y - 1][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, (map->p2y - 1) * 64);
	}
}

void check_object(t_map *map, t_game *game)
{
	if (game->po == 1)
	{
		game->po = extinct_fire(map, map->px, map->py);
		return	;
	}
	if (map->map[map->py][map->px - 1] == 'B')
	{
		game->po = 1;
		map->map[map->py][map->px - 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					(map->px - 1) * 64, map->py * 64);
	}
	if (map->map[map->py][map->px + 1] == 'B')
	{
		game->po = 1;
		map->map[map->py][map->px + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					(map->px + 1) * 64, map->py * 64);
	}
	if (map->map[map->py + 1][map->px] == 'B')
	{
		game->po = 1;
		map->map[map->py + 1][map->px] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->px * 64, (map->py + 1) * 64);
	}
	if (map->map[map->py - 1][map->px] == 'B')
	{
		game->po = 1;
		map->map[map->py - 1][map->px] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
			map->px * 64, (map->py - 1) * 64);
	}
}

int	ft_keypress(int keycode, t_game *game)
{
	ft_writemoves(game);
	if (keycode == ESC)
	{
		ft_freematrix(game->map);
		exit(0);
	}
	if (keycode == KEY_UP)
		ft_moveup(&game->map, game);
	if (keycode == ARROW_UP)
		ft_moveup2(&game->map, game);
	if (keycode == KEY_DOWN)
		ft_movedown(&game->map, game);
	if (keycode == ARROW_DOWN)
		ft_movedown2(&game->map, game);
	if (keycode == KEY_LEFT)
		ft_moveleft(&game->map, game);
	if (keycode == ARROW_LEFT)
		ft_moveleft2(&game->map, game);
	if (keycode == KEY_RIGHT)
		ft_moveright(&game->map, game);
	if (keycode == ARROW_RIGHT)
		ft_moveright2(&game->map, game);
	if (keycode == SPACE)
	{
		check_object2(&game->map, game);
		check_object(&game->map, game);
	}
	ft_updatemap(game->mlx, game->win, game->obj, game->map);
	check_opening(&game->map, game);
	return (0);
}

t_map	ft_findplayer(t_map map)
{
	map.cols = 0;
	map.rows = 0;
	while (map.cols < map.height)
	{
		while (map.rows < map.length)
		{
			if (map.map[map.cols][map.rows] == 'P')
			{
				map.px = map.rows;
				map.py = map.cols;
			}
			if (map.map[map.cols][map.rows] == 'p')
			{
				map.p2x = map.rows;
				map.p2y = map.cols;
			}
			map.rows++;
		}
		map.rows = 0;
		map.cols++;
	}
	return (map);
}
