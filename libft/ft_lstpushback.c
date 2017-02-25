/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:34:40 by mmartins          #+#    #+#             */
/*   Updated: 2016/12/01 11:39:45 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!*alst)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
