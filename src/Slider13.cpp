#include <Application.h>
#include "message_labels.h"
#include "Slider13.h"


Slider13::Slider13()
 : BSlider(BRect(56, 72, 414, 90), "slider", NULL, new BMessage(ABR_SLIDER_MAX), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_TOP);
	SetHashMarkCount(14);
	SetValue(13);
}

Slider13::~Slider13(void)
{
}

