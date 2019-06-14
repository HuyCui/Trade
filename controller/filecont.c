/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:文件选择界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>

#include "filecont.h"
#include "myview.h"


/******************************************
Function:取消按钮回调函数
out:无
return:void
******************************************/
void on_button_file_cancel_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_hide(GTK_WIDGET(window_file));
}

/******************************************
Function:确认按钮回调函数
out:无
return:void
******************************************/
void on_button_file_sure_clicked(GtkObject* widget,gpointer user_date)
{
	const gchar *s = gtk_file_chooser_get_filename(filechooser_window);
	gtk_entry_set_text(entry_load_show, s);
	gtk_widget_hide(GTK_WIDGET(window_file));
}

