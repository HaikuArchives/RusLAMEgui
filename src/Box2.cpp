#include <Application.h>
#include "message_labels.h"
#include "Box2.h"
#include <stdio.h>


Box2::Box2()
 : BBox(BRect(438, 132, 610, 435), "box", B_FOLLOW_BOTTOM | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW | B_FRAME_EVENTS, B_FANCY_BORDER)
{
	check3 = new BCheckBox(BRect(8, 13, 165, 31), "checkbox", "resample", new BMessage(SAMPLEFREQ_CHKBOX), B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW | B_NAVIGABLE);
	slider8 = new BSlider(BRect(8, 33, 165, 51), "slider", NULL, new BMessage(SAMPLE_FREQ), 0, 8, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT);
	slider8->SetBarThickness(4);
	slider8->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider8->SetHashMarkCount(9);
	slider8->SetValue(7);
	check5 = new BCheckBox(BRect(8, 59, 165, 77), "checkbox", "error protection", new BMessage(ERRORPROT_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	check6 = new BCheckBox(BRect(8, 81, 165, 99), "checkbox", "bit reservoir", new BMessage(BITRESERVE_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	check6->SetValue(B_CONTROL_ON);
	check9 = new BCheckBox(BRect(8, 103, 165, 121), "checkbox", "decode MP3 to WAV", new BMessage(DECODE_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	check11 = new BCheckBox(BRect(8, 125, 165, 143), "checkbox", "max ISO compliance", new BMessage(ISO_CHKBOX), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	check12 = new BCheckBox(BRect(8, 147, 165, 165), "checkbox", "allow different blocktypes", new BMessage(DEFAULT_MSG), B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW | B_NAVIGABLE);
	slider11 = new BSlider(BRect(8, 184, 165, 202), "slider", NULL, new BMessage(ATHLOWER_MSG), 0, 15, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT);
	slider11->SetBarThickness(4);
	slider11->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider11->SetHashMarkCount(16);
	check13 = new BCheckBox(BRect(8, 208, 165, 226), "checkbox", "use preset type", new BMessage(USEPRESET_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	popupmenu3 = new BPopUpMenu("select preset", true, true, B_ITEMS_IN_COLUMN);
	menufield3 = new BMenuField(BRect(8, 229, 166, 249), "menufield", "presets", popupmenu3, new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	menufield3->SetDivider(60);
	menuitem17 = new BMenuItem("phone", new BMessage(PHONE_MSG), 0, 0);
	menuitem18 = new BMenuItem("good phone", new BMessage(PHONEPLUS_MSG), 0, 0);
	menuitem19 = new BMenuItem("LW radio", new BMessage(LW_MSG), 0, 0);
	menuitem20 = new BMenuItem("MW Europe", new BMessage(MW_EUROPE_MSG), 0, 0);
	menuitem21 = new BMenuItem("MW USA", new BMessage(MW_USA_MSG), 0, 0);
	menuitem22 = new BMenuItem("SW radio", new BMessage(SW_MSG), 0, 0);
	menuitem23 = new BMenuItem("FM radio", new BMessage(FM_MSG), 0, 0);
	menuitem24 = new BMenuItem("voice", new BMessage(VOICE_MSG), 0, 0);
	menuitem25 = new BMenuItem("radio", new BMessage(RADIO_MSG), 0, 0);
	menuitem26 = new BMenuItem("tape", new BMessage(TAPE_MSG), 0, 0);
	menuitem27 = new BMenuItem("high fidelity", new BMessage(HIFI_MSG), 0, 0);
	menuitem28 = new BMenuItem("compact disc", new BMessage(CD_MSG), 0, 0);
	menuitem28->SetMarked(true);
	menuitem29 = new BMenuItem("studio", new BMessage(STUDIO_MSG), 0, 0);
	popupmenu1 = new BPopUpMenu("<select>", true, true, B_ITEMS_IN_COLUMN);
	menufield1 = new BMenuField(BRect(8, 253, 166, 273), "menufield", "algorithm quality", popupmenu1, new BMessage(DEFAULT_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	menufield1->SetDivider(110);
	menuitem1 = new BMenuItem("0 (best)", new BMessage(QUAL_0), 0, 0);
	menuitem2 = new BMenuItem("1", new BMessage(QUAL_1), 0, 0);
	menuitem3 = new BMenuItem("2 (good)", new BMessage(QUAL_2), 0, 0);
	menuitem3->SetMarked(true);
	menuitem4 = new BMenuItem("3", new BMessage(QUAL_3), 0, 0);
	menuitem5 = new BMenuItem("4", new BMessage(QUAL_4), 0, 0);
	menuitem6 = new BMenuItem("5 (normal)", new BMessage(QUAL_5), 0, 0);
	menuitem7 = new BMenuItem("6", new BMessage(QUAL_6), 0, 0);
	menuitem8 = new BMenuItem("7 (fast)", new BMessage(QUAL_7), 0, 0);
	menuitem9 = new BMenuItem("8", new BMessage(QUAL_8), 0, 0);
	menuitem10 = new BMenuItem("9 (poor)", new BMessage(QUAL_9), 0, 0);
	popupmenu2 = new BPopUpMenu("Menu", true, true, B_ITEMS_IN_COLUMN);
	menufield2 = new BMenuField(BRect(8, 277, 166, 297), "menufield", "channel mode", popupmenu2, new BMessage(DEFAULT_MSG), B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW | B_NAVIGABLE);
	menufield2->SetDivider(85);
	menuitem11 = new BMenuItem("j-stereo", new BMessage(JSTEREO_MSG), 0, 0);
	menuitem12 = new BMenuItem("stereo", new BMessage(STEREO_MSG), 0, 0);
	menuitem13 = new BMenuItem("mono", new BMessage(MONO_MSG), 0, 0);
	menuitem14 = new BMenuItem("auto", new BMessage(AUTOCHANNEL_MSG), 0, 0);
	menuitem15 = new BMenuItem("default", new BMessage(DEFAULTCHANNEL_MSG), 0, 0);
	menuitem15->SetMarked(true);
	menuitem16 = new BMenuItem("force j-s", new BMessage(FORCECHANNEL_MSG), 0, 0);
	stringview37 = new BStringView(BRect(8, 169, 165, 182), "StringView", "-", B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	SetLabel("other settings");
}

Box2::~Box2(void)
{
}

void
Box2::AttachedToWindow(void)
{
	AddChild(check3);
	AddChild(slider8);
	AddChild(check5);
	AddChild(check6);
	AddChild(check9);
	AddChild(check11);
	AddChild(check12);
	AddChild(slider11);
	AddChild(check13);
	AddChild(menufield3);
	popupmenu3->AddItem(menuitem17);
	popupmenu3->AddItem(menuitem18);
	popupmenu3->AddItem(menuitem19);
	popupmenu3->AddItem(menuitem20);
	popupmenu3->AddItem(menuitem21);
	popupmenu3->AddItem(menuitem22);
	popupmenu3->AddItem(menuitem23);
	popupmenu3->AddItem(menuitem24);
	popupmenu3->AddItem(menuitem25);
	popupmenu3->AddItem(menuitem26);
	popupmenu3->AddItem(menuitem27);
	popupmenu3->AddItem(menuitem28);
	popupmenu3->AddItem(menuitem29);
	AddChild(menufield1);
	popupmenu1->AddItem(menuitem1);
	popupmenu1->AddItem(menuitem2);
	popupmenu1->AddItem(menuitem3);
	popupmenu1->AddItem(menuitem4);
	popupmenu1->AddItem(menuitem5);
	popupmenu1->AddItem(menuitem6);
	popupmenu1->AddItem(menuitem7);
	popupmenu1->AddItem(menuitem8);
	popupmenu1->AddItem(menuitem9);
	popupmenu1->AddItem(menuitem10);
	AddChild(menufield2);
	popupmenu2->AddItem(menuitem11);
	popupmenu2->AddItem(menuitem12);
	popupmenu2->AddItem(menuitem13);
	popupmenu2->AddItem(menuitem14);
	popupmenu2->AddItem(menuitem15);
	popupmenu2->AddItem(menuitem16);
	AddChild(stringview37);
	SetLabel("other settings");
}

void
Box2::AllAttached(void)
{

	slider8->SetBarThickness(4);
	slider8->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider8->SetHashMarkCount(9);
	slider8->SetValue(7);
	check6->SetValue(B_CONTROL_ON);
	slider11->SetBarThickness(4);
	slider11->SetHashMarks(B_HASH_MARKS_BOTTOM);
	slider11->SetHashMarkCount(16);
	menufield3->SetDivider(60);
	popupmenu3->SetRadioMode(true);
	popupmenu3->SetLabelFromMarked(true);
	menuitem28->SetMarked(true);
	menufield1->SetDivider(110);
	popupmenu1->SetRadioMode(true);
	popupmenu1->SetLabelFromMarked(true);
	menuitem3->SetMarked(true);
	menufield2->SetDivider(85);
	popupmenu2->SetRadioMode(true);
	popupmenu2->SetLabelFromMarked(true);
	menuitem15->SetMarked(true);
if (B_CONTROL_OFF==check3->Value())
{slider8->SetEnabled(false);}
}

