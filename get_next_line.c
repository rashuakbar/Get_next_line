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

static size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	*ft_memset(void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)src)[i] = (unsigned char) c;
		i++;
	}
	return (src);
}

char	*get_next_line(int fd)
{
	char	file[BUFF_SIZE];
	size_t		op;
	
	op = read(fd, file, BUFF_SIZE);
	while (op > 0)
	{
		printf("%zu bytes\n", op);
		printf("%s  -  ", file);
		printf("%zu caracteres\n",ft_strlen(file));
		ft_memset(&file,'\0',BUFF_SIZE);
		op = read (fd, file, BUFF_SIZE);
		if (op == EOF)
			break;
	}
	return (NULL);
}
int main (void)
{
	int	ifile = open("test.txt",O_RDONLY);
	char *s; 
	int	i = 0;
	printf("O seu arquivo: \"test.txt\" tem: \n");
	while (i < BUFF_SIZE)
	{
		s = get_next_line(ifile);
		i++;
	}
	close(ifile);
	return (0);
}
