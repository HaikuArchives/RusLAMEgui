#include <Application.h>
#include "message_labels.h"
#include "View2.h"


View2::View2()
 : BView(BRect(10, 10, 425, 80), "CBR", B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{
	slider1 = new BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(CBR_SLIDER), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider1->SetBarThickness(4);
	slider1->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider1->SetHashMarkCount(14);
	AddChild(slider1);
	stringview10 = new BStringView(BRect(58, 23, 415, 34), "StringView", "32        40        48         56        64        80        96       112       128      160      192      224      256     320", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	AddChild(stringview10);
	font7 = new BFont(be_plain_font);
	font7->SetSize(9);
	font7->SetSpacing(B_FIXED_SPACING);
	stringview10->SetFont(font7);
	stringview11 = new BStringView(BRect(1, 4, 51, 17), "StringView", "bitrate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview11->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview11);
	SetViewColor((rgb_color) {216,216,216,255});
}

View2::~View2(void)
{
	}
