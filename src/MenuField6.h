#include <MenuField.h>
#include <PopUpMenu.h>

#ifndef _MenuField6_

class MenuField6 : public BMenuField
{
public:
	MenuField6 ();
	~MenuField6 (void);

	virtual void MouseMoved(BPoint point, uint32 transit, const BMessage *message);
	BPopUpMenu * popupmenu6;

};

#define _MenuField6_
#endif
