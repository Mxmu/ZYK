#include"VSM.h"
int main()
{
	SuperMarket suMar;
	srand(time(0));
	suMar.start();
	suMar.WaitForCompletion();
	return 0;
}
