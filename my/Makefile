#makefile

NAME = libmy.a
SRC = my_alpha.c my_atoi.c my_char.c my_digits.c my_int.c my_num_base.c my_revstr.c my_str.c my_strcat.c my_strcmp.c my_strconcat.c my_strcpy.c my_strdup.c my_strfind.c my_strindex.c my_strlen.c my_strncmp.c my_strconcat.c my_strncpy.c my_strrfind.c my_strrindex.c my_vect2str.c
OBJ = $(SRC:.c=.o)
TESTSRC= ../../test/testmy.c
TESTOBJ= $(TESTSRC:.c=.o)
RM = rm -f
INCLPATH= ../../include
LIBPATH= ../../lib
CFLAGS += -I$(INCLPATH) -Wall -Werror --pedantic -std=c99

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
	cc -L $(LIBPATH) $(TESTOBJ) -lmy -o vtest
	mv vtest ../../test
	../../test/vtest



