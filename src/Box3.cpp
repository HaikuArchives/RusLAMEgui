#include <Application.h>
#include "message_labels.h"
#include "Box3.h"


Box3::Box3()
 : BBox(BRect(2, 132, 432, 435), "box", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW, B_FANCY_BORDER)
{

	listview1 = new ListView1();
	scrollview1 = new BScrollView("View", listview1, B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW, true, true, B_FANCY_BORDER);
	scrollview1->SetHighColor((rgb_color) {255,255,255,255});
	scrollview1->SetLowColor((rgb_color) {0,0,0,255});
	button2 = new BButton(BRect(8, 27, 140, 55), "Button", "clear list", new BMessage(CLEAR_LIST_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	popupmenu4 = new BPopUpMenu("Menu", true, true, B_ITEMS_IN_COLUMN);
	menufield4 = new BMenuField(BRect(7, 59, 141, 79), "menufield", "process", popupmenu4, new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	menufield4->SetDivider(64);
	menuitem30 = new BMenuItem("all", new BMessage(DEFAULT_MSG), 0, 0);
	menuitem30->SetMarked(true);
	menuitem31 = new BMenuItem("selected", new BMessage(DEFAULT_MSG), 0, 0);
	menuitem32 = new BMenuItem("not selected", new BMessage(DEFAULT_MSG), 0, 0);
	popupmenu5 = new BPopUpMenu("Menu", true, true, B_ITEMS_IN_COLUMN);
	menufield5 = new BMenuField(BRect(6, 106, 140, 126), "menufield", " ", popupmenu5, new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	menufield5->SetDivider(0);
	menuitem33 = new BMenuItem("do nothing", new BMessage(DEFAULT_MSG), 0, 0);
	menuitem34 = new BMenuItem("move them to trash", new BMessage(DEFAULT_MSG), 0, 0);
	menuitem34->SetMarked(true);
	menuitem35 = new BMenuItem("delete files", new BMessage(DEFAULT_MSG), 0, 0);
	stringview15 = new BStringView(BRect(6, 89, 141, 102), "StringView", "with input files do this:", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	check14 = new BCheckBox(BRect(6, 132, 140, 150), "checkbox", "beep when finished", new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	popupmenu6 = new BPopUpMenu("<select>", true, true, B_ITEMS_IN_COLUMN);
	menufield6 = new BMenuField(BRect(6, 156, 141, 176), "menufield", NULL, popupmenu6, new BMessage(UPDATE_VOLUMES_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_PULSE_NEEDED | B_NAVIGABLE);
	menufield6->SetDivider(0);
	stringview18 = new BStringView(BRect(323, 13, 422, 23), "StringView", "no files", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview18->SetAlignment(B_ALIGN_RIGHT);
	textcontrol1 = new BTextControl(BRect(162, 254, 422, 273), "tc", "save files to folder", "/boot/home/Desktop", new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	textcontrol1->SetDivider(95);
	check15 = new BCheckBox(BRect(146, 255, 160, 273), "checkbox", NULL, new BMessage(PATH_CHK_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	textcontrol2 = new BTextControl(BRect(162, 277, 422, 296), "tc", "lame parameters", "--freeformat", new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	textcontrol2->SetDivider(95);
	check16 = new BCheckBox(BRect(146, 278, 160, 296), "checkbox", NULL, new BMessage(ARG_CHK_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview29 = new BStringView(BRect(9, 254, 135, 265), "StringView", "statistics ------------------", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	font16 = new BFont(be_plain_font);
	font16->SetSize(9);
	font16->SetShear(99);
	font16->SetSpacing(B_FIXED_SPACING);
	stringview30 = new BStringView(BRect(9, 265, 110, 276), "StringView", "mp3 files (session):", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	font17 = new BFont(be_plain_font);
	font17->SetSize(9);
	font17->SetSpacing(B_FIXED_SPACING);
	stringview31 = new BStringView(BRect(105, 265, 134, 276), "StringView", "000", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	stringview31->SetAlignment(B_ALIGN_RIGHT);
	font18 = new BFont(be_plain_font);
	font18->SetSize(9);
	font18->SetSpacing(B_FIXED_SPACING);
	stringview32 = new BStringView(BRect(9, 276, 95, 287), "StringView", "mp3 files (total):", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	font19 = new BFont(be_plain_font);
	font19->SetSize(9);
	font19->SetSpacing(B_FIXED_SPACING);
	stringview33 = new BStringView(BRect(94, 276, 134, 287), "StringView", "000", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	stringview33->SetAlignment(B_ALIGN_RIGHT);
	font20 = new BFont(be_plain_font);
	font20->SetSize(9);
	font20->SetSpacing(B_FIXED_SPACING);
	slider14 = new Slider14();
	stringview34 = new BStringView(BRect(6, 184, 47, 195), "StringView", "low", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	font34 = new BFont(be_plain_font);
	font34->SetSize(9);
	font34->SetSpacing(B_FIXED_SPACING);
	stringview35 = new BStringView(BRect(101, 184, 142, 195), "StringView", "high", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview35->SetAlignment(B_ALIGN_RIGHT);
	font35 = new BFont(be_plain_font);
	font35->SetSize(9);
	font35->SetSpacing(B_FIXED_SPACING);
	stringview36 = new BStringView(BRect(51, 184, 97, 195), "StringView", "priority", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	stringview36->SetAlignment(B_ALIGN_CENTER);
	stringview36->SetHighColor((rgb_color) {214,32,32,255});
	font36 = new BFont(be_plain_font);
	font36->SetSize(9);
	font36->SetSpacing(B_FIXED_SPACING);
	stringview37 = new BStringView(BRect(9, 287, 80, 298), "StringView", "timer (total):", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	font37 = new BFont(be_plain_font);
	font37->SetSize(9);
	font37->SetSpacing(B_FIXED_SPACING);
	stringview38 = new BStringView(BRect(80, 287, 134, 298), "StringView", "0ч 0м 0с", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT, B_WILL_DRAW);
	stringview38->SetAlignment(B_ALIGN_RIGHT);
	font38 = new BFont(be_plain_font);
	font38->SetSize(9);
	font38->SetSpacing(B_FIXED_SPACING);
	SetLabel("file action");

}

Box3::~Box3(void)
{

}

void
Box3::AttachedToWindow(void)
{

	AddChild(scrollview1);
	AddChild(button2);
	AddChild(menufield4);
	popupmenu4->AddItem(menuitem30);
	popupmenu4->AddItem(menuitem31);
	popupmenu4->AddItem(menuitem32);
	AddChild(menufield5);
	popupmenu5->AddItem(menuitem33);
	popupmenu5->AddItem(menuitem34);
	popupmenu5->AddItem(menuitem35);
	AddChild(stringview15);
	AddChild(check14);
	AddChild(menufield6);
	AddChild(stringview18);
	AddChild(textcontrol1);
	AddChild(check15);
	AddChild(textcontrol2);
	AddChild(check16);
	stringview29->SetFont(font16);
	AddChild(stringview29);
	stringview30->SetFont(font17);
	AddChild(stringview30);
	stringview31->SetFont(font18);
	AddChild(stringview31);
	stringview32->SetFont(font19);
	AddChild(stringview32);
	stringview33->SetFont(font20);
	AddChild(stringview33);
	AddChild(slider14);
	stringview34->SetFont(font34);
	AddChild(stringview34);
	stringview35->SetFont(font35);
	AddChild(stringview35);
	stringview36->SetFont(font36);
	AddChild(stringview36);
	stringview37->SetFont(font37);
	AddChild(stringview37);
	stringview38->SetFont(font38);
	AddChild(stringview38);
	SetLabel("file action");

}

void
Box3::AllAttached(void)
{

	scrollview1->SetHighColor((rgb_color) {255,255,255,255});
	scrollview1->SetLowColor((rgb_color) {0,0,0,255});
	menufield4->SetDivider(64);
	popupmenu4->SetRadioMode(true);
	popupmenu4->SetLabelFromMarked(true);
	menuitem30->SetMarked(true);
	menufield5->SetDivider(0);
	popupmenu5->SetRadioMode(true);
	popupmenu5->SetTriggersEnabled(false);
	popupmenu5->SetLabelFromMarked(true);
	menuitem34->SetMarked(true);
	menufield6->SetDivider(0);
	popupmenu6->SetRadioMode(true);
	popupmenu6->SetTriggersEnabled(false);
	popupmenu6->SetLabelFromMarked(true);
	stringview18->SetAlignment(B_ALIGN_RIGHT);
	font16->SetSize(9);
	font16->SetShear(99);
	font16->SetSpacing(B_FIXED_SPACING);
	font17->SetSize(9);
	font17->SetSpacing(B_FIXED_SPACING);
	stringview31->SetAlignment(B_ALIGN_RIGHT);
	font18->SetSize(9);
	font18->SetSpacing(B_FIXED_SPACING);
	font19->SetSize(9);
	font19->SetSpacing(B_FIXED_SPACING);
	stringview33->SetAlignment(B_ALIGN_RIGHT);
	font20->SetSize(9);
	font20->SetSpacing(B_FIXED_SPACING);
	font34->SetSize(9);
	font34->SetSpacing(B_FIXED_SPACING);
	stringview35->SetAlignment(B_ALIGN_RIGHT);
	font35->SetSize(9);
	font35->SetSpacing(B_FIXED_SPACING);
	stringview36->SetAlignment(B_ALIGN_CENTER);
	stringview36->SetHighColor((rgb_color) {214,32,32,255});
	font36->SetSize(9);
	font36->SetSpacing(B_FIXED_SPACING);
	font37->SetSize(9);
	font37->SetSpacing(B_FIXED_SPACING);
	stringview38->SetAlignment(B_ALIGN_RIGHT);
	font38->SetSize(9);
	font38->SetSpacing(B_FIXED_SPACING);

}

