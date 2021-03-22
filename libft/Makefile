# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 15:46:26 by agiraude          #+#    #+#              #
#    Updated: 2021/02/16 16:00:17 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FOLDER	=	srcs/

SRCS_FILES	=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_getindex.c \
				ft_countchar.c \
				ft_trim.c \
				ft_ltrim.c \
				ft_rtrim.c \
				ft_split.c \
				ft_nsplit.c \
				ft_strchr.c \
				ft_strpop.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_revstr.c \
				ft_putstr.c \
				ft_lstpop_front.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_lstpop_back.c \
				ft_lstpop_srch.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_lstswap.c \
				ft_itoa_base.c \
				ft_utoa.c \
				ft_ctostr.c

SRCS		=	$(addprefix $(SRCS_FOLDER), $(SRCS_FILES))

INC			=	-I includes/

OBJS		= 	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

NAME		=	libft.a

.c.o:
				$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
