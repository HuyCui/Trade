/******************************************
Copyright:SDUT
Author:李晓龙
Date:2018-01-18
Describe:上架界面回调函数
Mail:956622792@qq.com
******************************************/
#include <stdlib.h>
#include <string.h>
#include "addcont.h"
#include "myview.h"
#include "linklist.h"

/******************************************
Function:确认添加按钮回调函数
out:无
return:void
******************************************/
void on_button_sure_add_clicked(GtkObject* widget,gpointer user_data)
{
	const gchar* str1 = gtk_entry_get_text(entry_name_add);
	const gchar* str2 = gtk_entry_get_text(entry_address_add);
	const gchar* str3 = gtk_entry_get_text(entry_rest_add);
	const gchar* str4 = gtk_entry_get_text(entry_price_add);
	const gchar* str5 = gtk_entry_get_text(entry_sign_add);
	const gchar* str6 = gtk_entry_get_text(entry_material_add);
	const gchar* str7 = gtk_entry_get_text(entry_shape_add);
	const gchar* str8 = gtk_entry_get_text(entry_color_add);
	const gchar* str9 = gtk_entry_get_text(entry_describe_add);

	    if(strcmp(str9,"")==0||strcmp(str8,"")==0||strcmp(str7,"")==0||strcmp(str6,"")==0||strcmp(str5,"")==0||strcmp(str4,"")==0||strcmp(str3,"")==0||strcmp(str2,"")==0||strcmp(str1,"")==0)
	    {
			//gtk_widget_hide(GTK_WIDGET(window1_add));
	        gtk_widget_show(GTK_WIDGET(window2_add));
        }
	    else
	    {
			GtkTreeIter iter;
			gtk_list_store_append(liststore_goods,&iter);
			gtk_list_store_set(liststore_goods,&iter,0,str1,-1);
			gtk_list_store_set(liststore_goods,&iter,1,str2,-1);
			gtk_list_store_set(liststore_goods,&iter,2,str3,-1);
			gtk_list_store_set(liststore_goods,&iter,3,str4,-1);
			gtk_list_store_set(liststore_goods,&iter,4,str5,-1);
			gtk_list_store_set(liststore_goods,&iter,5,str6,-1);
			gtk_list_store_set(liststore_goods,&iter,6,str7,-1);
			gtk_list_store_set(liststore_goods,&iter,7,str8,-1);
			gtk_list_store_set(liststore_goods,&iter,8,str9,-1);
			link p;
			p = (link)malloc(sizeof(struct node));
			strcpy(p->obj.name, str1);
			strcpy(p->obj.city, str2);
			strcpy(p->obj.pinpai, str5);
			strcpy(p->obj.shape, str7);
			strcpy(p->obj.caizhi, str6);
			strcpy(p->obj.color, str8);
			strcpy(p->obj.use, str9);
			p->next = NULL;
			p->pre = listtail;
			listtail->next = p;
			listtail = p;
			gtk_widget_hide(GTK_WIDGET(window1_add));
	    }
}

//-----------上架取消-----------//
void on_button_cancel_add_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window1_add));
}
//-----------信息不完整返回---------//
void on_button_return_add_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window2_add));
	gtk_widget_show(GTK_WIDGET(window1_add));
}
//-----------重名确认修改--------
void on_button_change_add_clicked(GtkObject* widget,gpointer user_data)
{
	//change(str);
	gtk_widget_hide(GTK_WIDGET(window3_add));
	gtk_widget_show(GTK_WIDGET(window1_add));
}
//-----------重名取消修改--------//
void on_button_nchange_add_clicked(GtkObject* widget,gpointer user_data)
{
	gtk_widget_hide(GTK_WIDGET(window3_add));
	gtk_widget_show(GTK_WIDGET(window1_add));
}
