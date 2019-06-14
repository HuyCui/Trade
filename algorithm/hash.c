/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:建立哈希表的函数
Mail:956622792@qq.com
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "linklist.h"
#include "miniroat.h"
#include "hash.h"
/******************************************
Function:头指针数组的初始化
in:无
out:头指针链表
return:void
******************************************/
void inithead()
{
	int i = 0;
	
	for(i = 0; i < 18; i++)
	{
		city_head[i] = (link)malloc(sizeof(struct node));
		caizhi_head[i] = (link)malloc(sizeof(struct node));
		color_head[i] = (link)malloc(sizeof(struct node));
		pinpai_head[i] = (link)malloc(sizeof(struct node));
		city_head[i]->next = NULL;
		color_head[i]->next = NULL;
		caizhi_head[i]->next = NULL;
		pinpai_head[i]->next = NULL;
		city_head[i]->pre = NULL;
		color_head[i]->pre = NULL;
		caizhi_head[i]->pre = NULL;
		pinpai_head[i]->pre = NULL;
		city_tail[i] = city_head[i];
		color_tail[i] = color_head[i];
		caizhi_tail[i] = caizhi_head[i];
		pinpai_tail[i] = pinpai_head[i];
	}
}
/******************************************
Function:将颜色转化为数字
in：颜色的字符串
out:无
return:转化后的数字
******************************************/
int color_change(const gchar *str)
{
	int a;
	if(strcmp(str, "红") == 0)
	{
		a = 0;
	}
	else if(strcmp(str, "橙") == 0)
	{
		a = 1;
	}
	else if(strcmp(str, "黄") == 0)
	{
		a = 2;
	}
	else if(strcmp(str, "绿") == 0)
	{
		a = 3;
	}
	else if(strcmp(str, "青") == 0)
	{
		a = 4;
	}
	else if(strcmp(str, "蓝") == 0)
	{
		a = 5;
	}
	else if(strcmp(str, "紫") == 0)
	{
		a = 6;
	}
	return a;
}
/******************************************
Function:将材质转化为数字
in：材质的字符串
out:无
return:转化后的数字
******************************************/
int caizhi_change(const gchar *str)
{
	int a;
	if(strcmp(str, "牛皮") == 0)
	{
		a = 0;
	}
	else if(strcmp(str, "PU") == 0)
	{
		a = 1;
	}
	else if(strcmp(str, "牛津布") == 0)
	{
		a = 2;
	}
	else if(strcmp(str, "PVC") == 0)
	{
		a = 3;
	}
	else if(strcmp(str, "羊皮") == 0)
	{
		a = 4;
	}
	else if(strcmp(str, "尼龙布") == 0)
	{
		a = 5;
	}
	else if(strcmp(str, "猪皮") == 0)
	{
		a = 6;
	}
	return a;
}
/******************************************
Function:将品牌转化为数字
in：品牌的字符串
out:无
return:转化后的数字
******************************************/
int pinpai_change(const gchar *str)
{
	int a;
	if(strcmp(str, "银座") == 0)
	{
		a = 0;
	}
	else if(strcmp(str, "外交官") == 0)
	{
		a = 1;
	}
	else if(strcmp(str, "皇冠") == 0)
	{
		a = 2;
	}
	else if(strcmp(str, "啄木鸟") == 0)
	{
		a = 3;
	}
	else if(strcmp(str, "七匹狼") == 0)
	{
		a = 4;
	}
	else if(strcmp(str, "威戈") == 0)
	{
		a = 5;
	}
	else if(strcmp(str, "LV") == 0)
	{
		a = 6;
	}
	else if(strcmp(str, "阿玛尼") == 0)
	{
		a = 7;
	}
	else if(strcmp(str, "稻草人") == 0)
	{
		a = 8;
	}
	else if(strcmp(str, "老人头") == 0)
	{
		a = 9;
	}
	return a;
}
/******************************************
Function:依据城市建立哈希
in：读取的存储信息的结构体
out:城市对应链表的头指针数组
return:void
******************************************/
void create_city_list(struct info a)
{
	int x;
	x = wuliu_change1(a.city);
	link p;
	p = NULL;
	p = (link)malloc(sizeof(struct node));
	p->obj = a;
	
	p->next = NULL;
	p->pre = city_tail[x];
	city_tail[x]->next = p;
	city_tail[x] = p;
	//return tail[x];
}
/******************************************
Function:依据颜色建立哈希
in：读取的存储信息的结构体
out:颜色对应链表的头指针数组
return:void
******************************************/
void create_color_list(struct info a)
{
	int x;
	x = color_change(a.color);
	link p;
	p = NULL;
	p = (link)malloc(sizeof(struct node));
	p->obj = a;
	
	p->next = NULL;
	p->pre = color_tail[x];
	color_tail[x]->next = p;
	color_tail[x] = p;
}
/******************************************
Function:依据材质建立哈希
in：读取的存储信息的结构体
out:材质对应链表的头指针数组
return:void
******************************************/
void create_caizhi_list(struct info a)
{
	int x;
	x = caizhi_change(a.caizhi);
	link p;
	p = NULL;
	p = (link)malloc(sizeof(struct node));
	p->obj = a;
	
	p->next = NULL;
	p->pre = caizhi_tail[x];
	caizhi_tail[x]->next = p;
	caizhi_tail[x] = p;
}
/******************************************
Function:依据品牌建立哈希
in：读取的存储信息的结构体
out:品牌对应链表的头指针数组
return:void
******************************************/
void create_pinpai_list(struct info a)
{
	int x;
	x = pinpai_change(a.pinpai);
	link p;
	p = NULL;
	p = (link)malloc(sizeof(struct node));
	p->obj = a;
	
	p->next = NULL;
	p->pre = pinpai_tail[x];
	pinpai_tail[x]->next = p;
	pinpai_tail[x] = p;
}

