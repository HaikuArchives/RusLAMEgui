#include <Application.h>
#include "message_labels.h"
#include "PopUpMenu6.h"


PopUpMenu6::PopUpMenu6()
 : BPopUpMenu(NULL, true, true, B_ITEMS_IN_COLUMN)
{

	SetRadioMode(true);
	SetTriggersEnabled(false);
	SetLabelFromMarked(true);
//	name=VOLUMESELECT_STRING;
}

PopUpMenu6::~PopUpMenu6(void)
{
}

