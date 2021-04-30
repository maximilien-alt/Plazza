##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	 plazza	

SRC	=	$(wildcard src/*.cpp)	\
		$(wildcard src/Kitchens/*.cpp)	\
		$(wildcard src/Pizzas/*.cpp)	\
		$(wildcard src/Thread/*.cpp)	\
		$(wildcard src/Server/*.cpp)

SRC_FLAGS	=	-W -Wall -Wextra -lpthread -g3 -Wno-class-memaccess

OBJ_SRC	=	$(SRC:.cpp=.o)

all: $(OBJ_SRC)
	g++ -o $(NAME) $(SRC) $(SRC_FLAGS)

clean	:
	rm -rf $(OBJ_SRC)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
