# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:41:33 by ael-idri          #+#    #+#              #
#    Updated: 2022/10/03 19:21:39 by ael-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	=	cub3d
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
SRCS	 	=	GNL/get_next_line.c	GNL/get_next_line_utils.c \
				utils.c utils1.c utils2.c map_checker.c check_assets.c read_map.c cub3d.c \
				check_playermap.c \
				mini_map.c
OBJS		=	$(SRCS:.c=.o)
HEADER		=	cub3d.h ./GNL/get_next_line.h ./libft/libft.h
PATH_LIBFT 	=	libft/
LIBFT		=	libft/libft.a


all			:	$(NAME)

$(LIBFT) :
				@make -C $(PATH_LIBFT)

$(NAME)		:	$(OBJS) $(HEADER) $(LIBFT)
				${CC} ${FLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)



%.o			:	%.c $(HEADER)
				$(CC) ${FLAGS}  -c $< -o $@
    
clean		:
				$(RM) $(OBJS)
				@make clean -C $(PATH_LIBFT)

fclean		:	clean
				$(RM) $(NAME)
				@make fclean -C $(PATH_LIBFT)			

re			:	fclean all

.PHONY		:	all clean fclean re