/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:03:03 by arpenel           #+#    #+#             */
/*   Updated: 2025/02/13 07:34:36 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# define BUUFER_SIZE 1024  

char	*get_next_line(int fd);
char	*clean_n_stock(char *storage);
char    *extract_line(char *storage, char *line);
char	*readbuf(int fd, char *storage);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);

#endif