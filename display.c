/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:20:11 by mmartins          #+#    #+#             */
/*   Updated: 2017/02/25 16:19:52 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		relief(t_point *tab_p, t_env *e)
{
	int			i;
	float		x;
	float		y;
	int			z;

	i = 0;
	while (i <= e->nb)
	{
		x = e->zoom * tab_p[i].xx;
		y = e->zoom * tab_p[i].yy;
		z = (e->zoom / e->alpha) * tab_p[i].zz * e->zneg;
		if (e->iso == 1)
		{
			tab_p[i].newx = e->c1 * x - e->c2 * y;
			tab_p[i].newy = e->pivo * (e->c1 / 2 * x + e->c2 / 2 * y) - z;
		}
		else
		{
			tab_p[i].newx = x - e->c1 * z;
			tab_p[i].newy = y - e->c1 / 2 * z;
		}
		i++;
	}
}

static void		middle(t_env *e)
{
	e->winx = (WIN_X / 2) - ((e->xmax * e->zoom) / 2) + ((e->ymax * e->zoom) / 2);
	e->winy = (WIN_Y / 2) - ((e->ymax * e->zoom) / 2);
}

static void			draw_droite_x(t_line *line, t_env *e)
{
	int		i;
	int		cumul;

	cumul = line->dx / 2;
	i = 1;
	e->is_decr = line->dx > 0 ? 1 : -1;
	while (i <= line->dx)
	{
		line->x += line->xinc;
		cumul += line->dy;
		if (cumul >= line->dx)
		{
			cumul -= line->dx;
			line->y += line->yinc;
		}
		mlx_pixel_put(e->mlx, e->win, e->winx + line->x, e->winy + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * i, line->dx));
		i++;
	}
}

static void			draw_droite_y(t_line *line, t_env *e)
{
	int	j;
	int	cumul;

	j = 1;
	cumul = line->dy / 2;
	e->is_decr = line->dy > 0 ? 1 : -1;
	while (j <= line->dy)
	{
		line->y += line->yinc;
		cumul += line->dx;
		if (cumul >= line->dy)
		{
			cumul -= line->dy;
			line->x += line->xinc;
		}
		mlx_pixel_put(e->mlx, e->win, e->winx + line->x, e->winy + line->y,
			ft_get_color(line->cp1, line->cp2, e->is_decr * j, line->dx));
		j++;
	}
}

static void		join_point(t_env *e, t_point *p1, t_point *p2)
{
	t_line		line;

	e->is_decr = 0;
	line.x = p1->newx;
	line.y = p1->newy;
	line.dx = p2->newx - p1->newx;
	line.dy = p2->newy - p1->newy;
	line.xinc = (line.dx >= 0) ? 1 : -1;
	line.yinc = (line.dy >= 0) ? 1 : -1;
	line.dx = ABS(line.dx);
	line.dy = ABS(line.dy);
	line.cp1 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p1->zz - e->zmin);
	line.cp2 = (float)255 / (float)(e->zmax - e->zmin) *
	(float)(p2->zz - e->zmin);
	// mlx_pixel_put(e->mlx, e->win, e->winx + line.x, e->winy + line.y, 0x00FFFFFF);
	if (line.dx >= line.dy)
	{
		draw_droite_x(&line, e);
	}
	else
	{
		draw_droite_y(&line, e);
	}
}

static void	before_draw(t_point *tab_p, t_env *e)
{
	int			i;
	int			x;
	int			y;
	t_line		line;

	i = 0;
	display_comments(e);
	relief(tab_p, e);
	while (i <= e->nb)
	{
		y = tab_p[i].yy;
		x = tab_p[i].xx;

		if (y == (e->ymax - 1) && x != (e->xmax - 1))
			join_point(e, &tab_p[i], &tab_p[i + 1]);
		else if (x == (e->xmax - 1) && y != (e->ymax - 1))
		{
			join_point(e, &tab_p[i], &tab_p[i + e->xmax]);
			join_point(e, &tab_p[i], &tab_p[i + e->xmax - 1]);//diag
		}
		else if (x != (e->xmax - 1) && y != (e->ymax - 1))
		{
			join_point(e, &tab_p[i], &tab_p[i + 1]);
			join_point(e, &tab_p[i], &tab_p[i + e->xmax]);
			join_point(e, &tab_p[i], &tab_p[i + e->xmax + 1]);//diag
			if (x > e->xmin)
				join_point(e, &tab_p[i], &tab_p[i + e->xmax - 1]);//diag
		}
		line.x = tab_p[i].newx;
		line.y = tab_p[i].newy;
		mlx_pixel_put(e->mlx, e->win, e->winx + line.x, e->winy + line.y,
			0x00FFFFFF);
		i++;
	}
	i = 0;
}

static int	my_key(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if ((e->zoom >= 1 && keycode == 78) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom - 5 : e->zoom + 10;
	if (keycode == 53)
		exit(0);
	if (keycode == 34)
	{
		if (e->iso == 1)
			e->iso = 0;
		else if (e->iso == 0)
			e->iso = 1;
	}
	if (keycode == 6 && e->alpha >= 2)
		e->alpha -= 1;
	if (keycode == 0 && e->alpha <= 11)
		e->alpha += 1;
	if (keycode == 45)
	{
		if (e->zneg == 1)
			e->zneg = -1;
		else if (e->zneg == -1)
			e->zneg = 1;
	}
	if (keycode == 123 || keycode == 124)
		e->winx = keycode == 124 ? e->winx + 100 : e->winx - 100;
	if (keycode == 125 || keycode == 126)
		e->winy = keycode == 125 ? e->winy + 100 : e->winy - 100;
	if (keycode == 85 || keycode == 88)
		e->pivo = keycode == 85 ? e->pivo + 0.1 : e->pivo - 0.1;
	if (keycode == 84 || keycode == 83)
	{
		e->divpi = keycode == 84 ? e->divpi + M_PI / 15 : e->divpi - M_PI / 15;
		e->c1 = (float)sin(e->divpi);
		e->c2 = (float)cos(e->divpi);
	}
	mlx_clear_window(e->mlx, e->win);
	before_draw(e->tab_p, e);
	return (0);
}

void		display_comments(t_env *e)
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

void		ft_display(t_point *tab_p, t_env *e)
{
	middle(e);
	before_draw(tab_p, e);
	e->tab_p = tab_p;
	mlx_key_hook(e->win, my_key, e);
	mlx_loop(e->mlx);
}
