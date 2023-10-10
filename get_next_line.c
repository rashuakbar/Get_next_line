/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:55 by vimendes          #+#    #+#             */
/*   Updated: 2023/10/10 11:43:27 by vimendes         ###   ########.fr       */
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
	int	i;
	int	j;
	char	*str;

	i = -1;
	j = -1;
	totallen = ft_strlen(s1,'\0') + ft_strlen(s2, '\0') + 1;
	str = malloc(totallen * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[j + i] = s2[j];
	str[j + i] = '\0';
	free(s1);
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
char	*rest_line(char *src)
{
	int		i;
	int		ind;
	int		j;
	char	*rest;
		
	ind = 0;
	i = 0;
	j = ft_strlen(src,'\0');
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	rest = malloc((j - i) * sizeof(char));
	if(!rest)
	{
		free(src);
		return (NULL);
	}
	while (src[++i] != '\0')
		rest[ind++] = src[i];
	rest[ind] = '\0';
	free(src);
	return (rest);
}
char	*pick_line(char *src)
{
	char	*new_line;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if(!src[j])
		return (NULL);
	while (src[j] && src[j] != '\n')
		j++;
	new_line = malloc(j * sizeof(char) + 2);
	if(!new_line)
		return (NULL);
	while (i <= j)
	{
		new_line[i] = src[i];
		i++;	
	}
	new_line[i] = '\0';
	return (new_line);
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
	file = malloc(BUFF_SIZE * sizeof(char) + 1);
	if (!file)
		return (NULL);
	while (!ft_strchr(line,'\n') && (op != 0))
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

char	*get_next_line(int fd)
{
	static char	*line;
	char		*trash;
	
	if (!fd || !BUFF_SIZE)
		return (NULL);	
	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	line = get_nline(fd,line);
	if (!line)
		return (NULL);
	trash = pick_line(line);
	line = rest_line(line);
	return (trash);
}
/*int main (void)
{
	int	ifile = open("./Files_test/test.txt",O_RDONLY);
	int ifile1 = open("./Files_test/test_nl.txt",O_RDONLY);
	int ifile2 = open("./Files_test/test_1lsnl.txt", O_RDONLY);
	int	ifile3 = open("./Files_test/test_void.txt", O_RDONLY);
	int	ifile4 = open("./Files_test/test_1ch_snl.txt", O_RDONLY);
	int	ifile5 = open("./Files_test/test_alternate_nl.txt",O_RDONLY); 
	int	ifile6 = open("./Files_test/big_line_with_nl",O_RDONLY);
	char *s; 
	int	i = 0;

	printf("O seu arquivo: \"test_nl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile1);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile1);

	i = 0;
	printf("O seu arquivo: \"test_1lsnl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile2);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile2);

	i = 0;
	printf("O seu arquivo: \"test_void\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile3);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile3);

	i = 0;	
	printf("\n O seu arquivo: \"test.txt\" tem: \n");
	while (i < 133)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	
	i = 0;	
	printf("\n O seu arquivo: \"test_1ch_snl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile4);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile4);
	
	i = 0;
	printf("\n O seu arquivo: \"test_alternate_nl\" tem: \n");
	while (i < 3)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile5);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile5);

	i = 0;
	printf("\n O seu arquivo: \"big_line_with_nl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i+1));
		s = get_next_line(ifile6);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile6);

	return (0);
}*/
