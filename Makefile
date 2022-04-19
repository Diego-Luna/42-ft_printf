NAME = libftprintf.a

SRCS =	src/ft_printf.c src/ft_check_params.c src/ft_convert.c src/str_1.c src/str_2.c src/strt_to_number.c \
				src/ft_result_di_u.c src/ft_result_s_c.c src/ft_result_x.c

OBJS = ${SRCS:.c=.o}


OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all