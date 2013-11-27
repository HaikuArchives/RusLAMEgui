#include <Application.h>
#include "message_labels.h"
#include "View5.h"


View5::View5()
 : BView(BRect(10, 10, 420, 60), "Компрессия", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW)
{
	slider10 = new BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(COMP_SLIDER), 0, 38, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP);
	slider10->SetBarThickness(4);
	slider10->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider10->SetHashMarkCount(39);
	AddChild(slider10);

	stringview26 = new BStringView(BRect(2, 4, 51, 17), "StringView", "rate", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	stringview26->SetAlignment(B_ALIGN_RIGHT);
	AddChild(stringview26);

	font27 = new BFont(be_plain_font);
	font27->SetSize(9);
	font27->SetSpacing(B_FIXED_SPACING);

	stringview27 = new BStringView(BRect(2, 20, 51, 34), "StringView", "(10x)", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview27->SetAlignment(B_ALIGN_RIGHT);
	stringview27->SetFont(font27);
	AddChild(stringview27);

	font28 = new BFont(be_plain_font);
	font28->SetSize(9);
	font28->SetSpacing(B_FIXED_SPACING);

	stringview28 = new BStringView(BRect(58, 23, 415, 34), "StringView", " 2                         8                                16                               24                                32                              40", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview28->SetFont(font28);
	AddChild(stringview28);

	SetViewColor((rgb_color) {216,216,216,255});
}

View5::~View5(void)
{
}
