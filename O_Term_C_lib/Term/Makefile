##
## YNOV INFO PROJECT, 2021
## Recoded shell from C langage
## File description:
## visual studio code
##

NAME	= My_Oterm

CC	= gcc -g

RM	= rm -f

SRCS	=	./src/get_next_line.c		\
		./src/minishell.c		\
		./src/str_to_word_array.c	\
		./src/utils.c			\
		./src/str_concat.c		\
		./src/access_ft.c 		\
		./src/path_tricks.c		\
		./src/env_list_generation.c	\
		./src/linked_list_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./Headers/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
