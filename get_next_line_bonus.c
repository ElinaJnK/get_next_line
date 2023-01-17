/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejankovs <ejankovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:23:32 by ejankovs          #+#    #+#             */
/*   Updated: 2023/01/17 17:43:27 by ejankovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (*src)
	{
		if (*src == (unsigned char)c)
			return ((char *)src);
		src++;
	}
	if (*src == (unsigned char)c)
		return ((char *)src);
	return (0);
}

char	*ft_get_line(char **s)
{
	int		len;
	char	*tmp;
	char	*line;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		line = (char *)malloc(sizeof(char) * len + 2);
		tmp = ft_strdup(*s + len + 1);
		if (!line || !tmp)
			return (NULL);
		ft_strncpy(line, *s, len + 1);
		free(*s);
		*s = tmp;
		if (**s == '\0')
			ft_strdel(s);
	}
	else
	{
		line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (line);
}

char	*ft_result(char **s, int len, int fd)
{
	if (len < 0 || (len == 0 && s[fd] == NULL))
		return (NULL);
	return (ft_get_line(&s[fd]));
}

char	*ft_alloc(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*s[4096];
	char		*buf;
	int			size;
	char		*line;

	buf = ft_alloc();
	if (fd < 0 || !buf)
		return (free(buf), NULL);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			line = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = line;
		}
		if (ft_strchr(s[fd], '\n') || s[fd] == NULL)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (free(buf), ft_result(s, size, fd));
}
