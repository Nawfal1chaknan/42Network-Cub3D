/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:09:43 by nchaknan          #+#    #+#             */
/*   Updated: 2023/09/23 22:25:15 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkk(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] != '\n')
		{
			if (mlx->map[i][j] != ' ' && mlx->map[i][j] != 'S' && \
				mlx->map[i][j] != 'W' && mlx->map[i][j] != 'E' && mlx->map[i][j \
					] != 'N' && mlx->map[i][j] != '0' && mlx->map[i][j] != '1')
				print_err("ERROR\n");
			j++;
		}
		i++;
	}
}

void	valid_map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	part_of_it(mlx);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] != '\n')
		{
			if (mlx->map[i][j] == 'W' || mlx->map[i][j] == 'N' || \
				mlx->map[i][j] == 'S' || mlx->map[i][j] == 'E')
			{
				c++;
				if (c > 1)
					print_err("ERROE :: invalid map !!\n");
			}
			if (mlx->map[i][j] == '0')
				part_ot_valid_map(mlx, i, j);
			j++;
		}
		i++;
	}
}

void	error(int o)
{
	if (o == 0)
		print_err("ERROR :: W BACH BGHI TL3EB AL BATAL !!\n");
}
