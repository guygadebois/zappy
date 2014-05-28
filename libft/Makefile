#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2014/04/23 16:44:12 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources
.SUFFIXES:

export CC = gcc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCL_FLAGS = -Iinclude
CFLAGS = $(INCL_FLAGS) $(FLAGS)

OFILES = $(notdir $(CFILES:.c=.o))

CFILES= \
		ft_atoi.c \
		ft_bzero.c \
		ft_char_count.c \
		ft_check_star_and_prec_opt.c \
		ft_clean_begin.c \
		ft_color_bk_ongreen.c \
		ft_color_green.c \
		ft_color_red.c \
		ft_count_strtab.c \
		ft_create_elem.c \
		ft_div_by_pgcd.c \
		ft_dlst_at.c \
		ft_dlstclear.c \
		ft_dlst_create.c \
		ft_dlstins_aft.c \
		ft_dlstins_at.c \
		ft_dlstins_bef.c \
		ft_dlstpushback.c \
		ft_dlstpushfront.c \
		ft_dlst_remove_at.c \
		ft_dlst_remove.c \
		ft_free_strtab.c \
		ft_init_x_tab.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_l.c \
		ft_itoa_llx.c \
		ft_itoa_lu.c \
		ft_itoa_lx.c \
		ft_itoa_o.c \
		ft_itoa_u.c \
		ft_itoa_x.c \
		ft_last_char.c \
		ft_lstadd.c \
		ft_lstat.c \
		ft_lstclear.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lst_print_content.c \
		ft_lstpushback.c \
		ft_lstpushfront.c \
		ft_lst_remove_elem.c \
		ft_lstreverse.c \
		ft_lstsize.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_merge_signs.c \
		ft_opt_putnbr_fd.c \
		ft_pathadd.c \
		ft_pathjoin.c \
		ft_path_mergehome.c \
		ft_printf_add_sharp_opt.c \
		ft_printf.c \
		ft_printf_get_options.c \
		ft_printf_output_c.c \
		ft_printf_output_id.c \
		ft_printf_output_invalid.c \
		ft_printf_output_o.c \
		ft_printf_output_p.c \
		ft_printf_output_s.c \
		ft_printf_output_u.c \
		ft_printf_output_x.c \
		ft_printf_putstr.c \
		ft_print_output_without_prec.c \
		ft_print_strtab.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_sort_chartab.c \
		ft_split_option.c \
		ft_sqrt_d.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strchr_esc.c \
		ft_strchr_mult.c \
		ft_strchr_mult_esc.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel_and_new.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_str_gotochar.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strshift.c \
		ft_strsplit.c \
		ft_strsplit_esc.c \
		ft_strsplit_mult.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		matrix_dup.c \
		matrix_mult.c \
		matrix_print.c \


SRCDIR = src/

SRC = $(addprefix $(SRCDIR),$(CFILES))

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR),$(OFILES))

CYAN = "\033[36m"
BLUE = "\033[34;1;3m"
GREEN = "\033[32m"
IGREEN = "\033[30;42m"
RED = "\033[31m"
IRED = "\033[0;37;41m"
BRED = "\033[31;1m"
END = "\033[0m"

all: $(NAME)

a: all clean

