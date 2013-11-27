#include <View.h>
#include <Bitmap.h>
#include <TabView.h>
#include <Box.h>
#include <StringView.h>
#include "View2.h"
#include "View3.h"
#include "View4.h"
#include "View5.h"
#include "Box1.h"
#include "Box2.h"
#include "StringView4.h"
#include "Box3.h"



#ifndef _View1_

class View1 : public BView
{
public:
	View1 ();
	~View1 (void);

	virtual void AttachedToWindow(void);
	virtual void AllAttached(void);
	BTabView 	*tabview1;
	View2 		*view2;
	View3 		*view3;
	View4 		*view4;
	View5 		*view5;
	Box1 		*box1;
	Box2 		*box2;
	StringView4 	*stringview4;
	Box3 		*box3;
};

#define _View1_
#endif
