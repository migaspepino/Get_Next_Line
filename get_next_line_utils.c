/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:00 by mimarque          #+#    #+#             */
/*   Updated: 2021/12/15 00:24:57 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	if (s == NULL)
		return (NULL);
	while (*s && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s1) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	return ((char *) ft_memcpy(new, s1, len));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		((unsigned char *)b)[i] = (unsigned char)c;
	return (b);
}
