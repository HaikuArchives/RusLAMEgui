#include <Application.h>
#include "message_labels.h"
#include "Slider4.h"


Slider4::Slider4()
 : BSlider(BRect(56, 37, 414, 55), "slider", NULL, new BMessage(VBR_SLIDER_MAX), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_TOP);
	SetHashMarkCount(14);
	SetValue(13);
}

Slider4::~Slider4(void)
{
}

