/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:48:17 by mmartins          #+#    #+#             */
/*   Updated: 2016/11/28 17:03:43 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
