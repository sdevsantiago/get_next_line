/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:59 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/27 17:59:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Default buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 1
#  error "Invalid buffer size"
# endif

# define EOL '\n'

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

// Single linked list structure
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// File data structure
typedef struct s_file
{
	int		fd;
	char	*buffer;
}	t_file;

// get_next_line_bonus.c

char	*get_next_line(int fd);

// get_next_line_utils_bonus.c
//! Disclaimer: This functions are used in get_next_line internally and their
//!             use in any other context is highly discouraged. An internal
//!             header can't be created due to subject limitations.
//!             Libft contains a more regularly updated version of this
//!             functions.
//!
//!             Libft: https://github.com/sdevsantiago/Libft

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *s1, const char *s2);
char	*gnl_substr(const char *s, unsigned int start, size_t len);

#endif
