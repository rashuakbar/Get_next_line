/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:55 by vimendes          #+#    #+#             */
/*   Updated: 2023/06/02 21:01:46 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*size_t	ft_strlen(const char *s, int c)
{
	size_t	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	totallen;
	size_t	i;
	char	*str;

	i = 0;
	totallen = ft_strlen(s1,'\0') + ft_strlen(s2, '\0') + 1;
	str = malloc(totallen * sizeof(char));
	if (!str)
		return (NULL);
//	while (i < (totallen - 1))
//	{
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
//	}
	str[i] = '\0';
	//free(s1);
	return (str);
}

int	ft_strchr(const char *str, int c)
{
	char	*temp;
	size_t	i;

	if(!str)
		return (-1);
	temp = (char *)str;
	i = 0;
	if (temp[i] == c)
		return (1);
	while (temp[i] != '\0')
	{
		if (temp[i] == (unsigned char) c)
			return (i);
		i++;
	}
	if (temp[i] == (unsigned char) c)
		return (i);
	return (0);
}

void	*ft_calloc(size_t nl, size_t lsize)
{
	void	*temp;

	temp = malloc((lsize * nl));
	if (!temp)
		return (NULL);
	ft_bzero(temp, (lsize * nl));
	return ((void *)temp);
}

void	*ft_bzero(void *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *) src;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}*/
//
//
// MANDATORY PART
//
char	*get_nline(int fd, char *line)
{
	char	*file;
	int	op;

	op = 1;
	file = ft_calloc((BUFF_SIZE + 1),sizeof(char));
	if (!file)
		return (NULL);
	while (!ft_strchr(file,'\n') && (op > 0))
	{
		op = read(fd, file, BUFF_SIZE);
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

char	*rest_line(char *src, int j)
{
	int		i;
	int		ind;
	char	*rest;
	char	*temp;
	
	ind = 0;
	i = ft_strchr(src,'\0');
	rest = malloc((i - j + 1) * sizeof(char));
	if(!rest)
		return (NULL);
	temp = src;
	while (temp[++j] != '\0')
		rest[ind++] = temp[j];
	rest[ind] = '\0';
	free(src);
	return (rest);
}
char	*pick_line(char *src)
{
	int	i;
	char	*new_line;
	
	i = 0;
	if(!src[i])
		return (NULL);
	new_line = malloc((ft_strlen(src,'\n')+ 1) * sizeof(char));
	if(!new_line)
		return (NULL);
	while (src[i] != '\n')
	{
		new_line[i] = src[i];
		i++;	
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*trash;
	int		len;
	
	if (!fd || !BUFF_SIZE)
		return (NULL);	
	if (!line)
		line = ft_calloc(1,1);
	line = get_nline(fd,line);
	len = ft_strchr(line,'\n');
	trash = pick_line(line);
	line = rest_line(line, len);
	return (trash);
}
/*int main (void)
{
	int	ifile = open("test.txt",O_RDONLY);
	char *s; 
	int	i = 0;
	printf("O seu arquivo: \"test.txt\" tem: \n");
	while (i < 135)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	return (0);
}*/
