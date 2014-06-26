#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2014/06/24 11:41:00 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
CCPP = g++ -std=c++0x
NAME = zappy
SERVEUR_NAME = serveur
CLIENT_NAME = client
VISU_NAME = visu
FLAGS = -Wall -Wextra -Werror -ggdb -g
INCL_FLAGS = -Iinclude -Iinclude/models -Iinclude/visu_models -Ilibft/include
IRRLICHT_INCL_FLAGS = -I irrlicht/include

ifeq ($(shell uname), Linux)
IRRLICHT_LDFLAGS= -L ../irrlicht-trunk/lib/Linux -l Irrlicht -l GL -lXext \
-lX11 -lGLU -lXxf86vm
else
IRRLICHT_LDFLAGS= -L irrlicht/lib -l Irrlicht -framework OpenGL \
-framework Cocoa -framework Carbon -framework IOKit
endif
CFLAGS = $(INCL_FLAGS) $(FLAGS) $(IRRLICHT_INCL_FLAGS)
LDFLAGS = -Llibft -lft

SERVEUR_OFILES = $(notdir $(SERVEUR_CFILES:.c=.o))
CLIENT_OFILES = $(notdir $(CLIENT_CPPFILES:.cpp=.o))
VISU_OFILES = $(notdir $(VISU_CPPFILES:.cpp=.o))
COMMON_CPP_OFILES = $(notdir $(COMMON_CPPFILES:.cpp=.o))

OFILES = $(notdir $(CFILES:.c=.o)) $(notdir $(CPPFILES:.cpp=.o))
# START INSERT .source

SERVEUR_CFILES= \
		serveur_src/add_trant_map.c \
		serveur_src/answer_cmd.c \
		serveur_src/append_in_workbuff.c \
		serveur_src/broad2.c \
		serveur_src/broad.c \
		serveur_src/cmd_visu.c \
		serveur_src/connect_nbr.c \
		serveur_src/create_server.c \
		serveur_src/del_trant.c \
		serveur_src/drop_obj.c \
		serveur_src/errors.c \
		serveur_src/find_ret.c \
		serveur_src/fork.c \
		serveur_src/generate_map.c \
		serveur_src/get_arg.c \
		serveur_src/getclientbysock.c \
		serveur_src/get_inventory.c \
		serveur_src/incan_bis.c \
		serveur_src/incantation.c \
		serveur_src/incan_two.c \
		serveur_src/insert_trant.c \
		serveur_src/kick.c \
		serveur_src/listen_fd.c \
		serveur_src/loop.c \
		serveur_src/main.c \
		serveur_src/move_forward.c \
		serveur_src/place_deraumere.c \
		serveur_src/place_food_bis.c \
		serveur_src/place_linemate.c \
		serveur_src/place_mendiane.c \
		serveur_src/place_phiras.c \
		serveur_src/place_sibur.c \
		serveur_src/place_thystame.c \
		serveur_src/read_from_client.c \
		serveur_src/send_visu.c \
		serveur_src/sv_sendall.c \
		serveur_src/sv_send.c \
		serveur_src/take_obj.c \
		serveur_src/turn_left.c \
		serveur_src/turn_right.c \
		serveur_src/under_space.c \
		serveur_src/vision_bis.c \
		serveur_src/vision.c \
		serveur_src/vision_two.c \

CLIENT_CPPFILES= \
		client_src/cl_parse_line.cpp \
		client_src/errors.cpp \
		client_src/main.cpp \

VISU_CPPFILES= \
		visu_src/errors.cpp \
		visu_src/main.cpp \
		visu_src/models/Engine_cmd.cpp \
		visu_src/models/Engine.cpp \
		visu_src/models/MapData_animations.cpp \
		visu_src/models/MapData.cpp \
		visu_src/models/MapData_register.cpp \
		visu_src/models/MapData_setget.cpp \
		visu_src/models/MySceneNode.cpp \
		visu_src/models/MySceneNode_setget.cpp \
		visu_src/models/PartEmitterAnim.cpp \
		visu_src/models/VisuComm.cpp \

COMMON_CPPFILES= \
		common_cpp_src/find_ret.cpp \
		common_cpp_src/ft_sendall.cpp \
		common_cpp_src/mystring.cpp \
		common_cpp_src/new_connection.cpp \
		common_cpp_src/read_buf.cpp \

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
COMMON_CPP_OBJ = $(addprefix $(OBJDIR)cm_,$(COMMON_CPP_OFILES))

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
ifeq ($(shell uname), Linux)
	@$(CC) -o $@ $(SERVEUR_OBJ) $(CFLAGS) $(LDFLAGS) -lm
