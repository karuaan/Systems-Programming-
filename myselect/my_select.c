
#include "myselect.h"

/*pre: takes in an int argc and a char *argv
*post: runs the myselect program with argc number of command line arguments
*	defined by argv
*/

int main(int argc, char **argv)
{
	char buf[5];
	int n;

	if(argc < 2)
	{
		my_str("usage: ./myselect files [more files]...\n");
		exit(-1);
	}
	signal(SIGWINCH, show_elems);
	init_terminal();
	setup_elems(argc - 1, &argv[1]);
	show_elems();
	while(1)
	{
		if((n = read(0, buf, 4)) < 0)
		{
			my_str("ERROR: cannot read from keyboard\n");
			getout(0);
		}
		buf[n] = '\0';
		#ifdef DEBUG
			my_int(n);
			my_str("\nkeystroke: ");
			my_str(buf);
			my_str("<\n");
		#endif
		check_char(buf);
	}
	return 0;
}
