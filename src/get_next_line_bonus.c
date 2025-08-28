/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/28 02:35:22 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line_bonus.h"

static t_file	*get_file(t_list **files, int fd);
static void		del_file(t_list **files, int fd);
static char		*fill_buffer(char *buffer, int fd);
static void		resize_buffer(t_list **files, int fd);

/* Reads the next line from the file pointed by FD. If no lines have been read
   previously, reads the first one. */
char	*get_next_line(
	int fd)
{
	char			*line;
	static t_list	*files;
	t_file			*file;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	file = get_file(&files, fd);
	len = (size_t)gnl_strchr(file->buffer, EOL);
	if (len)
	{
		len -= (size_t)file->buffer;
		line = gnl_substr(file->buffer, 0, len + 1);
		resize_buffer(&files, file->fd);
		return (line);
	}
	file->buffer = fill_buffer(file->buffer, fd);
	if (!file->buffer || !*file->buffer)
		return (del_file(&files, fd), NULL);
	len = gnl_strchr(file->buffer, EOL) - file->buffer;
	line = gnl_substr(file->buffer, 0, len + 1);
	resize_buffer(&files, file->fd);
	return (line);
}

/* Returns the node of the list FILES that contains the FD passed. If it
   doesn't exitst, creates a new node at the beggining of the list for
   that FD. */
static t_file	*get_file(
	t_list **files,
	int fd)
{
	t_list	*file;
	t_list	*new_file;

	file = *files;
	while (file)
	{
		if (((t_file *)file->content)->fd == fd)
			return ((t_file *)file->content);
		file = file->next;
	}
	new_file = (t_list *)malloc(sizeof(t_list));
	if (!new_file)
		return (NULL);
	new_file->content = (t_file *)malloc(sizeof(t_file));
	if (!new_file->content)
		return (free(new_file), NULL);
	((t_file *)new_file->content)->fd = fd;
	((t_file *)new_file->content)->buffer = gnl_strdup("");
	if (!((t_file *)new_file->content)->buffer)
		return (free((t_file *)new_file->content), free(new_file), NULL);
	new_file->next = *files;
	*files = new_file;
	return (new_file->content);
}

/* Deletes the node from the list FILES containing the passed FD. */
static void	del_file(
	t_list **files,
	int fd)
{
	t_list	*del_file;
	t_list	*prev_file;

	del_file = *files;
	prev_file = NULL;
	while (((t_file *)del_file->content)->fd != fd)
	{
		prev_file = del_file;
		del_file = del_file->next;
	}
	if (!prev_file)
		*files = del_file->next;
	else
		prev_file->next = del_file->next;
	if (!*files)
		*files = NULL;
	free(((t_file *)del_file->content)->buffer);
	free(del_file->content);
	free(del_file);
}

static void	resize_buffer(
	t_list **files,
	int fd)
{
	t_list		*file;
	char		*new_buffer;
	size_t		len;
	uintptr_t	i;

	file = *files;
	while (((t_file *)file->content)->fd != fd)
		file = file->next;
	i = (uintptr_t)gnl_strchr(((t_file *)file->content)->buffer, EOL);
	if (i)
	{
		i -= (uintptr_t)((t_file *)file->content)->buffer;
		len = gnl_strlen(&((t_file *)file->content)->buffer[i + 1]);
	}
	if ((i || ((t_file *)file->content)->buffer[i] == EOL)
		&& ((t_file *)file->content)->buffer[i + 1])
	{
		new_buffer
			= gnl_substr(((t_file *)file->content)->buffer, i + 1, len + 1);
		free(((t_file *)file->content)->buffer);
		((t_file *)file->content)->buffer = new_buffer;
	}
	else
		del_file(files, fd);
}

/* Fills the buffer until it contains a full line. A complete line is
   understood to be one that contains an EOL. */
static char	*fill_buffer(
	char *buffer,
	int fd)
{
	char	*buf;
	ssize_t	len;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(buffer), NULL);
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
	{
		if (*buffer)
			return (free(buf), buffer);
		return (free(buf), free(buffer), NULL);
	}
	buf[len] = '\0';
	if (!gnl_strchr(buf, EOL) && len == BUFFER_SIZE)
	{
		buffer = gnl_strjoin(buffer, buf);
		return (free(buf), fill_buffer(buffer, fd));
	}
	buffer = gnl_strjoin(buffer, buf);
	if (!buffer)
		return (free(buffer), NULL);
	return (free(buf), buffer);
}
