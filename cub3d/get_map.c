/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:42:25 by nchaknan          #+#    #+#             */
/*   Updated: 2023/09/23 22:25:58 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_files(t_mlx *mlx)
{
	if ((!mlx->no) || (!mlx->ea) || (!mlx->we) || (!mlx->so))
		print_err("ERROR  ::  THERES NO TEXTURES FILE!\n");
}

void	part_1_getmap(t_mlx *mlx, int i, int j)
{
	if (mlx->line[i][j] == ' ')
		j++;
	if (mlx->line[i][j] == '\t')
		print_err("ERROR\n");
	if (mlx->line[i][j] == 'N' && mlx->line[i][j + 1] == 'O')
	{
		if (mlx->no)
			print_err("duplicate (NO)\n");
		else
			mlx->no = ft_strdupp(mlx->line[i], 5);
	}
	if (mlx->line[i][j] == 'S' && mlx->line[i][j + 1] == 'O')
	{
		if (mlx->so)
			print_err("duplicate (SO)\n");
		else
			mlx->so = ft_strdupp(mlx->line[i], 5);
	}
}

void	part_2_getmap(t_mlx *mlx, int i, int j)
{
	if (mlx->line[i][j] == 'W' && mlx->line[i][j + 1] == 'E')
	{
		if (mlx->we)
			print_err("duplicate (WE)\n");
		else
			mlx->we = ft_strdupp(mlx->line[i], 5);
	}
	if (mlx->line[i][j] == 'E' && mlx->line[i][j + 1] == 'A')
	{
		if (mlx->ea)
			print_err("duplicate (EA)\n");
		else
			mlx->ea = ft_strdupp(mlx->line[i], 5);
	}
}

void	part_3_getmap(t_mlx *mlx, int i, int j)
{
	if (mlx->line[i][j] == 'F' && mlx->line[i][j + 1] == ' ')
	{
		if (mlx->floor)
			print_err("duplicate (F)\n");
		else
		{
			mlx->floor = ft_split(mlx->line[i], ',');
			range_of_cnff(mlx);
		}
		if (!check_fb(mlx->floor))
			print_err("ERROR\n");
	}
	if (mlx->line[i][j] == 'C' && mlx->line[i][j + 1] == ' ')
	{
		if (mlx->sky)
			print_err("duplicate (C)\n");
		else
		{
			mlx->sky = ft_split(mlx->line[i], ',');
			range_of_cnf(mlx);
		}
		if (!check_fb(mlx->sky))
			print_err("ERROR\n");
	}
}

int	get_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	ini(mlx);
	while (mlx->line[i])
	{
		j = 0;
		while (mlx->line[i][j])
		{
			part_1_getmap(mlx, i, j);
			part_2_getmap(mlx, i, j);
			part_3_getmap(mlx, i, j);
			if (mlx->line[i][j] == '1' && mlx->line[i][j + 1] == '1')
			{
				check_files(mlx);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
