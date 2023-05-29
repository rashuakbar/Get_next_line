/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:27:41 by vimendes          #+#    #+#             */
/*   Updated: 2023/05/29 15:57:38 by vimendes         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	totallen;
	size_t	i;
	char	*str;

	i = 0;
	totallen = ft_strlen(s1,'\0') + ft_strlen(s2, '\0') + 1;
	str = malloc(totallen * sizeof(char));
	if (!str)
		return (NULL);
	while (i < (totallen - 1))
	{
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
	}
	str[i] = '\0';
	//free(s2);
	return (str);
}

int	ft_strchr(const char *str, int c)
{
	char	*temp;
	size_t	i;

	temp = (char *)str;
	i = 0;
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

	temp = malloc(lsize * nl);
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
}
