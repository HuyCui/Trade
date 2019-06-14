/******************************************
Copyright:SDUT
Author:李晓龙
Date:2018-01-18
Describe:上架界面回调函数
Mail:956622792@qq.com
******************************************/
#ifndef ADDCONT_H
#define ADDCONT_H
#include <gtk/gtk.h>
#include "window_add.h"

/******************************************
Function:确认添加按钮回调函数
out:无
return:void
******************************************/
void on_button_sure_add_clicked(GtkObject* widget,gpointer user_data);

/******************************************
Function:取消添加按钮回调函数
out:无
return:void
******************************************/
void on_button_cancel_add_clicked(GtkObject* widget,gpointer user_data);

/******************************************
Function:错误页面返回按钮回调函数
out:无
return:void
******************************************/
void on_button_return_add_clicked(GtkObject* widget,gpointer user_data);
void on_button_change_add_clicked(GtkObject* widget,gpointer user_data);
void on_button_nchange_add_clicked(GtkObject* widget,gpointer user_data);


#endif
