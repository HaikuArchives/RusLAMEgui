#include <Slider.h>
#include <Application.h>


#ifndef _Slider14_

class Slider14 : public BSlider
{
public:
	Slider14 ();
	~Slider14 (void);

	virtual void DrawBar(void);
	virtual void DrawThumb(void);
	virtual void DrawFocusMark(void);
};

#define _Slider14_
#endif
