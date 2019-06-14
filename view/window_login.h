/******************************************
Copyright:SDUT
Author:孙昊
Date:2018-01-18
Describe:登录显示界面
Mail:956622792@qq.com
******************************************/
#ifndef _WINDOW_LOGIN_H
#define _WINDOW_LOGIN_H
#include <gtk/gtk.h>

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
GtkWindow *window_login;    //登录页面
GtkEntry *entry_id;    //用户名输入文本框
GtkEntry *entry_password;  //密码输入文本框
GtkButton *button_login;  //登录按钮
GtkButton *button_login_cancel;   //登录取消按钮
GtkWindow *window2_login;   //错误信息提示
GtkButton *button_back;  //错误窗口返回

/******************************************
Function:将登录界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void login_get_widgets(GtkBuilder* gb);

#endif
