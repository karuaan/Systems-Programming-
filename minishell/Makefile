NAME=minishell
MINISHELL=minishell.c
MINISHELLOBJ=$(MINISHELL:.c=.o)
RM=rm -f
LIBPATH=../../lib
INCLPATH = ../../include 
CFLAGS += -I$(INCLPATH) -Wall -Werror --pedantic -std=c99

MINISHELL:$(MINISHELLOBJ)
	cc -L $(LIBPATH) $(MINISHELLOBJ) -lmy -o client

all:
	

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


debug: fclean $(MINISHELLOBJ)
	cc -L$(LIBPATH) $(MINISHELLOBJ) -lmy -g -o client