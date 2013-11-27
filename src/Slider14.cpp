#include <Application.h>
#include "message_labels.h"
#include "Slider14.h"


Slider14::Slider14()
 : BSlider(BRect(4, 196, 142, 214), "slider", NULL, new BMessage(PRIORITY_MSG), 1, 20, B_BLOCK_THUMB, B_FOLLOW_LEFT | B_FOLLOW_TOP)
{

	SetBarThickness(11);
	SetValue(10);
}

Slider14::~Slider14(void)
{
}

void
Slider14::DrawBar(void)
{

const rgb_color kWhite = {255,255,255,255};
const rgb_color kWhiteGray = {216,216,216,255};
const rgb_color kDarkGray = {106,106,106,255};
const rgb_color kBlackColor = {0,0,0,255};


BRect r;
BView *v;


r = BarFrame();
v = OffscreenView();
//v->SetHighColor(kBlackColor);
r.top-=5;
r.bottom-=5;
r.left-=4;
r.right+=5;
r.right--;
r.bottom--;
v->SetHighColor(kDarkGray);
v->StrokeRect(r);

r.left++;
r.top++;
r.right++;
r.bottom++;

v->SetHighColor(kWhite);
v->StrokeRect(r);

r.right--;
r.bottom--;

v->SetHighColor(kWhiteGray);
v->FillRect(r);
//v->SetHighColor(kDarkGray);

//v->StrokeRect(r);
//v->SetHighColor(kWhiteGray);

//r.InsetBy(1,1);
//v->FillEllipse(r);
v->SetHighColor(kBlackColor);

}

void
Slider14::DrawThumb(void)
{

const rgb_color kWhite = {255,255,255,255};
const rgb_color kWhiteGray = {236,236,236,255};
const rgb_color kDarkGray = {106,106,106,255};
const rgb_color kBlackColor = {0,0,0,255};

BRect r, r2;
BView *v;
r = ThumbFrame();
r2 = BarFrame();
v = OffscreenView();
//v->SetHighColor(kBlackColor);
r2.top-=5;
r2.bottom-=5;
r.left=r.left+4;
r.right=r.right-4;
r.top=++r2.top;
r.bottom=--r2.bottom;

r.right--;
r.bottom--;
v->SetHighColor(kWhite);
v->StrokeRect(r);

r.left++;
r.top++;
r.right++;
r.bottom++;

v->SetHighColor(kDarkGray);
v->StrokeRect(r);

r.right--;
r.bottom--;

v->SetHighColor(kWhiteGray);
v->FillRect(r);
//v->SetHighColor(kDarkGray);

//v->StrokeRect(r);
//v->SetHighColor(kWhiteGray);

//r.InsetBy(1,1);
//v->FillEllipse(r);
v->SetHighColor(kBlackColor);

}

void
Slider14::DrawFocusMark(void)
{


}

