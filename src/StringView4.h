#include <StringView.h>
#include <Font.h>


#ifndef _StringView4_

class StringView4 : public BStringView
{
public:
	StringView4 ();
	~StringView4 (void);


	virtual void MouseDown(BPoint point);

	BFont * font4;
};

#define _StringView4_
#endif
