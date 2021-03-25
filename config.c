/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:35:32 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 18:20:47 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"

void	config_init(t_cub *config)
{
	int	cpt;

	cpt = 0;
	while (cpt < 8)
		config->config_ready[cpt] = 0;
	config->dim_x = 0;
	config->dim_y = 0;
	config->F[0] = 0;
	config->F[1] = 0;
	config->F[2] = 0;
	config->C[0] = 0;
	config->C[1] = 0;
	config->C[2] = 0;
}

int	is_config_ready(t_cub *config)
{
	int	cpt;

	cpt = 0;
	while (cpt < 8)
		if (config->config_ready[cpt] == 0)
			return (0);
	return (1);
}

void	parse_config(char *filename, t_cub *config)
{
	int		fd;
	int		gnl_ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	config_init(config);
	while (!is_config_ready(config))
	{
		if (get_next_line(fd, &line) <= 0)
			ft_print_error("Erreur lors de la lecture du fichier");
		if (ft_len(line))
			ft_parse_config_line(line, config);
	}
	if (get_next_line(fd, &line) <= 0)
		ft_print_error("Erreur lors de la lecture du fichier");
	while (!ft_len(line))
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret <= 0)
			ft_print_error("Erreur lors de la lecture du fichier");
	}
	while (gnl_ret == 1)
	{
		ft_parse_map_line(line, config);
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			ft_print_error("Erreur lors de la lecture du fichier");
	}
}
