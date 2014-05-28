/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:44:26 by glourdel          #+#    #+#             */
/*   Updated: 2014/05/16 12:36:46 by glourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include "libft_types.h"

# define PI 3.141593
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define COLOR_END "\033[0m"

/*
** ******************************************************* **
** **             Part 1 - libc functions               ** **
** ******************************************************* **
*/
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, const size_t n);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t nb);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr_esc(const char *s, const char c);
char	*ft_strchr_mult(const char *s, const char *allow_chars);
/*
**         --> allow_chars contains the chars that can be found
*/
char	*ft_strchr_mult_esc(const char *s, const char *allow_chars);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** ******************************************************* **
** **             Part 2 - Extra functions              ** **
** ******************************************************* **
*/
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_free_strtab(char **tab);
void	ft_print_strtab(char **tab);
size_t	ft_count_strtab(char **tab);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	**ft_strsplit_esc(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_itoa_l(long int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_lu(long unsigned int n);
char	*ft_itoa_o(t_uint n);
char	*ft_itoa_x(t_uint n);
char	*ft_itoa_lx(unsigned long n);
char	*ft_itoa_llx(unsigned long long n);
char	*ft_init_x_tab(void);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putnbrn(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ******************************************************* **
** **             My Extra Functions                    ** **
** ******************************************************* **
*/
/*
**     optimisations
*/
void	ft_opt_putnbr_fd(int n, int fd);
/*
**     list functions
*/
t_list	*ft_create_elem(void *content, size_t size);
int		ft_lstpushfront(t_list **begin_list, void *data, size_t size);
int		ft_lstpushback(t_list **begin_list, void *data, size_t size);
int		ft_lstsize(t_list *begin_list);
t_list	*ft_lstlast(t_list *begin_list);
void	ft_lstclear(t_list **begin_list);
void	ft_lstreverse(t_list **begin_list);
t_list	*ft_lstat(t_list *begin_list, unsigned int nbr);
void	ft_lst_print_content(t_list *list);
void	ft_lst_remove_elem(t_list **list, size_t index);
/*
**     double-list functions
*/
t_dlist	*ft_dlst_create(void *data, size_t size);
int		ft_dlstpushfront(t_dlist **begin_list, void *data, size_t size);
int		ft_dlstpushback(t_dlist **begin_list, void *data, size_t size);
t_dlist	*ft_dlst_at(t_dlist *begin_list, size_t index);
void	ft_dlst_remove(t_dlist **begin_list, t_dlist *to_remove);
void	ft_dlst_remove_at(t_dlist **begin_list, size_t index);
int		ft_dlstins_aft(t_dlist *ptr, void *data, int size);
int		ft_dlstins_bef(t_dlist **beg_list, t_dlist *ptr, void *data, int size);
int		ft_dlstins_at(t_dlist **beg_list, size_t index, void *data, int size);
void	ft_dlstclear(t_dlist **begin_list);
void	ft_dlst_rollback(t_dlist **list);
size_t	ft_dlst_size(t_dlist *list);
t_dlist	*ft_dlst_last(t_dlist *list);
t_dlist	*ft_dlst_first(t_dlist *list);
/*
**     str functions
*/
char	*ft_last_char(const char *str);
size_t	ft_char_count(const char *str, const char c);
char	*ft_str_gotochar(char *str, const char c, size_t index);
char	*ft_color_red(char *str);
char	*ft_color_green(char *str);
char	*ft_color_bk_ongreen(char *str);
char	*ft_pathjoin(char *dir_path, char *name);
char	*ft_pathadd(const char *abs_path, const char *rel_path);
char	*ft_path_mergehome(const char *path, const char *home);
void	ft_sort_chartab(char **tab, int (*f)(const char *, const char *));
char	*ft_strdel_and_new(char *str, size_t size);
char	*ft_merge_signs(char *str);
char	*ft_clean_begin(char *s, char *allow);
/*
**       -> allow contains the chars that are NOT to clean
*/
char	**ft_strsplit_mult(char const *s, char *allow);
/*
**       -> allow contains the chars that does NOT split
*/
void	ft_strshift(char *dest, char *src);

/*
**     ft_printf
*/
# define ALLW_OPT "# +-.0123456789*l"
# define ALLW_FLAG "dicsuoxp"

int		ft_printf(const char *format, ...);
size_t	ft_printf_output_id(va_list *ap, t_opt *opt);
size_t	ft_printf_output_c(va_list *ap, t_opt *opt);
size_t	ft_printf_output_s(va_list *ap, t_opt *opt);
size_t	ft_printf_output_u(va_list *ap, t_opt *opt);
size_t	ft_printf_output_o(va_list *ap, t_opt *opt);
size_t	ft_printf_output_x(va_list *ap, t_opt *opt);
size_t	rec_printf_output_x(unsigned long nbr, char *tab);
size_t	ft_printf_output_p(va_list *ap, t_opt *opt);
t_opt	*ft_printf_get_options(char *content, va_list *ap);
size_t	ft_printf_output_invalid(char *content, t_opt *opt);
void	ft_check_star(va_list *ap, t_opt *opt);
t_uint	ft_check_precision(char **output, t_opt *opt);
void	ft_print_output_without_prec(char *output, t_opt *opt);
void	ft_print_output_without_prec_uox(char *output, t_opt *opt);
void	ft_print_output_without_prec_p(char *output, t_opt *opt);
void	ft_printf_putstr(char *str);
void	ft_printf_add_sharp_opt_o(char **output);
void	ft_printf_add_sharp_opt_xp(char **output, t_opt *opt);
t_list	*ft_split_option(char *str, const char c);

/*
**     math functions / defines
*/
# define DEG_TO_RAD(angle) ((double)angle * PI * 2 / 360)
# define ABS(nbr) (((nbr) >= 0) ? (nbr) : -(nbr))

int		ft_div_by_pgcd(int *nbr1, int *nbr2);
double	ft_sqrt_d(double nbr);

#endif
