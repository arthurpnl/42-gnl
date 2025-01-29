/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:36 by arpenel           #+#    #+#             */
/*   Updated: 2025/01/29 15:27:42 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    get_next_line(int fd)
{
    
}

int main(void)
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
