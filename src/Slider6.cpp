#include <Application.h>
#include "message_labels.h"
#include "Slider6.h"


Slider6::Slider6()
 : BSlider(BRect(7, 101, 165, 119), "slider", NULL, new BMessage(LOPASS_FREQ), 50, 2300, B_TRIANGLE_THUMB, B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT)
{

	SetBarThickness(4);
	SetHashMarks(B_HASH_MARKS_BOTTOM);
	SetHashMarkCount(5);
	SetKeyIncrementValue(8);
	SetValue(1000);
}

Slider6::~Slider6(void)
{
}

void
Slider6::SetEnabled(bool enabled)
{

const rgb_color green = {0,240,0,255};
const rgb_color red = {240,0,0,255};

if (enabled==true) SetBarColor(red); else SetBarColor(green);

BSlider::SetEnabled(enabled);
}

