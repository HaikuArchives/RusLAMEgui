#include <View.h>
#include <Bitmap.h>
#include <Slider.h>
#include <Application.h>
#include <StringView.h>
#include <Font.h>


#ifndef _View2_

class View2 : public BView
{
public:
	View2 ();
	~View2 (void);

	BSlider 	* slider1;
	BStringView 	* stringview10;
	BFont 		* font7;
	BStringView 	* stringview11;
};

#define _View2_
#endif
