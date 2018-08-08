##
## Makefile for Makefile in /home/jeremy.elkaim/PSU_2016_42sh
## 
## Made by jeremy elkaim
## Login   <jeremy.elkaim@epitech.net>
## 
## Started on  Thu Apr 13 11:45:30 2017 jeremy elkaim
## Last update Sun May 21 23:28:16 2017 Sridhar Vengadesan
##

NAME    = 	42sh

#CFLAGS +=       -W -Wall -Werror -Wextra

CFLAGS +=       -I./include/

SRC    =	src/write.c		\
	 	src/42sh.c		\
	 	src/42sh2.c		\
	 	src/strcmp.c		\
	 	src/get_next_line.c	\
		src/bin_comand.c	\
		src/command_strcpy.c	\
		src/get_flag.c		\
		src/cd_func.c		\
		src/exit.c		\
		src/cpy_command_line.c	\
		src/my_echo.c

OBJ     =       $(SRC:.c=.o)

TMP	=	$(SRC:.c=.c~)

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) -lncurses

clean:
		rm -rf $(OBJ)
		rm -rf $(TMP)

fclean:         clean
		rm -rf $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
