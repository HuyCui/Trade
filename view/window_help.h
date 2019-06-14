/******************************************
Copyright:SDUT
Author:许荣耀
Date:2018-01-18
Describe:帮助显示界面
Mail:956622792@qq.com
******************************************/
#ifndef _WINDOW_HELP_H
#define _WINDOW_HELP_H
#include <gtk/gtk.h>
#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

GtkWindow *window_help;    //显示界面窗口
GtkTextView *textview_help; //帮助页面文本框
GtkButton *button_help_back; //帮助页面返回按钮
/******************************************
Function:将帮助界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void help_get_widgets(GtkBuilder* gb);

#endif
