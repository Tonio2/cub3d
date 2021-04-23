/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:34:23 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/23 18:04:09 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("orientation initial : %c\n", c.o_init);
	while (++row < c.height)
	{
		column = -1;
		while (++column < c.width)
			printf("%c", c.map[row][column]);
		printf("\n");
	}
}

int	main(void)
{
	t_vars		vars;

	ft_parse_config_file("config_dir/lodev.cub", &vars.config);
	ft_print_cub(vars.config);
	vars.pos.x = vars.config.pos_x + 0.5;
	vars.pos.y = vars.config.pos_y + 0.5;
	vars.dir.x = (vars.config.o_init == 'E') - (vars.config.o_init == 'W');
	vars.dir.y = (vars.config.o_init == 'S') - (vars.config.o_init == 'N');
	vars.plane.x = -0.66 * vars.dir.y;
	vars.plane.y = 0.66 * vars.dir.x;
	vars.time = 0;
	vars.oldTime = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Lodev");
	vars.img.img = mlx_new_image(vars.mlx, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_loop_hook(vars.mlx, ft_update, &vars);
	mlx_hook(vars.win, 2, 0L, press_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
