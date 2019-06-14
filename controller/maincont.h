/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:主界面回调函数
Mail:956622792@qq.com
******************************************/
#ifndef _MAINCONT_H
#define _MAINCONT_H
#include <gtk/gtk.h>

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))


void on_button_help_clicked(GtkObject* widget,gpointer user_date);//帮助按钮响应函数
void on_button_decrease_clicked(GtkObject* widget,gpointer user_date);//商品下架按钮回调函数
void on_button_add_clicked(GtkObject* widget,gpointer user_date);//确认添加按钮回调函数
void on_button_wuliu_clicked(GtkObject* widget,gpointer user_date);//物流信息按钮回调函数
void on_button_sort_clicked(GtkObject* widget,gpointer user_date);//排序按钮回调函数
void on_button_change_clicked(GtkObject* widget,gpointer user_date);//修改按钮回调函数
void on_button_load_clicked(GtkObject* widget,gpointer user_date);//载入按钮回调函数
void on_button_search_clicked(GtkObject* widget,gpointer user_date);//搜索按钮回调函数
void on_button2_change_close_clicked(GtkObject* widget,gpointer user_data);//错误信息提示界面关闭按钮响应函数
void on_button_next_clicked(GtkObject* widget,gpointer user_date);
void on_button_pre_clicked(GtkObject* widget,gpointer user_date);

#endif
