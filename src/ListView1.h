#include <ListView.h>
#ifndef _ListView1_

class ListView1 : public BListView
{
public:
	ListView1 ();
	~ListView1 (void);

	virtual void KeyDown(const char *bytes, int32 numByte);
};

#define _ListView1_
#endif
