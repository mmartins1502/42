/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:01:56 by mmartins          #+#    #+#             */
/*   Updated: 2016/11/25 16:04:41 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *sout, const char *sin, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	len = ft_strlen(sin);
	if (!len)
		return ((char *)sout);
	while (sout[i] && i < n)
	{
		j = 0;
		while (sout[i + j] == sin[j] && sout[i + j] && sin[j] && i + j < n)
			j++;
		if (j == len)
			return ((char *)sout + i);
		i++;
	}
	return (NULL);
}
