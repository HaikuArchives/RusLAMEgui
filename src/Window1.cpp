#include <Application.h>
#include "message_labels.h"
#include "Window1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ListItem.h>
#include <ListView.h>
#include <Volume.h>
#include <sys/stat.h>
#include <Statable.h>
#include <Beep.h>






Window1::Window1()
 : BWindow(BRect(100, 100, 713, 548), "LAMEgui", B_TITLED_WINDOW, B_NOT_ZOOMABLE | B_NOT_H_RESIZABLE | B_NOT_V_RESIZABLE | B_ASYNCHRONOUS_CONTROLS, B_CURRENT_WORKSPACE)
{

	view1 = new View1();
	AddChild(view1);
	SetSizeLimits(613, 16384, 53, 16384);
//RSRCFile.SetTo("LAMEgui",B_READ_ONLY);
//if (LAMERes.SetTo(&RSRCFile)==B_OK)
//{
//CBR_rate_rsrc=&LAMERes.LoadResource(B_FLOAT_TYPE,long(101),ressize);
//view1->view2->slider1->SetPosition(CBR_rate_rsrc);
//}
const rgb_color green = {0,240,0,255};
const rgb_color red = {240,0,0,255};


view1->view2->stringview11->SetText(BITRATE_STRING);
view1->view4->stringview13->SetText(BITRATE_STRING);
view1->view3->stringview7->SetText(MINBITRATE_STRING);
view1->view4->stringview22->SetText(MINBITRATE_STRING);
view1->view3->stringview14->SetText(MAXBITRATE_STRING);
view1->view4->stringview23->SetText(MAXBITRATE_STRING);
view1->view3->stringview9->SetText(VBRQUALITY_STRING);
view1->view4->stringview13->SetText(BITRATE_STRING);
view1->box1->check4->SetLabel(DISABLEFILTER_STRING);
view1->box1->check1->SetLabel(HIGHPASS_STRING);
view1->box1->check2->SetLabel(LOWPASS_STRING);
view1->box2->SetLabel(BOX2LABEL_STRING);
view1->box1->SetLabel(BOX1LABEL_STRING);
view1->box3->SetLabel(BOX3LABEL_STRING);
view1->box2->check3->SetLabel(RESAMPLE_STRING);
view1->box2->check5->SetLabel(ERRORPROT_STRING);
view1->box2->check6->SetLabel(BITRESERVE_STRING);
view1->box2->check9->SetLabel(DECODECHECKBOX_STRING);
view1->box2->check3->SetLabel(RESAMPLE_STRING);
view1->box2->check11->SetLabel(ISO_STRING);
view1->box2->check12->SetLabel(BLOCKTYPE_STRING);
view1->box2->check13->SetLabel(PRESETCHECKBOX_STRING);
view1->box2->menuitem1->SetLabel(MI1_STRING);
view1->box2->menuitem2->SetLabel(MI2_STRING);
view1->box2->menuitem3->SetLabel(MI3_STRING);
view1->box2->menuitem4->SetLabel(MI4_STRING);
view1->box2->menuitem5->SetLabel(MI5_STRING);
view1->box2->menuitem6->SetLabel(MI6_STRING);
view1->box2->menuitem7->SetLabel(MI7_STRING);
view1->box2->menuitem8->SetLabel(MI8_STRING);
view1->box2->menuitem9->SetLabel(MI9_STRING);
view1->box2->menuitem10->SetLabel(MI10_STRING);
view1->box2->menuitem11->SetLabel(MI11_STRING);
view1->box2->menuitem12->SetLabel(MI12_STRING);
view1->box2->menuitem13->SetLabel(MI13_STRING);
view1->box2->menuitem14->SetLabel(MI14_STRING);
view1->box2->menuitem15->SetLabel(MI15_STRING);
view1->box2->menuitem16->SetLabel(MI16_STRING);
view1->box2->menuitem17->SetLabel(MI17_STRING);
view1->box2->menuitem18->SetLabel(MI18_STRING);
view1->box2->menuitem19->SetLabel(MI19_STRING);
view1->box2->menuitem20->SetLabel(MI20_STRING);
view1->box2->menuitem21->SetLabel(MI21_STRING);
view1->box2->menuitem22->SetLabel(MI22_STRING);
view1->box2->menuitem23->SetLabel(MI23_STRING);
view1->box2->menuitem24->SetLabel(MI24_STRING);
view1->box2->menuitem25->SetLabel(MI25_STRING);
view1->box2->menuitem26->SetLabel(MI26_STRING);
view1->box2->menuitem27->SetLabel(MI27_STRING);
view1->box2->menuitem28->SetLabel(MI28_STRING);
view1->box2->menuitem29->SetLabel(MI29_STRING);
view1->box3->menuitem30->SetLabel(MI30_STRING);
view1->box3->menuitem31->SetLabel(MI31_STRING);
view1->box3->menuitem32->SetLabel(MI32_STRING);
view1->box3->menuitem33->SetLabel(MI33_STRING);
view1->box3->menuitem34->SetLabel(MI34_STRING);
view1->box3->menuitem35->SetLabel(MI35_STRING);

view1->box2->menufield3->SetLabel(PRESETLABEL_STRING);
view1->box2->menufield1->SetLabel(ALGOLABEL_STRING);
view1->box2->menufield2->SetLabel(CHANNELLABEL_STRING);
view1->box3->button2->SetLabel(CLEARLIST_STRING);
view1->box3->menufield4->SetLabel(PROCESSLABEL_STRING);
view1->box3->stringview15->SetText(INPUTFILES_STRING);
view1->box3->check14->SetLabel(BEEPORNOT_STRING);
//view1->box3->stringview19->SetText(GETCDTRACK_STRING);
view1->box3->stringview18->SetText(FILECOUNTER_STRING);
view1->box3->textcontrol1->SetLabel(USERPATH_STRING);
view1->box3->textcontrol2->SetLabel(EXTRA_ARGS_STRING);
view1->view5->stringview26->SetText(COMPRESSION_RATE_STRING);

SetTitle(WINDOW_TITLE_STRING);


view1->box1->slider5->SetBarColor(green);
view1->box1->slider5->UseFillColor(true, &red);
view1->box1->slider6->SetBarColor(red);
view1->box1->slider6->UseFillColor(true, &green);
view1->box3->stringview31->SetText("0");
view1->box3->stringview33->SetText("0");
view1->box3->stringview29->SetText(STATISTICS_STRING);
view1->box3->stringview30->SetText(SESSIONFILES_STRING);
view1->box3->stringview32->SetText(TOTALFILES_STRING);
view1->box3->stringview34->SetText(LOW_STRING);
view1->box3->stringview36->SetText(PRIORITY_STRING);
view1->box3->stringview35->SetText(HIGH_STRING);
view1->box3->stringview37->SetText(ENCODERTIME_STRING);

mp3files_sessioncounter=0;
loadcfg();
number=0;
working=false;
encoding=false;
skipped=false;
//filter=new BMessageFilter(B_SIMPLE_DATA);
be_app->PostMessage(UPDATE_VOLUMES_MSG);
view1->box3->popupmenu6->AddItem( new BMenuItem(VOLUMESELECT_STRING,new BMessage(DEFAULT_MSG)));
view1->box3->popupmenu6->ItemAt(0)->SetMarked(true);
view1->box3->popupmenu6->RemoveItem((long)0);

view1->box1->slider5->SetModificationMessage(new BMessage(HIPASS_FREQ));
view1->box1->slider6->SetModificationMessage(new BMessage(LOPASS_FREQ));
view1->box2->slider11->SetModificationMessage(new BMessage(ATHLOWER_MSG));
view1->box2->slider8->SetModificationMessage(new BMessage(SAMPLE_FREQ));
view1->view4->slider3->SetModificationMessage(new BMessage(ABR_SLIDER));

view1->view3->slider2->SetModificationMessage(new BMessage(VBR_SLIDER_MIN));
view1->view3->slider4->SetModificationMessage(new BMessage(VBR_SLIDER_MAX));
view1->view4->slider12->SetModificationMessage(new BMessage(ABR_SLIDER_MIN));
view1->view4->slider13->SetModificationMessage(new BMessage(ABR_SLIDER_MAX));
view1->view5->slider10->SetModificationMessage(new BMessage(COMP_SLIDER));


BRect b4=BRect(29,220,49,240);
BRect b4_s=BRect(0,0,20,20);



BPicture *stop_on=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(stop_on);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b4_s,B_SOLID_HIGH);

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(214,32,32,255);
view1->box3->FillRect(BRect(4,4,15,16),B_SOLID_HIGH);

