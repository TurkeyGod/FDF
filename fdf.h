/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:22:57 by mrobinso          #+#    #+#             */
/*   Updated: 2016/12/08 14:22:58 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define ESC 53

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# define WHITE	0xFFFFFF
# define PURPLE	0x8E44AD
# define GREEN	0x2ECC71

# define ESC	53
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126
# define W		13
# define A		0
# define S		1
# define D		2
# define R		15

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}				t_point;

typedef struct	s_nuts
{
	void	*mlx;
	void	*win;
	t_point	*lst;
	int		view_x;
	int		view_y;
	int		origin_x;
	int		origin_y;
	int		max_z;
	int		min_z;
	int		depth;
}				t_nuts;

int				color_x(t_nuts *deez, double cur, t_point *lst, t_point *p2);
int				color_y(t_nuts *deez, double cur, t_point *lst, t_point *p2);
int				getmax_z(t_point *lst);
int				getmin_z(t_point *lst);
int				move_up(t_nuts *deez);
int				move_right(t_nuts *deez);
int				move_left(t_nuts *deez);
int				move_down(t_nuts *deez);
int				rotate_up(t_nuts *deez);
int				rotate_right(t_nuts *deez);
int				rotate_down(t_nuts *deez);
int				rotate_left(t_nuts *deez);
int				reset_and_draw(t_nuts *deez);
int				keyfunction(int keycode, t_nuts *deez);
void			connect_vert(t_nuts *deez, t_point *lst, t_point *p2);
void			connect_x(t_nuts *deez, t_point *lst, t_point *p2);
void			connect_y(t_nuts *deez, t_point *lst, t_point *p2);
void			draw_line(t_nuts *deez, t_point *lst, t_point *p2);
void			remove_last(t_point *lst);
void			create_horizontal(t_nuts *deez);
void			create_vertical(t_nuts *deez);
void			create_art(t_nuts *deez);
void			window_init(t_point *lst);
double			visual_x(t_nuts *deez, t_point *lst);
double			visual_y(t_nuts *deez, t_point *lst);
t_point			*store_coordinate(t_point *lst, int z, int y, int x);
t_point			*read_file(int fd, int x);
t_nuts			*reset(t_nuts *deez);

#endif
