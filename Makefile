#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2014/05/28 14:00:21 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
CCPP = g++
NAME = zappy
SERVEUR_NAME = serveur
CLIENT_NAME = client
VISU_NAME = visu
FLAGS = -Wall -Wextra -Werror -ggdb -g
INCL_FLAGS = -Iinclude -Ilibft/include
CFLAGS = $(INCL_FLAGS) $(FLAGS)
LDFLAGS = -Llibft -lft

SERVEUR_OFILES = $(notdir $(SERVEUR_CFILES:.c=.o))
CLIENT_OFILES = $(notdir $(CLIENT_CPPFILES:.cpp=.o))
VISU_OFILES = $(notdir $(VISU_CPPFILES:.cpp=.o))
COMMON_CPP_OFILES = $(notdir $(COMMON_CPPFILES:.cpp=.o))

OFILES = $(notdir $(CFILES:.c=.o)) $(notdir $(CPPFILES:.cpp=.o))
# START INSERT .source

SERVEUR_CFILES= \
		serveur_src//main.c \

CLIENT_CPPFILES= \
		client_src//main.cpp \

VISU_CPPFILES= \
		visu_src//main.cpp \

COMMON_CPPFILES= \

CFILES= $(SERVEUR_CFILES)
CPPFILES= $(CLIENT_CPPFILES) $(VISU_CPPFILES) $(COMMON_CPPFILES)


# END INSERT
SRCDIR = src/

SERVEUR_SRCDIR = src/serveur_src/
CLIENT_SRCDIR = src/client_src/
VISU_SRCDIR = src/visu_src/
COMMON_CPP_SRCDIR = src/common_cpp_src/

OBJDIR = obj/

SERVEUR_OBJ = $(addprefix $(OBJDIR)sv_,$(SERVEUR_OFILES))
CLIENT_OBJ = $(addprefix $(OBJDIR)cl_,$(CLIENT_OFILES))
VISU_OBJ = $(addprefix $(OBJDIR)visu_,$(VISU_OFILES))
COMMON_CPP_OBJ = $(addprefix($(OBJDIR)cm_,$(COMMON_OFILES))

OBJ = $(SERVEUR_OBJ) $(CLIENT_OBJ) $(VISU_OBJ) $(COMMON_CPP_OBJ)

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

$(NAME): $(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)

$(SERVEUR_NAME): libft/libft.a $(SERVEUR_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CC) -o $@ $(SERVEUR_OBJ) $(CFLAGS) $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ) $(COMMON_CPP_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CCPP) -o $@ $(CLIENT_OBJ) $(COMMON_CPP_OBJ) $(CFLAGS)

$(VISU_NAME): $(VISU_OBJ) $(COMMON_CPP_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CCPP) -o $@ $(VISU_OBJ) $(COMMON_CPP_OBJ) $(CFLAGS)

libft/libft.a:
	@make -C libft

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)
	@echo $(BRED)"    === Removing "$(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)$(END)

sclean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    --> Removing .o files"$(END)

clean: sclean
	@make -C libft $@

r: sclean all
re:	fclean all
# IGNORE NEXT LINES


obj/sv_main.o: src/serveur_src//main.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_main.o \
-c $(SRCDIR)serveur_src//main.c $(CFLAGS)

obj/cl_main.o: src/client_src//main.cpp
	@echo $(CYAN)"    Creating obj/cl_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cl_main.o \
-c $(SRCDIR)client_src//main.cpp $(CFLAGS)

obj/visu_main.o: src/visu_src//main.cpp
	@echo $(CYAN)"    Creating obj/visu_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_main.o \
-c $(SRCDIR)visu_src//main.cpp $(CFLAGS)

