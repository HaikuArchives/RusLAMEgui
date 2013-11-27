#include <Application.h>
#include "Application1.h"

int
main()
{
	new Application1();
	be_app->Run();
	delete be_app;
	return 0;
};
