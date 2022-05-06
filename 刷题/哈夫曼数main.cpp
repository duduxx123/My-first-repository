/*
 * 哈夫曼数main.cpp
 * 实验五哈夫曼树的建立与编码实现
 * ……
 * 作者：hu
 * 日期：2022年5月6日
 * email：abc@qq.com
*/

//a  b  c  d  e  f
//50 90 30 56 16 59
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char ElementType;
typedef int  WeightType;

//I、数据封装（数据表示），struct封装
typedef struct HTNode
{
	ElementType data;         //数据域
	WeightType weight;        //权值
	int leftChild; //左孩子(数组的下标)
	int rightChild;//右孩子
	int parent;    //父节点
}HTNode, *HTree;
typedef struct stack{
	int data[20];
	int top;
}*Stack;

//II、数据操作

//哈夫曼数的创建
//data:叶子节点的数据
//weight：叶子节点的权值
//n：叶子结点的个数
//返回值：创建好的哈夫曼数的数组的起始地址
HTree huffCreate(ElementType data[], WeightType weight[], int n)
{
	//1判断数据的合法性，两个指针，n>=2
	if(data==NULL || weight==NULL || n<2)
		return NULL;
	//2分配数组的内存（分配多少个？2*n-1）
	HTree T=(HTree)malloc(sizeof(HTNode)*(2*n-1));
	//2初始化
	for(int i=0;i<n;i++){
		T[i].data=data[i];
		T[i].weight=weight[i];
		T[i].leftChild=-1;
		T[i].rightChild=-1;
		T[i].parent=-1;
	}
	//3循环(n-1次)
	for(int i=n;i<=2*n-2;i++){
		int min1,min2=999;//记录两个最小节点的下标，不给min2初始化无法判断68行min2!=min1
		int minv1=1000,minv2=1000;//记录连个最小节点的权值
		//1找根当中的两个最小的（前提条件是parent为-1）
		for(int j=0;j<i;j++){
			if(minv1>T[j].weight && T[j].parent==-1){
				min1=j;
				minv1=T[j].weight;
			}
		}
		for(int j=0;j<i;j++){
			if(minv2>T[j].weight && T[j].parent==-1){
				if (j != min1) {
					min2 = j;
					minv2 = T[j].weight;
				}
			}
		}
		//2修改权值=两个孩子权值之和
		T[i].weight = minv1 + minv2;
		//3修改左右孩子（左小，右大）
		T[i].leftChild=min1;
		T[i].rightChild=min2;
		//4修改父节点为-1
		T[i].parent=-1;
		//修改左右孩子的父节点
		T[min1].parent=i;
		T[min2].parent=i;
	}
	//return 数的数组的起始地址
	return T;
}


//编码
//t：已经完全创建好的哈夫曼数
//n：叶子结点的个数
//编码后，打印出来
void encoding(HTree T, int n)
{
	int c,p;
	Stack sta=new struct stack;
	sta->top=-1;
	//循环对每个叶子节点进行编码
	for(int i=0;i<n;i++)
	{
		//c指向当前叶子节点，p指向c的父节点
		c=i;
		p=T[c].parent;
		//循环（条件：p!=-1）
		while(p!=-1){
		  //判断c是p的左孩子还是右孩子，左孩子编码为0，右孩子编码为1
			if(c==T[p].leftChild){
		          //编码入栈
		         //c指向p，p指向p的父节点
				sta->data[++sta->top]=0;
			}
			else{
				sta->data[++sta->top]=1;
			}
			c=p;
			p=T[p].parent;
		}
		//打印字母：
		while(sta->top!=-1){
			cout<<sta->data[sta->top]<<" ";
			sta->top--;
		}
		//一次出栈打印
		//打印换行
		cout<<endl;
	}
}
void printTree(HTree T,int n) {
	for (int i = 0;i < n;i++) {
		cout << T[i].data << " " << T[i].leftChild << " " << T[i].rightChild << " " << T[i].parent << endl;
	}
}

//III、应用

void test()
{

	ElementType data[]={'a',  'b',  'c',  'd',  'e',  'f'};
	WeightType w[]={50, 90, 30, 56, 16, 59};
	HTree ht = huffCreate(data,w,6);
	encoding(ht, 6);
	printTree(ht, 6);
}

int main()
{
	test();
	return 0;
}


