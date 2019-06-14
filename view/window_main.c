/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:显示主界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_main.h"


/******************************************
Function:初始化树视图
in:  
	GtkWidget * list树视图的列表对象
out:无
return:void
******************************************/
void init_list(GtkWidget * list) 
{
	GtkCellRenderer *rend;
	GtkTreeViewColumn *col;
	rend=gtk_cell_renderer_text_new();
	//给树视图设置表头
	col=gtk_tree_view_column_new_with_attributes("商品名称",rend,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("卖家地点",rend,"text",1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("存货",rend,"text",2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    col=gtk_tree_view_column_new_with_attributes("价格",rend,"text",3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("品牌",rend,"text",4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("材质",rend,"text",5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("形状",rend,"text",6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("颜色",rend,"text",7,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
	col=gtk_tree_view_column_new_with_attributes("功能关键字",rend,"text",8,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
}
/******************************************
Function:将主界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void main_get_widgets(GtkBuilder* gb)
{
	w_(gb,WINDOW,window_main);	
	w_(gb,ENTRY,entry_search);
	w_(gb,TREE_VIEW,treeview_goods);
	w_(gb,LIST_STORE,liststore_select);
	w_(gb,LIST_STORE,liststore_goods);
	w_(gb,BUTTON, button_search);				
	w_(gb,BUTTON, button_load);
	w_(gb,BUTTON, button_sort);
	w_(gb,BUTTON, button_change);
	w_(gb,BUTTON, button_wuliu);
	w_(gb,BUTTON, button_help);
	w_(gb,BUTTON, button_decrease);
	w_(gb,BUTTON, button_add);
	w_(gb,BUTTON, button_next);
	w_(gb,BUTTON, button_pre);
	w_(gb,BUTTON, button_pre_sort);
	w_(gb,BUTTON, button_pre_search);
	w_(gb,BUTTON, button_next_sort);
	w_(gb,BUTTON, button_next_search);
	w_(gb,COMBO_BOX, combox_select);
	w_(gb,SCROLLED_WINDOW, scrolledwindow);
}





