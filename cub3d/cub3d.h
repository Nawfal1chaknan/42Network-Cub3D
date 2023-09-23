/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:59:42 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 07:09:21 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/Users/namorgha/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "float.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define FOV			1.047198
# define WINDOW_WIDGHT	850
# define WINDOW_HEIGHT	450
# define RADIUS			5
# define WALL_WIDTH		1
# define TEX_SZ			64
# define TILE_SIZE		64
# define MINIMAP_FACTOR	0.1
# define ESC			256
# define DOWN_ARROW		264
# define UP_ARROW		265
# define LEFT_ARROW		263
# define RIGHT_ARROW	262
# define W				87
# define S				83
# define A				65
# define D				68

typedef struct s_moves
{
	double	x;
	double	y;
	double	radius;
	double	move_speed;
	double	rotation_speed;
	int		turn_direction;
	int		walk_direction;
	float	rotationangle;
}	t_moves;

typedef struct s_brass
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}		t_brass;

typedef struct s_bras
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}		t_bras;

typedef enum t_wall_dir{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_wall_dir;

typedef struct s_mlx
{
	t_moves			*mv;
	mlx_t			*mlx;
	mlx_image_t		*window;
	mlx_image_t		*mini_map;
	int32_t			color;
	char			*tile_values;
	double			res;
	double			ress;
	int				i;
	bool			foundwall;
	double			xnexthor;
	double			ynexthor;
	bool			foundvwall;
	double			wally;
	double			xnextvert;
	double			horx;
	double			ynextvert;
	double			check_dir;
	int				window_width;
	int				window_height;
	int				num_rays;
	bool			washitvertical;
	double			degree;
	int				map_width;
	int				map_height;
	char			*map_file;
	char			**line;
	char			**map;
	double			mv_step;
	double			xstep;
	double			ystep;
	double			xinsterept;
	double			yinsterept;
	double			ray;
	bool			down;
	bool			up;
	bool			left;
	bool			right;
	double			ray_angle;
	double			distance;
	double			correct;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**floor;
	char			**sky;
	int				*img;
	int				*tex_west;
	int				*tex_east;
	int				*tex_north;
	int				*tex_south;
	int				wallx;
	int				hory;
	int				xwall_hit;
	int				ywall_hit;
	double			wallheight;
	double			wall_start;
	double			dstprojplane;
	int				tex_x;
	double			y_step;
	double			y_start;
}	t_mlx;

void	checkk(t_mlx *mlx);
void	ini(t_mlx *mlx);
void	draw_line_player(t_mlx *mlx, t_brass *bras, int color);
void	draw_line_playerr(t_mlx *mlx, t_bras *bras);
int		*convert_tex_to_bitmap(mlx_texture_t *tex);
void	update(t_mlx *mlx);
void	print_err(char *err);
void	checking_err(t_mlx *mlx, int i);
void	valid_map(t_mlx *mlx);
void	part_of_it(t_mlx *mlx);
void	part_ot_valid_map(t_mlx *mlx, int i, int j);
int		part_of_haswallcircle(t_mlx *mlx, int x, int y);
int		haswall(t_mlx *mlx, int x, int y);
double	norm(float angle);
int		haswallcircle(t_mlx *mlx, int playerX, int playerY);
void	update3(t_mlx *mlx);
void	update2(t_mlx *mlx);
void	new_cast(t_mlx *mlx);
void	check_directions(t_mlx *mlx);
double	dst(double x1, double y1, double x2, double y2);
void	moves(void *vd);
void	setup(t_mlx *mlx);
void	init_textures(t_mlx *mlx);
void	draw_background(t_mlx *mlx, uint32_t floor, mlx_image_t *image);
void	init_p(t_mlx *mlx);
int		get_map(t_mlx *mlx);
void	player_position(t_mlx *mlx);
void	draw(t_mlx *mlx, int i, int j);
int		check_fb(char **a);
void	get_map2(t_mlx *mlx);
void	draw_wal(t_mlx *mlx);
void	size_of_map(t_mlx *mlx);
void	initialisation_ver(t_mlx *mlx);
void	initialisation_hor(t_mlx *mlx);
void	ver_or_hor(t_mlx *mlx);
void	cast_rays(t_mlx *mlx);
void	part_of_cast(t_mlx *mlx, int i, t_brass *bras);
void	d1(t_brass *bras, t_mlx *mlx, int i);
void	d2(t_brass *bras, t_mlx *mlx, int i);
void	syc(t_mlx *mlx);
void	sycc(t_mlx *mlx);
void	range_of_cnf(t_mlx *mlx);
void	range_of_cnff(t_mlx *mlx);
void	error(int o);

#endif
