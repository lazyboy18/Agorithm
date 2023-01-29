#include"Cirqueobject.h"
int main()
{
	Dancer man("Gentleman");
	Dancer woman("Lady");
	man.Dancer_Loading();
	woman.Dancer_Loading();
	man.Dancer_Match(woman);
	man.Dancer_Loading();
	man.Dancer_Match(woman);
	return 0;
}
