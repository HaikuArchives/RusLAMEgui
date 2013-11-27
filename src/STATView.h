#include <View.h>
#include <Bitmap.h>
#include <StringView.h>
#include <Font.h>
#include "StringView29.h"
#include "StringView32.h"
#include "StringView33.h"


#ifndef _STATView_

class STATView : public BView
{
public:
	STATView ();
	~STATView (void);


	virtual void AttachedToWindow(void);
	virtual void AllAttached(void);

	StringView29 	* stringview29;
	BStringView 	* stringview30;
	BFont 		* font30;
	BStringView 	* stringview31;
	BFont 		* font31;
	StringView32 	* stringview32;
	StringView33 	* stringview33;
};

#define _STATView_
#endif
