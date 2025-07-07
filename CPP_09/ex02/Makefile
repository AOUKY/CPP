STD = -std=c++98
CP = c++
FLAGS = -Wall -Wextra -Werror $(STD)
FILES = main.cpp PmergeMe.cpp
NAME = PmergeMe
OBJ = $(FILES:.cpp=.o)

all: $(NAME)


$(NAME) : $(OBJ)
	$(CP) $(FLAGS)  $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all