stop_on=view1->box3->EndPicture();

BPicture *stop_off=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(stop_off);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b4_s,B_SOLID_HIGH);

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(0,0,0,255);
view1->box3->FillRect(BRect(4,4,15,16),B_SOLID_HIGH);

stop_off=view1->box3->EndPicture();

BPictureButton *pb4 = new BPictureButton(b4,"pb4",stop_off,stop_on,new BMessage(STOP_MSG),
				B_ONE_STATE_BUTTON);
view1->box3->AddChild(pb4);




// picture buttons
BRect b3=BRect(59,220,79,240);
BRect b3_s=BRect(0,0,20,20);

BPicture *pause_on=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(pause_on);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b3_s,B_SOLID_HIGH);

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(214,32,32,255);
view1->box3->FillRect(BRect(4,4,8,16),B_SOLID_HIGH);
view1->box3->FillRect(BRect(11,4,15,16),B_SOLID_HIGH);

pause_on=view1->box3->EndPicture();

BPicture *pause_off=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(pause_off);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b3_s,B_SOLID_HIGH);

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(0,0,0,255);
view1->box3->FillRect(BRect(4,4,8,16),B_SOLID_HIGH);
view1->box3->FillRect(BRect(11,4,15,16),B_SOLID_HIGH);

pause_off=view1->box3->EndPicture();




pb3 = new BPictureButton(b3,"pb3",pause_off,pause_on,new BMessage(PAUSE_MSG),
				B_TWO_STATE_BUTTON);
view1->box3->AddChild(pb3);







BRect b5=BRect(89,220,109,240);
BRect b5_s=BRect(0,0,20,20);



BPicture *rec_on=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(rec_on);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b5_s,B_SOLID_HIGH);

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(214,32,32,255);
view1->box3->FillEllipse(BRect(3,3,17,17),B_SOLID_HIGH);

rec_on=view1->box3->EndPicture();

BPicture *rec_off=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(rec_off);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b5_s,B_SOLID_HIGH);

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(214,32,32,255);
view1->box3->FillEllipse(BRect(3,3,17,17),B_SOLID_HIGH);

rec_off=view1->box3->EndPicture();

pb5 = new BPictureButton(b5,"pb5",rec_off,rec_on,new BMessage(ENCODE),
				B_TWO_STATE_BUTTON);
view1->box3->AddChild(pb5);
view1->box3->SetHighColor(0,0,0,255);




BRect b6=BRect(119,220 ,139,240);
BRect b6_s=BRect(0,0,20,20);



BPicture *skip_on=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(skip_on);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b6_s,B_SOLID_HIGH);

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(214,32,32,255);
view1->box3->FillTriangle(BPoint(4,4),BPoint(4,16),BPoint(10,10),B_SOLID_HIGH);
view1->box3->FillRect(BRect(12,4,15,16),B_SOLID_HIGH);

skip_on=view1->box3->EndPicture();

BPicture *skip_off=new BPicture(); // PAUSE BUTTON
view1->box3->BeginPicture(skip_off);

view1->box3->SetHighColor(216,216,216,255);
view1->box3->FillRect(b6_s,B_SOLID_HIGH);

view1->box3->SetHighColor(246,246,246,255);
view1->box3->StrokeLine(BPoint(0,0),BPoint(19,0));
view1->box3->StrokeLine(BPoint(0,0),BPoint(0,19));

view1->box3->SetHighColor(146,146,146,255);
view1->box3->StrokeLine(BPoint(1,20),BPoint(20,20));
view1->box3->StrokeLine(BPoint(20,20),BPoint(20,1));


view1->box3->SetHighColor(0,0,0,255);
view1->box3->FillTriangle(BPoint(4,4),BPoint(4,16),BPoint(10,10),B_SOLID_HIGH);
view1->box3->FillRect(BRect(12,4,15,16),B_SOLID_HIGH);

skip_off=view1->box3->EndPicture();

BPictureButton *pb6 = new BPictureButton(b6,"pb6",skip_off,skip_on,new BMessage(SKIP_MSG),
				B_ONE_STATE_BUTTON);
view1->box3->AddChild(pb6);

watch=new BStopWatch("encoder watcher",true);
MoveTo(BPoint(CFGDATA.win_x,CFGDATA.win_y));
UpdateStats();
	Show();
}

Window1::~Window1(void)
{
SaveConfig();
}

