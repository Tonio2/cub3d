/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:17:07 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/28 16:13:59 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_verline(t_data *img, int x, t_line draw, int color)
{
	int	y;
	int	color1;
	int	color2;

	color1 = 0x00FF00;
	color2 = 0xFF0000;
	y = draw.drawStart -1;
	while (++y < draw.drawEnd)
		my_mlx_pixel_put(img, x, y, color);
}
