/******************************************
Copyright:SDUT
Author:许荣耀
Date:2018-01-18
Describe:帮助显示界面
Mail:956622792@qq.com
******************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_help.h"

/******************************************
Function:将帮助界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void help_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_help);	
	w_(gb,BUTTON, button_help_back);				
	w_(gb,TEXT_VIEW, textview_help);
}