bool
Window1::QuitRequested(void)
{

	if ((encoding==true) || (paused==true))
		{
		BAlert *quita=new BAlert("Info",QUIT_STRING,OK_STRING,NULL,NULL,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
		quita->Go();
		return false;
		}

	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
	
	
}

void
Window1::MessageReceived(BMessage *message)
{


	char string1[40];
	int var2;

	switch (message->what)
	{
		case DEFAULT_MSG:
		{
			break;
		}

		
		case CLEAR_LIST_MSG:
		{
		view1->box3->listview1->MakeEmpty();
		be_app->PostMessage('mm10');
		number=0;
		break;
		}
		
		case STOP_MSG:
		{
		if (encoding==false) break;
		stopped=true;
		paused=false;
		encoding=false;
		skipped=false;
		kill_thread(lameThread);
		pb3->SetValue(B_CONTROL_OFF);
		pb5->SetValue(B_CONTROL_OFF);
		break;
		}

		case SKIP_MSG:
		{
		if (encoding==false) break;
		paused=false;
		stopped=false;
		skipped=true;
		kill_thread(lameThread);
		pb3->SetValue(B_CONTROL_OFF);
		break;
		}

		case PAUSE_MSG:
		{
		if (encoding==false) {pb3->SetValue(B_CONTROL_OFF);break;}
		paused=!paused;
		
		if (paused==true)
		{
		watch->Suspend();
		 suspend_thread(lameThread);
		 } else
		 {
		 watch->Resume();
		 resume_thread(lameThread);
		 }
		
		break;
		}

		
		case PRIORITY_MSG:
		{
		CFGDATA.thread_priority=view1->box3->slider14->Value();
		if (encoding==true) set_thread_priority(lameThread,CFGDATA.thread_priority);
		break;
		}
		
		case B_SIMPLE_DATA: 
		{		
		message->what=B_REFS_RECEIVED;
		be_app->PostMessage(message, be_app);
		break;
		}

		case QUAL_0:{noisequal=0;break;}
		case QUAL_1:{noisequal=1;break;}
		case QUAL_2:{noisequal=2;break;}
		case QUAL_3:{noisequal=3;break;}
		case QUAL_4:{noisequal=4;break;}
		case QUAL_5:{noisequal=5;break;}
		case QUAL_6:{noisequal=6;break;}
		case QUAL_7:{noisequal=7;break;}
		case QUAL_8:{noisequal=8;break;}
		case QUAL_9:{noisequal=9;break;}
		case PHONE_MSG:{presettype=1;break;}
		case PHONEPLUS_MSG:{presettype=2;break;}
		case LW_MSG:{presettype=3;break;}
		case MW_EUROPE_MSG:{presettype=4;break;}
		case MW_USA_MSG:{presettype=5;break;}
		case SW_MSG:{presettype=6;break;}
		case FM_MSG:{presettype=7;break;}
		case VOICE_MSG:{presettype=8;break;}
		case RADIO_MSG:{presettype=9;break;}
		case TAPE_MSG:{presettype=10;break;}
		case HIFI_MSG:{presettype=11;break;}
		case CD_MSG:{presettype=12;break;}
		case STUDIO_MSG:{presettype=13;break;}
		
		case USEPRESET_MSG:
		{
		update();
		break;
		}
		
		case JSTEREO_MSG:{channelmode="j";break;}
		case STEREO_MSG:{channelmode="s";break;}
		case MONO_MSG:{channelmode="m";break;}
		case AUTOCHANNEL_MSG:{channelmode="a";break;}
		case DEFAULTCHANNEL_MSG:{channelmode="";break;}
		case FORCECHANNEL_MSG:{channelmode="f";break;}
		
		case HIPASS_CHKBOX:
		{
		UpdateFilters();
//		if (B_CONTROL_OFF==view1->box1->check1->Value())
//		{view1->box1->slider5->SetEnabled(false);} else
//		{view1->box1->slider5->SetEnabled(true);}		
		break;
		}
		
		case LOPASS_CHKBOX:
		{
		UpdateFilters();
//		if (B_CONTROL_OFF==view1->box1->check2->Value())
//		{view1->box1->slider6->SetEnabled(false);} else
//		{view1->box1->slider6->SetEnabled(true);}		
		break;
		}
		
		case PATH_CHK_MSG:
		{
		if (view1->box3->check15->Value()==B_CONTROL_OFF)
		view1->box3->textcontrol1->SetEnabled(false); else
		view1->box3->textcontrol1->SetEnabled(true);

		break;
		}
		
		case ARG_CHK_MSG:
		{
		if (view1->box3->check16->Value()==B_CONTROL_OFF)
		view1->box3->textcontrol2->SetEnabled(false); else
		view1->box3->textcontrol2->SetEnabled(true);

		break;
		}
		
		

		case SAMPLEFREQ_CHKBOX:
		{
		if (B_CONTROL_OFF==view1->box2->check3->Value())
		{view1->box2->slider8->SetEnabled(false);} else
		{view1->box2->slider8->SetEnabled(true);}			
		break;
		}
		
		case DISABLEFILTER_CHKBOX:
		{
		UpdateFilters();
		break;
		}
				
		
		case ATHLOWER_MSG:
		{
		sprintf(string1,"%s %d dB",ATH1_STRING,round(15*(1.00000-(view1->box2->slider11->Position()))));
		//view1->box2->slider11->SetLabel(string1);
		view1->box2->stringview37->SetText(string1);
		break;
		}
		
		case HIPASS_FREQ:
		{
		sprintf(string1,"%s (%dHz)",HIGHPASS_STRING, 10*view1->box1->slider5->Value() );
//		view1->box1->stringview24->SetText(string1);
		view1->box1->check1->SetLabel(string1);
		break;
		}

		case LOPASS_FREQ:
		{
		sprintf(string1,"%s (%dHz)",LOWPASS_STRING, 10*view1->box1->slider6->Value());
//		view1->box1->stringview25->SetText(string1);
		view1->box1->check2->SetLabel(string1);
		break;
		}

		case SAMPLE_FREQ:
		{
		 switch(int(8*(view1->box2->slider8->Position())))
		 {
		   case 0:{var2=8000;break;}
		   case 1:{var2=11025;break;}
		   case 2:{var2=12000;break;}
		   case 3:{var2=16000;break;}
		   case 4:{var2=22050;break;}
		   case 5:{var2=24000;break;}
		   case 6:{var2=32000;break;}
		   case 7:{var2=44100;break;}
		   case 8:{var2=48000;break;}
		   default: {var2=44100;break;}
		 }
		sprintf(string1,"%s (%dHz)",RESAMPLE_STRING, var2);
//		view1->box2->slider8->SetLabel(string1);
		view1->box2->check3->SetLabel(string1);
		break;
		}
		
		case VBR_SLIDER_MIN:
		{
		if (view1->view3->slider2->Position() > view1->view3->slider4->Position())
			view1->view3->slider4->SetPosition(view1->view3->slider2->Position());
		break;
		}

		case VBR_SLIDER_MAX:
		{
		if (view1->view3->slider4->Position() < view1->view3->slider2->Position())
			view1->view3->slider2->SetPosition(view1->view3->slider4->Position());
		break;
		}

		case ABR_SLIDER_MIN:
		{
		if (view1->view4->slider12->Position() > view1->view4->slider13->Position())
			view1->view4->slider13->SetPosition(view1->view4->slider12->Position());
		break;
		}

		case ABR_SLIDER_MAX:
		{
		if (view1->view4->slider13->Position() < view1->view4->slider12->Position())
			view1->view4->slider12->SetPosition(view1->view4->slider13->Position());
		break;
		}

		case COMP_SLIDER:
		{
		sprintf(string1,"(%dx)", 2+round(38*(view1->view5->slider10->Position())));
		view1->view5->stringview27->SetText(string1);
		break;
		}

		case ABR_SLIDER:
		{
		sprintf(string1,"(%dkbit/s)",48+round(240*(view1->view4->slider3->Position())));
		view1->view4->stringview20->SetText(string1);
		break;
		}

		
		case ENCODE:
		{
		if (encoding==true) {pb5->SetValue(B_CONTROL_ON);break;}
		stopped=false;
		skipped=false;
		paused=false;
		be_app->PostMessage(ENCODE);
		break;
		}

		case 'devc':
		{
		be_app->PostMessage('cdfl');
		break;
		}
		
		default:
		{
			BWindow::MessageReceived(message);
			break;
		}	
	}

}


int Window1::round(float x)
{
int rounded;
if ((x-int(x))*10>=5)
{
 rounded=int(x)+1;
  }
   else
    {
     rounded=int(x);
 }

return rounded;
}


int Window1::num2bitrate(int num)
{
int val;
val=0;
switch(num)
	{
	case 0:{val=32;break;}
	case 7:{val=40;break;}
	case 15:{val=48;break;}
	case 23:{val=56;break;}
	case 30:{val=64;break;}
	case 38:{val=80;break;}
	case 46:{val=96;break;}
	case 53:{val=112;break;}
	case 61:{val=128;break;}
	case 69:{val=160;break;}
	case 76:{val=192;break;}
	case 84:{val=224;break;}
	case 92:{val=256;break;}
	case 100:{val=320;break;}
	}
return val;
}


int Window1::num2quality(int num)
{
int val;
val=0;
switch(num)
	{
	case 0:{val=9;break;}
	case 11:{val=8;break;}
	case 22:{val=7;break;}
	case 33:{val=6;break;}
	case 44:{val=5;break;}
	case 55:{val=4;break;}
	case 66:{val=3;break;}
	case 77:{val=2;break;}
	case 88:{val=1;break;}
	case 100:{val=0;break;}
	}
return val;
}

void Window1::update()
{

		if (B_CONTROL_OFF==view1->box2->check13->Value())
		  //use preset
		  {
		  view1->box2->menufield3->SetEnabled(false);
//		   view1->box1->check4->SetEnabled(true);
//		   view1->box1->check2->SetEnabled(true);
//		   view1->box1->check1->SetEnabled(true);
//if (B_CONTROL_OFF==view1->box1->check1->Value())
//{
//view1->box1->slider5->SetEnabled(false);
//view1->box1->stringview24->SetHighColor(120,120,120,255);
//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
//} else
//{
//view1->box1->slider5->SetEnabled(true);
//view1->box1->stringview24->SetHighColor(0,0,0,255);
//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
//}	
////		   view1->box1->slider5->SetEnabled(true);
//if (B_CONTROL_OFF==view1->box1->check2->Value())
//{
//view1->box1->slider6->SetEnabled(false);
//view1->box1->stringview25->SetHighColor(120,120,120,255);
//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
//} else
//{
//view1->box1->slider6->SetEnabled(true);
//view1->box1->stringview25->SetHighColor(0,0,0,255);
//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
//}
//		   view1->box1->slider6->SetEnabled(true);
//		UpdateFilters();
		   view1->box2->check9->SetEnabled(true);
		   
		   view1->view2->slider1->SetEnabled(true);
		   view1->view3->slider2->SetEnabled(true);
		   view1->view3->slider4->SetEnabled(true);
if (B_CONTROL_OFF==view1->box2->check3->Value())
{view1->box2->slider8->SetEnabled(false);} else
{view1->box2->slider8->SetEnabled(true);}			
		   view1->view3->slider8->SetEnabled(true);
		  // view1->view3->check8->SetEnabled(true);

		   view1->view4->slider3->SetEnabled(true);
		   view1->view4->slider12->SetEnabled(true);
		   view1->view4->slider13->SetEnabled(true);
		   view1->view5->slider10->SetEnabled(true);
		   view1->view5->stringview26->SetHighColor(0,0,0,255);
		   view1->view5->stringview26->Draw(view1->view5->stringview26->Bounds());
		   view1->view5->stringview27->SetHighColor(0,0,0,255);
		   view1->view5->stringview27->Draw(view1->view5->stringview27->Bounds());
		   view1->view5->stringview28->SetHighColor(0,0,0,255);
		   view1->view5->stringview28->Draw(view1->view5->stringview28->Bounds());

		   view1->view2->stringview10->SetHighColor(0,0,0,255);
		   view1->view2->stringview10->Draw(view1->view2->stringview10->Bounds());
		   view1->view2->stringview11->SetHighColor(0,0,0,255);
		   view1->view2->stringview11->Draw(view1->view2->stringview11->Bounds());
		   view1->view3->stringview5->SetHighColor(0,0,0,255);
		   view1->view3->stringview5->Draw(view1->view3->stringview5->Bounds());
		   view1->view3->stringview7->SetHighColor(0,0,0,255);
		   view1->view3->stringview7->Draw(view1->view3->stringview7->Bounds());
		   view1->view3->stringview14->SetHighColor(0,0,0,255);
		   view1->view3->stringview14->Draw(view1->view3->stringview14->Bounds());
		   view1->view3->stringview9->SetHighColor(0,0,0,255);
		   view1->view3->stringview9->Draw(view1->view3->stringview9->Bounds());
		   view1->view3->stringview8->SetHighColor(0,0,0,255);
		   view1->view3->stringview8->Draw(view1->view3->stringview8->Bounds());
		   view1->view4->stringview12->SetHighColor(0,0,0,255);
		   view1->view4->stringview12->Draw(view1->view4->stringview12->Bounds());
		   view1->view4->stringview13->SetHighColor(0,0,0,255);
		   view1->view4->stringview13->Draw(view1->view4->stringview13->Bounds());
		   view1->view4->stringview20->SetHighColor(0,0,0,255);
		   view1->view4->stringview20->Draw(view1->view4->stringview20->Bounds());
		   view1->view4->stringview21->SetHighColor(0,0,0,255);
		   view1->view4->stringview21->Draw(view1->view4->stringview21->Bounds());
		   view1->view4->stringview22->SetHighColor(0,0,0,255);
		   view1->view4->stringview22->Draw(view1->view4->stringview22->Bounds());
		   view1->view4->stringview23->SetHighColor(0,0,0,255);
		   view1->view4->stringview23->Draw(view1->view4->stringview23->Bounds());
		  }
UpdateFilters();


//		if (B_CONTROL_ON==view1->box1->check4->Value())
//			{
//			view1->box1->slider5->SetEnabled(false);
//			view1->box1->slider6->SetEnabled(false);
//			view1->box1->stringview24->SetHighColor(120,120,120,255);
//			view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
//			view1->box1->stringview25->SetHighColor(120,120,120,255);
//			view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
//
//			view1->box1->check1->SetEnabled(false);
//			view1->box1->check2->SetEnabled(false);
//			} else
//			{
//			if (B_CONTROL_ON==view1->box1->check1->Value())
//			{view1->box1->slider5->SetEnabled(true);
//			view1->box1->stringview24->SetHighColor(0,0,0,255);
//			view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());}
//			if (B_CONTROL_ON==view1->box1->check2->Value())
//			{view1->box1->slider6->SetEnabled(true);
//			view1->box1->stringview25->SetHighColor(0,0,0,255);
//			view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());}
//			view1->box1->check1->SetEnabled(true);
//			view1->box1->check2->SetEnabled(true);
//			}
			
		if (B_CONTROL_ON==view1->box2->check13->Value())
			// PRESETS AN
		  {
		   view1->box2->menufield3->SetEnabled(true);
		 //  view1->box1->check4->SetEnabled(false);
//		   view1->box1->check2->SetEnabled(false);
//		   view1->box1->check1->SetEnabled(false);
//		   view1->box1->slider5->SetEnabled(false);
//		   view1->box1->slider6->SetEnabled(false);
		
		   view1->box2->check9->SetEnabled(false);
		   
		   view1->view2->slider1->SetEnabled(false);
		   view1->view3->slider2->SetEnabled(false);
		   view1->view3->slider4->SetEnabled(false);
		   view1->view3->slider8->SetEnabled(false);
		   //view1->view3->check8->SetEnabled(false);

		   view1->view4->slider3->SetEnabled(false);
		   view1->view5->slider10->SetEnabled(false);
		   view1->view4->slider12->SetEnabled(false);
		   view1->view4->slider13->SetEnabled(false);
		   
		   view1->view2->stringview10->SetHighColor(120,120,120,255);
		   view1->view2->stringview10->Draw(view1->view2->stringview10->Bounds());
		   view1->view2->stringview11->SetHighColor(120,120,120,255);
		   view1->view2->stringview11->Draw(view1->view2->stringview11->Bounds());
		   view1->view3->stringview5->SetHighColor(120,120,120,255);
		   view1->view3->stringview5->Draw(view1->view3->stringview5->Bounds());
		   view1->view3->stringview7->SetHighColor(120,120,120,255);
		   view1->view3->stringview7->Draw(view1->view3->stringview7->Bounds());
		   view1->view3->stringview14->SetHighColor(120,120,120,255);
		   view1->view3->stringview14->Draw(view1->view3->stringview14->Bounds());
		   view1->view3->stringview9->SetHighColor(120,120,120,255);
		   view1->view3->stringview9->Draw(view1->view3->stringview9->Bounds());
		   view1->view3->stringview8->SetHighColor(120,120,120,255);
		   view1->view3->stringview8->Draw(view1->view3->stringview8->Bounds());
		   view1->view4->stringview12->SetHighColor(120,120,120,255);
		   view1->view4->stringview12->Draw(view1->view4->stringview12->Bounds());
		   view1->view4->stringview13->SetHighColor(120,120,120,255);
		   view1->view4->stringview13->Draw(view1->view4->stringview13->Bounds());
		   view1->view4->stringview20->SetHighColor(120,120,120,255);
		   view1->view4->stringview20->Draw(view1->view4->stringview20->Bounds());
		   view1->view4->stringview21->SetHighColor(120,120,120,255);
		   view1->view4->stringview21->Draw(view1->view4->stringview21->Bounds());
		   view1->view4->stringview22->SetHighColor(120,120,120,255);
		   view1->view4->stringview22->Draw(view1->view4->stringview22->Bounds());
		   view1->view4->stringview23->SetHighColor(120,120,120,255);
		   view1->view4->stringview23->Draw(view1->view4->stringview23->Bounds());
		   view1->view5->stringview26->SetHighColor(120,120,120,255);
		   view1->view5->stringview26->Draw(view1->view5->stringview26->Bounds());
		   view1->view5->stringview27->SetHighColor(120,120,120,255);
		   view1->view5->stringview27->Draw(view1->view5->stringview27->Bounds());
		   view1->view5->stringview28->SetHighColor(120,120,120,255);
		   view1->view5->stringview28->Draw(view1->view5->stringview28->Bounds());
//		   view1->box1->stringview24->SetHighColor(120,120,120,255);
//		   view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
//		   view1->box1->stringview25->SetHighColor(120,120,120,255);
//		   view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());

		   } 
			
//if (B_CONTROL_ON==view1->box2->check9->Value())
//{view1->box3->button1->SetLabel(DECODE_STRING);} else {view1->box3->button1->SetLabel(ENCODE_STRING);}
		char string1[15];
		sprintf(string1,"(%dkbit/s)",48+round(240*(view1->view4->slider3->Position())));
		view1->view4->stringview20->SetText(string1);

if (view1->box3->check15->Value()==B_CONTROL_OFF)
	view1->box3->textcontrol1->SetEnabled(false); else
	view1->box3->textcontrol1->SetEnabled(true);
if (view1->box3->check16->Value()==B_CONTROL_OFF)
	view1->box3->textcontrol2->SetEnabled(false); else
	view1->box3->textcontrol2->SetEnabled(true);

}


void Window1::loadcfg()
{
char string1[40];
int var2=0;
off_t filesize=0;
CFGFilename="LAMEgui.settings";
dir.SetTo("/boot/home/config/settings");
if (CFGFile.SetTo(&dir,CFGFilename,B_READ_WRITE)!=B_OK)
			{
			CFGFile.Unset();
			//if (window1->Alert("Failure at BFile.Unset()\n\nCould not close configuration file.")==true) return;
			if (CFGFile.SetTo(&dir,CFGFilename,B_READ_WRITE | B_CREATE_FILE)!=B_OK)
				{
			 	if (Alert("Failure at BFile.SetTo()\n\nCould not open configuration file.")==true) return;
				MakeConfig();
				}
			return;
			}
			
// auf richtige grösse überprüfen
CFGFile.GetSize(&filesize);
if (filesize!=sizeof(CFGDATA))
			{
					char index;						
					BString str1;						
					str1<<CORRUPTCONFIGFILE_STRING;
					BAlert *al=new BAlert("Info",str1.String(),OK_STRING,NULL,NULL,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
					str1="";
					index=al->Go();
					MakeConfig();
			}
	
CFGFile.Seek(0,SEEK_SET);
CFGFile.Read(&CFGDATA,sizeof(cfgdata));

sprintf(string1,"%d",CFGDATA.mp3files_counter);
view1->box3->stringview33->SetText(string1);

view1->view2->slider1->SetPosition(CFGDATA.CBR_Slider);
//sprintf(string1,"constant bitrate: %d kbps", num2bitrate(int(100*(CFGDATA.CBR_Slider))));
//view1->view2->slider1->SetLabel(string1);

view1->view3->slider2->SetPosition(CFGDATA.VBRMin_Slider);
//sprintf(string1,"minimum bitrate: %d kbps",num2bitrate(int(100*(CFGDATA.VBRMin_Slider))));
//view1->view3->slider2->SetLabel(string1);

view1->view3->slider4->SetPosition(CFGDATA.VBRMax_Slider);
//sprintf(string1,"maximum bitrate: %d kbps",num2bitrate(int(100*(CFGDATA.VBRMax_Slider))));
//view1->view3->slider4->SetLabel(string1);

view1->view3->slider8->SetPosition(CFGDATA.VBRQual_Slider);
//sprintf(string1,"VBR quality: %d",num2quality(int(100*(CFGDATA.VBRQual_Slider))));
//view1->view3->slider8->SetLabel(string1);

view1->view4->slider3->SetPosition(CFGDATA.ABR_Slider);
view1->view4->slider12->SetPosition(CFGDATA.ABR_MINSlider);
view1->view4->slider13->SetPosition(CFGDATA.ABR_MAXSlider);

//sprintf(string1,"average bitrate: %d kbps", num2bitrate(int(100*(CFGDATA.ABR_Slider))));
//view1->view4->slider3->SetLabel(string1);

view1->view5->slider10->SetPosition(CFGDATA.COMP_Slider);
sprintf(string1,"(%dx)",round(38*(CFGDATA.COMP_Slider))+2);
view1->view5->stringview27->SetText(string1);

if ((CFGDATA.thread_priority>0) && (CFGDATA.thread_priority<21))
view1->box3->slider14->SetValue(CFGDATA.thread_priority); else
CFGDATA.thread_priority=10;

//view1->view3->check7->SetValue(CFGDATA.Xing_CBox);
//view1->view3->check8->SetValue(CFGDATA.oldVBR_CBox);

view1->box1->check4->SetValue(CFGDATA.check4box);
view1->box1->check1->SetValue(CFGDATA.check1box);
view1->box1->check2->SetValue(CFGDATA.check2box);

view1->box1->slider5->SetValue(CFGDATA.slider5val);
sprintf(string1,"%s (%dHz)",HIGHPASS_STRING, 10*CFGDATA.slider5val);
//view1->box1->stringview24->SetText(string1);
view1->box1->check1->SetLabel(string1);

view1->box1->slider6->SetValue(CFGDATA.slider6val);
sprintf(string1,"%s (%dHz)",LOWPASS_STRING, 10*CFGDATA.slider6val);
//view1->box1->stringview25->SetText(string1);
view1->box1->check2->SetLabel(string1);

view1->box2->slider11->SetPosition(CFGDATA.ATH_Slider);
sprintf(string1,"%s %d dB",ATH1_STRING,round(15*(1-CFGDATA.ATH_Slider)));
//view1->box2->slider11->SetLabel(string1);
view1->box2->stringview37->SetText(string1);
view1->box2->slider8->SetPosition(CFGDATA.slider8val);

		 switch(int(8*CFGDATA.slider8val))
		 {
		   case 0:{var2=8000;break;}
		   case 1:{var2=11025;break;}
		   case 2:{var2=12000;break;}
		   case 3:{var2=16000;break;}
		   case 4:{var2=22050;break;}
		   case 5:{var2=24000;break;}
		   case 6:{var2=32000;break;}
		   case 7:{var2=44100;break;}
		   case 8:{var2=48000;break;}
		 }
		sprintf(string1,"%s (%dHz)",RESAMPLE_STRING, var2);
 		//view1->box2->slider8->SetLabel(string1);
		view1->box2->check3->SetLabel(string1);

view1->box2->check3->SetValue(CFGDATA.check3box);
view1->box2->check5->SetValue(CFGDATA.check5box);
view1->box2->check6->SetValue(CFGDATA.check6box);
view1->box2->check9->SetValue(CFGDATA.check9box);
view1->box2->check11->SetValue(CFGDATA.check11box);
view1->box2->check12->SetValue(CFGDATA.check12box);
view1->box2->check13->SetValue(CFGDATA.check13box);

view1->box3->check14->SetValue(CFGDATA.check14box);
view1->box3->check15->SetValue(CFGDATA.check15box);
view1->box3->check16->SetValue(CFGDATA.check16box);

switch (CFGDATA.menufield2item)
{
case 11:{view1->box2->menuitem11->SetMarked(true);channelmode=" -m j";break;}
case 12:{view1->box2->menuitem12->SetMarked(true);channelmode=" -m s";break;}
case 13:{view1->box2->menuitem13->SetMarked(true);channelmode=" -m m";break;}
case 14:{view1->box2->menuitem14->SetMarked(true);channelmode=" -m a";break;}
case 15:{view1->box2->menuitem15->SetMarked(true);channelmode="";break;}
case 16:{view1->box2->menuitem16->SetMarked(true);channelmode=" -m f";break;}
}

switch (CFGDATA.menufield5item)
{
case 33:{view1->box3->menuitem33->SetMarked(true);break;}
case 34:{view1->box3->menuitem34->SetMarked(true);break;}
case 35:{view1->box3->menuitem35->SetMarked(true);break;}
default:{view1->box3->menuitem34->SetMarked(true);break;}
}

view1->box3->menuitem31->SetMarked(true);
view1->box3->menuitem30->SetMarked(true);
switch (CFGDATA.menufield4item)
{
case 30:{view1->box3->menuitem30->SetMarked(true);break;}
case 31:{view1->box3->menuitem31->SetMarked(true);break;}
case 32:{view1->box3->menuitem32->SetMarked(true);break;}
default:{view1->box3->menuitem30->SetMarked(true);break;}
}




switch (CFGDATA.menufield1item)
{
case 0:{view1->box2->menuitem1->SetMarked(true);noisequal=0;break;}
case 1:{view1->box2->menuitem2->SetMarked(true);noisequal=1;break;}
case 2:{view1->box2->menuitem3->SetMarked(true);noisequal=2;break;}
case 3:{view1->box2->menuitem4->SetMarked(true);noisequal=3;break;}
case 4:{view1->box2->menuitem5->SetMarked(true);noisequal=4;break;}
case 5:{view1->box2->menuitem6->SetMarked(true);noisequal=5;break;}
case 6:{view1->box2->menuitem7->SetMarked(true);noisequal=6;break;}
case 7:{view1->box2->menuitem8->SetMarked(true);noisequal=7;break;}
case 8:{view1->box2->menuitem9->SetMarked(true);noisequal=8;break;}
case 9:{view1->box2->menuitem10->SetMarked(true);noisequal=9;break;}
}

switch (CFGDATA.preset_type)
{
case 1:{view1->box2->menuitem17->SetMarked(true);presettype=1;break;}
case 2:{view1->box2->menuitem18->SetMarked(true);presettype=2;break;}
case 3:{view1->box2->menuitem19->SetMarked(true);presettype=3;break;}
case 4:{view1->box2->menuitem20->SetMarked(true);presettype=4;break;}
case 5:{view1->box2->menuitem21->SetMarked(true);presettype=5;break;}
case 6:{view1->box2->menuitem22->SetMarked(true);presettype=6;break;}
case 7:{view1->box2->menuitem23->SetMarked(true);presettype=7;break;}
case 8:{view1->box2->menuitem24->SetMarked(true);presettype=8;break;}
case 9:{view1->box2->menuitem25->SetMarked(true);presettype=9;break;}
case 10:{view1->box2->menuitem26->SetMarked(true);presettype=10;break;}
case 11:{view1->box2->menuitem27->SetMarked(true);presettype=11;break;}
case 12:{view1->box2->menuitem28->SetMarked(true);presettype=12;break;}
case 13:{view1->box2->menuitem29->SetMarked(true);presettype=13;break;}
default:{view1->box2->menuitem28->SetMarked(true);presettype=12;break;}
}
view1->box3->textcontrol1->SetText(CFGDATA.mp3path);
view1->box3->textcontrol2->SetText(CFGDATA.lameargs);

view1->tabview1->Select(CFGDATA.activetab);
update();

}


void
Window1::SaveConfig()
{
		CFGDATA.win_x=Frame().left;
		CFGDATA.win_y=Frame().top;
		if (CFGDATA.win_x>2000) CFGDATA.win_x=100;
		if (CFGDATA.win_y>2000) CFGDATA.win_y=100;
		if (CFGDATA.win_x<-1000) CFGDATA.win_x=100;
		if (CFGDATA.win_y<-1000) CFGDATA.win_y=100;
		CFGDATA.CBR_Slider=view1->view2->slider1->Position();	
		CFGDATA.VBRMin_Slider=view1->view3->slider2->Position();
		CFGDATA.VBRMax_Slider=view1->view3->slider4->Position();
		CFGDATA.ABR_MINSlider=view1->view4->slider12->Position();
		CFGDATA.ABR_MAXSlider=view1->view4->slider13->Position();
		CFGDATA.VBRQual_Slider=view1->view3->slider8->Position();
		//CFGDATA.Xing_CBox=(view1->view3->check7->Value()==B_CONTROL_ON);
		//CFGDATA.oldVBR_CBox=(view1->view3->check8->Value()==B_CONTROL_ON);
		CFGDATA.ABR_Slider=view1->view4->slider3->Position();	
		CFGDATA.COMP_Slider=view1->view5->slider10->Position();
		CFGDATA.check4box=(view1->box1->check4->Value()==B_CONTROL_ON);
		CFGDATA.check1box=(view1->box1->check1->Value()==B_CONTROL_ON);
		CFGDATA.check2box=(view1->box1->check2->Value()==B_CONTROL_ON);
		CFGDATA.slider5val=view1->box1->slider5->Value();	
		CFGDATA.slider6val=view1->box1->slider6->Value();
		CFGDATA.check3box=(view1->box2->check3->Value()==B_CONTROL_ON);
		CFGDATA.check5box=(view1->box2->check5->Value()==B_CONTROL_ON);
		CFGDATA.check6box=(view1->box2->check6->Value()==B_CONTROL_ON);
		CFGDATA.check9box=(view1->box2->check9->Value()==B_CONTROL_ON);
		CFGDATA.check11box=(view1->box2->check11->Value()==B_CONTROL_ON);
		CFGDATA.check12box=(view1->box2->check12->Value()==B_CONTROL_ON);
		CFGDATA.check13box=(view1->box2->check13->Value()==B_CONTROL_ON);
		CFGDATA.check14box=(view1->box3->check14->Value()==B_CONTROL_ON);
		CFGDATA.check15box=(view1->box3->check15->Value()==B_CONTROL_ON);
		CFGDATA.check16box=(view1->box3->check16->Value()==B_CONTROL_ON);
		CFGDATA.slider8val=view1->box2->slider8->Position();	
		CFGDATA.ATH_Slider=view1->box2->slider11->Position();
		CFGDATA.menufield1item=noisequal;
		CFGDATA.preset_type=presettype;
		sprintf(CFGDATA.mp3path,"%s",view1->box3->textcontrol1->Text());
		sprintf(CFGDATA.lameargs,"%s",view1->box3->textcontrol2->Text());
		CFGDATA.activetab=view1->tabview1->Selection();
		if (view1->box2->menuitem11->IsMarked()==true) {CFGDATA.menufield2item=11;}
		if (view1->box2->menuitem12->IsMarked()==true) {CFGDATA.menufield2item=12;}
		if (view1->box2->menuitem13->IsMarked()==true) {CFGDATA.menufield2item=13;}
		if (view1->box2->menuitem14->IsMarked()==true) {CFGDATA.menufield2item=14;}
		if (view1->box2->menuitem15->IsMarked()==true) {CFGDATA.menufield2item=15;}
		if (view1->box2->menuitem16->IsMarked()==true) {CFGDATA.menufield2item=16;}

		if (view1->box3->menuitem33->IsMarked()==true) {CFGDATA.menufield5item=33;}
		if (view1->box3->menuitem34->IsMarked()==true) {CFGDATA.menufield5item=34;}
		if (view1->box3->menuitem35->IsMarked()==true) {CFGDATA.menufield5item=35;}
		
		if (view1->box3->menuitem30->IsMarked()==true) {CFGDATA.menufield4item=30;}
		if (view1->box3->menuitem31->IsMarked()==true) {CFGDATA.menufield4item=31;}
		if (view1->box3->menuitem32->IsMarked()==true) {CFGDATA.menufield4item=32;}

		CFGFile.Seek(0,SEEK_SET);
		CFGFile.Write(&CFGDATA,sizeof(cfgdata));
		
		CFGFile.Unset();
		
}



void
Window1::MakeConfig()
{
char string1[40];
view1->box3->stringview33->SetText("0");
view1->box3->stringview31->SetText("0");
CFGDATA.encodertime=0;
mp3files_sessioncounter=0;
CFGDATA.win_x=100;
CFGDATA.win_y=100;
CFGDATA.mp3files_counter=0;
CFGDATA.thread_priority=10;
view1->view2->slider1->SetPosition(0.6);
view1->view3->slider2->SetPosition(0.5);
view1->view3->slider4->SetPosition(1);
view1->view3->slider8->SetPosition(0.7);
view1->view4->slider3->SetPosition(0.46);
view1->view4->slider12->SetPosition(0);
view1->view4->slider13->SetPosition(1);
view1->view5->slider10->SetPosition(0.3);
sprintf(string1,"(%dx)", round(38*(0.3))+2);
view1->view5->stringview27->SetText(string1);
//view1->view3->check7->SetValue(true);
//view1->view3->check8->SetValue(false);
view1->box1->check4->SetValue(false);
view1->box1->check1->SetValue(false);
view1->box1->check2->SetValue(false);
view1->box1->slider5->SetValue(50);

sprintf(string1,"%s (%dHz)",HIGHPASS_STRING, 500);
//view1->box1->stringview24->SetText(string1);
view1->box1->check1->SetLabel(string1);

view1->box1->slider6->SetValue(2300);
sprintf(string1,"%s (%dHz)",LOWPASS_STRING, 23000);
//view1->box1->stringview25->SetText(string1);
view1->box1->check2->SetLabel(string1);

view1->box2->slider11->SetPosition(1);
sprintf(string1,"%s %d dB",ATH1_STRING,0);
//view1->box2->slider11->SetLabel(string1);
view1->box2->stringview37->SetText(string1);
view1->box2->slider8->SetPosition(0.8888889);
		sprintf(string1,"%s (%dHz)",RESAMPLE_STRING, 44100);
// 		view1->box2->slider8->SetLabel(string1);
		view1->box2->check3->SetLabel(string1);
view1->box2->check3->SetValue(false);
view1->box2->check5->SetValue(false);
view1->box2->check6->SetValue(true);
view1->box2->check9->SetValue(false);
view1->box2->check11->SetValue(false);
view1->box2->check12->SetValue(false);
view1->box2->check13->SetValue(false);
view1->box3->check14->SetValue(false);
//view1->box3->check15->SetValue(false);
view1->box2->menuitem15->SetMarked(true);
view1->box3->textcontrol1->SetText("/boot/home/Desktop");
view1->box3->textcontrol2->SetText("--freeformat");
	channelmode="";
view1->box3->menuitem34->SetMarked(true);
view1->box3->menuitem30->SetMarked(true);
view1->box3->check15->SetValue(B_CONTROL_OFF);
view1->box3->check16->SetValue(B_CONTROL_OFF);
view1->box2->menuitem3->SetMarked(true);noisequal=2;
view1->box2->menuitem28->SetMarked(true);presettype=12;
view1->tabview1->Select(1);
update();
SaveConfig();
}

void
Window1::AddFile(char *text)
{
number=number+1;
view1->box3->listview1->AddItem(new BStringItem(text));
//sprintf(MP3s[filecount].MP3filename,"%s",text);
//MP3s[number].MP3filename=text;
be_app->PostMessage('mm10');
}

char *Window1::FindLAME()
{
BEntry LAMEFile1, LAMEFile2;
time_t time1, time2;

if (LAMEFile1.SetTo("/boot/home/config/bin/lame",false)==B_OK)
	{
	if (LAMEFile2.SetTo("/boot/home/config/bin/lame-dec",false)==B_OK)
		{
		LAMEFile2.GetCreationTime(&time2);
		LAMEFile1.GetCreationTime(&time1);
		if (time1<time2) return "/boot/home/config/bin/lame-dec"; else
				return "/boot/home/config/bin/lame";
		} else return "/boot/home/config/bin/lame";
	
	} else return "/boot/home/config/bin/lame-dec";
};


bool Window1::Alert(char *text)
{
BAlert *alert;
int32 index=5;

alert=new BAlert("Info",text,ABORT_STRING,CONTINUE_STRING,NULL,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
index=alert->Go();
if (index==0) return true;
if (index==1) return false;
};


void Window1::UpdateFilters(void)
{
		if (B_CONTROL_OFF==view1->box2->check13->Value())
		//presets aus
{
		if (B_CONTROL_ON==view1->box1->check4->Value())
		//disable all filters
			{
			view1->box1->slider5->SetEnabled(false);
			view1->box1->slider6->SetEnabled(false);
			view1->box1->check1->SetEnabled(false);
			view1->box1->check2->SetEnabled(false);
			//view1->box1->stringview24->SetHighColor(120,120,120,255);
			//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
			//view1->box1->stringview25->SetHighColor(120,120,120,255);
			//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
			} else
			{
			view1->box1->check1->SetEnabled(true);
			view1->box1->check2->SetEnabled(true);
			if (B_CONTROL_ON==view1->box1->check1->Value()) //hipass on
			{view1->box1->slider5->SetEnabled(true);
			//view1->box1->stringview24->SetHighColor(0,0,0,255);
			//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
			}
			else //hipass off
			{view1->box1->slider5->SetEnabled(false);
			//view1->box1->stringview24->SetHighColor(120,120,120,255);
			//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
			}
			if (B_CONTROL_ON==view1->box1->check2->Value()) //lopass on
			{view1->box1->slider6->SetEnabled(true);
			//view1->box1->stringview25->SetHighColor(0,0,0,255);
			//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
			} 
			else //lopass off
			{view1->box1->slider6->SetEnabled(false);
			//view1->box1->stringview25->SetHighColor(120,120,120,255);
			//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
			}
			}
	} else
			{
			view1->box1->slider5->SetEnabled(false);
			view1->box1->slider6->SetEnabled(false);
			view1->box1->check1->SetEnabled(false);
			view1->box1->check2->SetEnabled(false);
			//view1->box1->stringview24->SetHighColor(120,120,120,255);
			//view1->box1->stringview24->Draw(view1->box1->stringview24->Bounds());
			//view1->box1->stringview25->SetHighColor(120,120,120,255);
			//view1->box1->stringview25->Draw(view1->box1->stringview25->Bounds());
			}


}

void Window1::UpdateStats(void)
{
char string4[10];
uint h, m, s;

h=(uint)(CFGDATA.encodertime/3600000000);
m=(uint)(CFGDATA.encodertime/60000000)-60*h;
s=(uint)(CFGDATA.encodertime/1000000)-((uint)(CFGDATA.encodertime/60000000))*60;

sprintf(string4,"%d",mp3files_sessioncounter);
view1->box3->stringview31->SetText(string4);
sprintf(string4,"%d",CFGDATA.mp3files_counter);
view1->box3->stringview33->SetText(string4);
sprintf(string4,"%dh %dm %ds",h,m,s);
view1->box3->stringview38->SetText(string4);
}


