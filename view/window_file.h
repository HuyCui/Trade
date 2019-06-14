/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:文件读取显示界面
Mail:956622792@qq.com
******************************************/
#ifndef _WINDOW_FILE_H
#define _WINDOW_FILE_H

GtkWindow *window_file;       //文件窗口
GtkFileChooser *filechooser_window;  //文件选择页面
GtkButton *button_file_sure;   //确认选择按钮
GtkButton *button_file_cancel;  //取消选择按钮
/******************************************
Function:将文件读物界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void file_get_widgets(GtkBuilder* gb);

#endif
