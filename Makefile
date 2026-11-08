NAME=		libftprintf.a
LFTNAME=	libft.a
TEST=		libftprintf.test

CXX=		g++
CXXFLAGS=	-std=c++17 -Wall -Wextra -Werror -I ./include/
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -I ./include/

ifneq ($(wildcard $(HOME)/googletest),)
	GTEST_LIBS=	$(HOME)/googletest/googletest
	CXXFLAGS+=	-isystem $(GTEST_DIR)/include
	GTEST_LIBS=	$(GTEST_DIR)/libgtest/.a $(GTEST_DIR)/libgtest_main.a -lpthread
else
	GTEST_LIBS=	-lgtest -lgtest_main -lpthread
endif

LFTFILES=	./src/libft/*.c

FILES=		

TFILES=		$(FILES:./src/%.c=./test/%.cpp)

LFTOBJ=		$(LFTFILES:.c=.o)
OBJ=		$(FILES:.c=.o)
TOBJS=		$(TFILES:.cpp=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -o $@

%.o:		%.cpp
			$(CXX) $(CXXFLAGS) -c $^ -o $@

$(LFTNAME):	$(LFTOBJ)
			$(CC) $(CFLAGS) -o $(LFTNAME) $(LFTOBJ)

$(NAME):	$(LFTNAME) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LFTNAME) -o $(NAME)

$(TEST):	$(OBJ) $(LFTOBJ) $(TOBJS)
			$(CXX) $(CXXFLAGS) $(GTEST_LIBS) $^ -o $(TEST) 

clean:
			rm -rf $(OBJ)
			rm -rf $(LFTOBJ)
			rm -rf $(TOBJS)

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(LFTNAME)
			rm -rf $(TEST)

re:			fclean all

.PHONY:		all clean fclean re
