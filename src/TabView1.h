#include <TabView.h>
#include <View.h>
#include <Bitmap.h>
#include "View2.h"
#include "View3.h"
#include "View4.h"
#include "View5.h"


#ifndef _TabView1_

class TabView1 : public BTabView
{
public:
	TabView1 ();
	~TabView1 (void);

	View2 * view2;
	View3 * view3;
	View4 * view4;
	View5 * view5;

};

#define _TabView1_
#endif
