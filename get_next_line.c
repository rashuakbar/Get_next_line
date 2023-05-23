/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:55 by vimendes          #+#    #+#             */
/*   Updated: 2023/05/18 19:18:25 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *line)
{
	char	*file;
	int	op;
	
	op = 1;
	file = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!file)
		return (NULL);
	while (!ft_strchr(file,'\n') && (op > 0) )
	{
		op = read(fd, file, BUFF_SIZE);
		if (op == -1)
		{
			free(file);
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
	size_t		len;
	size_t		total;
	
	line = ft_strdup("");
	if(!line)
		return (NULL);
	line = get_line(fd,line);
	len = ft_strlen(line, '\n');
	total = ft_strlen(line, '\0');
	trash = ft_strdup("");
	trash = ft_strlcpy(trash, line, len);
	line = ft_strlcpy(line, line + (len + 1),(total - (len+1)));
	return (trash);
}
int main (void)
{
	int	ifile = open("test.txt",O_RDONLY);
	char *s; 
	int	i = 0;
	printf("O seu arquivo: \"test.txt\" tem: \n");
	while (i < BUFF_SIZE)
	{
		//printf("%d   ", i);
		s = get_next_line(ifile);
		printf("<%s> \n", s);
		i++;
	}
	close(ifile);
	return (0);
}
