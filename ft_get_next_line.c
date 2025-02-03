/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:36 by arpenel           #+#    #+#             */
/*   Updated: 2025/01/31 15:51:20 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fctnl.h>

#define BUFFER_SIZE 1024

// 1. Read the file and stock the data 
char	*readbuf(int fd, static char *storage)
{
	char	buffer;
	int		bytes_read;

	buffer = BUFFER_SZIE + 1;
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0) // Read til we find a \n
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0'; // Trasnform buffer as a valid string.
		storage = ft_strjoin(storage, buffer); // Cat the two strings
	}
	return (storage);
}

// 2. Extract the line 
char *extract_line(char *storage )
{
	char	*line;
	char	*i;
	
	i = 0;
	if(!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	ft_substr(storage, 0, i + 1);
	return (line);
}
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
