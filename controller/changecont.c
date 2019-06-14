/******************************************
Copyright:SDUT
Author:王姗姗
Date:2018-01-18
Describe:修改信息界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include "myview.h"
#include "mycontrol.h"
#include "changecont.h"


/******************************************
Function:树视图信息选中回调函数
out:无
return:void
******************************************/
void on_treeview_goods_cursor_changed(GtkObject* widget,gpointer user_data)
{
	GValue value[9]             = {0};
	GtkTreeIter iter            = {0}; 
   	GtkTreeStore* store         = NULL;
	GtkTreeSelection* selection = NULL;	 
	selection = gtk_tree_view_get_selection(treeview_goods);
	gtk_tree_selection_get_selected(selection, (GtkTreeModel**)&store, &iter);
	//获取每一列信息，然后显示到录入框
	const gchar *str;
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 0, &value[0]);
	str = g_value_get_string(&value[0]);
	gtk_entry_set_text(entry_name_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 1, &value[1]);
	str = g_value_get_string(&value[1]);
	gtk_entry_set_text(entry_address_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 2, &value[2]);
	str = g_value_get_string(&value[2]);
	gtk_entry_set_text(entry_rest_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 3, &value[3]);
	str = g_value_get_string(&value[3]);
	gtk_entry_set_text(entry_price_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 4, &value[4]);
	str = g_value_get_string(&value[4]);
	gtk_entry_set_text(entry_singal_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 5, &value[5]);
	str = g_value_get_string(&value[5]);
	gtk_entry_set_text(entry_material_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 6, &value[6]);
	str = g_value_get_string(&value[6]);
	gtk_entry_set_text(entry_body_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 7, &value[7]);
	str = g_value_get_string(&value[7]);
	gtk_entry_set_text(entry_color_change,str);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 8, &value[8]);
	str = g_value_get_string(&value[8]);
	gtk_entry_set_text(entry_fountion_change,str);
}

/******************************************
Function:确认修改按钮回调函数
out:无
return:void
******************************************/
void on_button_change_sure_clicked(GtkObject* widget,gpointer user_data)
{
	//将录入框中的内容替换选择的信息
	GtkTreeIter iter            = {0}; 
   	GtkTreeStore* store         = NULL;
	GtkTreeSelection* selection = NULL;	 
	selection = gtk_tree_view_get_selection(treeview_goods);
	gtk_tree_selection_get_selected(selection, (GtkTreeModel**)&store, &iter);
	//将修改后的信息重新录入到树视图当中
	gtk_list_store_set(liststore_goods, &iter, 0, gtk_entry_get_text(entry_name_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 1, gtk_entry_get_text(entry_address_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 2, gtk_entry_get_text(entry_rest_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 3, gtk_entry_get_text(entry_price_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 4, gtk_entry_get_text(entry_singal_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 5, gtk_entry_get_text(entry_material_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 6, gtk_entry_get_text(entry_body_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 7, gtk_entry_get_text(entry_color_change), -1);
	gtk_list_store_set(liststore_goods, &iter, 8, gtk_entry_get_text(entry_fountion_change), -1);
	gtk_widget_show(GTK_WIDGET(window1_change));
}
/******************************************
Function:取消修改按钮回调函数
out:无
return:void
******************************************/
void on_button_change_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window_change));
}
/******************************************
Function:退出提示信息界面按钮回调函数
out:无
return:void
******************************************/
void on_button1_change_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window1_change));
	gtk_widget_hide(GTK_WIDGET(window_change));
}

