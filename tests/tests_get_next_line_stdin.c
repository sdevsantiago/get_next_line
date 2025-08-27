/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line_stdin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:40:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/27 01:23:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <signal.h>

int main(void)
{
	char 			*line;
	unsigned int	count = 0;

    while (count++ < 5)
    {
		line = get_next_line(STDIN_FILENO);
        write(STDOUT_FILENO, line, gnl_strlen(line));
        free(line);
        line = NULL;
    }

    return (0);
}
