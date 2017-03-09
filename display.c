/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:56:09 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/09 13:04:48 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		middle(t_env *e)
{
	e->winx = (WIN_X / 2) - ((e->xmax * e->zoom) / 2) +
	((e->ymax * e->zoom) / 2);
	e->winy = (WIN_Y / 2) - ((e->ymax * e->zoom) / 2);
}

void			display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0xFFFFFF,
		"Quit             = esc");
	mlx_string_put(e->mlx, e->win, 10, 15, 0xFFFFFF,
		"Zoom in / out    = + / -");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
		"Manage z : + / - = z / a");
	mlx_string_put(e->mlx, e->win, 10, 45, 0xFFFFFF,
		"Negative z       = n");
	mlx_string_put(e->mlx, e->win, 10, 60, 0xFFFFFF,
		"Switch proj      = i");
	mlx_string_put(e->mlx, e->win, 10, 75, 0xFFFFFF,
		"Move map         = < > ^ v");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
		"Rot Horizon      = 1 / 2");
	mlx_string_put(e->mlx, e->win, 10, 105, 0xFFFFFF,
		"Rot Vertical     = 3 / 6");
}

void			ft_display(t_point *tab_p, t_env *e)
{
	middle(e);
	before_draw(tab_p, e);
	e->tab_p = tab_p;
	mlx_key_hook(e->win, my_key, e);
	mlx_loop(e->mlx);
}
