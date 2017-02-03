/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:32:57 by mrobinso          #+#    #+#             */
/*   Updated: 2017/01/13 15:32:59 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyfunction(int keycode, t_nuts *deez)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT)
		move_left(deez);
	else if (keycode == RIGHT)
		move_right(deez);
	else if (keycode == DOWN)
		move_down(deez);
	else if (keycode == UP)
		move_up(deez);
	else if (keycode == W)
		rotate_up(deez);
	else if (keycode == A)
		rotate_left(deez);
	else if (keycode == S)
		rotate_down(deez);
	else if (keycode == D)
		rotate_right(deez);
	else if (keycode == R)
		reset_and_draw(deez);
	return (0);
}

void	create_horizontal(t_nuts *deez)
{
	t_point *lst;

	lst = deez->lst;
	while (lst->next)
	{
		if (lst->y == lst->next->y)
			draw_line(deez, lst, lst->next);
		lst = lst->next;
	}
}

void	create_vertical(t_nuts *deez)
{
	t_point *lst;
	t_point	*point2;

	lst = deez->lst;
	while (lst)
	{
		point2 = lst->next;
		while (point2 && lst->x != point2->x)
			point2 = point2->next;
		draw_line(deez, lst, point2);
		lst = lst->next;
	}
}

void	create_art(t_nuts *deez)
{
	create_vertical(deez);
	create_horizontal(deez);
}

void	window_init(t_point *lst)
{
	void	*mlx;
	void	*win;
	t_nuts	*deez;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Big ass window");
	deez = (t_nuts *)malloc(sizeof(t_nuts));
	if (!deez)
	{
		ft_putstr("Not enough space in MeMorY");
		return ;
	}
	deez->lst = lst;
	deez->mlx = mlx;
	deez->win = win;
	deez->view_x = 32;
	deez->view_y = 18;
	deez->origin_x = 350;
	deez->origin_y = 190;
	deez->depth = 3;
	deez->max_z = getmax_z(lst);
	deez->min_z = getmin_z(lst);
	create_art(deez);
	mlx_key_hook(win, keyfunction, deez);
	mlx_loop(mlx);
}