else
	@$(CC) -o $@ $(SERVEUR_OBJ) $(CFLAGS) $(LDFLAGS)
endif

$(CLIENT_NAME): $(CLIENT_OBJ) $(COMMON_CPP_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CCPP) -o $@ $(CLIENT_OBJ) $(COMMON_CPP_OBJ) $(CFLAGS)

$(VISU_NAME): $(VISU_OBJ) $(COMMON_CPP_OBJ)
	@rm -f visu
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
ifeq ($(shell uname), Linux)
	@$(CCPP) -o $@ $(VISU_OBJ) $(COMMON_CPP_OBJ) $(INCL_FLAGS) \
$(IRRLICHT_INCL_FLAGS) $(IRRLICHT_LDFLAGS)
else
	@$(CCPP) -o $@ $(VISU_OBJ) $(COMMON_CPP_OBJ) $(INCL_FLAGS) \
$(IRRLICHT_INCL_FLAGS) $(IRRLICHT_LDFLAGS) 2>/dev/null \
|| echo '\033[31mERROR: visu linking failed...\033[0m'
	@lipo -create visu -output visu.app/Contents/MacOS/visu \
&& rm visu && ln -s visu.app/Contents/MacOS visu
endif

libft/libft.a:
	@make -C libft

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME) visu.app/Contents/MacOS/visu
	@echo $(BRED)"    === Removing "$(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)$(END)

sclean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    --> Removing .o files"$(END)

clean: sclean
	@make -C libft $@

r: sclean all
re:	fclean all
# IGNORE NEXT LINES


obj/sv_add_trant_map.o: src/serveur_src/add_trant_map.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_add_trant_map.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_add_trant_map.o \
-c $(SRCDIR)serveur_src/add_trant_map.c $(CFLAGS)

obj/sv_answer_cmd.o: src/serveur_src/answer_cmd.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/map.h include/server.h \
 include/types.h
	@echo $(CYAN)"    Creating obj/sv_answer_cmd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_answer_cmd.o \
-c $(SRCDIR)serveur_src/answer_cmd.c $(CFLAGS)

obj/sv_append_in_workbuff.o: src/serveur_src/append_in_workbuff.c \
 libft/include/libft.h libft/include/libft_types.h include/server.h \
 include/types.h include/common.h include/map.h include/get_arg.h \
 include/types.h
	@echo $(CYAN)"    Creating obj/sv_append_in_workbuff.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_append_in_workbuff.o \
-c $(SRCDIR)serveur_src/append_in_workbuff.c $(CFLAGS)

obj/sv_broad2.o: src/serveur_src/broad2.c include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_broad2.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_broad2.o \
-c $(SRCDIR)serveur_src/broad2.c $(CFLAGS)

obj/sv_broad.o: src/serveur_src/broad.c include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_broad.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_broad.o \
-c $(SRCDIR)serveur_src/broad.c $(CFLAGS)

obj/sv_cmd_visu.o: src/serveur_src/cmd_visu.c libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_cmd_visu.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_cmd_visu.o \
-c $(SRCDIR)serveur_src/cmd_visu.c $(CFLAGS)

obj/sv_connect_nbr.o: src/serveur_src/connect_nbr.c include/map.h \
 include/common.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_connect_nbr.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_connect_nbr.o \
-c $(SRCDIR)serveur_src/connect_nbr.c $(CFLAGS)

obj/sv_create_server.o: src/serveur_src/create_server.c libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h
	@echo $(CYAN)"    Creating obj/sv_create_server.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_create_server.o \
-c $(SRCDIR)serveur_src/create_server.c $(CFLAGS)

obj/sv_del_trant.o: src/serveur_src/del_trant.c include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_del_trant.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_del_trant.o \
-c $(SRCDIR)serveur_src/del_trant.c $(CFLAGS)

obj/sv_drop_obj.o: src/serveur_src/drop_obj.c include/map.h include/common.h \
 include/server.h include/types.h include/map.h include/get_arg.h \
 libft/include/libft.h libft/include/libft_types.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_drop_obj.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_drop_obj.o \
-c $(SRCDIR)serveur_src/drop_obj.c $(CFLAGS)

