/******************************************
Copyright:SDUT
Author:孙昊
Date:2018-01-18
Describe:登录界面
Mail:956622792@qq.com
******************************************/
#ifndef _LOGINCONT_H
#define _LOGINCONT_H
#include <gtk/gtk.h>

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

/******************************************
Function:确认登录按钮回调函数
out:无
return:void
******************************************/
void on_button_login_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:退出提示界面按钮回调函数
out:无
return:void
******************************************/
void on_button_back_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:取消登录按钮回调函数
out:无
return:void
******************************************/
void on_button_login_cancel_clicked(GtkObject* widget,gpointer user_data);


#endif
