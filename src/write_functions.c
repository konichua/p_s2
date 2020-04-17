/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:32:58 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 14:33:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	write_function(t_dlist **a, t_dlist **b, char *buf)
{
	if (a == NULL)
		write_function2(b, buf);
	else if (b == NULL)
		write_function2(a, buf);
	else if (ft_strcmp(buf, "pa") == 0)
	{
		write(1, "pa\n", 3);
		oper_p(a, b);
		if ((*a)->flag == 1)
			display_stack(a, b);
	}
	else if (ft_strcmp(buf, "pb") == 0)
	{
		write(1, "pb\n", 3);
		oper_p(a, b);
		if ((*a)->flag == 1)
			display_stack(b, a);
	}
	write_function4(a, b, buf);
}

void	write_function2(t_dlist **list, char *buf)
{
	if (ft_strcmp(buf, "sa") == 0)
	{
		write(1, "sa\n", 3);
		oper_s(list);
		if ((*list)->flag == 1)
			display_stack(list, NULL);
	}
	else if (ft_strcmp(buf, "sb") == 0)
	{
		write(1, "sb\n", 3);
		oper_s(list);
		if ((*list)->flag == 1)
			display_stack(NULL, list);
	}
	else if (ft_strcmp(buf, "ra") == 0)
	{
		write(1, "ra\n", 3);
		oper_r(list);
		if ((*list)->flag == 1)
			display_stack(list, NULL);
	}
	write_function3(list, buf);
}

void	write_function3(t_dlist **list, char *buf)
{
	if (ft_strcmp(buf, "rra") == 0)
	{
		write(1, "rra\n", 4);
		oper_rr(list);
		if ((*list)->flag == 1)
			display_stack(list, NULL);
	}
	else if (ft_strcmp(buf, "rrb") == 0)
	{
		write(1, "rrb\n", 4);
		oper_rr(list);
		if ((*list)->flag == 1)
			display_stack(NULL, list);
	}
	else if (ft_strcmp(buf, "rb") == 0)
	{
		write(1, "rb\n", 3);
		oper_r(list);
		if ((*list)->flag == 1)
			display_stack(NULL, list);
	}
}

void	write_function4(t_dlist **a, t_dlist **b, char *buf)
{
	if (ft_strcmp(buf, "rrr") == 0)
	{
		write(1, "rrr\n", 4);
		oper_rr(a);
		oper_rr(b);
		if ((*a)->flag == 1)
			display_stack(a, b);
	}
	if (ft_strcmp(buf, "ss") == 0)
	{
		write(1, "ss\n", 3);
		oper_s(a);
		oper_s(b);
		if ((*a)->flag == 1)
			display_stack(a, b);
	}
	if (ft_strcmp(buf, "rr") == 0)
	{
		write(1, "rr\n", 3);
		oper_r(a);
		oper_r(b);
		if ((*a)->flag == 1)
			display_stack(a, b);
	}
}
