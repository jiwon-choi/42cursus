/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:05:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/02 12:04:57 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define ERR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_newline_idx(const char *s);
char		*ft_strdup(const char *s);
int			ft_separate(char **save, char **line, char *join, int n_idx);
int			rest_after_eof(char **save, char **line, char *join);

#endif
