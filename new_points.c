/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:06:41 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/09 13:07:54 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		relief(t_point *tab_p, t_env *e)
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
