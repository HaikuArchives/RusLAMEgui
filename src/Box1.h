#include <Box.h>
#include <CheckBox.h>
#include <Application.h>
#include <Slider.h>
#include "Slider6.h"


#ifndef _Box1_

class Box1 : public BBox
{
public:
	Box1 ();
	~Box1 (void);

	virtual void AttachedToWindow(void);
	virtual void AllAttached(void);

	BCheckBox 	*check4;
	BCheckBox 	*check1;
	BSlider 	*slider5;
	BCheckBox 	*check2;
	Slider6 		*slider6;
};

#define _Box1_
#endif
