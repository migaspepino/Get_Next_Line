/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:04 by mimarque          #+#    #+#             */
/*   Updated: 2021/12/14 15:31:34 by mimarque         ###   ########.fr       */
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

char	*output(char **backup, char *hBackup, int ret, int fd)
{
	int		value;
	char	*temp;

	if (ret < 0)
		return (NULL);
	else if (ret == 0 && backup[fd] == NULL)
		return (NULL);
	value = (int)(ft_strchr(backup[fd], '\n') - backup[fd] + 1);
	hBackup = ft_substr(backup[fd], 0, value);
	temp = ft_substr(backup[fd], value, BUFFER_SIZE * BUFFER_SIZE);
	free(backup[fd]);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	backup[fd] = temp;
	return (hBackup);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[NUM_OF_FD];
	char		*hbackup;

	if (fd < 0)
		return (NULL);
	ret = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (backup[fd] == NULL)
		{
			backup[fd] = ft_strdup(buf);
			ft_memset(buf, 0, BUFFER_SIZE);
		}
		else
		{
			hbackup = ft_strjoin(backup[fd], buf);
			free(backup[fd]);
			backup[fd] = hbackup;
			ft_memset(buf, 0, BUFFER_SIZE);
		}
		if (ft_strchr(backup[fd], '\n'))
			break ;
	}
	return (output(backup, hbackup, ret, fd));
}
