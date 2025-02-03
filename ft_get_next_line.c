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
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

static char *storage;

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*cat_str;

	if (!s1 && !s2)
		return NULL;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cat_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!cat_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cat_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		cat_str[i++] = s2[j++];
	cat_str[i] = '\0';
	return (cat_str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	un_c;

	un_c = (unsigned char)c;
	while (*s)
	{
		if (*s == un_c)
			return ((char *)s);
		s++;
	}
	if (un_c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc(sizeof(const char) * ft_strlen(s) + 1);
	i = 0;
	if (str)
	{
		str[ft_strlen(s)] = '\0';
	}
	else
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (str != NULL)
			str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// 1. Read the file and stock the data 
char	*readbuf(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
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
	int		i;
	
	i = 0;
	if(!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_substr(storage, 0, i + 1);
	return (line);
}

// 3. Stock the rest of the lign in a new variables
char	*clean_n_stock(char *storage)
{
	int	i;
	char	*new_storage;

	i = 0;
	while(storage[i] && storage[i] != '\n')
		i++;
	if(!storage[i])
	{
		free(storage);
		return NULL;
	}
	new_storage = ft_strdup(storage + i + 1);
	free(storage);
	return (new_storage);
}


char	*get_next_line(int fd)
{
	char		*line;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = readbuf(fd, storage);
	line = extract_line(storage);
	storage = clean_n_stock(storage);

	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error openning the file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
}
