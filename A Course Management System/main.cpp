#include "lib.h"
#include "do_hoa.h"
int main()
{
	/*resizeConsole(5000, 900);*/
	textcolor(2);
	int x = 40, y = 10;
	list_log_in l; 
	tai_khoan inf;
	khoi_tao(l);
	log_in(l, inf,x,y);
}
 
