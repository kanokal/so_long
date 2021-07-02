# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 14:51:11 by jpyo              #+#    #+#              #
#    Updated: 2021/07/02 15:03:51 by jpyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	gcc
CFLAGS			=	#-Wall -Wextra -Werror

HEADER_DIR		=	./includes/

FILES			=	main so_long sl_parse sl_init player \
					utils/sl_utils \
					hook/sl_hook hook/sl_press_key hook/sl_release_key hook/sl_press_key2 \
					render/sl_render render/sl_background render/sl_move render/sl_move_count
SRCS_DIR		=	./srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_OBJS		=	$(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

FT_LIB_DIR		=	./libft/
FT_LIB			=	libft.a

MMS_DIR			=	./minilibx_mms_20200219/
MMS_LIB			=	libmlx.dylib

OPENGL_DIR		=	./minilibx_opengl_20191021/
OPENGL_LIB		=	libmlx.a

all : $(NAME)

run : $(NAME)
	./so_long map/sample2.ber

$(NAME) : $(FT_LIB) $(MMS_LIB) $(OPENGL_LIB) $(SRCS_OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(MMS_LIB) $(OPENGL_LIB) $(FT_LIB) $(SRCS_OBJS)

$(FT_LIB) :
	$(MAKE) -C $(FT_LIB_DIR)
	mv -f $(FT_LIB_DIR)$(FT_LIB) $(FT_LIB)

$(MMS_LIB) :
	$(MAKE) -C $(MMS_DIR)
	mv -f $(MMS_DIR)$(MMS_LIB) $(MMS_LIB)

$(OPENGL_LIB) :
	$(MAKE) -C $(OPENGL_DIR)
	mv -f $(OPENGL_DIR)$(OPENGL_LIB) $(OPENGL_LIB)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

bonus : $(NAME)

clean :
	rm -rf $(SRCS_OBJS)
	$(MAKE) -C $(FT_LIB_DIR) clean
	$(MAKE) -C $(MMS_DIR) clean
	$(MAKE) -C $(OPENGL_DIR) clean

fclean : clean
	rm -rf $(NAME) $(FT_LIB) $(MMS_LIB) $(OPENGL_LIB)

re : fclean all
