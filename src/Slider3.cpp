#include <Application.h>
#include "message_labels.h"
#include "Slider3.h"


Slider3::Slider3()
 : BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(ABR_SLIDER), 0, 300, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(31);
	SetValue(145);
}

Slider3::~Slider3(void)
{
}

