/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:32 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:52 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_bool;

typedef struct s_llst
{
	void				*data;
	struct s_llst		*prev;
	struct s_llst		*next;
}						t_llst;

# define BUFFER_SIZE 4096

int						ft_atoi_basique(char *s);
char					**ft_split(char const *str, char c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isalnum(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strndup(char *src, int n);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlen(const char *s);
int						ft_putendl_fd(char *s, int fd);
int						ft_putstr_fd(char *s, int fd);
int						ft_putchar_fd(char c, int fd);
char					*ft_strjoin(char *s1, char *s2, char *s3, t_bool opt);
void					*ft_calloc(size_t size);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_min(int a, int b);
int						ft_max(int a, int b);
void					*ft_if(int condition, void *if_true, void *if_false);
int						ft_abs(int n);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
int						ft_is_whitespace(char c);
int						ft_hasonly(void *data, void *value, size_t len_data,
							size_t size_value);
char					*ft_strcpy(char *dest, char *src);
int						ft_putstr(char *s);
int						ft_putendl(char *s);
int						ft_open(char *path, int file_descriptors, int rights);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);

void					*ft_errifnul(void *res_funct, char *error_name, \
	void (*f_free) (void *), void *data_free);
void					ft_errorif(int condition, char *error_name, \
	void (*f_free) (void *), void *data_free);

void					*ft_mid_free(void **var, void *res);
void					*ft_mid_free_array(void *ptr, void *res);
int						ft_mid_free_int(void *ptr, int res);
void					ft_free(void *ptr);
int						ft_close(int fd);

int						is_charset(char c, char *charset);

t_llst					*ft_llst_new(void *data, void (*f)(void *));
int						ft_llst_insert(t_llst *actual, t_llst *new);

int						ft_llst_join(t_llst *actual, t_llst *new);
int						ft_llst_joinbefore(t_llst **llst, t_llst *actual,
							t_llst *new);
int						ft_llst_addfront(t_llst **lst, t_llst *new);
t_llst					*ft_llst_getlast(t_llst *list);
int						ft_llst_addback(t_llst **lst, t_llst *new);
int						ft_llst_clear(t_llst **list, void (*f)(void *));
t_llst					*ft_llst_del(t_llst **list, t_llst *e,
							void (*f)(void *));
t_llst					*ft_llst_ndel(t_llst **list, t_llst *e, int n,
							void (*f)(void *));
void					ft_llst_del_if(t_llst **list, int (*cmp)(void *,
								void *), void *data_tocmp);
int						ft_llst_size(t_llst *list);
int						ft_llst_sizeif(t_llst *list, int (*cmp)(void *, void *),
							void *data_tocmp);
t_llst					*ft_llst_cut(t_llst *node, int nb, void (*f)(void *));
t_llst					*ft_llst_dup(t_llst *src, void *(*fdup)(void *),
							void (*fr)(void *));
t_llst					*ft_llst_extract(t_llst **llst, t_llst *begin,
							t_llst *end);
t_llst					*ft_llst_midnext(t_llst **list);
t_llst					*ft_llst_previf(t_llst *llst, int (*cmp)(void *,
								void *), void *ref);
t_llst					*ft_llst_nextif(t_llst *llst, int (*cmp)(void *,
								void *), void *ref);
t_llst					*ft_llst_find(t_llst *list, void *data,
							int (*cmp)(void *, void *));
void					ft_llst_iterate(t_llst *list, void (*f)(void *));
int						ft_llst_isall(t_llst *list, void *ref, int (*f)(void *,
								void *));
void					ft_llst_reverse_iterate(t_llst *list,
							void (*f)(void *));

char					*get_next_line(int fd);
#endif
