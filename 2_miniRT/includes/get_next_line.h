/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:30:47 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/03/29 17:44:53 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define ERR -1
# define BUFFER_SIZE 1

char		*gnl_strdup(const char *s);
char		*gnl_strjoin(char const *save, char const *buf);
int			gnl_newline_idx(const char *s);
int			gnl_separate(char **save, char **line, char *join, int n_idx);
int			get_next_line(int fd, char **line);

#endif
