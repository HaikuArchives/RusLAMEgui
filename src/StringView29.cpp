#include <Application.h>
#include "message_labels.h"
#include "StringView29.h"


StringView29::StringView29()
 : BStringView(BRect(3, 1, 129, 12), "StringView", "statistics", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE)
{

	font29 = new BFont(be_plain_font);
	font29->SetSize(9);
	font29->SetShear(99);
	font29->SetSpacing(B_FIXED_SPACING);
	SetFont(font29);
	font29->SetSize(9);
	font29->SetShear(99);
	font29->SetSpacing(B_FIXED_SPACING);
	SetAlignment(B_ALIGN_CENTER);

}

StringView29::~StringView29(void)
{
}

