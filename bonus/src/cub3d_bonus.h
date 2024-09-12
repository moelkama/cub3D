/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:33:13 by moelkama          #+#    #+#             */
/*   Updated: 2023/08/06 15:40:26 by akatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define BUFFER_SIZE 1

typedef struct s_img
{
	void	*img;
	char	*buffer;
	int		hight;
	int		width;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}			t_img;

typedef struct s_mini_map
{
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
	int	tmp;
	int	x_mini_map;
	int	y_mini_map;
	int	x;
	int	i;
	int	y;
}			t_mini_map;

typedef struct s_new
{
	t_img	*texture;
	char	*dst;
	char	*rst;
	int		m;
	float	l;
	int		b;
	int		f;
	int		a;
}			t_new;

typedef struct s_window
{
	void	*win;
	int		hight;
	int		width;
}			t_window;

typedef struct s_intersection
{
	float	x;
	float	y;
	float	ray;
	int		direct;
}			t_intersection;

typedef struct s_move
{
	float	x;
	float	y;
	float	teta;
	float	vites;
	float	teta_vites;
}			t_move;
typedef struct s_weapon
{
	t_img	*w1;
	t_img	*w2;
	t_img	*w3;
	t_img	*w4;
}			t_weapon;
typedef struct s_info
{
	void		*mlx;
	char		**map;
	char		**my_map;
	int			zooom;
	int			size;
	t_window	*window;
	long		sky_color;
	long		floor_color;
	t_weapon	*weapon;
	int			event_p;
	t_move		*move;
	t_img		*door;
	t_img		*no;
	t_img		*so;
	t_img		*ea;
	t_img		*we;
	t_img		*img;
	int			move_up;
	int			move_down;
	int			move_right;
	int			move_left;
	int			rotation_right;
	int			rotation_left;
}				t_info;

t_intersection	*get_y(t_info *info, float alpha);
t_intersection	*get_x(t_info *info, float alpha);
t_intersection	*get_intersection(t_info *info, float alpha);
t_intersection	*new_intersection(void);
t_window		*new_window(void);
t_move			*new_move(void);
t_info			*new_info(void);
char			**ft_split(char *str, char c);
char			*readfile(char *file);
int				ft_strlen(char *str);
int				arr_size(char **arr);
int				move(int key, t_info *info);
void			put_vector(t_info *info);
void			begin_status(t_info *info);
void			fall_img(t_info *info, t_intersection *position, int size);
t_img			*get_texture(t_info *info, t_intersection *position);
int				get_m(t_info *info, t_intersection *position, int width);
void			collisions(t_info *info, float alpha);
t_info			*handling_map(char	*file);
int				ft_strlen(char *str);
int				ft_check(char *str, char c);
char			**ft_split(char *s, char c);
char			*ft_substr(char *s, int start, int len);
char			*ft_search_line(char **map, char *str);
int				ft_strcmp(char *str1, char *str2);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_readfile(int fd);
int				ft_atoi(const char *str);
void			ft_free(char **str);
int				ft_len_line(char **str);
char			**ft_return_my_map(char **map, char *chrct);
void			ft_putplayer_img(t_info *data);
void			ft_putmini_map(t_info *data);
char			*ft_readfile(int fd);
int				rotate_with_mouse(int x, int y, t_info *data);
int				do_event(t_info *data);
t_weapon		*new_weapon(void);
int				ft_strcmp(char *str1, char *str2);
int				ft_handling_map_name(char *map_name);
int				ft_check(char *str, char c);
int				handle_caracteres(char **map, char *str1, char *str2);
int				ft_check_str(char *str1, char *str2);
t_img			*new_img(void);
char			*ft_alloc(char *str);
char			**ft_return_map(char **line);
char			*get_line(char *str);
int				check_newline(char *str);
int				ft_len_line(char **str);
int				handling_wall(char **map);
void			ft_write_err(char *str);
void			ft_give_value2(t_info **data, char **floor, char **ceiling);
void			ft_protection_x(int *start_x, int *end_x, t_info *data);
void			ft_protection_y(int *start_y, int *end_y, t_info *data);
void			give_mini_map_value(t_mini_map *mini, t_info *data);
void			ft_put_color(t_info *data, t_mini_map *mini);
void			ft_mlx_put_pixel(t_info *data, int x, int y, int color);
void			move_up(t_info *info, float alpha);
void			move_theta(t_info *info, int k);
int				remove_move(int key, t_info *info);
int				do_move(t_info *data);

#endif
