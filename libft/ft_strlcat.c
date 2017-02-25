/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:23:52 by mmartins          #+#    #+#             */
/*   Updated: 2016/11/21 18:09:46 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	ret;
	unsigned int	j;

	i = ft_strlen(dest);
	ret = i + ft_strlen(src);
	j = 0;
	if (n < i)
		return (ft_strlen(src) + n);
	if (n > i + 1)
	{
		while (src[j] && j < n - i - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (ret);
}
