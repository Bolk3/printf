NAME=		libftprintf.a
LFTNAME=	libft.a

CC=			cc
CFLAGS=		-Wall -Wextra -Werror

LFTFILES=	./libft/*.c

FILES=		

LFTOBJ=		$(LFTFILES:.c=.o)
OBJ=		$(FILES:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(LFTNAME):	$(LFTOBJ)
			$(CC) $(CFLAGS) -o $(LFTNAME) $(LFTOBJ)

$(NAME):	$(LFTNAME) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LFTNAME) -o $(NAME)

all:		$(NAME)

clean:
			rm -rf 
