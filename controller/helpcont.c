/******************************************
Copyright:SDUT
Author:许荣耀
Date:2018-01-18
Describe:帮助界面回调函数
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>

#include "helpcont.h"
#include "myview.h"

/******************************************
Function：返回按钮回调函数
out:无
return:void
******************************************/
void on_button_help_cancel_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_hide(GTK_WIDGET(window_help));
}