obj/sv_errors.o: src/serveur_src/errors.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_errors.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_errors.o \
-c $(SRCDIR)serveur_src/errors.c $(CFLAGS)

obj/sv_find_ret.o: src/serveur_src/find_ret.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_find_ret.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_find_ret.o \
-c $(SRCDIR)serveur_src/find_ret.c $(CFLAGS)

obj/sv_fork.o: src/serveur_src/fork.c libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h include/types.h \
 include/map.h
	@echo $(CYAN)"    Creating obj/sv_fork.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_fork.o \
-c $(SRCDIR)serveur_src/fork.c $(CFLAGS)

obj/sv_generate_map.o: src/serveur_src/generate_map.c include/map.h \
 include/common.h
	@echo $(CYAN)"    Creating obj/sv_generate_map.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_generate_map.o \
-c $(SRCDIR)serveur_src/generate_map.c $(CFLAGS)

obj/sv_get_arg.o: src/serveur_src/get_arg.c include/get_arg.h \
 libft/include/libft.h libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_get_arg.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_get_arg.o \
-c $(SRCDIR)serveur_src/get_arg.c $(CFLAGS)

obj/sv_getclientbysock.o: src/serveur_src/getclientbysock.c \
 libft/include/libft.h libft/include/libft_types.h include/types.h \
 include/common.h include/map.h include/get_arg.h
	@echo $(CYAN)"    Creating obj/sv_getclientbysock.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_getclientbysock.o \
-c $(SRCDIR)serveur_src/getclientbysock.c $(CFLAGS)

obj/sv_get_inventory.o: src/serveur_src/get_inventory.c include/map.h \
 include/common.h libft/include/libft.h libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_get_inventory.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_get_inventory.o \
-c $(SRCDIR)serveur_src/get_inventory.c $(CFLAGS)

obj/sv_incan_bis.o: src/serveur_src/incan_bis.c include/types.h include/common.h \
 include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/map.h
	@echo $(CYAN)"    Creating obj/sv_incan_bis.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_incan_bis.o \
-c $(SRCDIR)serveur_src/incan_bis.c $(CFLAGS)

obj/sv_incantation.o: src/serveur_src/incantation.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/map.h
	@echo $(CYAN)"    Creating obj/sv_incantation.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_incantation.o \
-c $(SRCDIR)serveur_src/incantation.c $(CFLAGS)

obj/sv_incan_two.o: src/serveur_src/incan_two.c include/types.h include/common.h \
 include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/map.h
	@echo $(CYAN)"    Creating obj/sv_incan_two.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_incan_two.o \
-c $(SRCDIR)serveur_src/incan_two.c $(CFLAGS)

obj/sv_insert_trant.o: src/serveur_src/insert_trant.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_insert_trant.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_insert_trant.o \
-c $(SRCDIR)serveur_src/insert_trant.c $(CFLAGS)

obj/sv_kick.o: src/serveur_src/kick.c include/map.h include/common.h \
 include/get_arg.h libft/include/libft.h libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_kick.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_kick.o \
-c $(SRCDIR)serveur_src/kick.c $(CFLAGS)

obj/sv_listen_fd.o: src/serveur_src/listen_fd.c include/types.h include/common.h \
 include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_listen_fd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_listen_fd.o \
-c $(SRCDIR)serveur_src/listen_fd.c $(CFLAGS)

obj/sv_loop.o: src/serveur_src/loop.c include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/types.h include/get_arg.h \
 include/map.h
	@echo $(CYAN)"    Creating obj/sv_loop.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_loop.o \
-c $(SRCDIR)serveur_src/loop.c $(CFLAGS)

obj/sv_main.o: src/serveur_src/main.c libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h \
 include/common.h include/map.h include/get_arg.h include/get_arg.h
	@echo $(CYAN)"    Creating obj/sv_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_main.o \
-c $(SRCDIR)serveur_src/main.c $(CFLAGS)

obj/sv_move_forward.o: src/serveur_src/move_forward.c include/server.h \
 include/types.h include/common.h include/map.h include/get_arg.h \
 libft/include/libft.h libft/include/libft_types.h include/map.h \
 include/types.h include/get_arg.h
	@echo $(CYAN)"    Creating obj/sv_move_forward.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_move_forward.o \
-c $(SRCDIR)serveur_src/move_forward.c $(CFLAGS)

