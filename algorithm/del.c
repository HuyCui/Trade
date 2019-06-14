#include<stdio.h>
#include<stdlib.h>
#include"del.h"
#include"linklist.h"

void delete(link p[], const char *str, int i)
{
	link q1 = p[i]->next, q2 = NULL;
	while(q1)
	{
		if(strcmp(q1->obj.name , str)  == 0)		
		{
			if(q2 == NULL)
			{
				p[i]->next = q1->next;
				free(q1);
				break;
			}
			else
			{
				q2->next = q1->next;
				free(q1);
				break;
			}

		}
		else
		{
			q2 = q1;
			q1 = q1->next;	
		}
		
	}
	
}

