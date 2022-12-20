#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define FD_SIZE 4096
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(const char *str);
void	ft_strdel(char **as);
char	*ft_strdup(char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_alloc(void);
char	*get_next_line(int fd);
#endif