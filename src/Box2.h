#include <Box.h>
#include <CheckBox.h>
#include <Application.h>
#include <Slider.h>
#include <MenuField.h>
#include <PopUpMenu.h>
#include <MenuItem.h>
#include <StringView.h>


#ifndef _Box2_

class Box2 : public BBox
{
public:
	Box2 ();
	~Box2 (void);


	virtual void AttachedToWindow(void);
	virtual void AllAttached(void);

	BCheckBox * check3;
	BSlider * slider8;
	BCheckBox * check5;
	BCheckBox * check6;
	BCheckBox * check9;
	BCheckBox * check11;
	BCheckBox * check12;
	BSlider * slider11;
	BCheckBox * check13;
	BMenuField * menufield3;
	BPopUpMenu * popupmenu3;
	BMenuItem * menuitem17;
	BMenuItem * menuitem18;
	BMenuItem * menuitem19;
	BMenuItem * menuitem20;
	BMenuItem * menuitem21;
	BMenuItem * menuitem22;
	BMenuItem * menuitem23;
	BMenuItem * menuitem24;
	BMenuItem * menuitem25;
	BMenuItem * menuitem26;
	BMenuItem * menuitem27;
	BMenuItem * menuitem28;
	BMenuItem * menuitem29;
	BMenuField * menufield1;
	BPopUpMenu * popupmenu1;
	BMenuItem * menuitem1;
	BMenuItem * menuitem2;
	BMenuItem * menuitem3;
	BMenuItem * menuitem4;
	BMenuItem * menuitem5;
	BMenuItem * menuitem6;
	BMenuItem * menuitem7;
	BMenuItem * menuitem8;
	BMenuItem * menuitem9;
	BMenuItem * menuitem10;
	BMenuField * menufield2;
	BPopUpMenu * popupmenu2;
	BMenuItem * menuitem11;
	BMenuItem * menuitem12;
	BMenuItem * menuitem13;
	BMenuItem * menuitem14;
	BMenuItem * menuitem15;
	BMenuItem * menuitem16;
	BStringView * stringview37;
};

#define _Box2_
#endif
