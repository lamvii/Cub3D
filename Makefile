# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:41:33 by ael-idri          #+#    #+#              #
#    Updated: 2022/09/27 12:34:17 by ael-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	=	cub3d
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
SRCS	 	=	cub3d.c
OBJS		=	$(SRCS:.c=.o)
HEADER		=	cub3d.h


all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				${CC} ${FLAGS} ${OBJS} -o $(NAME)

%.o			:	%.c $(HEADER)
				$(CC) ${FLAGS} -c $< -o $@
    
clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re