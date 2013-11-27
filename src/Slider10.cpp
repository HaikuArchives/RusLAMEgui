#include <Application.h>
#include "message_labels.h"
#include "Slider10.h"


Slider10::Slider10()
 : BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(COMP_SLIDER), 0, 38, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(39);
	SetValue(8);
}

Slider10::~Slider10(void)
{
}

