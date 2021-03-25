/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 15:09:37 by alabalet         ###   ########.fr       */
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

typedef struct s_color
{
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
}					t_color;

typedef struct s_cub
{
	int		dim_x;
	int		dim_y;
	char	*SO_path;
	char	*ZE_path;
	char	*EA_path;
	char	*S_path;
	t_color	F;
	t_color	C;
	char	**map;
}			t_cub;

int		ft_len(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char **dst, char *src);
int		ft_parse_buf(char **dst, char *src);
int		get_next_line(int fd, char **line);

void	parse_config(char *filename, t_cub *config);
#endif