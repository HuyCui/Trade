/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:物流信息显示主界面
Mail:
******************************************/
#ifndef WINDOW_WULIU_H
#define WINDOW_WULIU_H
#include <gtk/gtk.h>
#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
GtkWindow *window_wuliu;   //物流信息显示界面
GtkWindow *window1_wuliu;
GtkWindow *window2_wuliu;
GtkWindow *window3_wuliu;
GtkEntry *entry_short;    //最短时间显示文本框
GtkEntry *entry_short_time;  //最短时间显示路径
GtkEntry *entry_cheap;    //最低花费显示文本框
GtkEntry *entry_cheap_cost;   //最少花费路径显示
GtkComboBox *combobox1_wuliu;    //城市选择复选框
GtkComboBox *combobox2_wuliu; //城市选择复选框
GtkButton *button_wuliu_cancel;  //物流显示取消
GtkButton *button_wuliu_sure;   //确认选择按钮
GtkButton *button1_wuliu_close;   //关闭错误信息提示页面
GtkButton *button2_wuliu_close;
GtkButton *button3_wuliu_close;

/******************************************
Function:物流信息界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void wuliu_get_widgets(GtkBuilder* gb);

#endif
