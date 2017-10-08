NAME	=	mongo

SRC_DIR	=	../

SRC	=	mongomain.cpp \
		$(SRC_DIR)mongodb.cpp \

OBJ	= 	$(SRC:.cpp=.o)

CXX	=	g++

CXXFLAGS +=	-Iincludes -W -Wall -Wextra -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi -L/usr/local/lib -lmongocxx -lbsoncxx -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
