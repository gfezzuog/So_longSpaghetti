/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:36:27 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/11/21 17:32:00 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveup2(t_map *map, t_game *game)
{
	if (map->map[map->p2y - 1][map->p2x] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y - 1][map->p2x] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y - 1][map->p2x] == '1'
		|| (map->map[map->p2y - 1][map->p2x] == 'E' && map->opening == 0)
		|| map->map[map->p2y - 1][map->p2x] == 'B'
		|| map->map[map->p2y - 1][map->p2x] == 'P'
		|| map->map[map->p2y - 1][map->p2x] == 'Q')
		return ;
	if(map->map[map->p2y][map->p2x] == 'q')
		map->map[map->p2y][map->p2x] = 'O';
	else
	{
		map->map[map->p2y][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, map->p2y * 64);
	}
	map->p2y--;
	if(map->map[map->p2y][map->p2x] == 'O')
		map->map[map->p2y][map->p2x] = 'q';
	else
		map->map[map->p2y][map->p2x] = 'p';
	game->obj.fire++;
	// ft_create_enemy(game->mlx, game->win, game->obj, *map);
}

void	ft_movedown2(t_map *map, t_game *game)
{
	if (map->map[map->p2y + 1][map->p2x] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y + 1][map->p2x] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y + 1][map->p2x] == '1'
		|| (map->map[map->p2y + 1][map->p2x] == 'E' && map->opening == 0)
		|| map->map[map->p2y + 1][map->p2x] == 'B'
		|| map->map[map->p2y + 1][map->p2x] == 'P'
		|| map->map[map->p2y + 1][map->p2x] == 'Q')
		return ;
	if(map->map[map->p2y][map->p2x] == 'q')
		map->map[map->p2y][map->p2x] = 'O';
	else
	{
		map->map[map->p2y][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, map->p2y * 64);
	}
	map->p2y++;
	if(map->map[map->p2y][map->p2x] == 'O')
		map->map[map->p2y][map->p2x] = 'q';
	else
		map->map[map->p2y][map->p2x] = 'p';
	game->obj.fire++;

	// ft_create_enemy(game->mlx, game->win, game->obj, *map);
}

void	ft_moveleft2(t_map *map, t_game *game)
{
	if (map->map[map->p2y][map->p2x - 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x - 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x - 1] == '1'
		|| (map->map[map->p2y][map->p2x - 1] == 'E' && map->opening == 0)
		|| map->map[map->p2y][map->p2x - 1] == 'B'
		|| map->map[map->p2y][map->p2x - 1] == 'P'
		|| map->map[map->p2y][map->p2x - 1] == 'Q')
		return ;
	if(map->map[map->p2y][map->p2x] == 'q')
		map->map[map->p2y][map->p2x] = 'O';
	else
	{
		map->map[map->p2y][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, map->p2y * 64);
	}
	map->p2x--;
	if(map->map[map->p2y][map->p2x] == 'O')
		map->map[map->p2y][map->p2x] = 'q';
	else
		map->map[map->p2y][map->p2x] = 'p';
	game->obj.fire++;
	// ft_create_enemy(game->mlx, game->win, game->obj, *map);
}

void	ft_moveright2(t_map *map, t_game *game)
{
	if (map->map[map->p2y][map->p2x + 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x + 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x + 1] == '1'
		|| (map->map[map->p2y][map->p2x + 1] == 'E' && map->opening == 0)
		|| map->map[map->p2y][map->p2x + 1] == 'B'
		|| map->map[map->p2y][map->p2x + 1] == 'P'
		|| map->map[map->p2y][map->p2x + 1] == 'Q')
		return ;
	if(map->map[map->p2y][map->p2x] == 'q')
		map->map[map->p2y][map->p2x] = 'O';
	else
	{
		map->map[map->p2y][map->p2x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->obj.floor.pointer,
					map->p2x * 64, map->p2y * 64);
	}
	map->p2x++;
	if(map->map[map->p2y][map->p2x] == 'O')
		map->map[map->p2y][map->p2x] = 'q';
	else
		map->map[map->p2y][map->p2x] = 'p';
	game->obj.fire++;
	// ft_create_enemy(game->mlx, game->win, game->obj, *map);
}
