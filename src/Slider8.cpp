#include <Application.h>
#include "message_labels.h"
#include "Slider8.h"


Slider8::Slider8()
 : BSlider(BRect(56, 72, 414, 90), "slider", NULL, new BMessage(QUAL_SLIDER), 0, 9, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_TOP);
	SetHashMarkCount(10);
	SetValue(5);
}

Slider8::~Slider8(void)
{
}

