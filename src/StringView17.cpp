#include <Application.h>
#include "message_labels.h"
#include "StringView17.h"


StringView17::StringView17()
 : BStringView(BRect(78, 491, 153, 504), "StringView", "maurice michalski", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE)
{

	font9 = new BFont(be_plain_font);
	font9->SetSize(9);
	font9->SetSpacing(B_STRING_SPACING);
	SetFont(font9);
	font9->SetSize(9);
	font9->SetSpacing(B_STRING_SPACING);
	SetHighColor((rgb_color) {0,0,255,255});
}

StringView17::~StringView17(void)
{
}

void
StringView17::MouseDown(BPoint point)
{
}

