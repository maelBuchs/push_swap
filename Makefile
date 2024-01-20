NAME =	push_swap

CC = gcc
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
HEAD = push_swap.h
SRCS = 	main.c\
		srcs/instructions/push.c\
		srcs/instructions/reverse.c\
		srcs/instructions/rotate.c\
		srcs/instructions/swap.c\
		srcs/radix.c\
		# srcs/instructions/


OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))

all:			$(NAME)
				@clear
				@echo "Compilation terminée";

$(NAME):		$(OBJS)
				make --no-print-directory -C Libft/
				@$(CC) -o $(NAME)  $(HEAD) $(OBJS) $(CFLAGS) $(MLX) Libft/libft.a
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:			
				make clean --no-print-directory -C  Libft/
				@$(RM) $(OBJS)
				@clear
				@echo "Clean OK";


fclean: 		clean
				@clear
				@echo "Full Clean OK ";

re: 			fclean all

.PHONY:			all clean fclean re