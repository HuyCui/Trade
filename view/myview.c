/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:界面控件的声明、将glade与代码相链接
Mail:956622792@qq.com
******************************************/
#include <stdio.h>
#include "myview.h"
/******************************************
Function:载入glade文件
in:  
	gchar* filename：界面文件名
out:无
return:gb GtkBuilder对象
******************************************/
GtkBuilder* gtk_load_glade(gchar* filename)
{
	GtkBuilder *gb;
	gb=gtk_builder_new();
	if(!gtk_builder_add_from_file(gb,filename,NULL)) 			
		return NULL;
	gtk_builder_connect_signals(gb,NULL);
	return gb;
}
/******************************************
Function:将galde控件与代码相链接
in:  
	GtkBuilder* gb：GtkBuilder对象
out:无
return:void
******************************************/
void myview_get_widgets(GtkBuilder* gb)
{
	main_get_widgets(gb);          //主界面
	load_get_widgets(gb);          //载入界面
	help_get_widgets(gb);          //帮助界面
	login_get_widgets(gb);         //登录界面
	file_get_widgets(gb);          //文件选择界面
	wuliu_get_widgets(gb);         //物流信息界面
	change_get_widgets(gb);        //修改信息界面
	add_get_widgets(gb);           //商品上架界面
}
/******************************************
Function:显示glade页面
in: 无
out:无
return:void
******************************************/
void cal_widget_init()
{
	gtk_widget_show(GTK_WIDGET(window_login));
}

