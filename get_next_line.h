/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:25:13 by vimendes          #+#    #+#             */
/*   Updated: 2023/10/10 12:27:01 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strchr(char const *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s, int c);
char	*rest_line(char *src);
char	*get_nline(int fd, char *line);
char	*pick_line(char *src);

#endif
