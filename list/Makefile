NAME = liblist.a
SRC = new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_node_at.c remove_last.c count_s_nodes.c empty_list.c node_at.c elem_at.c traverse_char.c traverse_int.c traverse_string.c debug_int.c debug_char.c debug_string.c print_int.c print_char.c print_string.c
OBJ = $(SRC:.c=.o)
TESTSRC= ../../test/testlist.c
TESTOBJ= $(TESTSRC:.c=.o)
RM = rm -f
INCLPATH= ../../include
LIBPATH= ../../lib
CFLAGS += -I$(INCLPATH) -Werror -Wall --pedantic -std=c99

all: $(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.c~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) Makefile~
fclean: clean
	-(RM) $(LIBPATH)/$(NAME)

re: fclean all

test: $(TESTOBJ)
	cc -L $(LIBPATH) $(TESTOBJ) -llist -lmy -o mylisttest
	mv mylisttest ../../test/
	../../test/mylisttest

