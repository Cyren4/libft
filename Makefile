# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 10:38:04 by cramdani          #+#    #+#              #
#    Updated: 2020/05/01 02:09:03 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_memset.c \
			srcs/ft_bzero.c \
			srcs/ft_memcpy.c \
			srcs/ft_memccpy.c \
			srcs/ft_memmove.c \
			srcs/ft_memchr.c \
			srcs/ft_memcmp.c \
			srcs/ft_strlen.c \
			srcs/ft_isalpha.c \
			srcs/ft_isspace.c\
			srcs/ft_isdigit.c \
			srcs/ft_isalnum.c \
			srcs/ft_isascii.c \
			srcs/ft_isprint.c \
			srcs/ft_toupper.c \
			srcs/ft_tolower.c \
			srcs/ft_strchr.c \
			srcs/ft_strrchr.c \
			srcs/ft_strncmp.c \
			srcs/ft_strcmp.c \
			srcs/ft_strlcat.c \
			srcs/ft_strlcpy.c \
			srcs/ft_strnstr.c\
			srcs/ft_atoi.c \
			srcs/ft_calloc.c \
			srcs/ft_strdup.c \
			srcs/ft_substr.c \
			srcs/ft_strjoin.c \
			srcs/ft_strtrim.c \
			srcs/ft_split.c \
 			srcs/ft_itoa.c \
			srcs/ft_strmapi.c \
			srcs/ft_putchar_fd.c \
			srcs/ft_putstr_fd.c \
			srcs/ft_putendl_fd.c \
			srcs/ft_putnbr_fd.c \
			srcs/puissance.c\
			srcs/ft_putnbr_base.c\
			srcs/ft_atoi_base.c\
			srcs/ft_convert_base.c\
			srcs/ft_realloc.c\
			srcs/ft_lstadd_back_bonus.c\
			srcs/ft_lstclear_bonus.c\
			srcs/ft_lstdelone_bonus.c\
			srcs/ft_lstiter_bonus.c\
			srcs/ft_lstlast_bonus.c\
			srcs/ft_lstnew_bonus.c\
			srcs/ft_lstsize_bonus.c\

BONUS	=
OBJS	= ${SRCS:.c=.o}

BOOBS	= ${BONUS:.c=.o}

NAME	=	libft.a

HEADER	=	libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror 


all:	${NAME}

.o :	.c
		${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

${NAME}: 	 ${OBJS}
			ar rc ${NAME} ${OBJS}

bonus: 	 ${OBJS} ${BOOBS}
			ar rc ${NAME} ${OBJS} ${BOOBS}

clean:
		${RM} ${OBJS} ${BOOBS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re 
