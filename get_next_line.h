#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif
#define NUM_OF_FD 256
#include <unistd.h> //read
#include <stdlib.h> //malloc

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*output(char **backup, char *hBackup, int ret, int fd);
char	*get_next_line(int fd);