
#include "myselect.h"

/*pre: none
*post: gets the window size and updates the global stuct
*/

char get_win_size()
{
	return ioctl(0, TIOCGWINSZ, &gl_env.win);
}
