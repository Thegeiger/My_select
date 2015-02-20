##
## Makefile for make in /home/geiger_a/rendu/MY_LS
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sun Nov 23 15:17:22 2014 anthony geiger
## Last update Thu Jan  8 11:55:03 2015 anthony geiger
##

CC	= gcc

RM      = rm -f

NAME    = my_select

CFLAGS  += -Wextra -Wall
CFLAGS  += -pedantic
CFLAGS  += -I.

LDFLAGS = -lncurses

SRCS    = my_putnbr.c \
	my_move.c \
	my_goto.c \
	tab_fonction.c \
	my_clean.c \
	my_important_fonction.c \
	aff_fonction.c \
	my_putsterr.c \
	my_strlen.c \
	my_get_size.c \
	my_case_suppr.c \
	my_case_space.c \
	main.c \
	my_select.c \
        my_putstr.c \
	find_terme.c \
	my_strncmp.c \
	my_strnsdup.c \
	my_strnscpy.c \
        my_putchar.c

SRCS	:= $(addprefix src/, $(SRCS))

OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
