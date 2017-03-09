/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:55:52 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/09 13:44:08 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			initmax(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fdf42");
	e->xmax = 0;
	e->ymax = 0;
	e->xmin = 0;
	e->ymin = 0;
	e->nb = 0;
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->winx = 1000;
	e->winy = 100;
	e->iso = 1;
	e->alpha = 10;
	e->zoom = 50;
	e->zmin = 0;
	e->zmax = 0;
	e->pivo = 1;
	e->zneg = 1;
}

static int			ft_realloc(int fd, t_point **tab_p)
{
	char	**split;
	int		i;
	char	*line;
	int		j;
	t_point	nulle;

	j = 0;
	ft_bzero(&nulle, sizeof(t_point));
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
			i++;
		j = j + i;
		free(line);
	}
	if (!(*tab_p = (t_point*)malloc(sizeof(t_point) * (j + 1))))
		return (0);
	(*tab_p)[j + 1] = nulle;
	close(fd);
	return (j);
}

t_point				*readline(char *line, t_point **tab_p, t_env *e)
{
	int			i;
	char		**linesplit;
	static int	y = 0;
	static int	p = 0;

	i = 0;
	linesplit = ft_strsplit(line, ' ');
	while (linesplit[i])
	{
		(*tab_p)[p].xx = i;
		(*tab_p)[p].yy = y;
		if (((*tab_p)[p].zz = ft_atoi(linesplit[i])) <= e->zmin)
			e->zmin = (*tab_p)[p].zz;
		if (((*tab_p)[p].zz = ft_atoi(linesplit[i])) >= e->zmax)
			e->zmax = (*tab_p)[p].zz;
		i++;
		p++;
	}
	e->xmax = i;
	e->nb += i;
	y++;
	if (y > e->ymax)
		e->ymax = y;
	return (*tab_p);
}

int					main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_point		*tab_p;
	size_t		j;
	t_env		e;

	j = 0;
	initmax(&e);
	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	j = ft_realloc(fd, &tab_p);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		readline(line, &tab_p, &e);
	if (e.nb / e.xmax != e.ymax)
	{
		ft_putstr("\nerror\n");
		return (0);
	}
	close(fd);
	ft_display(tab_p, &e);
	return (1);
}
