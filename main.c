/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:34:23 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/29 16:54:44 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "constant.h"

void	ft_print_cub(t_cub c)
{
	int	row;
	int	column;

	row = -1;
	printf("R %d %d\n", c.dim_x, c.dim_y);
	printf("NO %s\n", c.textures_path[0]);
	printf("SO %s\n", c.textures_path[1]);
	printf("WE %s\n", c.textures_path[2]);
	printf("EA %s\n", c.textures_path[3]);
	printf("S %s\n", c.textures_path[4]);
	printf("F %d,%d,%d\n", c.bg[0][0], c.bg[0][1], c.bg[0][2]);
	printf("F %d,%d,%d\n", c.bg[1][0], c.bg[1][1], c.bg[1][2]);
	printf("map height : %d\n", c.height);
	printf("map width : %d\n", c.width);
	while (++row < c.height)
	{
		column = -1;
		while (++column < c.width)
			printf("%c", c.map[row][column]);
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_cub	config;

	if (ac != 2)
	{
		printf("Usage : ./cub3d config_file_path");
		return (1);
	}
	ft_parse_config_file(av[1], &config);
	ft_print_cub(config);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
