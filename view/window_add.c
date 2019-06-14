/******************************************
Copyright:SDUT
Author:李晓龙
Date:2018-01-18
Describe:商品上架界面的声明
Mail:956622792@qq.com
******************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "window_add.h"
#define BUFSIZE 1024
/******************************************
Function:将上架界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void add_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window1_add);	
	w_(gb,WINDOW,window2_add);
	w_(gb,WINDOW,window3_add);
	w_(gb,BUTTON,button_sure_add);
	w_(gb,BUTTON,button_cancel_add);
	w_(gb,BUTTON,button_return_add);
	w_(gb,BUTTON,button_change_add);
	w_(gb,BUTTON,button_nchange_add);
	w_(gb,ENTRY,entry_address_add);
	w_(gb,ENTRY,entry_rest_add);
	w_(gb,ENTRY,entry_price_add);
	w_(gb,ENTRY,entry_sign_add);
	w_(gb,ENTRY,entry_material_add);
	w_(gb,ENTRY,entry_shape_add);
	w_(gb,ENTRY,entry_color_add);
	w_(gb,ENTRY,entry_describe_add);
	w_(gb,ENTRY,entry_name_add);
}




