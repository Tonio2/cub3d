/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:31:14 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 18:22:27 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	ft_parse_dim(char *str, t_cub *config)
{
	int	cpt;

	cpt = 1;
	while (str[cpt] == ' ')
		cpt++;
	while (str[cpt] != ' ')
	{
		if (ft_in(str[cpt], "0123456789"))
			config->dim_x = config->dim_x * 10 + str[cpt] - '0';
		else
			ft_print_error("Dimensions incorrectes");
		cpt++;
	}
	while (str[cpt] == ' ')
		cpt++;
	while (str[cpt] != ' ')
	{
		if (ft_in(str[cpt], "0123456789"))
			config->dim_y = config->dim_y * 10 + str[cpt] - '0';
		else
			ft_print_error("Dimensions incorrectes");
		cpt++;
	}
	config->config_ready[0] = 1;
}

int	check_texture_path(char *str)
{
	return (1);
}

void	ft_parse_texture(char *str, t_cub *config, int mode)
{
	int	cpt;

	cpt = 2 - (mode == 5);
	while (str[cpt] == ' ')
		cpt++;
	if (str[cpt] == '.' && str[cpt + 1] == '/')
	{
		if (!check_texture_path(*(str + cpt)))
			ft_print_error("Nom de fichier de texture incorrect");
		config->textures_path[mode] = ft_strcreate(*(str + cpt));
	}
	config->config_ready[mode + 1] = 1;
}

void	ft_parse_color(char *str, t_cub *config, char mode)
{
	int	cpt;
	int	color;

	cpt = 1;
	color = 0;
	while (color < 3)
	{
		while (str[cpt] == ' ')
			cpt++;
		while (str[cpt] != ',')
		{
			if (!ft_in(str[cpt], "0123456789"))
				ft_print_error("Format de couleur incorrect");
			config->F[color] = config->F[color] * 10 + str[cpt] - '0';
		}
		color++;
	}
}

void	ft_parse_config_line(char *str, t_cub *config)
{
	if (str[0] == 'R')
		ft_parse_dim(str, config);
	else if (str[0] == 'N' && str[1] == 'O')
		ft_parse_texture(str, config, 0);
	else if (str[0] == 'S' && str[1] == 'O')
		ft_parse_texture(str, config, 1);
	else if (str[0] == 'W' && str[1] == 'E')
		ft_parse_texture(str, config, 2);
	else if (str[0] == 'E' && str[1] == 'A')
		ft_parse_texture(str, config, 3);
	else if (str[0] == 'S')
		ft_parse_texture(str, config, 4);
	else if (str[0] == 'F')
		ft_parse_color(str, config, 'F');
	else if (str[0] == 'C')
		ft_parse_color(str, config, 'C');
	else
		ft_print_error("Format incorrect");
}
