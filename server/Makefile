NAME	=	server

SRC_DIR	=	sources/

SRC	=	$(SRC_DIR)main.cpp \
		$(SRC_DIR)Server.cpp \
		$(SRC_DIR)tcpClient.cpp \

OBJ	= 	$(SRC:.cpp=.o)

CXX	=	g++

CXXFLAGS +=	-Iincludes -W -Wall -Wextra -lboost_system -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -lssl -lcrypto -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
