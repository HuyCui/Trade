/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:主界面回调函数
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myview.h"
#include "mycontrol.h"
#include "hash.h"
#include "linklist.h"
#include "sort.h"
#include "del.h"

link p_sort;    //排序的头指针
link p_search;   //查询的头指针
int page = 1, page1 = 1, page2 = 1;   //记录页码
int select_flag;   //记录查询哪个关键字
clock_t begin, end;   //用来计时的变量
double runtime;
/******************************************
Function:搜索按钮回调函数
out:无
return:void
******************************************/
void on_button_search_clicked(GtkObject* widget,gpointer user_date)
{
	char* str;
	const gchar *str1;
	int flag;
	//link p;
	char str_restnum[20], str_price[20];
	if(!gtk_combo_box_get_active_text(combox_select))
	{
		gtk_entry_set_text(entry_search,"请选择内容！");
		return ;		
	}
	str = gtk_combo_box_get_active_text(combox_select);
	str1 = gtk_entry_get_text(entry_search);
	//建立不同元素的存储链表
	begin = clock();
	if(strcmp(str,"地点") == 0)
	{
		flag = wuliu_change1(str1);
		p_search = city_head[flag]->next;
		select_flag = 1;
	}
	else if(strcmp(str, "品牌") == 0)
	{
		flag = pinpai_change(str1);
		p_search = pinpai_head[flag]->next;
		select_flag = 2;
	}
	else if(strcmp(str, "颜色") == 0)
	{
		flag = color_change(str1);
		p_search = color_head[flag]->next;
		select_flag = 3;
	}
	else if(strcmp(str, "材质") == 0)
	{
		flag = caizhi_change(str1);
		p_search = caizhi_head[flag]->next;
		select_flag = 4;
	}
	gtk_list_store_clear(liststore_goods);
	int j = 0;
	while(p_search && j < 14)//将储存在链表中的信息输出到树视图中
	{
		GtkTreeIter iter;
		sprintf(str_restnum, "%d", p_search->obj.restnum);//将库存转化为字符串
		sprintf(str_price, "%d", p_search->obj.price);//将价格转化为字符串
		gtk_list_store_append(liststore_goods, &iter);
		gtk_list_store_set(liststore_goods, &iter, 0, p_search->obj.name, -1);
		gtk_list_store_set(liststore_goods, &iter, 1, p_search->obj.city, -1);
		gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
		gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
		gtk_list_store_set(liststore_goods, &iter, 4, p_search->obj.pinpai, -1);
		gtk_list_store_set(liststore_goods, &iter, 5, p_search->obj.caizhi, -1);
		gtk_list_store_set(liststore_goods, &iter, 6, p_search->obj.shape, -1);
		gtk_list_store_set(liststore_goods, &iter, 7, p_search->obj.color, -1);
		gtk_list_store_set(liststore_goods, &iter, 8, p_search->obj.use, -1);
		p_search = p_search->next;
		j++;
	}
	end = clock();
	runtime = end-begin;
	runtime /= CLOCKS_PER_SEC;
	printf("搜索用的时间为%lfs\n", runtime);
	if(strcmp(str,"地点") == 0)//建立不同元素的哈希链表
	{
		flag = wuliu_change1(str1);
		p_sort = sortList(city_head[flag]);
	}
	else if(strcmp(str, "品牌") == 0)
	{
		flag = pinpai_change(str1);
		p_sort = sortList(pinpai_head[flag]);
	}
	else if(strcmp(str, "颜色") == 0)
	{
		flag = color_change(str1);
		p_sort = sortList(color_head[flag]);
	}
	else if(strcmp(str, "材质") == 0)
	{
		flag = caizhi_change(str1);
		p_sort = sortList(caizhi_head[flag]);
	}
	
}
/******************************************
Function：载入按钮回调函数
out:无
return:void
******************************************/
void on_button_load_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_show(GTK_WIDGET(window_load));
}
/******************************************
Function:修改按钮回调函数
out:无
return:void
******************************************/
void on_button_change_clicked(GtkObject* widget,gpointer user_date)
{
	GtkTreeIter iter = {0};
	GtkTreeStore *store = NULL;
	GtkTreeSelection *selection = NULL;
	selection = gtk_tree_view_get_selection(treeview_goods);
    if(!gtk_tree_selection_get_selected(selection, (GtkTreeModel**)&store, &iter))
	{
		gtk_widget_show(GTK_WIDGET(window2_change));
		return;
	}
	gtk_widget_show(GTK_WIDGET(window_change));
}
/******************************************
Function:排序按钮回调函数
out:无
return:void
******************************************/
void on_button_sort_clicked(GtkObject* widget,gpointer user_date)
{
	char str_restnum[20], str_price[20];
	gtk_list_store_clear(liststore_goods);
	int j = 0;
	begin = clock();
	while(p_sort->next && j < 14)//将排序后的数据输出
	{
		GtkTreeIter iter;
		sprintf(str_restnum, "%d", p_sort->obj.restnum);
		sprintf(str_price, "%d", p_sort->obj.price);
		gtk_list_store_append(liststore_goods, &iter);
		gtk_list_store_set(liststore_goods, &iter, 0, p_sort->obj.name, -1);
		gtk_list_store_set(liststore_goods, &iter, 1, p_sort->obj.city, -1);
		gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
		gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
		gtk_list_store_set(liststore_goods, &iter, 4, p_sort->obj.pinpai, -1);
		gtk_list_store_set(liststore_goods, &iter, 5, p_sort->obj.caizhi, -1);
		gtk_list_store_set(liststore_goods, &iter, 6, p_sort->obj.shape, -1);
		gtk_list_store_set(liststore_goods, &iter, 7, p_sort->obj.color, -1);
		gtk_list_store_set(liststore_goods, &iter, 8, p_sort->obj.use, -1);
		p_sort = p_sort->next;
		j++;
	}
	end = clock();
	runtime = end-begin;
	runtime /= CLOCKS_PER_SEC;
	printf("排序用的时间为%lfs\n", runtime);
}
/******************************************
Function:物流信息按钮回调函数
out:无
return:void
******************************************/
void on_button_wuliu_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_show(GTK_WIDGET(window_wuliu));
}
/******************************************
Function:确认添加按钮回调函数
out:无
return:void
******************************************/
void on_button_add_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_show(GTK_WIDGET(window1_add));
}
/******************************************
Function:商品下架按钮回调函数
out:无
return:void
******************************************/
void on_button_decrease_clicked(GtkObject* widget,gpointer user_date)
{
	//首先查看是否有信息被选中
    GtkTreeIter iter            = {0}; 
    GValue value[9]             = {0};  
   	GtkTreeStore* store         = NULL;
	GtkTreeSelection* selection = NULL;	 
	selection = gtk_tree_view_get_selection(treeview_goods);//从视图中得到选择的信息
	if(!gtk_tree_selection_get_selected(selection, (GtkTreeModel**)&store, &iter)) 
	{
		return;
	}
	selection = gtk_tree_view_get_selection(treeview_goods);
	gtk_tree_selection_get_selected(selection, (GtkTreeModel**)&store, &iter);
	const gchar *str1, *str2, *str3, *str4, *str5;
	//从树视图中得到要删除的商品信息
	//将其从储存链表中删除
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 0, &value[0]);
	str1 = g_value_get_string(&value[0]);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 1, &value[1]);
	str2 = g_value_get_string(&value[1]);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 4, &value[4]);
	str3 = g_value_get_string(&value[4]);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 5, &value[5]);
	str4 = g_value_get_string(&value[5]);
	gtk_tree_model_get_value(GTK_TREE_MODEL(store), &iter, 7, &value[7]);
	str5 = g_value_get_string(&value[7]);
	delete(city_head, str1, wuliu_change1(str2));
	delete(pinpai_head, str1, pinpai_change(str3));
	delete(caizhi_head, str1, caizhi_change(str4));
	delete(color_head, str1, color_change(str5));
}
/******************************************
Function:帮助按钮响应函数
out:无
return:void
******************************************/
void on_button_help_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_show(GTK_WIDGET(window_help));
}
/******************************************
Function:错误信息提示界面关闭按钮响应函数
out:无
return:void
******************************************/
void on_button2_change_close_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window2_change));
}
void on_button_next_clicked(GtkObject* widget,gpointer user_date)
{
		page++;
		GtkTreeIter iter;
		gtk_list_store_clear(liststore_goods);
		int j = 0;
		char str_restnum[50], str_price[50];
		while(j < 14 && listhead)
		{
			sprintf(str_restnum, "%d", listhead->obj.restnum);
			sprintf(str_price, "%d", listhead->obj.price);
			gtk_list_store_append(liststore_goods, &iter);
			gtk_list_store_set(liststore_goods, &iter, 0, listhead->obj.name, -1);
			gtk_list_store_set(liststore_goods, &iter, 1, listhead->obj.city, -1);
			gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
			gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
			gtk_list_store_set(liststore_goods, &iter, 4, listhead->obj.pinpai, -1);
			gtk_list_store_set(liststore_goods, &iter, 5, listhead->obj.caizhi, -1);
			gtk_list_store_set(liststore_goods, &iter, 6, listhead->obj.shape, -1);
			gtk_list_store_set(liststore_goods, &iter, 7, listhead->obj.color, -1);
			gtk_list_store_set(liststore_goods, &iter, 8, listhead->obj.use, -1);
			listhead = listhead->next;
			j++;
		}
}
void on_button_pre_clicked(GtkObject* widget,gpointer user_date)
{
		if(page == 1)
			return ;
		else 
			page--;
		GtkTreeIter iter;
		gtk_list_store_clear(liststore_goods);
		int j = 0;
		char str_restnum[50], str_price[50];
		for(j = 0; j < 27; j++)
		{
			listhead = listhead->pre;
		}
		j = 0;
		while(j < 14 )
		{
			sprintf(str_restnum, "%d", listhead->obj.restnum);
			sprintf(str_price, "%d", listhead->obj.price);
			gtk_list_store_append(liststore_goods, &iter);
			gtk_list_store_set(liststore_goods, &iter, 0, listhead->obj.name, -1);
			gtk_list_store_set(liststore_goods, &iter, 1, listhead->obj.city, -1);
			gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
			gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
			gtk_list_store_set(liststore_goods, &iter, 4, listhead->obj.pinpai, -1);
			gtk_list_store_set(liststore_goods, &iter, 5, listhead->obj.caizhi, -1);
			gtk_list_store_set(liststore_goods, &iter, 6, listhead->obj.shape, -1);
			gtk_list_store_set(liststore_goods, &iter, 7, listhead->obj.color, -1);
			gtk_list_store_set(liststore_goods, &iter, 8, listhead->obj.use, -1);
			listhead = listhead->next;
			j++;
		}
}
void on_button_next_sort_clicked(GtkObject* widget,gpointer user_date)
{
	char str_restnum[20], str_price[20];
	gtk_list_store_clear(liststore_goods);
	int j = 0;
	page1++;
	while(p_sort->next && j < 14)//将排序后的数据输出
	{
		GtkTreeIter iter;
		sprintf(str_restnum, "%d", p_sort->obj.restnum);
		sprintf(str_price, "%d", p_sort->obj.price);
		gtk_list_store_append(liststore_goods, &iter);
		gtk_list_store_set(liststore_goods, &iter, 0, p_sort->obj.name, -1);
		gtk_list_store_set(liststore_goods, &iter, 1, p_sort->obj.city, -1);
		gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
		gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
		gtk_list_store_set(liststore_goods, &iter, 4, p_sort->obj.pinpai, -1);
		gtk_list_store_set(liststore_goods, &iter, 5, p_sort->obj.caizhi, -1);
		gtk_list_store_set(liststore_goods, &iter, 6, p_sort->obj.shape, -1);
		gtk_list_store_set(liststore_goods, &iter, 7, p_sort->obj.color, -1);
		gtk_list_store_set(liststore_goods, &iter, 8, p_sort->obj.use, -1);
		p_sort = p_sort->next;
		j++;
	}
}
void on_button_pre_sort_clicked(GtkObject* widget,gpointer user_date)
{
		if(page1 == 1)
			return ;
		else 
			page1--;
		GtkTreeIter iter;
		gtk_list_store_clear(liststore_goods);
		int j = 0;
		char str_restnum[50], str_price[50];
		for(j = 0; j < 27; j++)
		{
			p_sort = p_sort->pre;
		}
		j = 0;
		while(j < 14 )
		{
			sprintf(str_restnum, "%d", p_sort->obj.restnum);
			sprintf(str_price, "%d", p_sort->obj.price);
			gtk_list_store_append(liststore_goods, &iter);
			gtk_list_store_set(liststore_goods, &iter, 0, p_sort->obj.name, -1);
			gtk_list_store_set(liststore_goods, &iter, 1, p_sort->obj.city, -1);
			gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
			gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
			gtk_list_store_set(liststore_goods, &iter, 4, p_sort->obj.pinpai, -1);
			gtk_list_store_set(liststore_goods, &iter, 5, p_sort->obj.caizhi, -1);
			gtk_list_store_set(liststore_goods, &iter, 6, p_sort->obj.shape, -1);
			gtk_list_store_set(liststore_goods, &iter, 7, p_sort->obj.color, -1);
			gtk_list_store_set(liststore_goods, &iter, 8, p_sort->obj.use, -1);
			p_sort = p_sort->next;
			j++;
		}
}

