#include <Application.h>
#include "message_labels.h"
#include "MenuField6.h"


MenuField6::MenuField6()
 : BMenuField(BRect(6, 183, 141, 203), "menufield", NULL, popupmenu6, new BMessage(UPDATE_VOLUMES_MSG), B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW | B_FRAME_EVENTS | B_PULSE_NEEDED | B_NAVIGABLE)
{

	SetDivider(0);
}

MenuField6::~MenuField6(void)
{
}

void
MenuField6::MouseMoved(BPoint point, uint32 transit, const BMessage *message)
{

be_app->PostMessage(UPDATE_VOLUMES_MSG);
}

