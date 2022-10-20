# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 19:08:56 by ael-idri          #+#    #+#              #
#    Updated: 2022/10/19 15:33:09 by ael-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isspace.c

OBJS		= 	$(SRCS:.c=.o)

BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS	= 	$(BONUS:.c=.o)

CC			=	cc

CFLAGS    	=	-Wall -Werror -Wextra 

AR			=	ar crs

RM			=	rm -rf

NAME		=	libft.a

HEADER		=	libft.h 

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			$(AR) $(NAME) $(BONUS_OBJS)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			clean fclean all

.PHONY:		all clean fclean re
