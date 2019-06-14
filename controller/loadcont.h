/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:信息载入界面
Mail:956622792@qq.com
******************************************/
#ifndef _LOADCONT_H
#define _LOADCONT_H
#include <gtk/gtk.h>

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

/******************************************
Function:文件选择按钮回调函数
out:无
return:void
******************************************/
void on_button_file_choose_clicked(GtkObject* widget,gpointer user_date);
/******************************************
Function:取消载入按钮回调函数
out:无
return:void
******************************************/
void on_button_load_cancel_clicked(GtkObject* widget,gpointer user_date);

/******************************************
Function:确认载入按钮回调函数
out:无
return:void
******************************************/
void on_button_load_sure_clicked(GtkObject* widget,gpointer user_date);


#endif
