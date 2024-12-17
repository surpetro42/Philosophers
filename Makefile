NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

SRC = philosophers.c \
	  creat_print.c \
	  src/ft_atoi.c \
	  src/info_start.c \
	  src/validation.c \
	  src/inspect.c \
	  src/time.c \
	  src/initializations_philo.c \
	  src/start_philo.c \
	  src/take_forks.c \
	  src/utils.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} philosophers.h Makefile
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

%.o:%.c
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re