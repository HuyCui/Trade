/******************************************
Copyright:SDUT
Author:孙昊
Date:2018-01-18
Describe:登录显示界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_login.h"
/******************************************
Function:将登录界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void login_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_login);	
	w_(gb,ENTRY,entry_id);
	w_(gb,ENTRY,entry_password);
	w_(gb,BUTTON, button_login);				
	w_(gb,BUTTON, button_login_cancel);
	w_(gb,WINDOW,window2_login);
	w_(gb,BUTTON, button_back);

}
