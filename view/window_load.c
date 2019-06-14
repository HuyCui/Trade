/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:载入界面声明
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_load.h"

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

/******************************************
Function:载入界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void load_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_load);	
	w_(gb,ENTRY,entry_load_show);
	w_(gb,BUTTON, button_load_sure);				
	w_(gb,BUTTON, button_load_cancel);
	w_(gb,COMBO_BOX, combobox_load);
	w_(gb,BUTTON, button_file_choose);
}





