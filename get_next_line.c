/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:36 by arpenel           #+#    #+#             */
/*   Updated: 2025/01/31 15:19:31 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fctnl.h>

#define BUFFER_SIZE 1024

// 1. Read the file and stock the data 
char	*read_n_stock(int fd, static char *storage)
{
	fd = open(fd )	
}
// 2. Extract the line 
// 3. Update storage variable
// 4. Return the lign that we just extract 

char	get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error openning the file");
		return (1);
	}
	while (1)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
}
