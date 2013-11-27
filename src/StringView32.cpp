#include <Application.h>
#include "message_labels.h"
#include "StringView32.h"


StringView32::StringView32()
 : BStringView(BRect(92, 14, 129, 25), "StringView", "000", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE)
{

	font32 = new BFont(be_plain_font);
	font32->SetSize(9);
	font32->SetSpacing(B_FIXED_SPACING);
	SetFont(font32);
	font32->SetSize(9);
	font32->SetSpacing(B_FIXED_SPACING);
	SetAlignment(B_ALIGN_RIGHT);
}

StringView32::~StringView32(void)
{
}

