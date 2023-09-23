/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:11:47 by namorgha          #+#    #+#             */
/*   Updated: 2023/09/23 01:25:25 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

int	get_color_from_img_data(mlx_texture_t *tex, unsigned int idx)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	int				rgb;

	r = tex->pixels[idx] & 0xFF;
	g = tex->pixels[idx + 1] & 0xFF;
	b = tex->pixels[idx + 2] & 0xFF;
	a = tex->pixels[idx + 3] & 0xFF;
	rgb = (r << 24) + (g << 16) + (b << 8) + (a);
	return (rgb);
}

int	*convert_tex_to_bitmap(mlx_texture_t *tex)
{
	int				*ret;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	ret = malloc(sizeof(unsigned int) * (TEX_SZ * TEX_SZ * 4));
	while (i < (TEX_SZ * TEX_SZ * 4))
	{
		ret[j] = get_color_from_img_data(tex, i);
		j++;
		i += 4;
	}
	return (ret);
}

int	count_linss(char *lin)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(lin, O_RDONLY);
	lin = get_next_line(fd);
	while (lin != NULL)
	{
		free(lin);
		lin = get_next_line(fd);
		i++;
	}
	free(lin);
	close(fd);
	return (i);
}

void	read_map(t_mlx *mlx, char *a)
{
	int	i;
	int	fd;
	int	o;

	i = 0;
	o = ft_strlen(a);
	o -= 4;
	if (ft_strncmp(&a[o], ".cub", 4))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	mlx->line = malloc(sizeof(char *) * (count_linss(a) + 1));
	fd = open(a, O_RDONLY);
	mlx->line[i] = get_next_line(fd);
	if (!(mlx->line[i]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (mlx->line[i] != NULL)
		mlx->line[++i] = get_next_line(fd);
	get_map2(mlx);
	size_of_map(mlx);
	close(fd);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	(void)ac;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	ft_bzero(mlx, sizeof(mlx));
	mlx->mv = malloc(sizeof(t_moves));
	if (ac < 2)
		print_err("ERROR\n");
	if (!mlx->mv)
	{
		free(mlx);
		return (1);
	}
	read_map(mlx, av[1]);
	valid_map(mlx);
	setup(mlx);
	free(mlx->mv);
	free(mlx);
	return (0);
}
