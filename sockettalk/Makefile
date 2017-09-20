NAME=sockettalk
CLISRC=client.c
SERSRC=server.c
CLIOBJ=$(CLISRC:.c=.o)
SEROBJ=$(SERSRC:.c=.o)
RM=rm -f
LIBPATH=../../lib
INCLPATH = ../../include 
CFLAGS += -I$(INCLPATH) -Wall -Werror --pedantic -std=c99

client:$(CLIOBJ)
	cc -L $(LIBPATH) $(CLIOBJ) -lmy -o client

server:$(SEROBJ)
	cc -L$(LIBPATH) $(SEROBJ) -lmy -o server

all:client server
	

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


debug: fclean $(SEROBJ) $(CLIOBJ)
	cc -L$(LIBPATH) $(CLIOBJ) -lmy -g -o client
	cc -L$(LIBPATH) $(SEROBJ) -lmy -g -o server




