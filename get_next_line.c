/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:55 by vimendes          #+#    #+#             */
/*   Updated: 2023/10/10 13:23:11 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// MANDATORY PART

char	*get_nline(int fd, char *line)
{
	char	*file;
	int		op;

	op = 1;
	file = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!file)
		return (NULL);
	while (!ft_strchr(line, '\n') && (op != 0))
	{
		op = read(fd, file, BUFFER_SIZE);
		if (op == -1)
		{
			free(file);
			free(line);
			return (NULL);
		}
		file[op] = '\0';
		line = ft_strjoin(line, file);
	}
	free(file);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*trash;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	line = get_nline(fd, line);
	if (!line)
		return (NULL);
	trash = pick_line(line);
	line = rest_line(line);
	return (trash);
}
