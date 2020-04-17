/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_s_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:25:00 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:25:23 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	oper_s(t_dlist **stack_a)
{
	t_dlist	*begin_a;
	t_dlist	*second_el;
	t_dlist	*third_el;
	int		count;

	count = 0;
	begin_a = *stack_a;
	while (begin_a)
	{
		count++;
		begin_a = begin_a->next;
	}
	if (count >= 2)
	{
		begin_a = (*stack_a);
		second_el = begin_a->next;
		third_el = second_el->next;
		begin_a->next = second_el->next;
		begin_a->previous = second_el;
		second_el->next = begin_a;
		second_el->previous = NULL;
		if (third_el)
			third_el->previous = begin_a;
		(*stack_a) = second_el;
	}
}

void	assist_oper_p(t_dlist **begin_push, t_dlist **begin_pop)
{
	if ((*begin_push) != NULL)
	{
		(*begin_pop)->next = (*begin_push);
		(*begin_push)->previous = (*begin_pop);
		(*begin_pop)->previous = NULL;
	}
	else
	{
		(*begin_pop)->next = NULL;
		(*begin_pop)->previous = NULL;
	}
}

void	oper_p(t_dlist **stack_push, t_dlist **stack_pop)
{
	t_dlist *begin_pop;
	t_dlist *begin_push;
	t_dlist *second_el;

	begin_pop = (*stack_pop);
	begin_push = (*stack_push);
	if ((*stack_pop) != NULL)
	{
		if (begin_pop->next != NULL)
		{
			second_el = begin_pop->next;
			assist_oper_p(&begin_push, &begin_pop);
			(*stack_pop) = second_el;
		}
		else
		{
			assist_oper_p(&begin_push, &begin_pop);
			(*stack_pop) = NULL;
		}
		(*stack_push) = begin_pop;
	}
}

void	oper_r(t_dlist **stack)
{
	t_dlist *begin;
	t_dlist *second_el;

	begin = (*stack);
	if (begin && begin->next)
	{
		second_el = begin->next;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = begin;
		begin->previous = (*stack);
		begin->next = NULL;
		second_el->previous = NULL;
		(*stack) = second_el;
	}
}

void	oper_rr(t_dlist **stack)
{
	t_dlist *previous_el;
	t_dlist *begin;

	begin = (*stack);
	if (begin && begin->next)
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		previous_el = (*stack)->previous;
		(*stack)->next = begin;
		(*stack)->previous = NULL;
		begin->previous = (*stack);
		previous_el->next = NULL;
	}
}
