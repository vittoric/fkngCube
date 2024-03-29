/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:30:49 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/28 16:49:23 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "types.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
t_status		ft_array_is_sorted(int *array, int len, int desc);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, \
							void *(*f)(void *), void (*del)(void *));
int				ft_isalnum(int c);
int				ft_strisnum(char *c);
char	*ft_fstrjoin(char *s1, char *s2);
char	**ft_sort_matrix(char **mat)	;
int	ft_get_matrix_size(char **env);
int				ft_isspace(char c);
int				ft_isdigit(int c);
int				ft_strisdigit(char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_array_has_value(int *arr, int value, int len);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_toupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_lstsize(t_list *lst);
int				ft_strarr_len(char **strarr);
long			ft_atol(const char *nptr);
void			ft_putendl(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_free_str_arr(char **arr);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_remove_quotes_arr(char **arr);
void			ft_remove_quotes(char *str);
void			show_error(char *error);
void			ft_rm_char_from_str(char *str, char c);
void			ft_free_double_void_pointer(void **ptr, \
											int size, void (*funct)(void *));
void			**ft_init_double_pointer(size_t size_of_struct, \
										size_t number_of_elems, \
										void *(*init_elem)(), \
										void (free_funct)(void *));
char			*ft_strchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_realloc_str(char *ptr, size_t size);
char			*ft_strncpy(char *destination, const char *source, size_t num);
char			*ft_itoa(int n);
char			**ft_lst_to_str(t_list **token_list);

#endif