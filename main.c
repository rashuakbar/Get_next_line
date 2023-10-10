/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimendes <vimendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:48:57 by vimendes          #+#    #+#             */
/*   Updated: 2023/10/10 13:20:06 by vimendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*s;
	int		ifile;
	int		i;

	i = 0;
	ifile = open("./Files_test/test_nl.txt", O_RDONLY);
	printf("O seu arquivo: \"test_nl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/test_1lsnl.txt", O_RDONLY);
	printf("O seu arquivo: \"test_1lsnl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/test_void.txt", O_RDONLY);
	printf("O seu arquivo: \"test_void\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/test.txt", O_RDONLY);
	printf("\n O seu arquivo: \"test.txt\" tem: \n");
	while (i < 133)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/test_1ch_snl.txt", O_RDONLY);
	printf("\n O seu arquivo: \"test_1ch_snl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/test_alternate_nl.txt", O_RDONLY);
	printf("\n O seu arquivo: \"test_alternate_nl\" tem: \n");
	while (i < 3)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	i = 0;
	ifile = open("./Files_test/big_line_with_nl", O_RDONLY);
	printf("\n O seu arquivo: \"big_line_with_nl\" tem: \n");
	while (i < 1)
	{
		printf("%d   ", (i + 1));
		s = get_next_line(ifile);
		printf("<%s> \n\n", s);
		free(s);
		i++;
	}
	close(ifile);
	return (0);
}
