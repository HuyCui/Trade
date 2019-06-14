/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:修改信息显示界面
Mail:956622792@qq.com
******************************************/
#include "window_change.h"
/******************************************
Function:将修改信息界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void change_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_change);
	w_(gb,WINDOW,window1_change);
	w_(gb,WINDOW,window2_change);
	w_(gb,BUTTON,button_change_sure);
	w_(gb,BUTTON,button_change_close);
	w_(gb,BUTTON,button1_change_close);
	w_(gb,BUTTON,button2_change_close);
	w_(gb,ENTRY,entry_name_change);
	w_(gb,ENTRY,entry_color_change);
	w_(gb,ENTRY,entry_singal_change);
	w_(gb,ENTRY,entry_body_change);
	w_(gb,ENTRY,entry_rest_change);
	w_(gb,ENTRY,entry_material_change);
	w_(gb,ENTRY,entry_price_change);
	w_(gb,ENTRY,entry_address_change);
	w_(gb,ENTRY,entry_fountion_change);
}
