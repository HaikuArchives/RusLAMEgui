#include <Window.h>
#include <View.h>
#include <Bitmap.h>
#include "View1.h"
#include <File.h>
#include <Path.h>
#include <Entry.h>
#include <Directory.h>
#include <Alert.h>
#include "my.h"
#include <Rect.h>
#include <OS.h>
#include <image.h>
#include <PictureButton.h>
#include <Picture.h>
#include <String.h>
#include <StopWatch.h>

#define PAUSE_MSG 	'a-54'
#define STOP_MSG 		'a-55'
#define REC_MSG 		'a-56'
#define ENCODE 		'a-57'
#define SKIP_MSG 		'a-58'


#ifndef _Window1_

class Window1 : public BWindow
{
public:
	Window1 ();
	~Window1 (void);

	virtual bool QuitRequested(void);
	virtual void MessageReceived(BMessage *message);

	View1 			*view1;
	typedef struct
	{
	long 		mp3files_counter;
	float 		CBR_Slider;
	float 		VBRMin_Slider;
	float 		VBRMax_Slider;
	float 		ABR_MINSlider;
	float 		ABR_MAXSlider;
	float 		VBRQual_Slider;
	float 		ABR_Slider;
	float 		COMP_Slider;
	bool 		check4box;
	bool 		check1box;
	int 		slider5val;
	bool 		check2box;
	int 		slider6val;
	bool 		check3box;
	float 		slider8val;
	bool 		check5box;
	bool 		check6box;
	bool 		check9box;
	float 		ATH_Slider;
	bool 		check11box;
	bool 		check12box;
	char 		menufield1item;
	char 		menufield2item;
	char 		menufield5item;
	char 		menufield4item;
	char 		preset_type;
	bool 		check13box; // use preset on/off
	int 		activetab; //cbr, vbr, abr oder comp
	bool 		check14box;
	bool 		check15box;
	bool 		check16box;
	char 		mp3path[255];
	char 		lameargs[255];
	char 		thread_priority;
	bigtime_t 	encodertime;
	float 		win_x,win_y;
	} cfgdata;


	int 	num2bitrate(int num);
	int 	num2quality(int num);
	void 	MakeConfig();
	void 	SaveConfig();
	int 	round(float x);
	void 	loadcfg();
	void 	update();
	void 	AddFile(char *text);
	char 	*FindLAME();
	void 	encode();
	bool 	Alert(char *text);
	void 	UpdateFilters(void);
	void 	UpdateStats(void);


	unsigned int 	number;
	int32 			received;
	char 			*allstring;
	uint32 			filecount;
	char 			mp3filename[B_FILE_NAME_LENGTH];
	BEntry 			CFGFileEntry;
	BDirectory 		dir;
	bool 			encoding;
	bool 			working;
	BFile 			CFGFile;
	char 			*CFGFilename;
	cfgdata 		CFGDATA;
	entry_ref 		droppedfile;
	char 			noisequal;
	char 			presettype;
	char 			*channelmode;
	long 			mp3files_sessioncounter;

	thread_id 		lameThread;
	bool 			paused, stopped,skipped;

	BPictureButton 	*pb3;
	BPictureButton 	*pb5;

	BStopWatch 		*watch;


};

#define _Window1_
#endif