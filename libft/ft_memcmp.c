/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:50:08 by mmartins          #+#    #+#             */
/*   Updated: 2016/11/25 16:33:13 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sone;
	unsigned char	*stwo;

	i = 0;
	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	while (i < n)
	{
		if (sone[i] != stwo[i])
			return ((int)(sone[i] - stwo[i]));
		i++;
	}
	return (0);
}
