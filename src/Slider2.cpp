#include <Application.h>
#include "message_labels.h"
#include "Slider2.h"


Slider2::Slider2()
 : BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(VBR_SLIDER_MIN), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(14);
	SetValue(7);
}

Slider2::~Slider2(void)
{
}

