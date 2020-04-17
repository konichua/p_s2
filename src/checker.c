/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:22:05 by mburnett          #+#    #+#             */
/*   Updated: 2020/03/15 19:22:29 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	solve_command2(t_dlist **stack_a, t_dlist **stack_b, char *str)
{
	if (ft_strcmp("rr", str) == 0)
	{
		oper_r(stack_a);
		oper_r(stack_b);
	}
	else if (ft_strcmp("rra", str) == 0)
		oper_rr(stack_a);
	else if (ft_strcmp("rrb", str) == 0)
		oper_rr(stack_b);
	else if (ft_strcmp("rrr", str) == 0)
	{
		oper_rr(stack_a);
		oper_rr(stack_b);
	}
}

void	solve_command(t_dlist **stack_a, t_dlist **stack_b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		oper_s(stack_a);
	else if (ft_strcmp("sb", str) == 0)
		oper_s(stack_b);
	else if (ft_strcmp("ss", str) == 0)
	{
		oper_s(stack_a);
		oper_s(stack_b);
	}
	else if (ft_strcmp("pa", str) == 0)
		oper_p(stack_a, stack_b);
	else if (ft_strcmp("pb", str) == 0)
		oper_p(stack_b, stack_a);
	else if (ft_strcmp("ra", str) == 0)
		oper_r(stack_a);
	else if (ft_strcmp("rb", str) == 0)
		oper_r(stack_b);
	else
		solve_command2(stack_a, stack_b, str);
}

void	do_operations(t_dlist **stack_a, t_dlist **stack_b, char **str)
{
	int i;

	i = 0;
	while (str[i] && checker_valid_command(str[i]))
	{
		solve_command(stack_a, stack_b, str[i]);
		i++;
	}
}

void	assist_checker_ok(int *flag, int prev, t_dlist **stack_a)
{
	int		num;
	t_dlist	*a;

	a = (*stack_a);
	while (a->next)
	{
		a = a->next;
		num = a->num;
		if (num < prev)
		{
			write(1, "KO\n", 3);
			*flag = 1;
			break ;
		}
		else
			prev = a->num;
	}
}

void	checker_ok(t_dlist **stack_a, t_dlist **stack_b)
{
	int prev;
	int flag;

	flag = 0;
	if ((*stack_b) == NULL)
	{
		prev = (*stack_a)->num;
		assist_checker_ok(&flag, prev, stack_a);
		if (flag == 0)
			write(1, "OК\n", 3);
	}
	else
		write(1, "KO\n", 3);
}
