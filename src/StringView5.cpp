#include <Application.h>
#include "message_labels.h"
#include "StringView5.h"
#include <TypeConstants.h>
#include <Rect.h>


StringView5::StringView5()
 : BStringView(BRect(151, 435, 224, 452), "StringView", "save settings", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE)
{

	font5 = new BFont(be_plain_font);
	font5->SetSize(12);
	font5->SetSpacing(B_STRING_SPACING);
	SetFont(font5);
	font5->SetSize(12);
	font5->SetSpacing(B_STRING_SPACING);
	SetViewColor((rgb_color) {90,90,90,255});
	SetHighColor((rgb_color) {255,255,255,255});
	SetLowColor((rgb_color) {108,108,108,255});

}

StringView5::~StringView5(void)
{

}

void
StringView5::MouseDown(BPoint point)
{


}

void
StringView5::MouseUp(BPoint point)
{

}

