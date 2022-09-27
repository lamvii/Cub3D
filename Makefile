# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:41:33 by ael-idri          #+#    #+#              #
#    Updated: 2022/09/27 14:46:54 by ael-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	=	cub3d
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
SRCS	 	=	GNL/get_next_line.c		\
				GNL/get_next_line_utils.c utils.c map_checker.c cub3d.c 
OBJS		=	$(SRCS:.c=.o)
HEADER		=	cub3d.h ./GNL/get_next_line.h


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