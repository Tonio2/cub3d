NAME	=	cub3d

SRCS	=	main.c \
			config.c \
			config_line.c \
			map_line.c \
			error.c \
			get_next_line.c \
			utils.c \

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
