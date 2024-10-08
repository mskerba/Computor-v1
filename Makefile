
NAME =computor_v1

SRC=main.cpp

OBJ= $(SRC)

CXXFLAGS=-Wall -Wextra -Werror -fsanitize=address -g

CXX=c++

GA= git add .

GC= git commit -m "$(ARGS)"

GP= git push

all : $(NAME)
$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(obj)

fclean : clean
	rm -rf $(NAME)

push: fclean
	@ $(GA) && $(GC) && $(GP) 

re : fclean all 
