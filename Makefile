# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 10:43:09 by agiraude          #+#    #+#              #
#    Updated: 2021/03/22 19:47:08 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	=	libft/

LIBFT		=	libft.a

INC_DIR		=	-I includes/ -I $(LIBFT_DIR)includes/

SRCS_DIR	=	srcs/

SRCS_FILES	=	checker.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				stack.c 

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		=	-Wall -Wextra -g

RM			=	rm -f

NAME		=	test

DEP			=	-lft 

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INC_DIR)

all:			checker

$(LIBFT):
				make -C $(LIBFT_DIR)

checker:		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o checker $(OBJS) -L $(LIBFT_DIR) $(DEP) $(INC_DIR)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) checker
				$(RM) $(LIBFT_DIR)$(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re
