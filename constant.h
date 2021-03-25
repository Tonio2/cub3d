/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 18:19:38 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_cub
{
	int		dim_x;
	int		dim_y;
	char	*textures_path[5];
	int		F[3];
	int		C[3];
	int		config_ready[8];
	char	**map;
}			t_cub;

int		ft_len(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char **dst, char *src);
int		ft_parse_buf(char **dst, char *src);
int		get_next_line(int fd, char **line);

void	ft_print_error(char *msg);

void	parse_config(char *filename, t_cub *config);
#endif