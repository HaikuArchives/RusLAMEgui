#include <Slider.h>
#include <Application.h>

#ifndef _Slider1_

class Slider1 : public BSlider
{
public:
	Slider1 ();
	~Slider1 (void);

	virtual void AllAttached(void);
};

#define _Slider1_
#endif
