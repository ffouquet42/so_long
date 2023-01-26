SRCS		=	srcs/game/so_long.c									\
				srcs/game/setup.c									\
				srcs/utils/print.c									\
				srcs/utils/tools.c									\
				srcs/map/initialyze.c								\
				srcs/get_next_line/get_next_line.c					\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

#CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./srcs/includes
CFLAGS		= 	-g3 -I./srcs/includes

NAME		= 	so_long
	
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus