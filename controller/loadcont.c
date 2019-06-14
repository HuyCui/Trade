/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:信息载入界面
Mail:956622792@qq.com
******************************************/
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "loadcont.h"
#include "myview.h"
#include "linklist.h"
#include "hash.h"

/******************************************
Function:文件选择按钮回调函数
out:无
return:void
******************************************/
void on_button_file_choose_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_show(GTK_WIDGET(window_file));
}

/******************************************
Function:取消载入按钮回调函数
out:无
return:void
******************************************/
void on_button_load_cancel_clicked(GtkObject* widget,gpointer user_date)
{
	gtk_widget_hide(GTK_WIDGET(window_load));
}


/******************************************
Function:确认载入按钮回调函数
out:无
return:void
******************************************/
void on_button_load_sure_clicked(GtkObject* widget,gpointer user_date)
{
	clock_t begin, end;
	int j = 0;
	double runtime;
	const gchar* str;
	char name[30], address[20], pinpai[20], caizhi[20], shape[20], color[10], use[30];
	char str_restnum[10], str_price[10];
	int restnum, price;
	if(!gtk_combo_box_get_active_text(combobox_load))
	{
		//gtk_widget_show(GTK_WIDGET(window_file));
		return ;		
	}
	str = gtk_combo_box_get_active_text(combobox_load);
	if(strcmp(str, "库存信息载入") == 0)
	{
		const gchar *keys = gtk_entry_get_text(entry_load_show);
		FILE *fp = fopen(keys, "r+");
		GtkTreeIter iter;
		link tail;
		head = initLink();
		listhead = head;
		tail = head;
		struct info obj={};
		gtk_list_store_clear(liststore_goods);
		begin = clock();
		
		while(fscanf(fp, "%[^;];%[^;];%d;%d;%[^;];%[^;];%[^;];%[^;];%s\n", obj.name, obj.city, &obj.restnum, &obj.price, obj.pinpai, obj.caizhi, obj.shape, obj.color, obj.use) != EOF)
		{
			
			//printf("%s-%s-%d-%d-%s-%s-%s-%s-%s\n", obj.name, obj.city, obj.restnum, obj.price, obj.pinpai, obj.caizhi, obj.shape, obj.color, obj.use);
			tail = createLink(tail, obj);
			sprintf(str_restnum, "%d", obj.restnum);
			sprintf(str_price, "%d", obj.price);
			if(j < 14)
			{
				gtk_list_store_append(liststore_goods, &iter);
				gtk_list_store_set(liststore_goods, &iter, 0, obj.name, -1);
				gtk_list_store_set(liststore_goods, &iter, 1, obj.city, -1);
				gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
				gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
				gtk_list_store_set(liststore_goods, &iter, 4, obj.pinpai, -1);
				gtk_list_store_set(liststore_goods, &iter, 5, obj.caizhi, -1);
				gtk_list_store_set(liststore_goods, &iter, 6, obj.shape, -1);
				gtk_list_store_set(liststore_goods, &iter, 7, obj.color, -1);
				gtk_list_store_set(liststore_goods, &iter, 8, obj.use, -1);
				listhead = listhead->next;
				j++;
			}
		}
		listtail = tail;
		end = clock();
		runtime = end-begin;
		runtime /= CLOCKS_PER_SEC;
		printf("载入并加载到树视图中的运行时间为%lfs\n", runtime);
		fclose(fp);
	}
	else if(strcmp(str, "批量信息载入") == 0)
	{
		const gchar *keys = gtk_entry_get_text(entry_load_show);
		FILE *fp = fopen(keys, "r+");
		GtkTreeIter iter;
		link tail;
		tail = listtail;
		struct info obj;
		
		begin = clock();
		while(fscanf(fp, "%[^;];%[^;];%d;%d;%[^;];%[^;];%[^;];%[^;];%s%*c", obj.name, obj.city, &obj.restnum, &obj.price, obj.pinpai, obj.caizhi, obj.shape, obj.color, obj.use) != EOF)
		{
			tail = createLink(tail, obj);
			//printf("%s-%s-%d-%d-%s-%s-%s-%s-%s\n", obj.name, obj.city, obj.restnum, obj.price, obj.pinpai, obj.caizhi, obj.shape, obj.color, obj.use);
			sprintf(str_restnum, "%d", obj.restnum);
			sprintf(str_price, "%d", obj.price);
			gtk_list_store_append (liststore_goods, &iter);
			gtk_list_store_set(liststore_goods, &iter, 0, obj.name, -1);
			gtk_list_store_set(liststore_goods, &iter, 1, obj.city, -1);
			gtk_list_store_set(liststore_goods, &iter, 2, str_restnum, -1);
			gtk_list_store_set(liststore_goods, &iter, 3, str_price, -1);
			gtk_list_store_set(liststore_goods, &iter, 4, obj.pinpai, -1);
			gtk_list_store_set(liststore_goods, &iter, 5, obj.caizhi, -1);
			gtk_list_store_set(liststore_goods, &iter, 6, obj.shape, -1);
			gtk_list_store_set(liststore_goods, &iter, 7, obj.color, -1);
			gtk_list_store_set(liststore_goods, &iter, 8, obj.use, -1);
		}
		listtail = tail;
		end = clock();
		runtime = end-begin;
		runtime /= CLOCKS_PER_SEC;
		printf("载入并加载到树视图中的运行时间为%lfs\n", runtime);
		fclose(fp);
	}
	/**/
	gtk_widget_hide(GTK_WIDGET(window_load));
	link p;
	p = head->next;
	inithead();
	while(p)
	{
		create_city_list(p->obj);
		create_color_list(p->obj);
		create_caizhi_list(p->obj);
		create_pinpai_list(p->obj);
		p = p->next;
	}
}
