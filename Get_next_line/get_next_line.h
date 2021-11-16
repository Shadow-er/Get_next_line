#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<stdlib.h>
#include<unistd.h>

char	*ft_split(char **s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
unsigned int	ft_strlen(char *src);
char			*get_next_line(int fd);

#endif