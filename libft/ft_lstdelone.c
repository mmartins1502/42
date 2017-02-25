/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:38:29 by mmartins          #+#    #+#             */
/*   Updated: 2016/11/30 16:43:45 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *begin_list;
	del(list->content, list->content_size);
	free(list);
	*begin_list = NULL;
}
