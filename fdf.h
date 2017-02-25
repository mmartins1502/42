/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:38:57 by mmartins          #+#    #+#             */
/*   Updated: 2017/02/24 14:52:58 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 1500
# define WIN_X 2000
# define WIN_Y 1400
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef struct	s_point
{
	float	newx;
	float	newy;
	int		xx;
	int		xo;
	int		yy;
	int		yo;
	int		zz;
}				t_point;

typedef struct	s_line
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	float	cp1;
	float	cp2;
}				t_line;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;
	int		zmax;
	int		zmin;
	int		nb;
	int		zoom;
	int		tr;
	int		td;
	int		iso;
	float	c1;
	float	c2;
	float	divpi;
	int		is_decr;
	int		winx;
	int		winy;
	int		alpha;
	float	pivo;
	int		zneg;
	t_point	*tab_p;
}				t_env;

unsigned int	ft_get_color(int cp1, int cp2, int i, int delta);
int				ft_color(int coef);
void			display_comments(t_env *e);
t_point			*readline(char *line, t_point **tab_p, t_env *e);
void			ft_display(t_point *tab_p, t_env *e);
int				get_next_line(int const fd, char **line);
int				main(int ac, char **av);

#endif
