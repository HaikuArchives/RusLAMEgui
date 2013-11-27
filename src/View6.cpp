#include <Application.h>
#include "message_labels.h"
#include "View6.h"


View6::View6()
 : BView(BRect(96, 8, 208, 85), "View", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW)
{
	SetViewColor((rgb_color) {216,216,216,255});
}

View6::~View6(void)
{
}
