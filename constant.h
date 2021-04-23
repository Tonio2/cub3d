/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:13 by alabalet          #+#    #+#             */
/*   Updated: 2021/04/23 18:16:00 by alabalet         ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <math.h>

typedef struct s_cub
{
	int		dim_x;
	int		dim_y;
	char	*textures_path[5];
	int		bg[2][3];
	int		config_ready[8];
	int		height;
	int		width;
	char	**map;
	char	o_init;
	int		pos_x;
	int		pos_y;
}			t_cub;

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_coor {
	int	x;
	int	y;
	int	speed_x;
	int	speed_y;
}			t_coor;

typedef struct s_vector {
	double	x;
	double	y;
}			t_vector;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		time;
	double		oldTime;
	t_cub		config;
}				t_vars;

char		*ft_strcreate(char *str);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
int			ft_in(char c, char *str);

int			ft_len(char *str);
void		ft_strcpy(char *dst, char *src);
void		ft_strcat(char **dst, char *src);
int			ft_parse_buf(char **dst, char *src);
int			get_next_line(int fd, char **line);

void		ft_print_error(char *msg);

void		ft_parse_dim(char *str, t_cub *config);
int			check_texture_path(char *str);
void		ft_parse_texture(char *str, t_cub *config, int mode);
void		ft_parse_color(char *str, t_cub *config, int mode);
void		ft_parse_config_line(char *str, t_cub *config);

void		ft_parse_map_lines(t_map_line *lines, t_cub *config);
t_map_line	*ft_parse_map(int fd);

void		ft_check_config(t_cub *c);
void		ft_check_color(int *bg);
void		ft_check_map(t_cub *c);

void		ft_config_init(t_cub *config);
int			is_config_ready(t_cub *config);
void		ft_parse_config_file(char *filename, t_cub *config);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_print_square(t_data *img);
void		ft_print_rainbow(t_data *img, int x_ini, int y_ini);
void		ft_verline(t_data *img, int x, int drawStart, int drawEnd, int side);

int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(void);
int			esc_close_window(int keycode, t_vars *vars);
int			ft_close(int keycode, t_vars *vars);
int			ft_update(t_vars *vars);
int			press_hook(int keycode, t_vars *vars);
int			release_hook(int keycode, t_vars *vars);
#endif