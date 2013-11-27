#include <Application.h>
#include "message_labels.h"
#include "View1.h"



View1::View1()
 : BView(BRect(0, 0, 613, 448), "View", B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{

	tabview1 = new BTabView(BRect(2, 3, 432, 129), "View", B_WIDTH_AS_USUAL, B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_FRAME_EVENTS | B_NAVIGABLE);
	view2 = new View2();
	view3 = new View3();
	view4 = new View4();
	view5 = new View5();
	box1 = new Box1();
	box2 = new Box2();
	stringview4 = new StringView4();
	box3 = new Box3();
	SetViewColor((rgb_color) {216,216,216,255});

}

View1::~View1(void)
{
	
}

void
View1::AttachedToWindow(void)
{

	AddChild(tabview1);
	tabview1->AddTab(view2, new BTab());
	tabview1->AddTab(view3, new BTab());
	tabview1->AddTab(view4, new BTab());
	tabview1->AddTab(view5, new BTab());
	AddChild(box1);
	AddChild(box2);
	AddChild(stringview4);
	AddChild(box3);
	SetViewColor((rgb_color) {216,216,216,255});

}

void
View1::AllAttached(void)
{

	tabview1->Select(0);

}

