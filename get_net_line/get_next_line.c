/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 00:45:36 by youlee            #+#    #+#             */
/*   Updated: 2020/04/10 16:34:56 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			put_line(char **line, char **buf2, int fd, int idx)
{
	char			*temp;
	char			*temp2;

	temp = malloc(sizeof(char) * (idx + 1));
	ft_strncpy(temp, buf2[fd], (unsigned int)idx);
	if (buf2[fd][idx] != '\0')
	{
		if (buf2[fd][idx + 1] == '\0')
		{
			free(buf2[fd]);
			buf2[fd] = NULL;
		}
		else
		{
			temp2 = ft_strdup(buf2[fd] + (idx + 1));
			free(buf2[fd]);
			buf2[fd] = temp;
		}
	}
	else if ((buf2[fd][idx]) == '\0')
	{
		free(buf2[fd]);
		buf2[fd] = NULL;
	}
	*line = ft_strdup(temp);
	free(temp);
}

static int			val_ret(char **buf2, int fd, int fdnum, char **line)
{
	if (fdnum == 0 && buf2[fd] == NULL)
	{
		*line = NULL;
		free(buf2[fd]);
		buf2[fd] = NULL;
		free(buf2);
		return (0);
	}
	else if (fdnum == 0)
	{
		if ((ft_strchr(buf2[fd], '\n')) >= 0)
		{
			put_line(line, buf2, fd, ft_strchr(buf2[fd], '\n'));
			return (1);
		}
		else
		{
			put_line(line, buf2, fd, ft_strchr(buf2[fd], '\0'));
			free(buf2[fd]);
			buf2[fd] = NULL;
			free(buf2);
			return (0);
		}
	}
	return ((fdnum < 0 ? -1 : 0));
}

static int			buf2_manage(char **buf2, char **line, char *buf, int fd)
{
	char			*temp;

	temp = NULL;
	if (buf2[fd][0] == 0)
	{
		temp = ft_strdup(buf);
		free(buf);
		buf2[fd] = temp;
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	else
	{
		temp = ft_strjoin(buf2[fd], buf);
		free(buf2[fd]);
		buf2[fd] = temp;
		free(buf);
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	if ((ft_strchr(buf2[fd], '\n')) >= 0)
	{
		free(buf);
		put_line(line, buf2, fd, ft_strchr(buf2[fd], '\n'));
		return (1);
	}
	return (0);
}

static void			row_calloc(char **buf2, int fd, int row_size)
{
	char			**temp;
	
	while (buf2[row_size] != NULL)
		row_size++;
	if (fd > row_size)
	{
		row_size = 0;
		temp = malloc(sizeof(char) * (fd + 1));
		temp[fd + 1] = NULL;
		while (buf2[row_size] != NULL)
		{
			temp[row_size] = ft_strdup(buf2[row_size]);
			free(buf2[row_size++]);
		}
		while (temp[row_size] != NULL)
		{
			if (row_size == fd)
				temp[row_size] = ft_strdup(buf2[row_size]);
			else
				temp[row_size] = ft_strdup("\0");
			row_size++;
		}
	}
}

int					get_next_line(int fd, char **line)
{
	static char		**buf2;
	char			*buf;
	int				fdnum;
	int				idx;

	idx = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || \
			(!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (buf2 == NULL)
	{
		while (idx < fd)
			buf2[idx] = ft_strdup("\0");
		buf2 = malloc(sizeof(char) * (fd + 1));
		buf2[fd + 1] = NULL;
	}
	else
		row_calloc(buf2, fd, 0);
	while ((fdnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[fdnum] = '\0';
		if (buf2_manage(buf2, line, buf, fd) == 1)
			return (1);
	}
	if (buf)
		free(buf);
	return (val_ret(buf2, fd, fdnum, line));
}
