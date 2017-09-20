
#include "myselect.h"

/*pre: none
*post: moves the cursor up one element
*	moves the cursor to the last element if it is at the first
*/

void moveup()
{
	refreshout(gl_env.pos);
	if(--gl_env.pos < 0)
		gl_env.pos = gl_env.nbelems - 1;
	refreshin();
}
