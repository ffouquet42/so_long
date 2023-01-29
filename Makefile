SRCS		=	srcs/so_long.c									\
				srcs/initialyze.c								\
				srcs/setup.c									\
				srcs/movement.c									\
				srcs/print.c									\
				srcs/tools.c									\
				srcs/get_next_line.c							\
				srcs/action.c									\
				srcs/check_error.c								\
				srcs/parsing.c									\

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