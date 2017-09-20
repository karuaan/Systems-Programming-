
#include "myselect.h"

/*pre: takes in an int pos
*post: refreshes the item at pos
*/

void refreshout(int pos)
{
	term_move_to_item(pos);
	if(gl_env.elements[pos].mode)
		term_standout();
	my_str(gl_env.elements[pos].elem);
	term_standend();
}
