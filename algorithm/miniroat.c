#include <string.h>
#include <gtk/gtk.h>
#include "window_wuliu.h"

double map_cost[17][17]={{0, 7, 10, 13, 10, 5, 12, 15, 9999, 7, 12, 9999, 12, 9999, 7, 9999, 9999}, {7,0, 3, 5, 4, 11, 9999, 9999, 9999, 15, 9999, 9999, 9999, 9999, 14, 9999, 9999},{10, 3, 0, 2, 7, 14, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999,9999}, {13, 5, 2, 0, 9, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999}, {10, 4, 7, 9, 0, 15, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999}, {5, 11, 14, 9999, 15, 0, 7, 10, 12, 7, 12, 9999, 12, 9999, 12, 9999, 9999}, {12, 9999, 9999, 9999, 9999, 7, 0, 3, 5, 7, 12, 9999, 12, 9999, 9999, 9999, 9999}, {15, 9999, 9999, 9999, 9999, 10, 3, 0, 2, 10, 14, 9999, 15, 9999, 9999, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 12, 5, 2, 0, 12, 12, 9999, 9999, 9999, 9999, 9999, 9999}, {7, 15, 9999, 9999, 9999, 7, 7, 10, 12, 0, 5, 9999, 5, 12, 14, 9999, 9999}, {12, 9999, 9999, 9999, 9999, 12, 12, 14, 12, 5, 0, 11, 10, 9999, 9999, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 11, 0, 9999, 9999, 9999, 9999, 9999}, {12, 9999, 9999, 9999, 9999, 12, 12, 15, 9999, 5, 10, 9999, 0, 7, 13, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 12, 9999, 9999, 7, 0, 11, 19, 21}, {7, 14, 9999, 9999, 9999, 12, 9999, 9999, 9999, 14, 9999, 9999, 13, 11, 0, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 19, 9999, 0, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 21, 9999, 9999, 0}};
double map_time[17][17]={{0, 0.7, 1, 1.3, 1, 0.45, 0.5, 0.5, 9999, 0.5, 1, 9999, 1.1, 9999, 0.5, 9999, 9999}, {0.7, 0, 0.5, 0.5, 0.5, 1.2, 9999, 9999, 9999, 2, 9999, 9999, 9999, 9999, 1.5, 9999, 9999},{1, 0.5, 0, 0.5, 0.5, 2, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999,9999}, {1.3, 0.5, 0.5, 0, 1.5, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999}, {1, 0.5, 0.5, 1.5, 0, 2, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999}, {0.45, 1.2, 2, 9999, 2, 0, 0.5, 1.1, 1.5, 0.5, 1.2, 9999, 1.5, 9999, 2, 9999, 9999}, {0.5, 9999, 9999, 9999, 9999, 0.5, 0, 0.5, 0.5, 1, 1.5, 9999, 1.5, 9999, 9999, 9999, 9999}, {0.5, 9999, 9999, 9999, 9999, 1.1, 0.5, 0, 0.3, 1.2, 1.5, 9999, 2, 9999, 9999, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 1.5, 0.5, 0.3, 0, 1.5, 1.5, 9999, 9999, 9999, 9999, 9999, 9999}, {0.5, 2, 9999, 9999, 9999, 0.5, 1, 1.2, 1.5, 0, 0.5, 9999, 0.5, 1.5, 2, 9999, 9999}, {1, 9999, 9999, 9999, 9999, 1.2, 1.5, 1.5, 1.5, 0.5, 0, 1.5, 1, 9999, 9999, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 1.5, 0, 9999, 9999, 9999, 9999, 9999}, {1.1, 9999, 9999, 9999, 9999, 1.5, 1.5, 2, 9999, 0.5, 1, 9999, 0, 0.5, 2, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 1.5, 9999, 9999, 0.5, 0, 2, 2, 3}, {0.5, 1.5, 9999, 9999, 9999, 2, 9999, 9999, 9999, 2, 9999, 9999, 2, 2, 0, 9999, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 2, 9999, 0, 9999}, {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 3, 9999, 9999, 0}};

