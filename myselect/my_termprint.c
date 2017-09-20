

#include "myselect.h"

/*pre: takes in an int n
*post: returns the number of bytes written to the terminal by printing n
*/

int my_termprint(int n)
{
	return write(1, &n, 1);
}
