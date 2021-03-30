/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:17:07 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/30 10:26:53 by alabalet         ###   ########.fr       */
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

void	ft_print_rainbow(t_data *img)
{
	int	x[2];
	int	y[2];

	x[0] = 1;
	x[1] = 1919;
	y[0] = 50;
	y[1] = 70;
	ft_print_rectangle(img, x, y, 0x00FF0000);
	y[0] = 70;
	y[1] = 90;
	ft_print_rectangle(img, x, y, 0x00FFA500);
	y[0] = 90;
	y[1] = 110;
	ft_print_rectangle(img, x, y, 0x00FFFF00);
	y[0] = 110;
	y[1] = 130;
	ft_print_rectangle(img, x, y, 0x0000FF00);
	y[0] = 130;
	y[1] = 150;
	ft_print_rectangle(img, x, y, 0x000000FF);
	y[0] = 150;
	y[1] = 170;
	ft_print_rectangle(img, x, y, 0x00A500FF);
}
