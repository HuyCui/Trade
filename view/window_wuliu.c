/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:物流信息显示主界面
Mail:
******************************************/
#include <gtk/gtk.h>
#include "window_wuliu.h"
//----- 根据GtkBuilder对象，获得glade中对应的计算器中的控件------

/******************************************
Function:物流信息界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void wuliu_get_widgets(GtkBuilder* gb)
{
	w_(gb, WINDOW, window_wuliu);
	w_(gb, WINDOW, window1_wuliu);
	w_(gb, WINDOW, window2_wuliu);
	w_(gb, WINDOW, window3_wuliu);
	w_(gb, BUTTON, button_wuliu_cancel);
	w_(gb, BUTTON, button_wuliu_sure);
	w_(gb, BUTTON, button1_wuliu_close);
	w_(gb, BUTTON, button2_wuliu_close);
	w_(gb, BUTTON, button3_wuliu_close);
	w_(gb, ENTRY, entry_short);
	w_(gb, ENTRY, entry_short_time);
	w_(gb, ENTRY, entry_cheap);
	w_(gb, ENTRY, entry_cheap_cost);
	w_(gb, COMBO_BOX, combobox1_wuliu);
	w_(gb, COMBO_BOX, combobox2_wuliu);
}
