#include <Application.h>
#include "message_labels.h"
#include "StringView33.h"


StringView33::StringView33()
 : BStringView(BRect(81, 27, 127, 38), "StringView", "000", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE)
{

	font33 = new BFont(be_plain_font);
	font33->SetSize(9);
	font33->SetSpacing(B_FIXED_SPACING);
	SetFont(font33);
	font33->SetSize(9);
	font33->SetSpacing(B_FIXED_SPACING);
	SetAlignment(B_ALIGN_RIGHT);
}

StringView33::~StringView33(void)
{
}

