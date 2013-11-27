#include <StringView.h>
#include <Font.h>


#ifndef _StringView32_

class StringView32 : public BStringView
{
public:
	StringView32 ();
	~StringView32 (void);

	BFont * font32;
};

#define _StringView32_
#endif
