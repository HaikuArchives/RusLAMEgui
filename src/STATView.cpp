#include <Application.h>
#include "message_labels.h"
#include "STATView.h"


STATView::STATView()
 : BView(BRect(7, 243, 138, 284), "View", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW | B_NAVIGABLE)
{
	stringview29 = new StringView29();
	stringview30 = new BStringView(BRect(3, 14, 87, 25), "StringView", "mp3 files (session):", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	font30 = new BFont(be_plain_font);
	font30->SetSize(9);
	font30->SetSpacing(B_FIXED_SPACING);
	stringview31 = new BStringView(BRect(3, 27, 74, 38), "StringView", "mp3 files (total):", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	font31 = new BFont(be_plain_font);
	font31->SetSize(9);
	font31->SetSpacing(B_FIXED_SPACING);
	stringview32 = new StringView32();
	stringview33 = new StringView33();
	SetViewColor((rgb_color) {190,190,190,255});
}

STATView::~STATView(void)
{
	}

void
STATView::AttachedToWindow(void)
{

	AddChild(stringview29);
	stringview30->SetFont(font30);
	AddChild(stringview30);
	stringview31->SetFont(font31);
	AddChild(stringview31);
	AddChild(stringview32);
	AddChild(stringview33);
	SetViewColor((rgb_color) {190,190,190,255});
}

void
STATView::AllAttached(void)
{

	font30->SetSize(9);
	font30->SetSpacing(B_FIXED_SPACING);
	font31->SetSize(9);
	font31->SetSpacing(B_FIXED_SPACING);
}

