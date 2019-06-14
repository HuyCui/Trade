#ifndef HASH_H
#define HASH_H
#include <gtk/gtk.h>
#include "linklist.h"
link city_head[18];
link color_head[18];   //七种颜色
link caizhi_head[18];   //七种材质
link pinpai_head[18];  
link city_tail[18];
link color_tail[18];   //七种颜色
link caizhi_tail[18];   //七种材质
link pinpai_tail[18];  
/******************************************
Function:头指针数组的初始化
in:无
out:头指针链表
return:void
******************************************/
void inithead();
/******************************************
Function:依据城市建立哈希
in：读取的存储信息的结构体
out:城市对应链表的头指针数组
return:void
******************************************/
void create_city_list(struct info a);
/******************************************
Function:将颜色转化为数字
in：颜色的字符串
out:无
return:转化后的数字
******************************************/
int color_change(const gchar *str);
/******************************************
Function:将材质转化为数字
in：材质的字符串
out:无
return:转化后的数字
******************************************/
int caizhi_change(const gchar *str);
/******************************************
Function:将品牌转化为数字
in：品牌的字符串
out:无
return:转化后的数字
******************************************/
int pinpai_change(const gchar *str);
/******************************************
Function:依据颜色建立哈希
in：读取的存储信息的结构体
out:颜色对应链表的头指针数组
return:void
******************************************/
void create_color_list(struct info a);
/******************************************
Function:依据材质建立哈希
in：读取的存储信息的结构体
out:材质对应链表的头指针数组
return:void
******************************************/
void create_caizhi_list(struct info a);
/******************************************
Function:依据品牌建立哈希
in：读取的存储信息的结构体
out:品牌对应链表的头指针数组
return:void
******************************************/
void create_pinpai_list(struct info a);

#endif
