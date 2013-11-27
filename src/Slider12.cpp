#include <Application.h>
#include "message_labels.h"
#include "Slider12.h"


Slider12::Slider12()
 : BSlider(BRect(56, 37, 414, 55), "slider", NULL, new BMessage(ABR_SLIDER_MIN), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(14);
	SetValue(7);
}

Slider12::~Slider12(void)
{
}

