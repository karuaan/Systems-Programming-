NAME = nminishell
SRC = nminishell.c

OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBRARYPATH = ../../lib 
CFLAGS += -I../../include
LDFLAGS += -L$(LIBRARYPATH)
LDLIBS += -lmy

all: $(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.exe
	-$(RM) *.exe.stackdump

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: flcean