
#include "myselect.h"

/*pre: none
*post: moves the cursor down, left, right, or up one element
*	moves the cursor to the first element if already at the last element
*/

void movedown()
{
	refreshout(gl_env.pos);
	gl_env.pos++;
	if(gl_env.pos >= gl_env.nbelems)
		gl_env.pos %= gl_env.nbelems;
	refreshin();
}