int visit[20], ans[20];//全局变量分别为矩阵图，标记数组，记录权值
double dis[20];
int wuliu_change1(char *str)
{
	int a;
	if(strcmp(str, "北京") == 0)
	{
		a = 0;
	}
	else if(strcmp(str, "沈阳") == 0)
	{
		a = 1;
	}
	else if(strcmp(str, "长春") == 0)
	{
		a = 2;
	}
	else if(strcmp(str, "哈尔滨") == 0)
	{
		a = 3;
	}
	else if(strcmp(str, "大连") == 0)
	{
		a = 4;
	}
	else if(strcmp(str, "济南") == 0)
	{
		a = 5;
	}
	else if(strcmp(str, "南京") == 0)
	{
		a = 6;
	}
	else if(strcmp(str, "上海") == 0)
	{
		a = 7;
	}
	else if(strcmp(str, "杭州") == 0)
	{
		a = 8;
	}
	else if(strcmp(str, "郑州") == 0)
	{
		a = 9;
	}
	else if(strcmp(str, "武汉") == 0)
	{
		a = 10;
	}
	else if(strcmp(str, "广州") == 0)
	{
		a = 11;
	}
	else if(strcmp(str, "西安") == 0)
	{
		a = 12;
	}
	else if(strcmp(str, "兰州") == 0)
	{
		a = 13;
	}
	else if(strcmp(str, "呼和浩特") == 0)
	{
		a = 14;
	}
	else if(strcmp(str, "乌鲁木齐") == 0)
	{
		a = 15;
	}
	else if(strcmp(str, "拉萨") == 0)
	{
		a = 16;
	}
	return a;
}
void wuliu_change2(int s, char a[])
{
	switch(s)
	{
	case 0: strcpy(a,"北京");break;
	case 1: strcpy(a,"沈阳");break;
	case 2: strcpy(a,"长春");break;
	case 3: strcpy(a,"哈尔滨");break;
	case 4: strcpy(a,"大连");break;
	case 5: strcpy(a,"济南");break;
	case 6: strcpy(a,"南京");break;
	case 7: strcpy(a,"上海");break;
	case 8: strcpy(a,"杭州");break;
	case 9: strcpy(a,"郑州");break;
	case 10: strcpy(a,"武汉");break;
	case 11: strcpy(a,"广州");break;
	case 12: strcpy(a,"西安");break;
	case 13: strcpy(a,"兰州");break;
	case 14: strcpy(a,"呼和浩特");break;
	case 15: strcpy(a,"乌鲁木齐");break;
	case 16: strcpy(a,"拉萨");break;
	}
}
void mini_time(int s, int e)
{
    int i, j, k;
   double INF = 9999;
   memset(visit, 0, sizeof(visit));
   for(i = 0;i < 17;i++)//从s开始
   {
       dis[i] = map_time[s][i];
       if(dis[i] == INF)
		{
          ans[i] = -1;
		}
       else
		{
		 ans[i] = s;
		}
   }
   visit[s] = 1;
   for(i = 1;i < 17;i++)
   {
      double mini = INF;
      int u = s;
      for(j = 0;j < 17;j++)
      {
         if(!visit[j] && mini > dis[j])
         {
             u = j;
             mini = dis[j];
         }
      }
      visit[u] = 1;
      if(u == e)
      break;
      for(j = 0;j < 17;j++)
      {
         if(!visit[j] && map_time[u][j] < INF)
         {
             double newdist = dis[u] + map_time[u][j];
             if(newdist < dis[j])
             {
                 dis[j] = newdist;
                 ans[j] = u;
             }
         }
      }
   }
	char temp[50], str[50], str1[200];
	int ans1[20], m = 0;
    sprintf(temp, "%lf", dis[e]);
	gtk_entry_set_text(entry_short_time, temp);
	while(ans[e] != s)
	{
		ans1[m++] = e;
		e = ans[e];
	}
	ans1[m++] = e;
    ans1[m] = s;
    for(i = m; i >= 0; i--)
	{
		wuliu_change2(ans1[i], str);
		if(i == m)
		{
			strcpy(str1, str);
		}
		else
		{
			strcat(str1, "->");
			strcat(str1, str);
		}
	}
	gtk_entry_set_text(entry_short, str1);
}

void mini_cost(int s, int e)
{
   int i, j, k;
   double INF = 9999;
   memset(visit, 0, sizeof(visit));
   for(i = 0;i < 17;i++)//从s开始
   {
       dis[i] = map_cost[s][i];
       if(dis[i] == INF)
		{
          ans[i] = -1;
		}
       else
		{
		 ans[i] = s;
		}
   }
   visit[s] = 1;
   for(i = 1;i < 17;i++)
   {
      double mini = INF;
      int u = s;
      for(j = 0;j < 17;j++)
      {
         if(!visit[j] && mini > dis[j])
         {
             u = j;
             mini = dis[j];
         }
      }
      visit[u] = 1;
      if(u == e)
      break;
      for(j = 0;j < 17;j++)
      {
         if(!visit[j] && map_cost[u][j] < INF)
         {
             double newdist = dis[u] + map_cost[u][j];
             if(newdist < dis[j])
             {
                 dis[j] = newdist;
                 ans[j] = u;
             }
         }
      }
   }
	char temp[50], str[50], str1[200];
	int ans1[20], m = 0;
    sprintf(temp, "%lf", dis[e]);
	gtk_entry_set_text(entry_cheap_cost, temp);
	while(ans[e] != s)
	{
		ans1[m++] = e;
		e = ans[e];
	}
	ans1[m++] = e;
    ans1[m] = s;
    for(i = m; i >= 0; i--)
	{
		wuliu_change2(ans1[i], str);
		if(i == m)
		{
			strcpy(str1, str);
		}
		else
		{
			strcat(str1, "->");
			strcat(str1, str);
		}
	}
	gtk_entry_set_text(entry_cheap, str1);
}

