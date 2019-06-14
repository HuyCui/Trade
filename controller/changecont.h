/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:修改信息界面
Mail:956622792@qq.com
******************************************/
#ifndef CHANGECONT_H
#define CHANGECONT_H
#include "window_change.h"
#include <gtk/gtk.h>


/******************************************
Function:树视图信息选中回调函数
out:无
return:void
******************************************/
void on_treeview_goods_cursor_changed(GtkObject* widget,gpointer user_data);
/******************************************
Function:确认修改按钮回调函数
out:无
return:void
******************************************/
void on_button_change_sure_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:取消修改按钮回调函数
out:无
return:void
******************************************/
void on_button_change_close_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:退出提示信息界面按钮回调函数
out:无
return:void
******************************************/
void on_button1_change_close_clicked(GtkObject* widget,gpointer user_data);

#endif
