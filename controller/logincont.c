/******************************************
Copyright:SDUT
Author:孙昊
Date:2018-01-18
Describe:登录界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>

#include "logincont.h"
#include "myview.h"

/******************************************
Function:确认登录按钮回调函数
out:无
return:void
******************************************/
void on_button_login_clicked(GtkObject* widget,gpointer user_data)
{
	char user[] = "root";
	char password[] = "******";
	const gchar* str;
	str = gtk_entry_get_text(entry_id);
    const gchar* str1;
    str1 = gtk_entry_get_text(entry_password);
    if(strcmp(str,user)==0&&strcmp(str1,password)==0)
    {
        gtk_widget_hide(GTK_WIDGET(window_login));
        gtk_widget_show(GTK_WIDGET(window_main));
        init_list(GTK_WIDGET(treeview_goods));
    }
    else 
    {
        gtk_widget_show(GTK_WIDGET(window2_login));
    }
        
}
/******************************************
Function:退出提示界面按钮回调函数
out:无
return:void
******************************************/
void on_button_back_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window2_login));
}
/******************************************
Function:取消登录按钮回调函数
out:无
return:void
******************************************/
void on_button_login_cancel_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window_login));
}

