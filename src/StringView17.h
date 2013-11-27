#include <StringView.h>
#include <Font.h>
#include <E-mail.h>
#include "my.h"


#ifndef _StringView17_

class StringView17 : public BStringView
{
public:
	StringView17 ();
	~StringView17 (void);

	virtual void MouseDown(BPoint point);
	BFont * font9;
};

#define _StringView17_
#endif
