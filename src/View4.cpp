#include <Application.h>
#include "message_labels.h"
#include "View4.h"


View4::View4()
 : BView(BRect(10, 10, 425, 101), "ABR", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW)
{
	slider3 = new BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(ABR_SLIDER), 0, 300, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider3->SetBarThickness(4);
	slider3->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider3->SetHashMarkCount(31);
	AddChild(slider3);

	font8 = new BFont(be_plain_font);
	font8->SetSize(9);
	font8->SetSpacing(B_FIXED_SPACING);

	stringview12 = new BStringView(BRect(58, 23, 415, 34), "StringView", "48      64       80      96      112    128    144     160     176    192    208    224    240    256    272    288", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview12->SetFont(font8);
	AddChild(stringview12);

	stringview13 = new BStringView(BRect(1, 3, 51, 17), "StringView", "bitrate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview13->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview13);

	font20 = new BFont(be_plain_font);
	font20->SetSize(9);
	font20->SetSpacing(B_FIXED_SPACING);

	stringview20 = new BStringView(BRect(1, 20, 51, 34), "StringView", "(128kbit/s)", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview20->SetAlignment(B_ALIGN_RIGHT);
	stringview20->SetFont(font20);
	AddChild(stringview20);

	slider12 = new BSlider(BRect(56, 37, 414, 55), "slider", NULL, new BMessage(ABR_SLIDER_MIN), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider12->SetBarThickness(4);
	slider12->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider12->SetHashMarkCount(14);
	AddChild(slider12);

	font12 = new BFont(be_plain_font);
	font12->SetSize(9);
	font12->SetSpacing(B_FIXED_SPACING);

	stringview21 = new BStringView(BRect(58, 58, 415, 69), "StringView", "32        40        48         56        64        80        96       112       128      160      192      224      256     320", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview21->SetFont(font12);
	AddChild(stringview21);

	slider13 = new BSlider(BRect(56, 72, 414, 90), "slider", NULL, new BMessage(ABR_SLIDER_MAX), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT);
	slider13->SetBarThickness(4);
	slider13->SetHashMarks(B_HASH_MARKS_TOP);
	slider13->SetHashMarkCount(14);
	AddChild(slider13);

	stringview22 = new BStringView(BRect(0, 39, 55, 52), "StringView", "min. rate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview22->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview22);

	stringview23 = new BStringView(BRect(0, 72, 60, 87), "StringView", "max. rate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview23->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview23);

	SetViewColor((rgb_color) {216,216,216,255});
}

View4::~View4(void)
{
}
