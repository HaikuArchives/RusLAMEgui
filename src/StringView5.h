#include <StringView.h>
#include <Font.h>



#ifndef _StringView5_

class StringView5 : public BStringView
{
public:
	StringView5 ();
	~StringView5 (void);


	virtual void MouseDown(BPoint point);
	virtual void MouseUp(BPoint point);
	BFont * font5;

};

#define _StringView5_
#endif
