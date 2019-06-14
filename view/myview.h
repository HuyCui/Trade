/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:将所有界面的头文件联系起来
Mail:956622792@qq.com
******************************************/
#ifndef _MYVIEW_H
#define _MYVIEW_H

#include <gtk/gtk.h>
#include "window_load.h"
#include "window_help.h"
#include "window_main.h"
#include "window_login.h"
#include "window_file.h"
#include "window_wuliu.h"
#include "window_change.h"
#include "window_login.h"
#include "window_add.h"


#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
/******************************************
Function:载入glade文件
in:  
	gchar* filename：界面文件名
out:无
return:gb GtkBuilder对象
******************************************/
GtkBuilder* gtk_load_glade(gchar* filename);
/******************************************
Function:将galde控件与代码相链接
in:  
	GtkBuilder* gb：GtkBuilder对象
out:无
return:void
******************************************/
void myview_get_widgets(GtkBuilder* gb);
/******************************************
Function:显示glade页面
in: 无
out:无
return:void
******************************************/
void cal_widget_init();

#endif
