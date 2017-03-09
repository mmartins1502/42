/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:14:48 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/09 13:22:22 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		my_key_bis(int keycode, t_env *e)
{
	if ((e->zoom > 5 && keycode == 78) || keycode == 69)
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
	mlx_clear_window(e->mlx, e->win);
	before_draw(e->tab_p, e);
	return (0);
}

int				my_key(int keycode, t_env *e)
{
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
	my_key_bis(keycode, e);
	return (0);
}
