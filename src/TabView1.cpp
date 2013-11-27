#include <Application.h>
#include "message_labels.h"
#include "TabView1.h"


TabView1::TabView1()
 : BTabView(BRect(2, 5, 432, 188), "View", B_WIDTH_AS_USUAL, B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_FRAME_EVENTS | B_NAVIGABLE)
{

	view2 = new View2();
	view3 = new View3();
	view4 = new View4();
	view5 = new View5();
	AddTab(view2, new BTab());
	AddTab(view3, new BTab());
	AddTab(view4, new BTab());
	AddTab(view5, new BTab());
}

TabView1::~TabView1(void)
{
}

