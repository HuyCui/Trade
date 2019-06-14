/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:文件选择界面
Mail:956622792@qq.com
******************************************/
#ifndef _FILECONT_H
#define _FILECONT_H
#include <gtk/gtk.h>

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
/******************************************
Function:取消按钮回调函数
out:无
return:void
******************************************/
void on_button_file_cancel_clicked(GtkObject* widget,gpointer user_date);

/******************************************
Function:确认按钮回调函数
out:无
return:void
******************************************/
void on_button_file_sure_clicked(GtkObject* widget,gpointer user_date);


#endif
