#include <Application.h>
#include "message_labels.h"
#include "Application1.h"
#include <Path.h>
#include <stdio.h>
#include <Node.h>
#include <NodeInfo.h>
#include <string.h>
#include <unistd.h>
#include <Screen.h>
#include <StopWatch.h>


Application1::Application1()
 : BApplication("application/x-LAMEgui.application")
{
roster=new BVolumeRoster();
roster->StartWatching(be_app_messenger);
LAMEargs = (const char **)malloc(sizeof(char *) * (60));
}

Application1::~Application1(void)
{
roster->StopWatching();
}

void
Application1::ReadyToRun(void)
{
	window1 = new Window1();
}

bool
Application1::QuitRequested(void)
{
	WindowAt(0)->Lock();
	while (CountWindows()>0) WindowAt(0)->Quit();
	return true;
}

void
Application1::MessageReceived(BMessage *message)
{
	switch (message->what)
	{
		case DEFAULT_MSG:
		{
			break;
		}
		
		case 'mm10':
		{
		char *num;
		int32 nof;
		
		nof=window1->view1->box3->listview1->CountItems();
		
		if (nof==0)
		asprintf(&num,"%s",FILECOUNTER_STRING); else
		if (nof==1)
		asprintf(&num,"%s",ONEFILECOUNTER_STRING); else
		asprintf(&num,"%d %s",nof,MOREFILECOUNTER_STRING);
		window1->Lock();
		window1->view1->box3->stringview18->SetText(num);
		window1->Unlock();
		break;
		}		
		
		case ENCODE:
		{
		if (window1->encoding==true) break;
		//BMessageFilter *filter=new BMessageFilter(B_QUIT_REQUESTED);
		//AddCommonFilter(filter);
		//window1->SetFlags(B_NOT_CLOSABLE);
		encode();
		//RemoveCommonFilter(filter);
		be_app->PostMessage('mm10');
		//window1->SetFlags(!B_NOT_CLOSABLE);
		break;
		}
		
		case B_NODE_MONITOR:
		{
		
			int32 opcode;
			if (message->FindInt32("opcode", &opcode) != B_OK)
							break;
			
			//volume mounted message
			if (opcode == B_DEVICE_MOUNTED || B_DEVICE_UNMOUNTED) update();
		}
		
		
		case 'cdfl':
		{
		putCDfiles();
		break;
		}
	
		
		
		
		case UPDATE_VOLUMES_MSG:
		{
		update();
		break;
		}
		
	
		default:
		{
			BApplication::MessageReceived(message);
			break;
		}	
	}

}

void
Application1::RefsReceived(BMessage *message)
{


	uint32 		type;
	int32 		count;
	BEntry		*entry=new BEntry();
	entry_ref	ref;
	BPath		path;
	BNode		*node=new BNode();
	char 		*str2;
	char		mp3name[250];
	//int32		i;

	char		ftype[B_MIME_TYPE_LENGTH];

	//window1->number=0;	
	message->GetInfo("refs", &type, &count);
	//window1->received=count;
//while (startup_complete==false);
	
	if (type != B_REF_TYPE) return;
//	i=count-1;
	for (int32 i = --count; i >= 0; i--) 
	{
		if (message->FindRef("refs", i, &ref) != B_OK)
		{
		if (window1->Alert("Failure at BMessage.FindRef()\n\nProbably you didn't drop a file.")==true) return;
		} else
		{
		entry->SetTo(&ref,false);
		node->SetTo(&ref);
		BNodeInfo	info(node);				
		if (info.GetType(ftype)!=B_OK) 
		{
		delete node;
		delete entry;	
		return;
		}

		if (strstr(ftype,"audio/")==NULL)
		   {
			entry->GetPath(&path);
			asprintf(&str2,"Failure while checking MIME type\n\n%s is not an audio file or the MIME type isn't set correctly.",path.Path());
			window1->Lock();
		   	window1->Alert(str2);
		   	window1->Unlock();
		    } else


	   	   {
	   	   if (entry->GetPath(&path)==B_OK)
		   	{
		   	//window1->number=window1->number+1;
	                	sprintf(mp3name,"%s",path.Path());
    			//window1->PostMessage(ADD_FILE,window1);     
   			//sleep(1);    
    			//if ((window1->number == 10) || (window1->number == 20)) sleep(1);
    			//fname=path.Path();
    			window1->Lock();
    		   	window1->AddFile(mp3name);
    		   	window1->Unlock();
		   	}
		   }
		}
}
		delete node; 
		delete entry;	

}

