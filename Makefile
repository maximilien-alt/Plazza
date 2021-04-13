##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	 plazza	

SRC	=	$(wildcard src/*.cpp)	\

SRC_FLAGS	=	-W -Wall -Wextra -lpthread -g3

OBJ_SRC	=	$(SRC:.cpp=.o)

all: $(OBJ_SRC)
	g++ -o $(NAME) $(SRC) $(SRC_FLAGS)

clean	:
	rm -rf $(OBJ_SRC)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
