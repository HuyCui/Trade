/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:主函数，调用显示界面
Mail:956622792@qq.com
******************************************/
#include <stdio.h>
#include <gtk/gtk.h>
#include "mycontrol.h"
#include "myview.h"

int main(int argc,char* argv[])
{
	GtkBuilder *gb;        //建立GtkBuilder对象
	gtk_init(&argc,&argv);
	gb = gtk_load_glade("./view/window_main.glade");    //载入登录界面
	if(gb==NULL) return -1;
	myview_get_widgets(gb);
	cal_widget_init();
	gtk_main();         //循环显示页面，使页面不会消失
	return 0;
}
