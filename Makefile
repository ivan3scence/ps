# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdonny <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 11:44:18 by sdonny            #+#    #+#              #
#    Updated: 2022/04/30 19:28:26 by sdonny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMECHECK = checker

LIST1	= ft_BigSort.c ft_check.c ft_checkSorted.c ft_clean.c ft_init.c ft_MaxMinMed.c ft_Rotate.c ft_RRotate.c \
			ft_SearchScore.c ft_sorted.c ft_SwapPush.c ft_units.c push_swap.c ft_free.c ft_SortScore.c

LIST2	= ft_BigSort.c ft_check.c ft_checkSorted.c ft_clean.c ft_init.c ft_MaxMinMed.c ft_Rotate.c ft_RRotate.c \
			ft_SearchScore.c ft_sorted.c ft_SwapPush.c ft_units.c ft_free.c ft_checker.c ft_SortScore.c ft_stack_null.c\
			underscore1.c underscore2.c

OBJ1		= $(addprefix ${BUILDIR}, $(patsubst %.c,%.o,$(LIST1)))

OBJ2		= $(addprefix ${BUILDIR}, $(patsubst %.c,%.o,$(LIST2)))

CC = cc

FLAGS = -Wall -Werror -Wextra

LIBFT_INCL = ./libft/

LIBFT_NAME = libft.a

HDR_P_S = push_swap.h

BUILDIR = obj/

LIBFT = $(addprefix ${LIBFT_INCL}, ${LIBFT_NAME})

all: ${BUILDIR} ${LIBFT} ${NAME} ${NAMECHECK}

${LIBFT}:
	${MAKE} -C ${LIBFT_INCL}

${BUILDIR}%.o : %.c $(HDR_P_S) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ1)
	${CC} ${FLAGS} -o ${NAME} ${OBJ1} -L ${LIBFT_INCL} -lft -o $@

$(NAMECHECK) : $(OBJ2)
	${CC} ${FLAGS} -o ${NAME} ${OBJ2} -L ${LIBFT_INCL} -lft -o $@

${BUILDIR}:
	mkdir $@

clean:
	rm -rf ${BUILDIR}
	${MAKE} clean -C ${LIBFT_INCL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAMECHECK}
	${MAKE} fclean -C ${LIBFT_INCL}

re: fclean all

.PHONNY : all clean fclean re
