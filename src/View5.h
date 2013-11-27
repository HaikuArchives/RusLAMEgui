#include <View.h>
#include <Bitmap.h>
#include <Slider.h>
#include <Application.h>
#include <StringView.h>
#include <Font.h>


#ifndef _View5_

class View5 : public BView
{
public:
	View5 ();
	~View5 (void);

	BSlider * slider10;
	BStringView * stringview26;
	BStringView * stringview27;
	BFont * font27;
	BStringView * stringview28;
	BFont * font28;
};

#define _View5_
#endif
