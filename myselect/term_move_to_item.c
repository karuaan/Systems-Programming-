
#include "myselect.h"

/*pre: takes in an int pos
*post: moves the selection to the element at index pos
*/

void term_move_to_item(int pos)
{
	int x;
	int y;

	x = gl_env.elements[pos].x;
	y = gl_env.elements[pos].y;
	tputs(tgoto(gl_env.move, x, y), 1, my_termprint);
}
