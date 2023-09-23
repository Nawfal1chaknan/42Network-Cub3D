/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:39:09 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 22:26:46 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part_of_moves(t_mlx *mlx)
{
	int32_t	color;

	color = 1000;
	draw_background(mlx, color, mlx->mini_map);
	if (mlx_is_key_down(mlx->mlx, W))
	{
		mlx->mv->walk_direction = 1;
		update2(mlx);
	}
	if (mlx_is_key_down(mlx->mlx, S))
	{
		mlx->mv->walk_direction = -1;
		update2(mlx);
	}
	if (mlx_is_key_down(mlx->mlx, A))
	{
		mlx->mv->walk_direction = -1;
		update3(mlx);
	}
}

void	moves(void *vd)
{
	t_mlx	*mlx;

	mlx = vd;
	part_of_moves(mlx);
	if (mlx_is_key_down(mlx->mlx, D))
	{
		mlx->mv->walk_direction = 1;
		update3(mlx);
	}
	if (mlx_is_key_down(mlx->mlx, RIGHT_ARROW))
	{
		mlx->mv->turn_direction = 1;
		update(mlx);
	}
	if (mlx_is_key_down(mlx->mlx, LEFT_ARROW))
	{
		mlx->mv->turn_direction = -1;
		update(mlx);
	}
	if (mlx_is_key_down(mlx->mlx, ESC))
		exit(0);
	draw_wal(mlx);
	cast_rays(mlx);
}

void	init_p(t_mlx *mlx)
{
	int32_t		color;

	mlx->num_rays = (mlx->window_width) / WALL_WIDTH;
	player_position(mlx);
	mlx->mv->radius = 3;
	mlx->mv->turn_direction = 0;
	mlx->mv->walk_direction = 0;
	mlx->mv->rotationangle = mlx->check_dir;
	mlx->mv->move_speed = 3;
	mlx->mv->rotation_speed = 2 * (M_PI / 180);
	mlx->mv->rotationangle += mlx->mv->turn_direction * mlx->mv->rotation_speed;
	color = 0x00FF00;
	mlx_put_pixel(mlx->mini_map, MINIMAP_FACTOR * \
		mlx->mv->x, MINIMAP_FACTOR * mlx->mv->y, color);
}

void	setup(t_mlx *mlx)
{
	mlx->window_width = WINDOW_WIDGHT;
	mlx->window_height = WINDOW_HEIGHT;
	mlx->mlx = mlx_init(mlx->window_width, mlx->window_height, "Cub3D", 1);
	mlx->window = mlx_new_image(mlx->mlx, \
		mlx->window_width, mlx->window_height);
	mlx->mini_map = mlx_new_image(mlx->mlx, MINIMAP_FACTOR * (mlx->map_width \
		* TILE_SIZE), MINIMAP_FACTOR * (mlx->map_height * TILE_SIZE));
	init_textures(mlx);
	init_p(mlx);
	mlx_image_to_window(mlx->mlx, mlx->window, 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->mini_map, 0, 0);
	mlx_loop_hook(mlx->mlx, moves, mlx);
	mlx_loop(mlx->mlx);
	mlx_delete_image(mlx->mlx, mlx->window);
	mlx_delete_image(mlx->mlx, mlx->mini_map);
	mlx_terminate(mlx->mlx);
}

void	init_textures(t_mlx *mlx)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(mlx->so);
	if (!tex)
		print_err("ERROR  ::  THERES NO TEXTURES FILE!!\n");
	mlx->tex_south = convert_tex_to_bitmap(tex);
	mlx_delete_texture(tex);
	tex = mlx_load_png(mlx->no);
	if (!tex)
		print_err("ERROR  ::  THERES NO TEXTURES FILE!!\n");
	mlx->tex_north = convert_tex_to_bitmap(tex);
	mlx_delete_texture(tex);
	tex = mlx_load_png(mlx->ea);
	if (!tex)
		print_err("ERROR  ::  THERES NO TEXTURES FILE!!\n");
	mlx->tex_east = convert_tex_to_bitmap(tex);
	mlx_delete_texture(tex);
	tex = mlx_load_png(mlx->we);
	if (!tex)
		print_err("ERROR  ::  THERES NO TEXTURES FILE!!\n");
	mlx->tex_west = convert_tex_to_bitmap(tex);
	mlx_delete_texture(tex);
}