obj/sv_place_deraumere.o: src/serveur_src/place_deraumere.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_deraumere.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_deraumere.o \
-c $(SRCDIR)serveur_src/place_deraumere.c $(CFLAGS)

obj/sv_place_food_bis.o: src/serveur_src/place_food_bis.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_food_bis.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_food_bis.o \
-c $(SRCDIR)serveur_src/place_food_bis.c $(CFLAGS)

obj/sv_place_linemate.o: src/serveur_src/place_linemate.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_linemate.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_linemate.o \
-c $(SRCDIR)serveur_src/place_linemate.c $(CFLAGS)

obj/sv_place_mendiane.o: src/serveur_src/place_mendiane.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_mendiane.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_mendiane.o \
-c $(SRCDIR)serveur_src/place_mendiane.c $(CFLAGS)

obj/sv_place_phiras.o: src/serveur_src/place_phiras.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_phiras.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_phiras.o \
-c $(SRCDIR)serveur_src/place_phiras.c $(CFLAGS)

obj/sv_place_sibur.o: src/serveur_src/place_sibur.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_sibur.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_sibur.o \
-c $(SRCDIR)serveur_src/place_sibur.c $(CFLAGS)

obj/sv_place_thystame.o: src/serveur_src/place_thystame.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_place_thystame.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_place_thystame.o \
-c $(SRCDIR)serveur_src/place_thystame.c $(CFLAGS)

obj/sv_read_from_client.o: src/serveur_src/read_from_client.c include/common.h \
 include/server.h include/types.h include/common.h include/map.h \
 include/get_arg.h libft/include/libft.h libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_read_from_client.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_read_from_client.o \
-c $(SRCDIR)serveur_src/read_from_client.c $(CFLAGS)

obj/sv_send_visu.o: src/serveur_src/send_visu.c include/common.h \
 include/server.h include/types.h include/common.h include/map.h \
 include/get_arg.h libft/include/libft.h libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_send_visu.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_send_visu.o \
-c $(SRCDIR)serveur_src/send_visu.c $(CFLAGS)

obj/sv_sv_sendall.o: src/serveur_src/sv_sendall.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_sv_sendall.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_sv_sendall.o \
-c $(SRCDIR)serveur_src/sv_sendall.c $(CFLAGS)

obj/sv_sv_send.o: src/serveur_src/sv_send.c include/types.h include/common.h \
 include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_sv_send.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_sv_send.o \
-c $(SRCDIR)serveur_src/sv_send.c $(CFLAGS)

obj/sv_take_obj.o: src/serveur_src/take_obj.c include/map.h include/common.h \
 libft/include/libft.h libft/include/libft_types.h include/types.h \
 include/map.h include/get_arg.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_take_obj.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_take_obj.o \
-c $(SRCDIR)serveur_src/take_obj.c $(CFLAGS)

obj/sv_turn_left.o: src/serveur_src/turn_left.c include/map.h include/common.h \
 include/types.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_turn_left.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_turn_left.o \
-c $(SRCDIR)serveur_src/turn_left.c $(CFLAGS)

obj/sv_turn_right.o: src/serveur_src/turn_right.c include/map.h include/common.h \
 include/types.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_turn_right.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_turn_right.o \
-c $(SRCDIR)serveur_src/turn_right.c $(CFLAGS)

obj/sv_under_space.o: src/serveur_src/under_space.c
	@echo $(CYAN)"    Creating obj/sv_under_space.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_under_space.o \
-c $(SRCDIR)serveur_src/under_space.c $(CFLAGS)

obj/sv_vision_bis.o: src/serveur_src/vision_bis.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_vision_bis.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_vision_bis.o \
-c $(SRCDIR)serveur_src/vision_bis.c $(CFLAGS)

obj/sv_vision.o: src/serveur_src/vision.c include/types.h include/common.h \
 include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_vision.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_vision.o \
-c $(SRCDIR)serveur_src/vision.c $(CFLAGS)

obj/sv_vision_two.o: src/serveur_src/vision_two.c include/types.h \
 include/common.h include/map.h include/get_arg.h libft/include/libft.h \
 libft/include/libft_types.h include/server.h include/types.h
	@echo $(CYAN)"    Creating obj/sv_vision_two.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_vision_two.o \
-c $(SRCDIR)serveur_src/vision_two.c $(CFLAGS)

