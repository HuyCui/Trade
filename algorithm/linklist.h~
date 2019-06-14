/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:建立链表
Mail:956622792@qq.com
******************************************/
#ifndef _LINKLIST_H
#define _LINKLIST_H

struct info
{
	char name[25];   //名称
	char city[15];    //城市
	int restnum;    //存货量
	int price;     //价格
	char pinpai[15];    //品牌
	char caizhi[20];    //材质
	char shape[20];     //款式形状
	char color[20];     //颜色
	char use[40];       //功能描述
};
typedef struct node
{
	struct info obj;             //结点中记录的结构体数据
	struct node *next,*pre;   //后继指针和前驱指针
}*link;
link head, listhead;   //头指针
link listtail;   //尾指针
/******************************************
Function:链表的初始化函数
in：无
out:头指针
return:void
******************************************/
link initLink();
/******************************************
Function:将每一个新的元素加入到链表
in：  尾指针   记录信息的结构体
out:  无
return:尾指针
******************************************/
link createLink(link tail, struct info a);




#endif
