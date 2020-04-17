/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:22:41 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 16:10:16 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		assist_checker_main(t_dlist **stack_a, t_dlist **stack_b, char **str)
{
	do_operations(stack_a, stack_b, str);
	checker_ok(stack_a, stack_b);
	return (0);
}

void	read_commands(char **str, int *proverka)
{
	int i;

	i = 0;
	while (get_next_line(0, &(str[i])) > 0)
	{
		if ((*proverka = checker_valid_command(str[i])) == 0)
		{
			write(1, "Error\nAn instruction don’t", 26);
			write(1, " exist and/or is incorrectly formatted\n", 39);
			break ;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char	*str[20000];
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int		proverka;

	proverka = 1;
	if (ac > 1)
	{
		if (checker_valid_isdigit(av) == 0)
			return (0);
		stack_a = get_stack_a(av, 0);
		read_commands(str, &proverka);
		if (proverka == 1)
			return (assist_checker_main(&stack_a, &stack_b, str));
	}
	return (0);
}
