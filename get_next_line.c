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

	if (fd < 0 || fd > NUM_OF_FD)
		return (NULL);
	ret = 1;
	while (ft_strchr(backup[fd], '\n') != NULL || ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup(buf);
		else
		{
			hbackup = ft_strjoin(backup[fd], buf);
			free(backup[fd]);
			backup[fd] = hbackup;
		}
	}
	return (output(backup, hbackup, ret, fd));
}
