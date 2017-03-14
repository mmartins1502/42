/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:58:35 by mmartins          #+#    #+#             */
/*   Updated: 2017/03/13 16:05:25 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_bis(char c)
{
	if (c < '0' || c > '9')
	{
		ft_putstr("error bis\n");
		exit(0);
	}
	return (1);
}

int		error(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fdf file_name\n");
		exit(0);
	}
	return (1);
}
