/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:25:35 by arpenel           #+#    #+#             */
/*   Updated: 2025/01/29 14:20:32 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>

#define BUFFER_SIZE 1024

int	main(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	fd = open("txt.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File can't be open");
		return (1);
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		printf("Buffer : %s\n", buffer);
	}
	close(fd);
	return (0);
}
