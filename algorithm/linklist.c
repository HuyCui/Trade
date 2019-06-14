/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:建立链表
Mail:956622792@qq.com
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
/******************************************
Function:链表的初始化函数
in：无
out:头指针
return:void
******************************************/
link initLink()
{
	link head;   //定义一个头指针
	head = (link)malloc(sizeof(struct node));   //为头指针分配空间
	head->next = NULL;
	head->pre = NULL;
	return  head;
}
/******************************************
Function:将每一个新的元素加入到链表
in：  尾指针   记录信息的结构体
out:  无
return:尾指针
******************************************/
link createLink(link tail, struct info a)
{
	link p;   //定义一个结点指针
	p = (link)malloc(sizeof(struct node));
	p->obj = a;
	
	p->next = NULL;
	p->pre = tail;
	tail->next = p;
	tail = p;
	return tail;
}
