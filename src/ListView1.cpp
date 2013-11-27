#include <Application.h>
#include "message_labels.h"
#include "ListView1.h"



ListView1::ListView1()
 : BListView(BRect(149, 29, 405, 233), "listview", B_MULTIPLE_SELECTION_LIST, B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE)
{


}

ListView1::~ListView1(void)
{

}

void
ListView1::KeyDown(const char *bytes, int32 numByte)
{

if (bytes[0]==B_DELETE) 
{
  for (int32 i=0; i<CountItems();i++)
  {
  if (IsItemSelected(i)==true) 
     {
     RemoveItem(i);
     be_app->PostMessage('mm10');
     i=-1;
     }
  }
}
}

