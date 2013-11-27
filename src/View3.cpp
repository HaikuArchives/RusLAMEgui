#include <Application.h>
#include "message_labels.h"
#include "View3.h"


View3::View3()
 : BView(BRect(10, 10, 425, 100), "VBR", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW)
{
	slider2 = new BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(VBR_SLIDER_MIN), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider2->SetBarThickness(4);
	slider2->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider2->SetHashMarkCount(14);
	AddChild(slider2);

	slider4 = new BSlider(BRect(56, 37, 414, 55), "slider", NULL, new BMessage(VBR_SLIDER_MAX), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT);
	slider4->SetBarThickness(4);
	slider4->SetHashMarks(B_HASH_MARKS_TOP);
	slider4->SetHashMarkCount(14);
	AddChild(slider4);

	slider8 = new BSlider(BRect(56, 72, 414, 90), "slider", NULL, new BMessage(QUAL_SLIDER), 0, 9, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider8->SetBarThickness(4);
	slider8->SetHashMarks(B_HASH_MARKS_TOP);
	slider8->SetHashMarkCount(10);
	AddChild(slider8);

	font5 = new BFont(be_plain_font);
	font5->SetSize(9);
	font5->SetSpacing(B_FIXED_SPACING);

	stringview5 = new BStringView(BRect(58, 23, 415, 34), "StringView", "32        40        48         56        64        80        96       112       128      160      192      224      256     320", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview5->SetFont(font5);
	AddChild(stringview5);


	stringview7 = new BStringView(BRect(0, 4, 55, 17), "StringView", "min. rate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview7->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview7);

	stringview14 = new BStringView(BRect(0, 37, 60, 52), "StringView", "max. rate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview14->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview14);

	font6 = new BFont(be_plain_font);
	font6->SetSize(9);
	font6->SetSpacing(B_FIXED_SPACING);

	stringview8 = new BStringView(BRect(58, 61, 414, 72), "StringView", " 9                 8                7                 6                5                4                 3                 2                1                 0", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview8->SetFont(font6);
	AddChild(stringview8);

	stringview9 = new BStringView(BRect(0, 73, 49, 87), "StringView", "quality", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview9->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview9);

	SetViewColor((rgb_color) {216,216,216,255});
}

View3::~View3(void)
{
	
}
