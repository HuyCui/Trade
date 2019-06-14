/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:物流信息展示界面回调函数声明
Mail:956622792@qq.com
******************************************/
#ifndef WULIUCONT_H
#define WULIUCONT_H

/******************************************
Function:物流信息展示按钮响应函数
out:无
return:void
******************************************/
void on_button_wuliu_sure_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:物流信息展示取消按钮响应函数
out:无
return:void
******************************************/
void on_button_wuliu_cancel_clicked(GtkObject* widget,gpointer user_data);
/******************************************
Function:退出错误信息提示按钮响应函数
out:无
return:void
******************************************/
void on_button_wuliu_cancel_clicked(GtkObject* widget,gpointer user_data);
void on_button1_wuliu_close_clicked(GtkObject* widget,gpointer user_data);
void on_button2_wuliu_close_clicked(GtkObject* widget,gpointer user_data);
void on_button3_wuliu_close_clicked(GtkObject* widget,gpointer user_data);

#endif
