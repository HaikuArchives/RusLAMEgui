#include <Application.h>
#include "message_labels.h"
#include "Slider1.h"


Slider1::Slider1()
 : BSlider(BRect(56, 2, 414, 20), "slider", NULL, new BMessage(CBR_SLIDER), 0, 13, B_TRIANGLE_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(14);
	SetValue(8);
//SetLimitLabels("32 kbps","320 kbps");


}

Slider1::~Slider1(void)
{
}

void
Slider1::AllAttached(void)
{


}

