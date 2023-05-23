/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:25:13 by vimendes          #+#    #+#             */
/*   Updated: 2023/05/18 19:38:32 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 50
#endif

char	*get_next_line(int fd);
char	*ft_strchr(char const *str,int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *str);
void	*ft_strlcpy(char *dest, char *src, size_t byte);
size_t	ft_strlen(const char *s, int c);

#endif
