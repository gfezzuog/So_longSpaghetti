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
	check_opening(map, game);
	if (map->map[map->p2y - 1][map->p2x] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y - 1][map->p2x] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y - 1][map->p2x] == '1'
		|| (map->map[map->p2y - 1][map->p2x] == 'E' && map->opening == 0))
		return ;
	map->map[map->p2y][map->p2x] = '0';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.floor.pointer, map->p2x * 64, map->p2y * 64);
	// map->p2y--;
	map->map[map->p2y][map->p2x] = 'p';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.player2.pointer, map->p2x * 64, map->p2y * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_movedown2(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->p2y + 1][map->p2x] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y + 1][map->p2x] == 'N')
		ft_freematrix(game->map);
	map->map[map->p2y][map->p2x] = '0';
	if (map->map[map->p2y + 1][map->p2x] == '1'
		|| (map->map[map->p2y + 1][map->p2x] == 'E' && map->opening == 0))
		return ;
	map->map[map->p2y][map->p2x] = '0';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.floor.pointer, map->p2x * 64, map->p2y * 64);
	map->p2y++;
	map->map[map->p2y][map->p2x] = 'p';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.player2.pointer, map->p2x * 64, map->p2y * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_moveleft2(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->p2y][map->p2x - 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x - 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x - 1] == '1'
		|| (map->map[map->p2y][map->p2x - 1] == 'E' && map->opening == 0))
		return ;
	map->map[map->p2y][map->p2x] = '0';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.floor.pointer, map->p2x * 64, map->p2y * 64);
	map->p2x--;
	map->map[map->p2y][map->p2x] = 'p';
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->obj.player2.pointer, map->p2x * 64, map->p2y * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}

void	ft_moveright2(t_map *map, t_game *game)
{
	check_opening(map, game);
	if (map->map[map->p2y][map->p2x + 1] == 'E' && map->opening == 1)
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x + 1] == 'N')
		ft_freematrix(game->map);
	if (map->map[map->p2y][map->p2x + 1] == '1'
		|| (map->map[map->p2y][map->p2x + 1] == 'E' && map->opening == 0))
		return ;
	map->map[map->p2y][map->p2x] = '0';
	mlx_put_image_to_window(game->mlx, game->win,
		game->obj.floor.pointer, map->p2x * 64, map->p2y * 64);
	map->p2x++;
	map->map[map->p2y][map->p2x] = 'p';
	//mlx_put_image_to_window(game->mlx, game->win,
	//	game->obj.player2.pointer, map->p2x * 64, map->p2y * 64);
	game->obj.fire++;
	ft_create_enemy(game->mlx, game->win, game->obj, *map);
	check_opening(map, game);
}
