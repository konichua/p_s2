/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:43:31 by mburnett          #+#    #+#             */
/*   Updated: 2019/10/01 18:09:30 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_to_line(char **line, char **statarr)
{
	char	*tmp;

	CHECKEND((*statarr[0]));
	if (ft_strchr(*statarr, '\n') != NULL)
	{
		*(ft_strchr(*statarr, '\n')) = '\0';
		MERROR((*line = ft_strdup(*statarr)));
		MERROR((tmp = ft_strdup(ft_strchr(*statarr, '\0') + 1)));
		free(*statarr);
		MERROR((*statarr = ft_strdup(tmp)));
		free(tmp);
	}
	else
	{
		MERROR((*line = ft_strdup(*statarr)));
		ft_memdel((void **)statarr);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*statarr[MAX_FD];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	CHECKMEM(statarr[fd]);
	while (!ft_strchr(statarr[fd], '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		MERROR((tmp = ft_strdup(statarr[fd])));
		free(statarr[fd]);
		MERROR((statarr[fd] = ft_strjoin(tmp, buf)));
		CHECKMEM(statarr[fd]);
		free(tmp);
	}
	return (write_to_line(line, &statarr[fd]));
}
