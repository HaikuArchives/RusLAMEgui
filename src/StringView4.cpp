#include <Application.h>
#include "message_labels.h"
#include "StringView4.h"


StringView4::StringView4()
 : BStringView(BRect(445, 438, 605, 449), "StringView", "Copyright 2001 by Maurice Michalski", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW)
{

	font4 = new BFont(be_plain_font);
	font4->SetSize(9);
	SetFont(font4);
	font4->SetSize(9);
	SetAlignment(B_ALIGN_RIGHT);
	SetViewColor((rgb_color) {216,216,216,255});
	SetHighColor((rgb_color) {99,99,99,255});
}

StringView4::~StringView4(void)
{
}

void
StringView4::MouseDown(BPoint point)
{

be_app->AboutRequested();
}

