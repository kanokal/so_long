# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 14:51:11 by jpyo              #+#    #+#              #
#    Updated: 2021/06/25 17:12:38 by jpyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

HEADER_DIR		=	./includes/

FILES			=	so_long 
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

$(NAME) : $(FT_LIB) $(MMS_LIB) $(OPENGL_LIB) $(SRCS_OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(FT_LIB) $(SRCS_OBJS)

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
