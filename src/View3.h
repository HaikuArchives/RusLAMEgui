#include <View.h>
#include <Bitmap.h>
#include <Slider.h>
#include <Application.h>
#include <StringView.h>
#include <Font.h>


#ifndef _View3_

class View3 : public BView
{
public:
	View3 ();
	~View3 (void);

	BSlider * slider2;
	BSlider * slider4;
	BSlider * slider8;
	BStringView * stringview5;
	BFont * font5;
	BStringView * stringview7;
	BStringView * stringview14;
	BStringView * stringview8;
	BFont * font6;
	BStringView * stringview9;


};

#define _View3_
#endif
