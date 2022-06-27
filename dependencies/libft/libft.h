/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:26:22 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/13 13:33:26 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);

size_t	ft_strlen(const char *str);

void	*ft_memset(void *ptr, int c, size_t cap);
void	ft_bzero(void *ptr, size_t cap);
void	*ft_memmove(void *dstv, const void *srcv, size_t cap);
void	*ft_memcpy(void *dstv, const void *srcv, size_t cap);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t cap);
size_t	ft_strlcat(char *dst, const char *src, size_t cap);

int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memchr(const void *ptr, int c, size_t cap);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *lil, size_t cap);

int		ft_memcmp(const void *sv, const void *tv, size_t cap);
int		ft_strncmp(const char *s, const char *t, size_t cap);

int		ft_atoi(const char *s);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int at, size_t cap);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s, char const *set);

char	**ft_split(char const *str, char sep);

char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_len_dec(int n);

// New.

int		ft_power10(size_t n);

#endif
