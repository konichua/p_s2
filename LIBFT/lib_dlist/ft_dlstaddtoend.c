/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_first_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:27:36 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:28:12 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/dlist.h"

void	ft_dlstadd_to_end(t_dlist **alst, t_dlist **new)
{
	t_dlist *begin;

	begin = (*alst);
	if (begin)
	{
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = (*new);
		(*new)->previous = (*alst);
		(*new)->next = NULL;
		(*alst) = begin;
	}
	else
		(*alst) = (*new);
}
