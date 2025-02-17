NAME = push_swap
BONUS = checker

CC = cc
# CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

PUSH_SRC = ./mandatory/add_stack.c \
 			./mandatory/lesregles.c \
			./mandatory/libft.c \
			./mandatory/main.c \
			./mandatory/split.c \
			./mandatory/algo_cinquieme.c \
			./mandatory/algo_quatre.c \
			./mandatory/algo_troi.c \
			./mandatory/algo.c \
			./mandatory/chek_number.c \
			./mandatory/fonction.c \
			./mandatory/parsine.c 

BONUS_SRC = ./bonus/main.c  \
			./bonus/get_next_line.c \
			./bonus/get_next_line_utils.c\
			./bonus/fonction.c\
			./bonus/split.c \
			./bonus/parsine_bonus.c\
			./bonus/add_stack.c \
			./bonus/les_regles.c
			

PUSH_OBJ = $(PUSH_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

$(NAME): $(PUSH_OBJ)
	$(CC) $(CFLAGS) $(PUSH_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(PUSH_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

















#NAME = push_swap

#CC = cc

#CFLAGS = -Wall -Werror -Wextra

#SRC = add_stack.c lesregles.c libft.c main.c split.c

#OBJ =${SRC:.c=.o}

#ARCHIVING = ar -rcs

#all: ${NAME}

#${NAME}: ${OBJ}
#	${ARCHIVING} ${NAME} ${OBJ}

#clean:
#	rm -rf ${OBJ}

#fclean: clean
#	rm -rf ${NAME}

#re: fclean all

#.SECONDARY: $(OBJ)

#.PHONY:  all clean fclean re
