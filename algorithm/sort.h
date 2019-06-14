#ifndef SORT_H
#define SORT_H

void swap(int *a,int *b);
struct node *partion(struct node *pBegin,struct node *pEnd);
void quick_sort(struct node *pBegin,struct node *pEnd);
struct node* sortList(struct node* head);

#endif
