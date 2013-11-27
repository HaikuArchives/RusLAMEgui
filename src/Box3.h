#include <Box.h>
#include <ScrollView.h>
#include <ListView.h>
#include <Button.h>
#include <Application.h>
#include <MenuField.h>
#include <PopUpMenu.h>
#include <MenuItem.h>
#include <StringView.h>
#include <CheckBox.h>
#include <TextControl.h>
#include <TextView.h>
#include <Font.h>
#include <Slider.h>
#include "ListView1.h"
#include "Slider14.h"


#ifndef _Box3_

class Box3 : public BBox
{
public:
	Box3 ();
	~Box3 (void);

	virtual void AttachedToWindow(void);
	virtual void AllAttached(void);

	BScrollView 	* scrollview1;
	ListView1 	* listview1;
	BButton 	* button2;
	BMenuField 	* menufield4;
	BPopUpMenu 	* popupmenu4;
	BMenuItem 	* menuitem30;
	BMenuItem 	* menuitem31;
	BMenuItem 	* menuitem32;
	BMenuField 	* menufield5;
	BPopUpMenu 	* popupmenu5;
	BMenuItem 	* menuitem33;
	BMenuItem 	* menuitem34;
	BMenuItem 	* menuitem35;
	BStringView 	* stringview15;
	BCheckBox 	* check14;
	BMenuField 	* menufield6;
	BPopUpMenu 	* popupmenu6;
	BStringView 	* stringview18;
	BTextControl 	* textcontrol1;
	BCheckBox 	* check15;
	BTextControl 	* textcontrol2;
	BCheckBox 	* check16;
	BStringView 	* stringview29;
	BFont 		* font16;
	BStringView 	* stringview30;
	BFont 		* font17;
	BStringView 	* stringview31;
	BFont 		* font18;
	BStringView 	* stringview32;
	BFont 		* font19;
	BStringView 	* stringview33;
	BFont 		* font20;
	Slider14 	* slider14;
	BStringView 	* stringview34;
	BFont 		* font34;
	BStringView 	* stringview35;
	BFont 		* font35;
	BStringView 	* stringview36;
	BFont 		* font36;
	BStringView 	* stringview37;
	BFont 		* font37;
	BStringView 	* stringview38;
	BFont 		* font38;
};

#define _Box3_
#endif
