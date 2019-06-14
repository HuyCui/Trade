/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:物流信息展示界面回调函数声明
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wuliucont.h"
#include "window_wuliu.h"
#include "miniroat.h"
/******************************************
Function:物流信息展示按钮响应函数
out:无
return:void
******************************************/

void on_button_wuliu_sure_clicked(GtkObject* widget,gpointer user_data)
{
	char *str1, *str2;
	int s, d;
	if(!gtk_combo_box_get_active_text(combobox1_wuliu))
	{
		gtk_widget_show(GTK_WIDGET(window1_wuliu));
		return;			
	}
	if(!gtk_combo_box_get_active_text(combobox2_wuliu))
	{
		gtk_widget_show(GTK_WIDGET(window2_wuliu));
		return;	
	}
	str1 = gtk_combo_box_get_active_text((GtkComboBox *)combobox1_wuliu);//卖家地址
	str2 = gtk_combo_box_get_active_text((GtkComboBox *)combobox2_wuliu);//买家地址
    gtk_widget_show(GTK_WIDGET(window3_wuliu));
	s = wuliu_change1(str1);
	d = wuliu_change1(str2);
	mini_time(s, d);
    mini_cost(s, d);
}
/******************************************
Function:物流信息展示取消按钮响应函数
out:无
return:void
******************************************/
void on_button_wuliu_cancel_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window_wuliu));
}
/******************************************
Function:退出错误信息提示按钮响应函数
out:无
return:void
******************************************/
void on_button1_wuliu_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window1_wuliu));
}
void on_button2_wuliu_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window2_wuliu));
}
void on_button3_wuliu_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window3_wuliu));
}

