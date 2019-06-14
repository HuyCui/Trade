/******************************************
Copyright:SDUT
Author:崔辉
Date:2018-01-18
Describe:显示主界面
Mail:956622792@qq.com
******************************************/
#ifndef _WINDOW_MAIN_H
#define _WINDOW_MAIN_H

#define w_(builder,type,name) name=GTK_##type(gtk_builder_get_object(builder,#name))
GtkWindow *window_main;    //主界面
GtkEntry *entry_search;   //搜索内容输入文本框
GtkTreeView *treeview_goods;  //树视图
GtkListStore *liststore_select;  //选择显示对象
GtkListStore *liststore_goods;   //商品展示对象
GtkButton *button_search;     //搜索按钮
GtkButton *button_load;       //商品载入按钮
GtkButton *button_sort;        //排序按钮
GtkButton *button_change;     //修改信息按钮
GtkButton *button_wuliu;      //物流信息展示
GtkButton *button_help;       //帮助展示按钮
GtkButton *button_decrease;   //商品下架按钮
GtkButton *button_add;    //商品上架按钮
GtkComboBox *combox_select;     //选择复选框
GtkScrolledWindow *scrolledwindow;   //可滚动窗口
GtkButton *button_next;       //下一页
GtkButton *button_pre;        //上一页
GtkButton *button_pre_sort;        
GtkButton *button_next_sort;
GtkButton *button_pre_search;
GtkButton *button_next_search;

/******************************************
Function:将主界面galde控件与代码相链接
in:  
	gchar* filename界面文件名
out:无
return:void
******************************************/
void main_get_widgets(GtkBuilder* gb);
/******************************************
Function:初始化树视图
in:  
	GtkWidget * list树视图的列表对象
out:无
return:void
******************************************/
void init_list(GtkWidget * list);

#endif
