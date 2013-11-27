#include <Slider.h>
#include <Application.h>


#ifndef _Slider6_

class Slider6 : public BSlider
{
public:
	Slider6 ();
	~Slider6 (void);

	virtual void SetEnabled(bool enabled);
};

#define _Slider6_
#endif
