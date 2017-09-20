NAME=pipes
SRC=pipes.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../../lib
INCLPATH = ../../include 
CFLAGS += -I$(INCLPATH) -Wall -Werror --pedantic -std=c99

all:$(OBJ)
	cc -L $(LIBPATH) $(OBJ) -lmy -o $(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.c~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) Makefile~

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)


re: fclean all




