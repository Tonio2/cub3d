/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:17:07 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/23 14:41:10 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_print_square(t_data *img)
{
	int	row;
	int	column;

	row = 49;
	while (++row < 100)
	{
		column = 49;
		while (++column < 100)
			my_mlx_pixel_put(img, row, column, 0x00FF0000);
	}
}

void	ft_print_rectangle(t_data *img, int *x, int *y, int color)
{
	int	row;
	int	column;

	row = y[0] - 1;
	while (++row < y[1])
	{
		column = x[0] - 1;
		while (++column < x[1])
			my_mlx_pixel_put(img, column, row, color);
	}
}

void	ft_verline(t_data *img, int x, int drawStart, int drawEnd, int side)
{
	int	y;
	int	color1;
	int	color2;

	color1 = 0x00FF00;
	color2 = 0xFF0000;
	y = drawStart -1;
	while (++y < drawEnd)
	{
		if (side)
			my_mlx_pixel_put(img, x, y, color1);
		else
			my_mlx_pixel_put(img, x, y, color2);
	}
}

void	ft_print_rainbow(t_data *img, int x_ini, int y_ini)
{
	int	x[2];
	int	y[2];

	x[0] = x_ini;
	x[1] = x_ini + 180;
	y[0] = y_ini;
	y[1] = y_ini + 20;
	ft_print_rectangle(img, x, y, 0x00FF0000);
	y[0] = y_ini + 20;
	y[1] = y_ini + 40;
	ft_print_rectangle(img, x, y, 0x00FFA500);
	y[0] = y_ini + 40;
	y[1] = y_ini + 60;
	ft_print_rectangle(img, x, y, 0x00FFFF00);
	y[0] = y_ini + 60;
	y[1] = y_ini + 80;
	ft_print_rectangle(img, x, y, 0x0000FF00);
	y[0] = y_ini + 80;
	y[1] = y_ini + 100;
	ft_print_rectangle(img, x, y, 0x000000FF);
	y[0] = y_ini + 100;
	y[1] = y_ini + 120;
	ft_print_rectangle(img, x, y, 0x00A500FF);
}
