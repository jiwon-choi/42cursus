#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define FD 0
# define BUFFER_SIZE 1
# define ERR -1

int		get_next_line(char **line);
int		ft_strlen(char *str);
char	*ft_strjoin(char *save, char *buf);
char	*ft_strdup(char *str);
int		ft_newline_idx(char *str);

#endif
