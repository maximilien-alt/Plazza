##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	 plazza	

CC	=	g++

SRC	=	$(wildcard src/*.cpp)	\
		$(wildcard src/Kitchens/*.cpp)	\
		$(wildcard src/Pizzas/*.cpp)	\
		$(wildcard src/Thread/*.cpp)	\
		$(wildcard src/Server/*.cpp)

CPPFLAGS	=	-W -Wall -Wextra -Wno-class-memaccess -std=c++17

LDFLAGS	=	-lpthread

OBJ_SRC	=	$(SRC:.cpp=.o)

all: $(OBJ_SRC)
	$(CC) -o $(NAME) $(OBJ_SRC) $(LDFLAGS)

clean	:
	rm -f $(OBJ_SRC)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