void on_button_next_search_clicked(GtkObject* widget,gpointer user_date)
{
	char str_restnum[20], str_price[20];
	gtk_list_store_clear(liststore_goods);
	int j = 0;
	page2++;
	while(p_search && j < 14)//将储存在链表中的信息输出到树视图中
	{
		GtkTreeIter iter;
		sprintf(str_restnum, "%d", p_search->obj.restnum);//将库存转化为字符串
		sprintf(str_price, "%d", p_search->obj.price);//将价格转化为字符串
		gtk_list_store_append(liststore_goods, &iter);
		gtk_list_store_set(liststore_goods, &iter, 0, p_search->obj.name, -1);
		gtk_list_store_set(liststore_goods, &iter, 1, p_search->obj.city, -1);
		gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
		gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
		gtk_list_store_set(liststore_goods, &iter, 4, p_search->obj.pinpai, -1);
		gtk_list_store_set(liststore_goods, &iter, 5, p_search->obj.caizhi, -1);
		gtk_list_store_set(liststore_goods, &iter, 6, p_search->obj.shape, -1);
		gtk_list_store_set(liststore_goods, &iter, 7, p_search->obj.color, -1);
		gtk_list_store_set(liststore_goods, &iter, 8, p_search->obj.use, -1);
		p_search = p_search->next;
		j++;
	}
	
}
void on_button_pre_search_clicked(GtkObject* widget,gpointer user_date)
{
		if(page2 == 1)
			return ;
		else 
			page2--;
		GtkTreeIter iter;
		gtk_list_store_clear(liststore_goods);
		int j = 0;
		char str_restnum[50], str_price[50];
		for(j = 0; j < 27; j++)
		{
			p_search = p_search->pre;
		}
		j = 0;
		while(p_search && j < 14)//将储存在链表中的信息输出到树视图中
	{
		GtkTreeIter iter;
		sprintf(str_restnum, "%d", p_search->obj.restnum);//将库存转化为字符串
		sprintf(str_price, "%d", p_search->obj.price);//将价格转化为字符串
		gtk_list_store_append(liststore_goods, &iter);
		gtk_list_store_set(liststore_goods, &iter, 0, p_search->obj.name, -1);
		gtk_list_store_set(liststore_goods, &iter, 1, p_search->obj.city, -1);
		gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
		gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
		gtk_list_store_set(liststore_goods, &iter, 4, p_search->obj.pinpai, -1);
		gtk_list_store_set(liststore_goods, &iter, 5, p_search->obj.caizhi, -1);
		gtk_list_store_set(liststore_goods, &iter, 6, p_search->obj.shape, -1);
		gtk_list_store_set(liststore_goods, &iter, 7, p_search->obj.color, -1);
		gtk_list_store_set(liststore_goods, &iter, 8, p_search->obj.use, -1);
		p_search = p_search->next;
		j++;
	}
}
