/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:载入界面声明
Mail:956622792@qq.com
******************************************/
#ifndef _WINDOW_LOAD_H
#define _WINDOW_LOAD_H
#include <gtk/gtk.h>

GtkWindow *window_load;     //窗口界面
GtkEntry *entry_load_show;   //显示文件路径文本框
GtkButton *button_file_choose;  //文件选择按钮
GtkComboBox *combobox_load;   //载入方式复选框
GtkButton *button_load_sure;  //确定载入按钮
GtkButton *button_load_cancel;  //取消载入按钮
/******************************************
Function:载入界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void load_get_widgets(GtkBuilder* gb);


#endif
