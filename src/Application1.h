#include <Application.h>
#include <Window.h>
#include <Alert.h>
#include "Window1.h"
#include <Volume.h>
#include <Beep.h>
#include <fs_info.h>
#include <String.h>
#include <VolumeRoster.h>
#include <NodeMonitor.h>
#include <Directory.h>
#include <Path.h>
#include <Entry.h>
#include "my.h"
#include <image.h>
#include <stdlib.h>
#include <string.h>



#ifndef _Application1_

class Application1 : public BApplication
{
public:
	Application1 ();
	~Application1 (void);

	virtual void ReadyToRun(void);
	virtual bool QuitRequested(void);
	virtual void MessageReceived(BMessage *message);
	virtual void RefsReceived(BMessage *message);
	virtual void AboutRequested(void);

	void  encode();
	void update();
	void putCDfiles();

	Window1 		*window1;
	BVolumeRoster 	*roster;
	const char 		**LAMEargs;
};

#define _Application1_
#endif