obj/cl_cl_parse_line.o: src/client_src/cl_parse_line.cpp
	@echo $(CYAN)"    Creating obj/cl_cl_parse_line.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cl_cl_parse_line.o \
-c $(SRCDIR)client_src/cl_parse_line.cpp $(CFLAGS)

obj/cl_errors.o: src/client_src/errors.cpp
	@echo $(CYAN)"    Creating obj/cl_errors.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cl_errors.o \
-c $(SRCDIR)client_src/errors.cpp $(CFLAGS)

obj/cl_main.o: src/client_src/main.cpp include/common.h include/client.h
	@echo $(CYAN)"    Creating obj/cl_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cl_main.o \
-c $(SRCDIR)client_src/main.cpp $(CFLAGS)

obj/visu_errors.o: src/visu_src/errors.cpp
	@echo $(CYAN)"    Creating obj/visu_errors.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_errors.o -Wall \
-c $(SRCDIR)visu_src/errors.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_main.o: src/visu_src/main.cpp irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MapData.h include/visu_models/PartEmitterAnim.h \
 include/visu_models/visu_define.h include/visu_models/Engine.h \
 include/visu_models/MySceneNode.h include/visu_models/MapData.h \
 include/visu_models/VisuComm.h include/visu_models/Engine.h \
 include/common.h include/mystring.h include/visu_models/visu_define.h \
 include/visu_models/VisuComm.h
	@echo $(CYAN)"    Creating obj/visu_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_main.o -Wall \
-c $(SRCDIR)visu_src/main.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_Engine_cmd.o: src/visu_src/models/Engine_cmd.cpp \
 include/visu_models/Engine.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MySceneNode.h include/visu_models/MapData.h \
 include/visu_models/PartEmitterAnim.h include/visu_models/visu_define.h \
 include/visu_models/Engine.h include/visu_models/VisuComm.h \
 include/visu_models/MySceneNode.h include/mystring.h \
 include/visu_models/errors.h
	@echo $(CYAN)"    Creating obj/visu_Engine_cmd.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_Engine_cmd.o -Wall \
-c $(SRCDIR)visu_src/models/Engine_cmd.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_Engine.o: src/visu_src/models/Engine.cpp include/visu_models/Engine.h \
 irrlicht/include/irrlicht.h irrlicht/include/IrrCompileConfig.h \
 irrlicht/include/aabbox3d.h irrlicht/include/irrMath.h \
 irrlicht/include/irrTypes.h irrlicht/include/plane3d.h \
 irrlicht/include/vector3d.h irrlicht/include/line3d.h \
 irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MySceneNode.h include/visu_models/MapData.h \
 include/visu_models/PartEmitterAnim.h include/visu_models/visu_define.h \
 include/visu_models/Engine.h include/visu_models/VisuComm.h \
 include/visu_models/MySceneNode.h include/visu_models/VisuComm.h \
 include/visu_models/errors.h
	@echo $(CYAN)"    Creating obj/visu_Engine.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_Engine.o -Wall \
-c $(SRCDIR)visu_src/models/Engine.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MapData_animations.o: src/visu_src/models/MapData_animations.cpp \
 include/visu_models/MapData.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/PartEmitterAnim.h include/visu_models/visu_define.h \
 include/visu_models/Engine.h include/visu_models/MySceneNode.h \
 include/visu_models/MapData.h include/visu_models/VisuComm.h \
 include/visu_models/MySceneNode.h
	@echo $(CYAN)"    Creating obj/visu_MapData_animations.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MapData_animations.o -Wall \
-c $(SRCDIR)visu_src/models/MapData_animations.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MapData.o: src/visu_src/models/MapData.cpp include/visu_models/MapData.h \
 irrlicht/include/irrlicht.h irrlicht/include/IrrCompileConfig.h \
 irrlicht/include/aabbox3d.h irrlicht/include/irrMath.h \
 irrlicht/include/irrTypes.h irrlicht/include/plane3d.h \
 irrlicht/include/vector3d.h irrlicht/include/line3d.h \
 irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/PartEmitterAnim.h include/visu_models/visu_define.h \
 include/visu_models/Engine.h include/visu_models/MySceneNode.h \
 include/visu_models/MapData.h include/visu_models/VisuComm.h \
 include/mystring.h include/visu_models/MySceneNode.h
	@echo $(CYAN)"    Creating obj/visu_MapData.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MapData.o -Wall \
-c $(SRCDIR)visu_src/models/MapData.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MapData_register.o: src/visu_src/models/MapData_register.cpp \
 include/visu_models/MapData.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/PartEmitterAnim.h include/visu_models/visu_define.h \
 include/visu_models/Engine.h include/visu_models/MySceneNode.h \
 include/visu_models/MapData.h include/visu_models/VisuComm.h \
 include/visu_models/MySceneNode.h
	@echo $(CYAN)"    Creating obj/visu_MapData_register.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MapData_register.o -Wall \
-c $(SRCDIR)visu_src/models/MapData_register.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MapData_setget.o: src/visu_src/models/MapData_setget.cpp \
 include/visu_models/MySceneNode.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MapData.h include/visu_models/PartEmitterAnim.h \
 include/visu_models/visu_define.h include/visu_models/Engine.h \
 include/visu_models/MySceneNode.h include/visu_models/VisuComm.h
	@echo $(CYAN)"    Creating obj/visu_MapData_setget.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MapData_setget.o -Wall \
-c $(SRCDIR)visu_src/models/MapData_setget.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MySceneNode.o: src/visu_src/models/MySceneNode.cpp \
 include/visu_models/MySceneNode.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MapData.h include/visu_models/PartEmitterAnim.h \
 include/visu_models/visu_define.h include/visu_models/Engine.h \
 include/visu_models/MySceneNode.h include/visu_models/VisuComm.h
	@echo $(CYAN)"    Creating obj/visu_MySceneNode.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MySceneNode.o -Wall \
-c $(SRCDIR)visu_src/models/MySceneNode.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_MySceneNode_setget.o: src/visu_src/models/MySceneNode_setget.cpp \
 include/visu_models/MySceneNode.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/MapData.h include/visu_models/PartEmitterAnim.h \
 include/visu_models/visu_define.h include/visu_models/Engine.h \
 include/visu_models/MySceneNode.h include/visu_models/VisuComm.h
	@echo $(CYAN)"    Creating obj/visu_MySceneNode_setget.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_MySceneNode_setget.o -Wall \
-c $(SRCDIR)visu_src/models/MySceneNode_setget.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_PartEmitterAnim.o: src/visu_src/models/PartEmitterAnim.cpp \
 include/visu_models/PartEmitterAnim.h irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/visu_define.h
	@echo $(CYAN)"    Creating obj/visu_PartEmitterAnim.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_PartEmitterAnim.o -Wall \
-c $(SRCDIR)visu_src/models/PartEmitterAnim.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_VisuComm.o: src/visu_src/models/VisuComm.cpp irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/mystring.h include/visu_models/VisuComm.h \
 include/visu_models/MapData.h include/visu_models/PartEmitterAnim.h \
 include/visu_models/visu_define.h include/visu_models/Engine.h \
 include/visu_models/MySceneNode.h include/visu_models/VisuComm.h
	@echo $(CYAN)"    Creating obj/visu_VisuComm.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_VisuComm.o -Wall \
-c $(SRCDIR)visu_src/models/VisuComm.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/cm_find_ret.o: src/common_cpp_src/find_ret.cpp
	@echo $(CYAN)"    Creating obj/cm_find_ret.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cm_find_ret.o -Wall \
-c $(SRCDIR)common_cpp_src/find_ret.cpp $(CFLAGS)

obj/cm_ft_sendall.o: src/common_cpp_src/ft_sendall.cpp libft/include/colors.h
	@echo $(CYAN)"    Creating obj/cm_ft_sendall.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cm_ft_sendall.o -Wall \
-c $(SRCDIR)common_cpp_src/ft_sendall.cpp $(CFLAGS)

obj/cm_mystring.o: src/common_cpp_src/mystring.cpp include/mystring.h
	@echo $(CYAN)"    Creating obj/cm_mystring.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cm_mystring.o -Wall \
-c $(SRCDIR)common_cpp_src/mystring.cpp $(CFLAGS)

obj/cm_new_connection.o: src/common_cpp_src/new_connection.cpp include/common.h
	@echo $(CYAN)"    Creating obj/cm_new_connection.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cm_new_connection.o -Wall \
-c $(SRCDIR)common_cpp_src/new_connection.cpp $(CFLAGS)

obj/cm_read_buf.o: src/common_cpp_src/read_buf.cpp include/common.h
	@echo $(CYAN)"    Creating obj/cm_read_buf.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cm_read_buf.o -Wall \
-c $(SRCDIR)common_cpp_src/read_buf.cpp $(CFLAGS)

