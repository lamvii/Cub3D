# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaamaou <rnaamaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:41:33 by ael-idri          #+#    #+#              #
#    Updated: 2022/11/01 18:50:29 by rnaamaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	=	cub3D
NAME_BONUS	=	cub3D_bonus
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
SRCS	 	=	Mandatory/GNL/get_next_line.c	Mandatory/GNL/get_next_line_utils.c \
				Mandatory/parsing/utils.c Mandatory/parsing/utils1.c Mandatory/parsing/utils2.c \
				Mandatory/parsing/map_checker.c Mandatory/parsing/check_assets.c  \
				Mandatory/parsing/read_map.c Mandatory/parsing/check_playermap.c \
				Mandatory/intersection_vert.c Mandatory/intersection_hori.c \
				Mandatory/mini_map.c Mandatory/moving_player.c Mandatory/map.c\
				Mandatory/setup_cub.c Mandatory/setup_texture.c \
				Mandatory/mlx/_mlx.c Mandatory/mlx/mlx1.c \
				Mandatory/rendering_texture.c Mandatory/extra.c\
				Mandatory/cub3d.c\

SRCS_BONUS	= 	bonus/GNL/get_next_line.c	bonus/GNL/get_next_line_utils.c \
				bonus/parsing/utils.c bonus/parsing/utils1.c bonus/parsing/utils2.c \
				bonus/parsing/map_checker.c bonus/parsing/check_assets.c  \
				bonus/parsing/read_map.c bonus/parsing/check_playermap.c \
				bonus/intersection_vert.c bonus/intersection_hori.c \
				bonus/mini_map.c bonus/moving_player.c bonus/map.c\
				bonus/setup_cub.c bonus/setup_texture.c \
				bonus/mlx/_mlx.c bonus/mlx/mlx1.c \
				bonus/rendering_texture.c bonus/extra.c\
				bonus/cub3d.c\

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

HEADER		= Mandatory/cub3d.h  Mandatory/GNL/get_next_line.h  Mandatory/libft/libft.h

HEADER_BONUS	= bonus/cub3d.h  bonus/GNL/get_next_line.h  bonus/libft/libft.h
PATH_LIBFT 	=	Mandatory/libft/
LIBFT		=	Mandatory/libft/libft.a
PATH_LIBFT_BNS 	=	bonus/libft/
LIBFT_BNS		=	bonus/libft/libft.a


all			:	$(NAME)

bonus		:	$(NAME_BONUS)

$(LIBFT) :
				@make -C $(PATH_LIBFT)
$(LIBFT_BNS) :
				@make -C $(PATH_LIBFT_BNS)


$(NAME)		:	$(OBJS) $(HEADER) $(LIBFT)
				${CC} ${CFLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(NAME_BONUS)		:	$(OBJS_BONUS) $(HEADER_BONUS) $(LIBFT_BNS)
				${CC} ${CFLAGS} ${SRCS_BONUS} -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(LIBFT_BNS)

%.o			:	%.c  $(HEADER_BONUS)
				$(CC) ${CFLAGS}  -c $< -o $@
    
clean		:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BONUS)
				@make clean -C $(PATH_LIBFT)
				@make clean -C $(PATH_LIBFT_BNS)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)
				@make fclean -C $(PATH_LIBFT)			
				@make fclean -C $(PATH_LIBFT_BNS)			

re			:	fclean all

re_bonus	:	fclean bonus
.PHONY		:	all clean fclean re bonus