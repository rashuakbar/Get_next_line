/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:25:13 by vimendes          #+#    #+#             */
/*   Updated: 2023/05/29 17:00:07 by vimendes         ###   ########.fr       */
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
int	ft_strchr(char const *str,int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s, int c);
void	*ft_calloc(size_t nl, size_t lsize);
void	*ft_bzero(void *src, size_t n);

#endif
