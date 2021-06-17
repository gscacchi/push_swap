/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:10:07 by gscala            #+#    #+#             */
/*   Updated: 2021/04/26 17:10:08 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_emptybuffer(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_renewbuffer(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] == '\0' && i < BUFFER_SIZE)
		i++;
	while (buff[i] != '\n' && buff[i] && i < BUFFER_SIZE)
		buff[i++] = '\0';
	buff[i] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		buffer[256][BUFFER_SIZE + 1];
	size_t			count;

	if (fd < 0 || read(fd, buffer[fd], 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strnew(1);
	count = BUFFER_SIZE;
	while (1)
	{
		if (ft_emptybuffer(buffer[fd]))
		{
			count = read(fd, buffer[fd], BUFFER_SIZE);
			if (count == 0)
				return (0);
		}
		*line = ft_strjoin(*line, buffer[fd]);
		if (ft_iscinstr('\n', buffer[fd], BUFFER_SIZE))
			return (ft_renewbuffer(buffer[fd]));
		else
		{
			ft_renewbuffer(buffer[fd]);
			if (count != BUFFER_SIZE)
				return (0);
		}
	}
}
