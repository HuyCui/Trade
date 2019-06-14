/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:文件读取显示界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_file.h"

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

/******************************************
Function:将文件读物界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void file_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_file);	
	w_(gb,BUTTON, button_file_sure);				
	w_(gb,BUTTON, button_file_cancel);
	w_(gb,FILE_CHOOSER, filechooser_window);
}