$(NAME): $(OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    [libft] Linking $@..."$(END);
	@/bin/echo "";
	@ar rc $@ $(OBJ)
	@ranlib $@

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(BRED)"    [libft] Removing "$(NAME)$(END)

clean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    [libft] Removing .o files"$(END)

re:	fclean all


obj/ft_atoi.o: src/ft_atoi.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_atoi.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_atoi.o \
-c $(SRCDIR)ft_atoi.c $(CFLAGS)

obj/ft_bzero.o: src/ft_bzero.c
	@echo $(CYAN)"    [libft] Creating obj/ft_bzero.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_bzero.o \
-c $(SRCDIR)ft_bzero.c $(CFLAGS)

obj/ft_char_count.o: src/ft_char_count.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_char_count.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_char_count.o \
-c $(SRCDIR)ft_char_count.c $(CFLAGS)

obj/ft_check_star_and_prec_opt.o: src/ft_check_star_and_prec_opt.c \
 include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_check_star_and_prec_opt.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_check_star_and_prec_opt.o \
-c $(SRCDIR)ft_check_star_and_prec_opt.c $(CFLAGS)

obj/ft_clean_begin.o: src/ft_clean_begin.c
	@echo $(CYAN)"    [libft] Creating obj/ft_clean_begin.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_clean_begin.o \
-c $(SRCDIR)ft_clean_begin.c $(CFLAGS)

obj/ft_color_bk_ongreen.o: src/ft_color_bk_ongreen.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_color_bk_ongreen.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_color_bk_ongreen.o \
-c $(SRCDIR)ft_color_bk_ongreen.c $(CFLAGS)

obj/ft_color_green.o: src/ft_color_green.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_color_green.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_color_green.o \
-c $(SRCDIR)ft_color_green.c $(CFLAGS)

obj/ft_color_red.o: src/ft_color_red.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_color_red.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_color_red.o \
-c $(SRCDIR)ft_color_red.c $(CFLAGS)

obj/ft_count_strtab.o: src/ft_count_strtab.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_count_strtab.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_count_strtab.o \
-c $(SRCDIR)ft_count_strtab.c $(CFLAGS)

obj/ft_create_elem.o: src/ft_create_elem.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_create_elem.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_create_elem.o \
-c $(SRCDIR)ft_create_elem.c $(CFLAGS)

obj/ft_div_by_pgcd.o: src/ft_div_by_pgcd.c
	@echo $(CYAN)"    [libft] Creating obj/ft_div_by_pgcd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_div_by_pgcd.o \
-c $(SRCDIR)ft_div_by_pgcd.c $(CFLAGS)

obj/ft_dlst_at.o: src/ft_dlst_at.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlst_at.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlst_at.o \
-c $(SRCDIR)ft_dlst_at.c $(CFLAGS)

obj/ft_dlstclear.o: src/ft_dlstclear.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstclear.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstclear.o \
-c $(SRCDIR)ft_dlstclear.c $(CFLAGS)

obj/ft_dlst_create.o: src/ft_dlst_create.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlst_create.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlst_create.o \
-c $(SRCDIR)ft_dlst_create.c $(CFLAGS)

obj/ft_dlstins_aft.o: src/ft_dlstins_aft.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstins_aft.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstins_aft.o \
-c $(SRCDIR)ft_dlstins_aft.c $(CFLAGS)

obj/ft_dlstins_at.o: src/ft_dlstins_at.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstins_at.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstins_at.o \
-c $(SRCDIR)ft_dlstins_at.c $(CFLAGS)

obj/ft_dlstins_bef.o: src/ft_dlstins_bef.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstins_bef.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstins_bef.o \
-c $(SRCDIR)ft_dlstins_bef.c $(CFLAGS)

obj/ft_dlstpushback.o: src/ft_dlstpushback.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstpushback.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstpushback.o \
-c $(SRCDIR)ft_dlstpushback.c $(CFLAGS)

obj/ft_dlstpushfront.o: src/ft_dlstpushfront.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlstpushfront.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlstpushfront.o \
-c $(SRCDIR)ft_dlstpushfront.c $(CFLAGS)

obj/ft_dlst_remove_at.o: src/ft_dlst_remove_at.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlst_remove_at.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlst_remove_at.o \
-c $(SRCDIR)ft_dlst_remove_at.c $(CFLAGS)

obj/ft_dlst_remove.o: src/ft_dlst_remove.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_dlst_remove.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_dlst_remove.o \
-c $(SRCDIR)ft_dlst_remove.c $(CFLAGS)

obj/ft_free_strtab.o: src/ft_free_strtab.c
	@echo $(CYAN)"    [libft] Creating obj/ft_free_strtab.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_free_strtab.o \
-c $(SRCDIR)ft_free_strtab.c $(CFLAGS)

obj/ft_init_x_tab.o: src/ft_init_x_tab.c
	@echo $(CYAN)"    [libft] Creating obj/ft_init_x_tab.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_init_x_tab.o \
-c $(SRCDIR)ft_init_x_tab.c $(CFLAGS)

obj/ft_isalnum.o: src/ft_isalnum.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_isalnum.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_isalnum.o \
-c $(SRCDIR)ft_isalnum.c $(CFLAGS)

obj/ft_isalpha.o: src/ft_isalpha.c
	@echo $(CYAN)"    [libft] Creating obj/ft_isalpha.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_isalpha.o \
-c $(SRCDIR)ft_isalpha.c $(CFLAGS)

obj/ft_isascii.o: src/ft_isascii.c
	@echo $(CYAN)"    [libft] Creating obj/ft_isascii.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_isascii.o \
-c $(SRCDIR)ft_isascii.c $(CFLAGS)

obj/ft_isdigit.o: src/ft_isdigit.c
	@echo $(CYAN)"    [libft] Creating obj/ft_isdigit.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_isdigit.o \
-c $(SRCDIR)ft_isdigit.c $(CFLAGS)

obj/ft_isprint.o: src/ft_isprint.c
	@echo $(CYAN)"    [libft] Creating obj/ft_isprint.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_isprint.o \
-c $(SRCDIR)ft_isprint.c $(CFLAGS)

obj/ft_itoa.o: src/ft_itoa.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa.o \
-c $(SRCDIR)ft_itoa.c $(CFLAGS)

obj/ft_itoa_l.o: src/ft_itoa_l.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_l.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_l.o \
-c $(SRCDIR)ft_itoa_l.c $(CFLAGS)

obj/ft_itoa_llx.o: src/ft_itoa_llx.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_llx.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_llx.o \
-c $(SRCDIR)ft_itoa_llx.c $(CFLAGS)

obj/ft_itoa_lu.o: src/ft_itoa_lu.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_lu.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_lu.o \
-c $(SRCDIR)ft_itoa_lu.c $(CFLAGS)

obj/ft_itoa_lx.o: src/ft_itoa_lx.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_lx.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_lx.o \
-c $(SRCDIR)ft_itoa_lx.c $(CFLAGS)

obj/ft_itoa_o.o: src/ft_itoa_o.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_o.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_o.o \
-c $(SRCDIR)ft_itoa_o.c $(CFLAGS)

obj/ft_itoa_u.o: src/ft_itoa_u.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_u.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_u.o \
-c $(SRCDIR)ft_itoa_u.c $(CFLAGS)

obj/ft_itoa_x.o: src/ft_itoa_x.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_itoa_x.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_itoa_x.o \
-c $(SRCDIR)ft_itoa_x.c $(CFLAGS)

obj/ft_last_char.o: src/ft_last_char.c
	@echo $(CYAN)"    [libft] Creating obj/ft_last_char.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_last_char.o \
-c $(SRCDIR)ft_last_char.c $(CFLAGS)

obj/ft_lstadd.o: src/ft_lstadd.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstadd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstadd.o \
-c $(SRCDIR)ft_lstadd.c $(CFLAGS)

obj/ft_lstat.o: src/ft_lstat.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstat.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstat.o \
-c $(SRCDIR)ft_lstat.c $(CFLAGS)

obj/ft_lstclear.o: src/ft_lstclear.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstclear.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstclear.o \
-c $(SRCDIR)ft_lstclear.c $(CFLAGS)

obj/ft_lstdel.o: src/ft_lstdel.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstdel.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstdel.o \
-c $(SRCDIR)ft_lstdel.c $(CFLAGS)

obj/ft_lstdelone.o: src/ft_lstdelone.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstdelone.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstdelone.o \
-c $(SRCDIR)ft_lstdelone.c $(CFLAGS)

obj/ft_lstiter.o: src/ft_lstiter.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstiter.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstiter.o \
-c $(SRCDIR)ft_lstiter.c $(CFLAGS)

obj/ft_lstlast.o: src/ft_lstlast.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstlast.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstlast.o \
-c $(SRCDIR)ft_lstlast.c $(CFLAGS)

obj/ft_lstmap.o: src/ft_lstmap.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstmap.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstmap.o \
-c $(SRCDIR)ft_lstmap.c $(CFLAGS)

obj/ft_lstnew.o: src/ft_lstnew.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstnew.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstnew.o \
-c $(SRCDIR)ft_lstnew.c $(CFLAGS)

obj/ft_lst_print_content.o: src/ft_lst_print_content.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lst_print_content.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lst_print_content.o \
-c $(SRCDIR)ft_lst_print_content.c $(CFLAGS)

obj/ft_lstpushback.o: src/ft_lstpushback.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstpushback.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstpushback.o \
-c $(SRCDIR)ft_lstpushback.c $(CFLAGS)

obj/ft_lstpushfront.o: src/ft_lstpushfront.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstpushfront.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstpushfront.o \
-c $(SRCDIR)ft_lstpushfront.c $(CFLAGS)

obj/ft_lst_remove_elem.o: src/ft_lst_remove_elem.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lst_remove_elem.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lst_remove_elem.o \
-c $(SRCDIR)ft_lst_remove_elem.c $(CFLAGS)

obj/ft_lstreverse.o: src/ft_lstreverse.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstreverse.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstreverse.o \
-c $(SRCDIR)ft_lstreverse.c $(CFLAGS)

obj/ft_lstsize.o: src/ft_lstsize.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_lstsize.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_lstsize.o \
-c $(SRCDIR)ft_lstsize.c $(CFLAGS)

obj/ft_memalloc.o: src/ft_memalloc.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_memalloc.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memalloc.o \
-c $(SRCDIR)ft_memalloc.c $(CFLAGS)

obj/ft_memccpy.o: src/ft_memccpy.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memccpy.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memccpy.o \
-c $(SRCDIR)ft_memccpy.c $(CFLAGS)

obj/ft_memchr.o: src/ft_memchr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memchr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memchr.o \
-c $(SRCDIR)ft_memchr.c $(CFLAGS)

obj/ft_memcmp.o: src/ft_memcmp.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memcmp.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memcmp.o \
-c $(SRCDIR)ft_memcmp.c $(CFLAGS)

obj/ft_memcpy.o: src/ft_memcpy.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memcpy.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memcpy.o \
-c $(SRCDIR)ft_memcpy.c $(CFLAGS)

obj/ft_memdel.o: src/ft_memdel.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memdel.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memdel.o \
-c $(SRCDIR)ft_memdel.c $(CFLAGS)

obj/ft_memmove.o: src/ft_memmove.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_memmove.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memmove.o \
-c $(SRCDIR)ft_memmove.c $(CFLAGS)

obj/ft_memset.o: src/ft_memset.c
	@echo $(CYAN)"    [libft] Creating obj/ft_memset.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_memset.o \
-c $(SRCDIR)ft_memset.c $(CFLAGS)

obj/ft_merge_signs.o: src/ft_merge_signs.c
	@echo $(CYAN)"    [libft] Creating obj/ft_merge_signs.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_merge_signs.o \
-c $(SRCDIR)ft_merge_signs.c $(CFLAGS)

obj/ft_opt_putnbr_fd.o: src/ft_opt_putnbr_fd.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_opt_putnbr_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_opt_putnbr_fd.o \
-c $(SRCDIR)ft_opt_putnbr_fd.c $(CFLAGS)

obj/ft_pathadd.o: src/ft_pathadd.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_pathadd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_pathadd.o \
-c $(SRCDIR)ft_pathadd.c $(CFLAGS)

obj/ft_pathjoin.o: src/ft_pathjoin.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_pathjoin.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_pathjoin.o \
-c $(SRCDIR)ft_pathjoin.c $(CFLAGS)

obj/ft_path_mergehome.o: src/ft_path_mergehome.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_path_mergehome.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_path_mergehome.o \
-c $(SRCDIR)ft_path_mergehome.c $(CFLAGS)

obj/ft_printf_add_sharp_opt.o: src/ft_printf_add_sharp_opt.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_add_sharp_opt.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_add_sharp_opt.o \
-c $(SRCDIR)ft_printf_add_sharp_opt.c $(CFLAGS)

obj/ft_printf.o: src/ft_printf.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf.o \
-c $(SRCDIR)ft_printf.c $(CFLAGS)

obj/ft_printf_get_options.o: src/ft_printf_get_options.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_get_options.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_get_options.o \
-c $(SRCDIR)ft_printf_get_options.c $(CFLAGS)

obj/ft_printf_output_c.o: src/ft_printf_output_c.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_c.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_c.o \
-c $(SRCDIR)ft_printf_output_c.c $(CFLAGS)

obj/ft_printf_output_id.o: src/ft_printf_output_id.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_id.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_id.o \
-c $(SRCDIR)ft_printf_output_id.c $(CFLAGS)

obj/ft_printf_output_invalid.o: src/ft_printf_output_invalid.c \
 include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_invalid.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_invalid.o \
-c $(SRCDIR)ft_printf_output_invalid.c $(CFLAGS)

obj/ft_printf_output_o.o: src/ft_printf_output_o.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_o.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_o.o \
-c $(SRCDIR)ft_printf_output_o.c $(CFLAGS)

obj/ft_printf_output_p.o: src/ft_printf_output_p.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_p.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_p.o \
-c $(SRCDIR)ft_printf_output_p.c $(CFLAGS)

obj/ft_printf_output_s.o: src/ft_printf_output_s.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_s.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_s.o \
-c $(SRCDIR)ft_printf_output_s.c $(CFLAGS)

obj/ft_printf_output_u.o: src/ft_printf_output_u.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_u.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_u.o \
-c $(SRCDIR)ft_printf_output_u.c $(CFLAGS)

obj/ft_printf_output_x.o: src/ft_printf_output_x.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_output_x.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_output_x.o \
-c $(SRCDIR)ft_printf_output_x.c $(CFLAGS)

obj/ft_printf_putstr.o: src/ft_printf_putstr.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_printf_putstr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_printf_putstr.o \
-c $(SRCDIR)ft_printf_putstr.c $(CFLAGS)

obj/ft_print_output_without_prec.o: src/ft_print_output_without_prec.c \
 include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_print_output_without_prec.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_print_output_without_prec.o \
-c $(SRCDIR)ft_print_output_without_prec.c $(CFLAGS)

obj/ft_print_strtab.o: src/ft_print_strtab.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_print_strtab.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_print_strtab.o \
-c $(SRCDIR)ft_print_strtab.c $(CFLAGS)

obj/ft_putchar.o: src/ft_putchar.c
	@echo $(CYAN)"    [libft] Creating obj/ft_putchar.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putchar.o \
-c $(SRCDIR)ft_putchar.c $(CFLAGS)

obj/ft_putchar_fd.o: src/ft_putchar_fd.c
	@echo $(CYAN)"    [libft] Creating obj/ft_putchar_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putchar_fd.o \
-c $(SRCDIR)ft_putchar_fd.c $(CFLAGS)

obj/ft_putendl.o: src/ft_putendl.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putendl.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putendl.o \
-c $(SRCDIR)ft_putendl.c $(CFLAGS)

obj/ft_putendl_fd.o: src/ft_putendl_fd.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putendl_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putendl_fd.o \
-c $(SRCDIR)ft_putendl_fd.c $(CFLAGS)

obj/ft_putnbr.o: src/ft_putnbr.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putnbr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putnbr.o \
-c $(SRCDIR)ft_putnbr.c $(CFLAGS)

obj/ft_putnbr_fd.o: src/ft_putnbr_fd.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putnbr_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putnbr_fd.o \
-c $(SRCDIR)ft_putnbr_fd.c $(CFLAGS)

obj/ft_putstr.o: src/ft_putstr.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putstr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putstr.o \
-c $(SRCDIR)ft_putstr.c $(CFLAGS)

obj/ft_putstr_fd.o: src/ft_putstr_fd.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_putstr_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_putstr_fd.o \
-c $(SRCDIR)ft_putstr_fd.c $(CFLAGS)

obj/ft_sort_chartab.o: src/ft_sort_chartab.c
	@echo $(CYAN)"    [libft] Creating obj/ft_sort_chartab.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_sort_chartab.o \
-c $(SRCDIR)ft_sort_chartab.c $(CFLAGS)

obj/ft_split_option.o: src/ft_split_option.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_split_option.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_split_option.o \
-c $(SRCDIR)ft_split_option.c $(CFLAGS)

obj/ft_sqrt_d.o: src/ft_sqrt_d.c
	@echo $(CYAN)"    [libft] Creating obj/ft_sqrt_d.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_sqrt_d.o \
-c $(SRCDIR)ft_sqrt_d.c $(CFLAGS)

obj/ft_strcat.o: src/ft_strcat.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strcat.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strcat.o \
-c $(SRCDIR)ft_strcat.c $(CFLAGS)

obj/ft_strchr.o: src/ft_strchr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strchr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strchr.o \
-c $(SRCDIR)ft_strchr.c $(CFLAGS)

obj/ft_strchr_esc.o: src/ft_strchr_esc.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strchr_esc.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strchr_esc.o \
-c $(SRCDIR)ft_strchr_esc.c $(CFLAGS)

obj/ft_strchr_mult.o: src/ft_strchr_mult.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strchr_mult.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strchr_mult.o \
-c $(SRCDIR)ft_strchr_mult.c $(CFLAGS)

obj/ft_strchr_mult_esc.o: src/ft_strchr_mult_esc.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strchr_mult_esc.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strchr_mult_esc.o \
-c $(SRCDIR)ft_strchr_mult_esc.c $(CFLAGS)

obj/ft_strclr.o: src/ft_strclr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strclr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strclr.o \
-c $(SRCDIR)ft_strclr.c $(CFLAGS)

obj/ft_strcmp.o: src/ft_strcmp.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strcmp.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strcmp.o \
-c $(SRCDIR)ft_strcmp.c $(CFLAGS)

obj/ft_strcpy.o: src/ft_strcpy.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strcpy.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strcpy.o \
-c $(SRCDIR)ft_strcpy.c $(CFLAGS)

obj/ft_strdel_and_new.o: src/ft_strdel_and_new.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strdel_and_new.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strdel_and_new.o \
-c $(SRCDIR)ft_strdel_and_new.c $(CFLAGS)

obj/ft_strdel.o: src/ft_strdel.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strdel.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strdel.o \
-c $(SRCDIR)ft_strdel.c $(CFLAGS)

obj/ft_strdup.o: src/ft_strdup.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strdup.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strdup.o \
-c $(SRCDIR)ft_strdup.c $(CFLAGS)

obj/ft_strequ.o: src/ft_strequ.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strequ.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strequ.o \
-c $(SRCDIR)ft_strequ.c $(CFLAGS)

obj/ft_str_gotochar.o: src/ft_str_gotochar.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_str_gotochar.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_str_gotochar.o \
-c $(SRCDIR)ft_str_gotochar.c $(CFLAGS)

obj/ft_striter.o: src/ft_striter.c
	@echo $(CYAN)"    [libft] Creating obj/ft_striter.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_striter.o \
-c $(SRCDIR)ft_striter.c $(CFLAGS)

obj/ft_striteri.o: src/ft_striteri.c
	@echo $(CYAN)"    [libft] Creating obj/ft_striteri.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_striteri.o \
-c $(SRCDIR)ft_striteri.c $(CFLAGS)

obj/ft_strjoin.o: src/ft_strjoin.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strjoin.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strjoin.o \
-c $(SRCDIR)ft_strjoin.c $(CFLAGS)

obj/ft_strlcat.o: src/ft_strlcat.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strlcat.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strlcat.o \
-c $(SRCDIR)ft_strlcat.c $(CFLAGS)

obj/ft_strlen.o: src/ft_strlen.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strlen.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strlen.o \
-c $(SRCDIR)ft_strlen.c $(CFLAGS)

obj/ft_strmap.o: src/ft_strmap.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strmap.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strmap.o \
-c $(SRCDIR)ft_strmap.c $(CFLAGS)

obj/ft_strmapi.o: src/ft_strmapi.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strmapi.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strmapi.o \
-c $(SRCDIR)ft_strmapi.c $(CFLAGS)

obj/ft_strncat.o: src/ft_strncat.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strncat.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strncat.o \
-c $(SRCDIR)ft_strncat.c $(CFLAGS)

obj/ft_strncmp.o: src/ft_strncmp.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strncmp.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strncmp.o \
-c $(SRCDIR)ft_strncmp.c $(CFLAGS)

obj/ft_strncpy.o: src/ft_strncpy.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strncpy.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strncpy.o \
-c $(SRCDIR)ft_strncpy.c $(CFLAGS)

obj/ft_strndup.o: src/ft_strndup.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strndup.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strndup.o \
-c $(SRCDIR)ft_strndup.c $(CFLAGS)

obj/ft_strnequ.o: src/ft_strnequ.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strnequ.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strnequ.o \
-c $(SRCDIR)ft_strnequ.c $(CFLAGS)

obj/ft_strnew.o: src/ft_strnew.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strnew.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strnew.o \
-c $(SRCDIR)ft_strnew.c $(CFLAGS)

obj/ft_strnstr.o: src/ft_strnstr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strnstr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strnstr.o \
-c $(SRCDIR)ft_strnstr.c $(CFLAGS)

obj/ft_strrchr.o: src/ft_strrchr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strrchr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strrchr.o \
-c $(SRCDIR)ft_strrchr.c $(CFLAGS)

obj/ft_strshift.o: src/ft_strshift.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strshift.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strshift.o \
-c $(SRCDIR)ft_strshift.c $(CFLAGS)

obj/ft_strsplit.o: src/ft_strsplit.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strsplit.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strsplit.o \
-c $(SRCDIR)ft_strsplit.c $(CFLAGS)

obj/ft_strsplit_esc.o: src/ft_strsplit_esc.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strsplit_esc.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strsplit_esc.o \
-c $(SRCDIR)ft_strsplit_esc.c $(CFLAGS)

obj/ft_strsplit_mult.o: src/ft_strsplit_mult.c include/libft.h \
 include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strsplit_mult.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strsplit_mult.o \
-c $(SRCDIR)ft_strsplit_mult.c $(CFLAGS)

obj/ft_strstr.o: src/ft_strstr.c
	@echo $(CYAN)"    [libft] Creating obj/ft_strstr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strstr.o \
-c $(SRCDIR)ft_strstr.c $(CFLAGS)

obj/ft_strsub.o: src/ft_strsub.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strsub.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strsub.o \
-c $(SRCDIR)ft_strsub.c $(CFLAGS)

obj/ft_strtrim.o: src/ft_strtrim.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/ft_strtrim.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_strtrim.o \
-c $(SRCDIR)ft_strtrim.c $(CFLAGS)

obj/ft_tolower.o: src/ft_tolower.c
	@echo $(CYAN)"    [libft] Creating obj/ft_tolower.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_tolower.o \
-c $(SRCDIR)ft_tolower.c $(CFLAGS)

obj/ft_toupper.o: src/ft_toupper.c
	@echo $(CYAN)"    [libft] Creating obj/ft_toupper.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_toupper.o \
-c $(SRCDIR)ft_toupper.c $(CFLAGS)

obj/get_next_line.o: src/get_next_line.c include/get_next_line.h \
 include/libft.h include/libft_types.h include/libft.h
	@echo $(CYAN)"    [libft] Creating obj/get_next_line.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)get_next_line.o \
-c $(SRCDIR)get_next_line.c $(CFLAGS)

obj/matrix_dup.o: src/matrix_dup.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/matrix_dup.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)matrix_dup.o \
-c $(SRCDIR)matrix_dup.c $(CFLAGS)

obj/matrix_mult.o: src/matrix_mult.c
	@echo $(CYAN)"    [libft] Creating obj/matrix_mult.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)matrix_mult.o \
-c $(SRCDIR)matrix_mult.c $(CFLAGS)

obj/matrix_print.o: src/matrix_print.c include/libft.h include/libft_types.h
	@echo $(CYAN)"    [libft] Creating obj/matrix_print.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)matrix_print.o \
-c $(SRCDIR)matrix_print.c $(CFLAGS)

