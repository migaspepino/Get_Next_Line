/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:04 by mimarque          #+#    #+#             */
/*   Updated: 2021/12/15 01:06:30 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if ((dst != src) && n)
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*output(char **backup, char *rbackup, int ret, int fd)
{
	int		value;
	char	*temp;

	if (ret < 0)
		return (NULL);
	else if (ret == 0 && backup[fd] == NULL)
		return (NULL);
	value = (int)(ft_strchr(backup[fd], '\n') - backup[fd] + 1);
	rbackup = ft_substr(backup[fd], 0, value);
	temp = ft_substr(backup[fd], value, BUFFER_SIZE * BUFFER_SIZE);
	free(backup[fd]);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	backup[fd] = temp;
	return (rbackup);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[NUM_OF_FD];
	char		*rbackup;

	if (fd < 0 || fd > NUM_OF_FD)
		return (NULL);
	while (ft_strchr(backup[fd], '\n') == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret <= 0)
			break ;
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup(buf);
		else
		{
			rbackup = ft_strjoin(backup[fd], buf);
			free(backup[fd]);
			backup[fd] = rbackup;
		}
	}
	return (output(backup, rbackup, ret, fd));
}
