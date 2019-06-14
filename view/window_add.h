/******************************************
Copyright:SDUT
Author:李晓龙
Date:2018-01-18
Describe:商品上架界面控件的声明
Mail:956622792@qq.com
******************************************/
#ifndef WINDOW_ADD_H
#define WINDOW_ADD_H

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))

GtkWindow *window1_add;    //错误返回信息窗口
GtkWindow *window2_add;
GtkWindow *window3_add;
GtkButton *button_sure_add;  //确认添加按钮
GtkButton *button_cancel_add;  //取消添加按钮
GtkButton *button_return_add; //错误信息页面返回按钮
GtkEntry* entry_name_add; //输入姓名文本框
GtkEntry* entry_address_add;  //城市输入文本框
GtkEntry* entry_rest_add;  //输入存货量文本框
GtkEntry* entry_price_add;  //输入价格文本框
GtkEntry* entry_sign_add;    //输入品牌文本框
GtkEntry* entry_material_add;  //输入材料文本框
GtkEntry* entry_shape_add; //输入形状文本框
GtkEntry* entry_color_add;  //输入颜色文本框
GtkEntry* entry_describe_add; //输入商品描述文本框
GtkButton *button_change_add;
GtkButton *button_nchange_add;
/******************************************
Function:将上架界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void add_get_widgets(GtkBuilder* gb);


#endif
