/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:04 by mimarque          #+#    #+#             */
/*   Updated: 2022/02/22 14:37:22 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"

char	*cycle(char **backup, int fd, char *buf)
{
	int	size;

	size = read(fd, buf, BUFFER_SIZE);
	buf[size] = '\0';
	while (size > 0)
	{
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (ft_strchr(backup[fd], '\n') != NULL)
			return (returner(backup, fd));
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
	}
	return (NULL);
}

char	*returner(char **backup, int fd)
{
	int		index;
	char	*line;
	char	*temp;

	index = ft_strchr(backup[fd], '\n') - backup[fd] + 1;
	line = ft_strldup(backup[fd], 0, index);
	temp = ft_strldup(backup[fd], index, ft_strlen(backup[fd]));
	free(backup[fd]);
	backup[fd] = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[NUM_OF_FD];
	char		*line;

	if (fd < 0 || fd > NUM_OF_FD)
		return (NULL);
	line = NULL;
	if (ft_strchr(backup[fd], '\n') == NULL)
	{
		line = cycle(backup, fd, buf);
		if (line != NULL)
			return (line);
	}
	else
		return (returner(backup, fd));
	if (backup[fd])
	{
		line = backup[fd];
		backup[fd] = NULL;
		return (line);
	}
	return (NULL);
}