void
Application1::AboutRequested(void)
{

BAlert *alert;

alert=new BAlert("Info",ABOUTBOX_STRING,"OK",NULL,NULL,B_WIDTH_AS_USUAL,B_EMPTY_ALERT);
alert->Go();
}

void  Application1::encode()
{
		char *comstr;
		char *encmode="";
		char *string4="";
		char *final;
		bool preset, skip_next=false;
		int var1;
		int var2;
		int var3;
		int32 arguments=0;
		extern char **environ;
		status_t returnvalue=B_OK;
		BFile dfile=BFile();
		BString fina, fipa;
		BEntry *destfileentry=new BEntry();
		char *text;
		BStringItem *stringitem;
		BFile *destfile=new BFile();
		BVolume *vol=new BVolume();
		BDirectory *fdir=new BDirectory(); 

		window1->stopped=false;
		window1->paused=false;
		//BMessageFilter *filter=new BMessageFilter(ENCODE);
		int32 filestoprocess=0;
		window1->Lock();
		//window1->view1->box3->button1->SetEnabled(false);
		//AddCommonFilter(filter);
//		window1->view1->box3->statusbar1->SetText("going to do something now...");
		preset=window1->view1->box2->check13->Value()==B_CONTROL_ON;
		comstr=window1->FindLAME();
		LAMEargs[arguments++] = strdup(comstr);

//		window1->view1->box3->statusbar1->Reset();
		switch (window1->view1->tabview1->Selection())
			{
			case 0:
				{
				if (preset==true) break;
				var1=int(100*(window1->view1->view2->slider1->Position()));
				var1=window1->num2bitrate(var1);
				asprintf(&encmode,"%d",var1);
				LAMEargs[arguments++] = strdup("-b");
				LAMEargs[arguments++] = strdup(encmode);
				//asprintf(&encmode," -b %d",var1);
				break;
				}
			case 1:
				{
				if (preset==true) {asprintf(&encmode," -v");break;}
				var1=int(100*(window1->view1->view3->slider2->Position()));
				var1=window1->num2bitrate(var1);
				var2=int(100*(window1->view1->view3->slider4->Position()));
				var2=window1->num2bitrate(var2);
				var3=int(100*(window1->view1->view3->slider8->Position()));
				var3=window1->num2quality(var3);
				LAMEargs[arguments++] = strdup("--vbr-new");
				LAMEargs[arguments++] = strdup("-b");
				asprintf(&encmode,"%d",var1);
				LAMEargs[arguments++] = strdup(encmode);
				LAMEargs[arguments++] = strdup("-B");
				asprintf(&encmode,"%d",var2);
				LAMEargs[arguments++] = strdup(encmode);
				LAMEargs[arguments++] = strdup("-V");
				asprintf(&encmode,"%d",var3);
				LAMEargs[arguments++] = strdup(encmode);
				//asprintf(&encmode," %s --vbr-old -b %d -B %d -V %d",Xing,var1,var2,var3);}
				
				break;
				}
			case 2:
				{
				if (preset==true) break;
				var1=48+window1->round(240*(window1->view1->view4->slider3->Position()));
				//asprintf(&encmode," --abr %d",var1);
				LAMEargs[arguments++] = strdup("--abr");
				asprintf(&encmode,"%d",var1);
				LAMEargs[arguments++] = strdup(encmode);
		
				var2=int(100*(window1->view1->view4->slider12->Position()));
				var2=window1->num2bitrate(var2);
				var3=int(100*(window1->view1->view4->slider13->Position()));
				var3=window1->num2bitrate(var3);
				LAMEargs[arguments++] = strdup("-b");
				asprintf(&encmode,"%d",var2);
				LAMEargs[arguments++] = strdup(encmode);
				LAMEargs[arguments++] = strdup("-B");
				asprintf(&encmode,"%d",var3);
				LAMEargs[arguments++] = strdup(encmode);


				break;
				}
			case 3:
				{
				if (preset==true) break;
				var1=2+window1->round(38*(window1->view1->view5->slider10->Position()));
				//asprintf(&encmode," --comp %d",var1);
				LAMEargs[arguments++] = strdup("--comp");
				asprintf(&encmode,"%d",var1);
				LAMEargs[arguments++] = strdup(encmode);
				break;
				}
			}


		if (preset==false)
		{

		// disable all filters
		if (B_CONTROL_ON==window1->view1->box1->check4->Value())
		{LAMEargs[arguments++] = strdup("-k");
		//asprintf(&comstr,"%s -k",comstr);
		} else
		{
		// HIPASS-Filter an
		if (window1->view1->box1->check1->Value()==B_CONTROL_ON)
		   {
		   LAMEargs[arguments++] = strdup("--highpass");
		  // asprintf(&comstr,"%s --highpass %f",comstr,float(window1->round(600+24400*(window1->view1->box1->slider5->Position())))/1000);
		   asprintf(&comstr,"%f",float(window1->round(500+22500*(window1->view1->box1->slider5->Position())))/1000);
		   LAMEargs[arguments++] = strdup(comstr);
		   }
		// LOPASS-Filter an
		if (window1->view1->box1->check2->Value()==B_CONTROL_ON)
		   {
		   LAMEargs[arguments++] = strdup("--lowpass");		
		   //asprintf(&comstr,"%s --lowpass %f",comstr,float(window1->round(600+24400*(window1->view1->box1->slider6->Position())))/1000);
		   asprintf(&comstr,"%f",float(window1->round(500+22500*(window1->view1->box1->slider6->Position())))/1000);
		   LAMEargs[arguments++] = strdup(comstr);
		   }
		}
		}
		// resample
		if (B_CONTROL_ON==window1->view1->box2->check3->Value())
		{
		var2=44100;
		 switch(int(8*(window1->view1->box2->slider8->Position())))
		 {
		   case 0:{string4="8";break;}
		   case 1:{string4="11.025";break;}
		   case 2:{string4="12";break;}
		   case 3:{string4="16";break;}
		   case 4:{string4="22.05";break;}
		   case 5:{string4="24";break;}
		   case 6:{string4="32";break;}
		   case 7:{string4="44.1";break;}
		   case 8:{string4="48";break;}
		 }
		LAMEargs[arguments++] = strdup("--resample");
		asprintf(&comstr,"%s",string4);
		LAMEargs[arguments++] = strdup(comstr);
		}
		
		// Error Protection
	                 if (B_CONTROL_ON==window1->view1->box2->check5->Value())
			{
			LAMEargs[arguments++] = strdup("-p");
			//asprintf(&comstr,"%s -p",comstr);
			}
		// allow different blocktypes
	                 if (B_CONTROL_ON==window1->view1->box2->check12->Value())
			{
			LAMEargs[arguments++] = strdup("-d");
			//asprintf(&comstr,"%s -d",comstr);
			}
		// Bit Reservoir
		  if (B_CONTROL_OFF==window1->view1->box2->check6->Value())
		    	{
		    	//asprintf(&comstr,"%s --nores",comstr);
		    	//asprintf(&comstr,"--nores");
		    	LAMEargs[arguments++] = strdup("--nores");
			}
		if (preset==false) 
		{
		// decoding
		  if (B_CONTROL_ON==window1->view1->box2->check9->Value())
		    	{
		    	//asprintf(&comstr,"%s --decode",comstr);
		    	LAMEargs[arguments++] = strdup("--decode");
		    	}
		   }
		// ISO
		  if (B_CONTROL_ON==window1->view1->box2->check11->Value())
		    	{
		    	//asprintf(&comstr,"%s --strictly-enforce-ISO",comstr);
		    	LAMEargs[arguments++] = strdup("--strictly-enforce-ISO");
		    	}
		if (window1->round(15*(1-window1->view1->box2->slider11->Position()))!=0)
		{
		LAMEargs[arguments++] = strdup("--athlower");
		//asprintf(&comstr,"%s --athlower %d",comstr,window1->round(15*(1-window1->view1->box2->slider11->Position())));
		asprintf(&comstr,"%d",window1->round(15*(1-window1->view1->box2->slider11->Position())));
		LAMEargs[arguments++] = strdup(comstr);
		}
		
		if (preset==true)
		{
		LAMEargs[arguments++] = strdup("--preset");
		switch (window1->presettype)
		{
		case 1:{LAMEargs[arguments++] = strdup("phone");break;}
		case 2:{LAMEargs[arguments++] = strdup("phon+");break;}
		case 3:{LAMEargs[arguments++] = strdup("lw");break;}
		case 4:{LAMEargs[arguments++] = strdup("mw-eu");break;}
		case 5:{LAMEargs[arguments++] = strdup("mw-us");break;}
		case 6:{LAMEargs[arguments++] = strdup("sw");break;}
		case 7:{LAMEargs[arguments++] = strdup("fm");break;}
		case 8:{LAMEargs[arguments++] = strdup("voice");break;}
		case 9:{LAMEargs[arguments++] = strdup("radio");break;}
		case 10:{LAMEargs[arguments++] = strdup("tape");break;}
		case 11:{LAMEargs[arguments++] = strdup("hifi");break;}
		case 12:{LAMEargs[arguments++] = strdup("cd");break;}
		case 13:{LAMEargs[arguments++] = strdup("studio");break;}
		}
		}
		
		
		LAMEargs[arguments++] = strdup("-q");
		if (window1->view1->box2->menuitem1->IsMarked()==true) LAMEargs[arguments++] = strdup("0"); else
		if (window1->view1->box2->menuitem2->IsMarked()==true) LAMEargs[arguments++] = strdup("1"); else
		if (window1->view1->box2->menuitem3->IsMarked()==true) LAMEargs[arguments++] = strdup("2"); else
		if (window1->view1->box2->menuitem4->IsMarked()==true) LAMEargs[arguments++] = strdup("3"); else
		if (window1->view1->box2->menuitem5->IsMarked()==true) LAMEargs[arguments++] = strdup("4"); else
		if (window1->view1->box2->menuitem6->IsMarked()==true) LAMEargs[arguments++] = strdup("5"); else
		if (window1->view1->box2->menuitem7->IsMarked()==true) LAMEargs[arguments++] = strdup("6"); else
		if (window1->view1->box2->menuitem8->IsMarked()==true) LAMEargs[arguments++] = strdup("7"); else
		if (window1->view1->box2->menuitem9->IsMarked()==true) LAMEargs[arguments++] = strdup("8"); else
		if (window1->view1->box2->menuitem10->IsMarked()==true) LAMEargs[arguments++] = strdup("9");

		if (window1->view1->box2->menuitem15->IsMarked()==false)
		{	
			LAMEargs[arguments++] = strdup("-m");
			if (window1->view1->box2->menuitem11->IsMarked()==true)		LAMEargs[arguments++] = strdup("j"); else
			if (window1->view1->box2->menuitem12->IsMarked()==true)		LAMEargs[arguments++] = strdup("s"); else
			if (window1->view1->box2->menuitem13->IsMarked()==true)		LAMEargs[arguments++] = strdup("m"); else
			if (window1->view1->box2->menuitem14->IsMarked()==true)		LAMEargs[arguments++] = strdup("a"); else
			if (window1->view1->box2->menuitem16->IsMarked()==true)		LAMEargs[arguments++] = strdup("f");

		}
		
//		if (strlen(window1->channelmode)>0)
//		{
//		LAMEargs[arguments++] = strdup("-m");
//		LAMEargs[arguments++] = strdup(window1->channelmode);
//		}
		
		if (window1->view1->box3->check16->Value()==B_CONTROL_ON)
		{
		BString args,s1;
		args=window1->view1->box3->textcontrol2->Text();
		printf("\nLAMEgui: extra arguments are\n");
		if (args.Length()>0)		
		while (args.FindFirst(' ')!=B_ERROR)
		{
		while (args[0]==' ') args.Remove(0,1);
		args.CopyInto(s1,0,args.FindFirst(' '));
		args.RemoveFirst(s1);
		while (args[0]==' ') args.Remove(0,1);
		LAMEargs[arguments++]=strdup(s1.String());
		printf(">%s ",s1.String());
		};
		if (args.Length()>0)		
		while (args[0]==' ') args.Remove(0,1);
				if (args.Length()>0)
				{
				LAMEargs[arguments++]=strdup(args.String());
				printf("%s<\n",args.String());
				}


//		BString st2=BString();
//		printf("args: %s",args.String());
//		
//		if (args.FindFirst(' ')==B_ERROR)
//		{
//		asprintf(&text,"%s",args.String());
//		printf("\n%s",text);
//		LAMEargs[arguments++]=strdup(text);
//		} else
//		while (args.Length()>0)
//			{
//			if (args.FindFirst(' ')==B_ERROR)
//			{
//			asprintf(&text,"%s",args.String());
//			printf("\n%s",st2.String());sleep(1);
//			args.SetTo("");
//			break;
//		//	LAMEargs[arguments++]=strdup(text);
//			}
//			args.CopyInto(st2,0,args.FindFirst(' '));
//			args.Remove(0,args.FindFirst(' '));
//			printf("\n%s ---%s",st2.String(),args.String());sleep(1);
//		//	LAMEargs[arguments++]=strdup(st);
//			};

		
		}

		
		
		//asprintf(&comstr,"%s -q %d%s",comstr,window1->noisequal,window1->channelmode);
		//asprintf(&comstr,"%s%s",comstr,encmode);
		
		//EnableUpdates();
	
//		// all
//		if (window1->view1->box3->menuitem30->IsMarked()==true) items=window1->view1->box3->listwindow1->view1->CountItems();
//		// selected
//		if (window1->view1->box3->menuitem31->IsMarked()==true) 
//		{
//		items=0;
//		  for (int32 i=1;i<=window1->view1->box3->listwindow1->view1->CountItems();i++)
//		  {
//		  if (window1->view1->box3->listwindow1->view1->IsItemSelected(i)==true) items=items+1;
//		  }
//		}
//		// not selected
//		if (window1->view1->box3->menuitem32->IsMarked()==true) 
//		{
//		items=0;
//		  for (int32 i=1;i<=window1->view1->box3->listwindow1->view1->CountItems();i++)
//		  {
//		  if (window1->view1->box3->listwindow1->view1->IsItemSelected(i)==false) items=items+1;
//		  }
//		}
		window1->encoding=true;
		skip_next=false;
		window1->Unlock();
		for (int32 i=0;i<window1->view1->box3->listview1->CountItems();i++)
		{
		 if (
		 ((window1->view1->box3->menuitem31->IsMarked()==true) && (window1->view1->box3->listview1->IsItemSelected(i)==true))
	 	||
 		((window1->view1->box3->menuitem32->IsMarked()==true) && (window1->view1->box3->listview1->IsItemSelected(i)==false))
 		||
 		(window1->view1->box3->menuitem30->IsMarked()==true)
		)
			// encode file
			{
			filestoprocess++;
			}
		}
		
		
		
		if (filestoprocess==0) {
					window1->Lock();
					window1->pb5->SetValue(B_CONTROL_OFF);
					window1->encoding=false;
					window1->paused=false;
					window1->stopped=false;
					//window1->view1->box3->button1->SetEnabled(true);
					window1->Unlock();
					//RemoveCommonFilter(filter);
					return;
					}
//		asprintf(&final,"files processed: %d/%d",0,filestoprocess);
//		window1->view1->box3->stringview15->SetText(final);

		for (int32 i=0;i<window1->view1->box3->listview1->CountItems();i++)
		{
		 if (
		 ((window1->view1->box3->menuitem31->IsMarked()==true) && (window1->view1->box3->listview1->IsItemSelected(i)==true))
	 	||
 		((window1->view1->box3->menuitem32->IsMarked()==true) && (window1->view1->box3->listview1->IsItemSelected(i)==false))
 		||
 		(window1->view1->box3->menuitem30->IsMarked()==true)
		)
			// encode file
			{
			char *destfilename;
			char fn[B_FILE_NAME_LENGTH];
			stringitem=(BStringItem *) window1->view1->box3->listview1->ItemAt(i);
			
			destfile->SetTo(stringitem->Text(),B_READ_ONLY);

			struct stat st;
			if (destfile->GetStat(&st)!=B_OK)
						if (window1->Alert("Failure at: BFile.GetStat()\n\nCould not get file information.")==true)
					//window1->Lock();
					//window1->view1->box3->listview1->MakeEmpty();
					//window1->Unlock();
					break;

			if (vol->SetTo(st.st_dev)!=B_OK) 
				if (window1->Alert("Failure at: BVolume.SetTo()\n\nCould not assign file.")==true)
					break;



			destfileentry->SetTo(stringitem->Text(),false);
			
			destfileentry->GetName(fn);
			fina.SetTo(fn);

				if (B_CONTROL_ON==window1->view1->box2->check9->Value())
				{
				fina.RemoveLast(".mp3");
				fina.RemoveLast(".mpeg3");
				fina.RemoveLast(".mp2");
				fina.RemoveLast(".mp1");
				fina.Append(".wav");
				}
				else
				{
				fina.RemoveLast(".wav");
				fina.RemoveLast(".aiff");
				fina.RemoveLast(".aif");
				fina.RemoveLast(".raw");
				fina.Append(".mp3");
				}
			

			fipa.SetTo(window1->view1->box3->textcontrol1->Text());
			while (fipa.ByteAt(fipa.Length()-1)=='/') fipa.RemoveLast("/");
//			fipa.RemoveLast("/");
			fipa.Append("/");
			
			if (window1->view1->box3->check15->Value()==B_CONTROL_ON)
			{

			if (fdir->SetTo(fipa.String())!=B_OK)  // Folder existiert nicht!
			{
			asprintf(&text,"%s\n\n%s",fipa.String(),FOLDERNOTEXISTS_STRING);
			BAlert *al=new BAlert("Info",text,ABORT_STRING,NULL,NULL,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
			al->Go();

			window1->Lock();
			window1->pb5->SetValue(B_CONTROL_OFF);
			window1->encoding=false;
			window1->paused=false;
			window1->stopped=false;
			window1->Unlock();
			return;			
			}
			}
			
			window1->Lock();
			window1->view1->box3->textcontrol1->SetText(fipa.String());
			window1->Unlock();
			fipa.Append(fina);

			if (window1->view1->box3->check15->Value()==B_CONTROL_ON)
				asprintf(&destfilename,"%s",fipa.String()); else
		{
			if (vol->FreeBytes()==0)
			asprintf(&destfilename,"/boot/home/Desktop/%s",fina.String());
			else
			{
			fina=stringitem->Text();
				if (B_CONTROL_ON==window1->view1->box2->check9->Value())
				{
				fina.RemoveLast(".mp3");
				fina.RemoveLast(".mpeg3");
				fina.RemoveLast(".mp2");
				fina.RemoveLast(".mp1");
				fina.Append(".wav");
				}
				else
				{
				fina.RemoveLast(".wav");
				fina.RemoveLast(".aiff");
				fina.RemoveLast(".aif");
				fina.RemoveLast(".raw");
				fina.Append(".mp3");
				}

			asprintf(&destfilename,"%s",fina.String());
			}
		}
		
		// existiert destfilename schon?
		skip_next=false;
		if (dfile.SetTo(destfilename,B_READ_WRITE)==B_OK)  //Datei existiert also
			{
			char index;
			asprintf(&text,"%s\n\n%s",destfilename,FILE_EXISTS_STRING);
			BAlert *al=new BAlert("Info",text,ABORT_STRING,SKIP_STRING,OVERWRITE_STRING,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
			index=al->Go();
			if (index==0) break;
			if (index==1)	skip_next=true;
			if (index==2) window1->stopped=false;
			};
		
		
		
		
//			asprintf(&final,"files processed: %d/%d",filestoprocess-i,filestoprocess);
//			window1->view1->box3->stringview15->SetText(final);
			//asprintf(&final,"%s \"%s\" \"%s\"",comstr,stringitem->Text(),destfilename);
//			strcat(comstr,MP3s[i].MP3filename);
//			strcat(comstr," ");
//			strcat(comstr,MP3s[i].MP3filename);
//			strcat(comstr,".mp3");
//			window1->view1->box3->statusbar1->SetText(stringitem->Text());
// 			window1->view1->box3->statusbar1->Update(float(100.0/filestoprocess));
			//window1->view1->box3->statusbar1->Draw();
			//encoding=true;
			//stringitem->SetEnabled(false);
			
			printf("LAMEgui: dest. file >%s<\n",destfilename);
			window1->Lock();
			window1->view1->box3->listview1->ItemAt(i)->SetEnabled(false);
			window1->view1->box3->listview1->Invalidate();
			window1->Unlock();
			
			//be_app->PostMessage('encd');
			//allstring=final;
			//asprintf(&final,"\"%s\"",stringitem->Text());
			LAMEargs[arguments]=strdup(stringitem->Text());
			LAMEargs[arguments+1]=strdup(destfilename);
			LAMEargs[arguments+2]=NULL;
			
//			printf("\n");
//			for (char k=0;k<=arguments+1;k++)
//			printf("LAMEgui: %d: >%s<\n",k,LAMEargs[k]);
		

			//system(final);
			window1->paused=false;
			window1->stopped=false;
			window1->skipped=false;
			//if (window1->stopped==true) break;
			if (skip_next==false)
			{
		//	printf("\n------------------------------------------------------");
			window1->lameThread=load_image(arguments+2, LAMEargs, (const char **)environ);
			set_thread_priority(window1->lameThread,window1->CFGDATA.thread_priority);
			if (window1->lameThread<0)
				if (window1->Alert("Failure at: load_image()\n\nUnknown load error. Sorry.")==true) 
								{
								window1->Lock();
								window1->view1->box3->listview1->ItemAt(i)->SetEnabled(true);
								window1->view1->box3->listview1->Invalidate();
								window1->Unlock();
								break;
								}
			window1->watch->Reset();
			if (wait_for_thread(window1->lameThread,&returnvalue)!=B_OK) 
				if (window1->Alert("Failure at: wait_for_thread()\n\nInvalid thread id or thread killed")==true) 
								{
								kill_thread(window1->lameThread);
								window1->Lock();
								window1->view1->box3->listview1->ItemAt(i)->SetEnabled(true);
								window1->view1->box3->listview1->Invalidate();
								window1->Unlock();
								break;
								}
		
			if (window1->stopped==true) 
						{
						char index;
						BString str1;
						str1<<destfilename<<"\n\n"<<DELETE_MP3_FILE_STRING;
						BAlert *al=new BAlert("Info",str1.String(),MI33_STRING,MI35_STRING,MI34_STRING,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
						str1="";
						index=al->Go();
						if (index==2)	{str1<<"mv \""<<destfilename<<"\" /boot/home/Desktop/Trash";
								system (str1.String());}
						if (index==1) {str1<<"rm \""<<destfilename<<"\"";
								system(str1.String());}
	
									
									window1->Lock();
									window1->view1->box3->listview1->ItemAt(i)->SetEnabled(true);
									window1->view1->box3->listview1->Invalidate();
									window1->Unlock();
									break; 
						}else 
						// nicht auf stop gedrückt
						{
						kill_thread(window1->lameThread);
						if (((skip_next) || (window1->skipped))==false)
							{
							window1->CFGDATA.mp3files_counter++;
							window1->mp3files_sessioncounter++;
							window1->CFGDATA.encodertime+=window1->watch->ElapsedTime();
							} else
						if (!skip_next)
							{
							char index;
							BString str1;
							str1<<destfilename<<"\n\n"<<DELETE_MP3_FILE_STRING;
							BAlert *al=new BAlert("Info",str1.String(),MI33_STRING,MI35_STRING,MI34_STRING,B_WIDTH_AS_USUAL,B_WARNING_ALERT);
							str1="";
							index=al->Go();
							if (index==2)	{str1<<"mv \""<<destfilename<<"\" /boot/home/Desktop/Trash";
									system (str1.String());}
							if (index==1) {str1<<"rm \""<<destfilename<<"\"";
									system(str1.String());}
							}
							

						window1->Lock();
						window1->view1->box3->listview1->RemoveItem(i);
						window1->view1->box3->listview1->Invalidate();
						window1->UpdateStats();
						window1->Unlock();
						} //nicht auf stop gedrückt
			} else
			{
			window1->Lock();
			window1->view1->box3->listview1->RemoveItem(i);
			window1->view1->box3->listview1->Invalidate();
			window1->Unlock();
			}
				
			//exec_thread = load_image(arg_c, arg_v, environ);

//			while (encoding==true)
//			{
//			if (NeedsUpdate()==true) UpdateIfNeeded();sleep(1);
//			}
			window1->Lock();
			//stringitem->SetEnabled(false);
			if (window1->view1->box3->listview1->ItemAt(i)!=NULL)
			window1->view1->box3->listview1->ItemAt(i)->SetEnabled(true);
			window1->UpdateStats();
			window1->view1->box3->listview1->Invalidate();
			window1->Unlock();
			i--;
			
			printf("\n");
 			//system(final);
			//in den papierkorb tun???
		if (vol->FreeBytes()>0)
			{
 			if (window1->view1->box3->menuitem34->IsMarked()==true) 
 			  {
 			  asprintf(&final,"mv \"%s\" /boot/home/Desktop/Trash",stringitem->Text());
 			  system(final);
 			  }
			// oder sogar ganz löschen???
 			if (window1->view1->box3->menuitem35->IsMarked()==true) 
 			  {
 			  asprintf(&final,"rm \"%s\"",stringitem->Text());
 			  system(final);
 			  }
 			  }
// 			i=i-1;

			//delete dfile;

 			//delete stringitem;
			//stringitem=new BStringItem("");
			//listitem=window1->view1->box3->listwindow1->view1->ItemAt(i);
			//encmode=&MP3s[i].MP3filename;
			//delete stringitem;
			}

		}
//		window1->view1->box3->statusbar1->SetText("");
//		window1->view1->box3->statusbar1->Reset();
		window1->Lock();
		window1->encoding=false;
		//window1->view1->box3->button1->SetEnabled(true);
		//RemoveCommonFilter(filter);
		if (window1->view1->box3->check14->Value()==B_CONTROL_ON) beep();
		//while (--arguments >= 0) free(LAMEargs[arguments]);
		//free(LAMEargs);
		window1->pb5->SetValue(B_CONTROL_OFF);
			delete fdir;
			delete destfile;
			delete vol;
			delete destfileentry;

		window1->Unlock();
}


void Application1::update()
{
BVolume volume;
off_t cap;
fs_info info;
BString str1;
char b=0, num=0;
char *siz;


window1->Lock();
while (window1->view1->box3->popupmenu6->CountItems()>0) {delete (window1->view1->box3->popupmenu6->RemoveItem((long)0));}
window1->view1->box3->popupmenu6->SetEnabled(false);

do
{
if (roster->GetNextVolume(&volume)==B_NO_ERROR)
	//if (volume.Capacity()!=0)
	{	
	if (fs_stat_dev(volume.Device(),&info)==0)
	{
	// if (volume.GetName(name)==B_OK)
		{
		cap=volume.Capacity();
		b=0;
		if (cap>10240)
		{do
		{
		cap=cap/1024;
		b++;
		} while (cap>10240);}
		siz="  ";
		switch (b)
		{
		case 0: {siz="B";break;}
		case 1: {siz="kB";break;}
		case 2: {siz="MB";break;}
		case 3: {siz="GB";break;}
		case 4: {siz="TB";break;}
		}

		str1="";
		str1 << info.volume_name << " (" << cap << siz <<")";
		//asprintf(&name,"%s (%ldMB) %s",name,cap/(1024*1024),info.fsh_name);
		if ((volume.FreeBytes()==0) && (volume.IsRemovable()==true))
		{
		//window1->Lock();
		num++;
		window1->view1->box3->popupmenu6->AddItem(new BMenuItem(str1.String(),new BMessage('devc'),0,0));
		//window1->Unlock();
		}
		}
		
	}	
	} else  break;
} while (1==1);
roster->Rewind();
if (num!=0) window1->view1->box3->popupmenu6->SetEnabled(true); else
{
window1->view1->box3->popupmenu6->AddItem( new BMenuItem(VOLUMESELECT_STRING,new BMessage(DEFAULT_MSG)));
window1->view1->box3->popupmenu6->ItemAt(0)->SetMarked(true);
window1->view1->box3->popupmenu6->RemoveItem((long)0);
}
window1->Unlock();
}


void Application1::putCDfiles()
{
BVolume volume;

fs_info info;
BDirectory *dir=new BDirectory();
BString str1;
BEntry *entry=new BEntry();
BPath path=BPath();
char num=0;
char marked;

window1->Lock();
marked=window1->view1->box3->popupmenu6->IndexOf(window1->view1->box3->popupmenu6->FindMarked());
window1->working=false;
window1->number=0;	
window1->received=0;

do
{
if (roster->GetNextVolume(&volume)==B_NO_ERROR)
	//if (volume.Capacity()!=0)
	{	
	if (fs_stat_dev(volume.Device(),&info)==0)
	{
	// if (volume.GetName(name)==B_OK)
		{
				
		//asprintf(&name,"%s (%ldMB) %s",name,cap/(1024*1024),info.fsh_name);
		if ((volume.FreeBytes()==0) && (volume.IsRemovable()==true))
		{
		//window1->Lock();
		num++;
		if (marked==num-1)
			{
			if (volume.GetRootDirectory(dir)!=B_OK)
			 	if (window1->Alert("Failure at BVolume.GetRootDirectory() in CDfiles()\n\nCould not identify root directory of volume.")==true) break;
			dir->SetTo(dir,"wav");
			dir->Rewind();
			while (dir->GetNextEntry(entry,true)==B_OK)
				{
			   	//window1->number++;
				window1->received++;
		   	   if (entry->GetPath(&path)==B_OK)	{
				sprintf(window1->mp3filename,"%s",path.Path());
				if (window1->Lock()==true)	{
				window1->AddFile(window1->mp3filename);
				window1->Unlock();
					}
				}

				};
			}

		//window1->Unlock();
		}
		}
		
	}	
	} else break;
} while (1==1);
roster->Rewind();
delete dir;
delete entry;
window1->working=false;
window1->Unlock();
}



