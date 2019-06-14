/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:修改信息显示界面
Mail:956622792@qq.com
******************************************/
#ifndef WINDOW_CHANGE_H
#define WINDOW_CHANGE_H


#include <gtk/gtk.h>
#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
GtkWindow *window_change;    //修改信息界面
GtkWindow *window2_change;   //错误信息返回界面
GtkEntry *entry_name_change;  //输入姓名文本框
GtkEntry *entry_color_change;  //输入颜色文本框
GtkEntry *entry_singal_change; //输入品牌文本框
GtkEntry *entry_body_change;  //输入形状文本框
GtkEntry *entry_rest_change;  //输入存货量文本框
GtkEntry *entry_material_change;  //输入材质文本框
GtkEntry *entry_price_change;    //输入价格文本框
GtkEntry *entry_address_change;  //输入地址文本框
GtkEntry *entry_fountion_change;  //输入功能描述文本框
GtkButton *button_change_sure;   //修改确认按钮
GtkButton *button_change_close;   //修改取消按钮
GtkWindow *window1_change;     
GtkButton *button1_change_close;   //退出提示页面按钮
GtkButton *button2_change_close;   //退出提示页面按钮
/******************************************
Function:将修改信息界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void change_get_widgets(GtkBuilder* gb);

#endif
