NAME = ft_container

CC = c++
CFLAGS = -Wall -Wextra -Werror 
INC = iterator_traits.hpp \
	vector.hpp \
	iterator.hpp \
	utils.hpp \
	reverse_iterator.hpp
SRC = main.cpp 

OBJS = $(SRC:.cpp=.o) 

all : $(NAME)

%.o : %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(INC)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : re clean fclean