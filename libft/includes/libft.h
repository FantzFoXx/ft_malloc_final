/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:02:59 by udelorme          #+#    #+#             */
/*   Updated: 2018/02/12 11:10:17 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "get_next_line.h"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_memcheck(const void *m, int c, size_t size);
void					ft_putchar(char c);
void					ft_putnbr(int n);
void					ft_putstr(char const *s);
void					ft_trace(const char *mess, const char *s);
void					ft_nbrtrace(const char *mess, int i);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_strcmp(char const *s1, char const *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
char					*ft_itoa(long n);
char					*ft_itoa_base(int n, char *base);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s,
						void (*f)(unsigned int, char *));
char					*ft_strsub(const char *s, unsigned int start,
						size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(const char *s, char c);
int						ft_wordcount(const char *s, char c);
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list					*ft_lstdup(t_list *lst);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstpush(t_list **alst, t_list *new);
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char					**ft_create_tab(int length);
char					**ft_inc_tab(char **data, int size);
void					ft_freetab(char **data);
void					ft_realloc_tab(char ***data, size_t size);
size_t					ft_tab_size(char **data);
void					ft_print_rep(int c, size_t repeat);
char					*ft_strtrim_w(const char *s);
char					**ft_strdup_tab(char **data);
char					*ft_implode_tab(char **data, int start, size_t len);
int						ft_index_fmatch(char *str, char chr);
int						ft_index_lmatch(char *str, char chr);
int						ft_index_nmatch(char *str, char chr, int n);
char					*ft_cut_cur_word(char *str, int index, int *start,
						size_t *len);
char					**ft_split_index(char *str, int index);
char					*ft_str_renew(char **old, char *new);
void					print_memory(const void *addr, size_t size);

/*
** External debug functions
*/

void					ft_external_debug(char *debug, int fd);
void					ft_close_external_debug(int fd);
int						ft_init_external_debug(char *filename, int verbose);

# define FT_LL long long int
# define FT_UL long unsigned int
# define FT_ULL long long unsigned int
# define FT_UC unsigned char
# define FT_UI unsigned int
# define FT_SI short int
# define FT_US short unsigned int
# define FT_UNSIGNED unsigned

typedef long double		t_ld;

typedef FT_UC			t_uc;
typedef FT_US			t_us;
typedef FT_UI			t_ui;
typedef FT_UL			t_ul;
typedef FT_ULL			t_ull;
typedef FT_LL			t_ll;

typedef FT_UNSIGNED		t_u;
# define MSG_OUT_OF_MEMORY "Out-of memory."
# define OUT_OF_MEMORY write(STDERR_FILENO, MSG_OUT_OF_MEMORY, 14);

int						ft_strocu(const char *str);
char					*ft_uitoa(unsigned int n);
char					*ft_ltoa(long n);
char					*ft_ultoa(t_ul n);
char					*ft_lltoa(t_ll n);
char					*ft_ulltoa(t_ull n);
void					ft_putstr_width(const char *str, int n);
void					ft_putnbr_width(int nb, int n);
char					*ft_uitoa_base(t_ui n, char *base);
char					*ft_ustoa_base(t_us n, char *base);
char					*ft_stoa_base(short n, char *base);
char					*ft_ultoa_base(t_ul n, char *base);
char					*ft_ltoa_base(long n, char *base);
char					*ft_lltoa_base(t_ll n, char *base);
char					*ft_ulltoa_base(t_ull n, char *base);
char					*ft_imtoa_base(intmax_t n, char *base);
char					*ft_uimtoa_base(uintmax_t n, char *base);
int						ft_itoa_s(int n, char *str);
t_ui					ft_uitoa_s(unsigned int n, char *str);
long					ft_ltoa_s(long n, char *str);
t_ul					ft_ultoa_s(unsigned long n, char *str);
void					ft_putnbrl(long n);
void					ft_putnbrul(t_ul n);
void					*ft_memallocset(size_t size, int c);

#endif
