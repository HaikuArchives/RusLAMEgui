#include <Application.h>
#include "message_labels.h"
#include "Box1.h"


Box1::Box1()
 : BBox(BRect(438, 3, 610, 130), "box", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW | B_FRAME_EVENTS, B_FANCY_BORDER)
{
	check4 = new BCheckBox(BRect(7, 13, 165, 31), "checkbox", "disable all filters", new BMessage(DISABLEFILTER_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	check1 = new BCheckBox(BRect(7, 35, 165, 53), "checkbox", "HiPass", new BMessage(HIPASS_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	slider5 = new BSlider(BRect(7, 55, 165, 73), "slider", NULL, new BMessage(HIPASS_FREQ), 50, 2300, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT);
	slider5->SetBarThickness(4);
	slider5->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider5->SetHashMarkCount(5);
	slider5->SetKeyIncrementValue(8);
	slider5->SetValue(1000);
	check2 = new BCheckBox(BRect(7, 81, 165, 99), "checkbox", "LoPass", new BMessage(LOPASS_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	slider6 = new Slider6();
	SetLabel("filter settings");
}

Box1::~Box1(void)
{
}

void
Box1::AttachedToWindow(void)
{
	AddChild(check4);
	AddChild(check1);
	AddChild(slider5);
	AddChild(check2);
	AddChild(slider6);
	SetLabel("filter settings");
}

void
Box1::AllAttached(void)
{

	slider5->SetBarThickness(4);
	slider5->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider5->SetHashMarkCount(5);
	slider5->SetKeyIncrementValue(8);
	slider5->SetValue(1000);
}

