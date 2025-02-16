NAME = push_swapA

CC = cc
CFLAGS =  -Wall -Werror -Wextra

SRC = add_stack.c lesregles.c libft.c main.c split.c\
	algo_cinquieme.c algo_quatre.c algo_troi.c algo.c\
	chek_number.c fonction.c parsine.c
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re


















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
