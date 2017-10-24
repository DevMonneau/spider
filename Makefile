NAME	=	server

SRC_DIR	=	sources/

SRC	=	$(SRC_DIR)main.cpp \
		$(SRC_DIR)Server.cpp \
		$(SRC_DIR)tcpClient.cpp \
		$(SRC_DIR)Parser.cpp \
		$(SRC_DIR)mongodb.cpp \

OBJ	 = 	$(SRC:.cpp=.o)

CXX	=	g++

CXXFLAGS +=	-Iincludes -W -Wall -Wextra -lboost_system -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -lssl -lcrypto -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi -L/usr/local/lib -lmongocxx -lbsoncxx -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
