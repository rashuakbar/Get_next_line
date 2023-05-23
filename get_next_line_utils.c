/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:27:41 by vimendes          #+#    #+#             */
/*   Updated: 2023/05/18 19:28:10 by vimendes         ###   ########.fr       */
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
	//free(s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*temp;
	size_t	i;

	temp = (char *)str;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == (unsigned char) c)
			return (temp + i);
		i++;
	}
	if (temp[i] == (unsigned char) c)
		return (temp + i);
	return (NULL);
}
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc (sizeof(*str) * (ft_strlen(str,'\0') + 1));
	if (!dup)
		return (0);
	while (str[i] != 0)
	{
		dup[i] = (char)str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_strlcpy(char *dest, char *src, size_t byte)
{
	size_t	i;
	
	i = 0;
	if(!src)
		return (0);
	while(src[i] && i < byte)
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
