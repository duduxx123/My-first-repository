#include<stdio.h>
#include<iostream>
using namespace std;
int n;
double starttime;
double finishtime = 0;
double zztime;
double avgzztime;
double sumzztime;
struct JCB
{
	int name;
	double arrivetime;
	double worktime;
	int state;//-1等待 0运行 1完成
	JCB* next;
};
void InitJCB(JCB* jcb) {
	jcb->next = NULL;
}
void CreateFCFSQue(int n, JCB* jcb)//20
{
	JCB* front = jcb->next;
	JCB* after = jcb;
	for (int i = 1;i < n + 1;i++)
	{
		JCB* p = new JCB();
		p->name = i;
		cout << "请输入第" << i << "个作业的提交时间" << endl;
		cin >> p->arrivetime;
		cout << "请输入该作业的工作时间(worktime)" << endl;
		cin >> p->worktime;
		p->state = -1;
		if (p->arrivetime < 0 || p->worktime <= 0)
		{
			cout << "作业提交时间不能小于0或运行时间不能小于等于0" << endl;
		}
		else
		{
			if (jcb->next == NULL)
			{
				jcb->next = p;
				p->next = NULL;
				after->next = p;
				front = p;
			}
			else
			{
				while (front != NULL)
				{
					if (p->arrivetime < front->arrivetime)
					{
						p->next = front;
						after->next = p;
						break;
					}
					else
					{
						after = front;
						front = front->next;
					}
				}
				if (front == NULL)
				{
					after->next = p;
					p->next = NULL;
				}
			}
		}
		after = jcb;
		front = after->next;
	}
}
void CreateSJFQue(int n,JCB* jcb) {
	JCB* front = jcb->next;
	JCB* after = jcb;
	JCB* t;
	for (int i = 1;i <= n;i++) {
		JCB* p = new JCB();
		p->name = i;
		cout << "请输入第" << i << "个作业的提交时间" << endl;
		cin >> p->arrivetime;
		cout << "请输入该作业的工作时间(worktime)" << endl;
		cin >> p->worktime;
		p->state = -1;
		if (p->arrivetime < 0 || p->worktime <= 0){
			cout << "作业提交时间不能小于0或运行时间不能小于等于0" << endl;
		}
		else {
			if (jcb->next == NULL) {
				jcb->next = p;
				p->next = NULL;
				front = p;
			}
			else {
				while (front != NULL) {
					if (p->arrivetime < front->arrivetime){
						break;
					}
					else
					{
						after = front;
						front = front->next;
					}
				}
				while (front != NULL) {
					if (front->worktime > p->worktime && front->arrivetime==p->arrivetime) {
						after->next = p;
						p->next = front;
						break;
					}
					else {
						after = front;
						front = front->next;
					}
				}
				if (front == NULL) {
					after->next = p;
					p->next = NULL;
				}
			}
		}
		after = jcb;
		front = after->next;
	}
}

void show(JCB* jcb)
{
	finishtime = 0;
	JCB* p = jcb->next;
	cout << "作业号(n) arrivetime worktime starttime finishtime zztime" << endl;
	while (p != NULL)
	{
		JCB* q = jcb->next;
		if (finishtime == 0)
		{
			starttime = p->arrivetime;
			finishtime = p->arrivetime + p->worktime;
			zztime = p->worktime;
		}
		else
		{
			starttime = finishtime;
			finishtime = starttime + p->worktime;
			zztime = finishtime - p->arrivetime;
		}
		cout << "	" << p->name << "	" << p->arrivetime << "	"
			<< p->worktime << "	" << starttime <<
			"	" << finishtime << "	" << zztime << endl;
		jcb->next = p->next;
		p = p->next;
		sumzztime = sumzztime + zztime;
		delete(q);
	}
	avgzztime = sumzztime / n;
	cout << "平均周转时间(avgzztime):" << avgzztime << endl;
	delete(jcb);
}
int main()
{
	cout << "----SJS----" << endl;
	JCB* jcb = new JCB();
	InitJCB(jcb);
	cout << "请输入作业数" << endl;
	cin >> n;
	//CreateFCFSQue(n, jcb);
	CreateSJFQue(n, jcb);
	show(jcb);
	return 0;
}
