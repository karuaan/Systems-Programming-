
#include "myselect.h"

/*pre: none
*post: selects the current element
*/

void doselect()
{
	if(!gl_env.elements[gl_env.pos].mode)
	{
		gl_env.elements[gl_env.pos].mode = 1;
		movedown();
	}
	else
		gl_env.elements[gl_env.pos].mode = 0;
	refreshin();
}
