/*
 * ��������main.cpp
 * ʵ������������Ľ��������ʵ��
 * ����
 * ���ߣ�hu
 * ���ڣ�2022��5��6��
 * email��abc@qq.com
*/

//a  b  c  d  e  f
//50 90 30 56 16 59
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char ElementType;
typedef int  WeightType;

//I�����ݷ�װ�����ݱ�ʾ����struct��װ
typedef struct HTNode
{
	ElementType data;         //������
	WeightType weight;        //Ȩֵ
	int leftChild; //����(������±�)
	int rightChild;//�Һ���
	int parent;    //���ڵ�
}HTNode, *HTree;
typedef struct stack{
	int data[20];
	int top;
}*Stack;

//II�����ݲ���

//���������Ĵ���
//data:Ҷ�ӽڵ������
//weight��Ҷ�ӽڵ��Ȩֵ
//n��Ҷ�ӽ��ĸ���
//����ֵ�������õĹ����������������ʼ��ַ
HTree huffCreate(ElementType data[], WeightType weight[], int n)
{
	//1�ж����ݵĺϷ��ԣ�����ָ�룬n>=2
	if(data==NULL || weight==NULL || n<2)
		return NULL;
	//2����������ڴ棨������ٸ���2*n-1��
	HTree T=(HTree)malloc(sizeof(HTNode)*(2*n-1));
	//2��ʼ��
	for(int i=0;i<n;i++){
		T[i].data=data[i];
		T[i].weight=weight[i];
		T[i].leftChild=-1;
		T[i].rightChild=-1;
		T[i].parent=-1;
	}
	//3ѭ��(n-1��)
	for(int i=n;i<=2*n-2;i++){
		int min1,min2=999;//��¼������С�ڵ���±꣬����min2��ʼ���޷��ж�68��min2!=min1
		int minv1=1000,minv2=1000;//��¼������С�ڵ��Ȩֵ
		//1�Ҹ����е�������С�ģ�ǰ��������parentΪ-1��
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
		//2�޸�Ȩֵ=��������Ȩֵ֮��
		T[i].weight = minv1 + minv2;
		//3�޸����Һ��ӣ���С���Ҵ�
		T[i].leftChild=min1;
		T[i].rightChild=min2;
		//4�޸ĸ��ڵ�Ϊ-1
		T[i].parent=-1;
		//�޸����Һ��ӵĸ��ڵ�
		T[min1].parent=i;
		T[min2].parent=i;
	}
	//return �����������ʼ��ַ
	return T;
}


//����
//t���Ѿ���ȫ�����õĹ�������
//n��Ҷ�ӽ��ĸ���
//����󣬴�ӡ����
void encoding(HTree T, int n)
{
	int c,p;
	Stack sta=new struct stack;
	sta->top=-1;
	//ѭ����ÿ��Ҷ�ӽڵ���б���
	for(int i=0;i<n;i++)
	{
		//cָ��ǰҶ�ӽڵ㣬pָ��c�ĸ��ڵ�
		c=i;
		p=T[c].parent;
		//ѭ����������p!=-1��
		while(p!=-1){
		  //�ж�c��p�����ӻ����Һ��ӣ����ӱ���Ϊ0���Һ��ӱ���Ϊ1
			if(c==T[p].leftChild){
		          //������ջ
		         //cָ��p��pָ��p�ĸ��ڵ�
				sta->data[++sta->top]=0;
			}
			else{
				sta->data[++sta->top]=1;
			}
			c=p;
			p=T[p].parent;
		}
		//��ӡ��ĸ��
		while(sta->top!=-1){
			cout<<sta->data[sta->top]<<" ";
			sta->top--;
		}
		//һ�γ�ջ��ӡ
		//��ӡ����
		cout<<endl;
	}
}
void printTree(HTree T,int n) {
	for (int i = 0;i < n;i++) {
		cout << T[i].data << " " << T[i].leftChild << " " << T[i].rightChild << " " << T[i].parent << endl;
	}
}

//III��Ӧ��

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


