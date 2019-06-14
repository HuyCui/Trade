#include<stdio.h>
#include<stdlib.h>
#include"sort.h"
#include"linklist.h"
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
struct node *partion(struct node *pBegin,struct node *pEnd)   //一次划分
{
    if(pBegin==pEnd||pBegin->next==pEnd)    return pBegin;
    int key=pBegin->obj.price;    //选择pBegin作为基准元素
    struct node *p=pBegin,*q=pBegin;
    while(q!=pEnd){   //从pBegin开始向后进行一次遍历
        if(q->obj.price<key){
            p=p->next;
            swap(&p->obj.price,&q->obj.price);
        }
        q=q->next;
    }
    swap(&p->obj.price,&pBegin->obj.price);
    return p;
}
void quick_sort(struct node *pBegin,struct node *pEnd)
{
    if(pBegin==pEnd||pBegin->next==pEnd)    return;
    struct node *mid=partion(pBegin,pEnd);
    quick_sort(pBegin,mid);
    quick_sort(mid->next,pEnd);
}
struct node* sortList(struct node* head) 
{
    if(head==NULL||head->next==NULL)    return head;
    quick_sort(head,NULL);
    return head;
}
