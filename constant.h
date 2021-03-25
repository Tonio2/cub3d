/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/03/25 14:47:58 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# include <stdio.h>

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

void	parse_config(char *filename, t_cub *config);
#endif