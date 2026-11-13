NAME        = libftprintf.a
LFTNAME     = libft.a
TEST        = libftprintf.test

CXX         = g++
CXXFLAGS    = -std=c++17 -Wall -Wextra -Werror -I ./include/
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I ./include/

GTEST_DIR ?= $(HOME)/googletest

ifneq ($(wildcard $(GTEST_DIR)),)
    CXXFLAGS    += -isystem $(GTEST_DIR)/include
    GTEST_LIBS  = -L$(GTEST_DIR)/build/lib -lgtest -lgtest_main -lpthread
else
    GTEST_LIBS  = -lgtest -lgtest_main -lpthread
endif

LFTFILES    = $(wildcard ./src/libft/*.c)
LFTOBJ      = $(LFTFILES:.c=.o)

FILES       = ./src/writers/ft_ltoh.c\
			  ./src/writers/ft_ultoa.c\
			  ./src/parcer/newzone.c\

OBJ         = $(FILES:.c=.o)

TFILES      = $(FILES:./src/%.c=./test/%.cpp)
TOBJS       = $(TFILES:.cpp=.o)

WRAPS       = -Wl,--wrap=malloc -Wl,--wrap=free
WRAPS_FILES = ./test/wraps/free.cpp ./test/wraps/malloc.cpp

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LFTNAME): $(LFTOBJ)
	ar rcs $(LFTNAME) $(LFTOBJ)

$(NAME): $(LFTNAME) $(OBJ)
	ar rcs $(NAME) $(LFTOBJ) $(OBJ)

$(TEST): $(NAME) $(TOBJS) $(WRAPS_FILES)
	$(CXX) $(CXXFLAGS) $(WRAPS) $(TOBJS) $(WRAPS_FILES) $(NAME) $(GTEST_LIBS) -o $(TEST)

clean:
	rm -rf $(OBJ)
	rm -rf $(LFTOBJ)
	rm -rf $(TOBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LFTNAME)
	rm -rf $(TEST)

re: fclean all

.PHONY: all clean fclean re test
