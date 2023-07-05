/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:27:41 by vimendes          #+#    #+#             */
/*   Updated: 2023/07/05 22:34:26 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, int c)
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
	int		j;
	int		ind;
	char	*rest;
	
	ind = 0;
	i = 0;
	j = ft_strlen(src, '\0');
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	rest = malloc((j - i) * sizeof(char));
	if(!rest)
		return (NULL);
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
}
