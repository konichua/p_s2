/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:26:48 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 14:37:36 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		find_min_int(t_dlist *begin)
{
	int min;

	min = begin->num;
	while (begin)
	{
		if (begin->num < min)
			min = begin->num;
		begin = begin->next;
	}
	return (min);
}

int		find_max_int(t_dlist *begin)
{
	int max;

	max = begin->num;
	while (begin)
	{
		if (begin->num > max)
			max = begin->num;
		begin = begin->next;
	}
	return (max);
}

int		find_end_int(t_dlist **list)
{
	t_dlist *tmp;

	tmp = (*list);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->num);
}

int		ft_dlistlen(t_dlist *begin)
{
	int i;

	i = 0;
	if (begin)
	{
		i++;
		while (begin->next != NULL)
		{
			begin = begin->next;
			i++;
		}
	}
	return (i);
}
