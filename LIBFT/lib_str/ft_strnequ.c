/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:51:05 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/19 14:54:57 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && *s1 && *s2)
	{
		while (*s1 && *s2 && *s1 == *s2 && n > 0)
		{
			s1++;
			s2++;
			n--;
		}
	}
	if ((s1 && s2 && n == 0) || (s1 && s2 && !*s1 && !*s2))
		return (1);
	return (0);
}