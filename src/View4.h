#include <View.h>
#include <Bitmap.h>
#include <Slider.h>
#include <Application.h>
#include <StringView.h>
#include <Font.h>


#ifndef _View4_

class View4 : public BView
{
public:
	View4 ();
	~View4 (void);

	BSlider * slider3;
	BStringView * stringview12;
	BFont * font8;
	BStringView * stringview13;
	BStringView * stringview20;
	BFont * font20;
	BSlider * slider12;
	BStringView * stringview21;
	BFont * font12;
	BSlider * slider13;
	BStringView * stringview22;
	BStringView * stringview23;
};

#define _View4_
#endif
