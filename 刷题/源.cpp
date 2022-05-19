#include<iostream>
#include<cstdlib>
#include<String>
using namespace std;
const int MAXSIZE = 50;
typedef struct stack stack;
typedef struct stack* Sta;
struct stack {
	int data[MAXSIZE];
	int top;
};
bool pop(Sta S, int& e) {
	if (S->top == -1)
		return false;
	else e = S->data[S->top--];
	return true;
}
bool push(Sta S, int e) {
	if (S->top == MAXSIZE - 1)
		return false;
	else S->data[++S->top] = e;
	return true;
}
int gettop(Sta s) {
	return s->data[s->top];
}
bool isEmpty(Sta s) {
	if (s->top == -1)
		return true;
	else return false;
}
int youxianji(int fu) {//��ȡ�������ȼ�
	char fuhao=fu;
	int x=-1;
	switch (fuhao)
	{
	case'+':
	case'-':
		x=1;
		break;
	case'*':
	case'/':
		x=2;
		break;
	case'(':
		x = 3;
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	return x;
}
bool isnum(int a) {//�ж��Ƿ�Ϊ����
	char n = a;
	if (n != '+' && n != '-' && n != '*' && n != '/' && n != '(' && n != ')')
		return true;
	else return false;
}
int calculate(int a, int b, int e) {//���ڼ���
	char fu = e;
	int c=-1;
	switch (fu) {
	case'+':
		c = a + b;
		break;
	case'-':
		c = a - b;
		break;
	case'*':
		c = a * b;
		break;
	case'/':
		c = a / b;
		break;
	default:
		cerr << "ERROR" << endl;
	}
	return c;
}
bool isnotIllegal(string s) {//�жϱ��ʽ�Ƿ�Ϸ�
	int flag=0;//��¼������
	int idx = 0;//��¼������
	if (s[0] == ')')
		return false;
	else if (s[0] == '(')
		flag++;
	for (int i = 1;i < s.length();i++) {
		if (isnum(s[i]) && isnum(s[i - 1]))
			return false;
		if (!isnum(s[i]) && !isnum(s[i - 1]) && s[i]!='(' && s[i] != ')' && s[i - 1] != '(' && s[i - 1] != ')')
			return false;
		if (flag == 0 && s[i] == ')')
			return false;
		if (s[i] == '(')
			flag++;
		if (s[i] == ')')
			idx++;
	}
	if (flag != idx)
		return false;
	return true;
}
int zhongzhuizhuanhouzhui(string suanshi) {
	if (!isnotIllegal(suanshi)) {
		cerr << "���ʽ����ȷ" << endl;
		return -1000;
	}
	Sta shuzi = new stack;//����ջ
	Sta fuhao = new stack;//����ջ
	shuzi->top = -1;
	fuhao->top = -1;
	int c;
	int x, y;//��ȡ���ȼ��ı���
	for (int i = 0;i < suanshi.length();i++) {
		c=suanshi[i];//���ô���ô���ˣ�
		if (isnum(c))
			push(shuzi, c-'0');
		else {//����Ƿ���
			if (isEmpty(fuhao) || c=='(')
				push(fuhao, c);
			else {
				if ((char)c == ')') {//���������ţ���ֱ�ӳ�ջ�����㣬ֱ������������
					int e;//���շ���
					int a, b;//��������
					int c;//���ռ�����
					while ((char)fuhao->data[fuhao->top] != '(') {
						pop(fuhao,e);
						pop(shuzi, b);
						pop(shuzi, a);
						c = calculate(a, b, e);
						push(shuzi, c);
					}
					pop(fuhao, e);//����������
				}else if (youxianji(c) > youxianji(gettop(fuhao)) || (char)gettop(fuhao)=='(')//С��ջ���������ȼ���ջ����'('
						push(fuhao, c);
				else if (youxianji(c) <= youxianji(fuhao->data[fuhao->top])) {
						int e1;
						int a1, b1;
						int c1;
						pop(fuhao, e1);
						pop(shuzi, b1);
						pop(shuzi, a1);
						c1 = calculate(a1, b1, e1);
						push(shuzi, c1);
						push(fuhao, c);
				}
			}
		}
	}
	int a2, b2, e2;
	while (fuhao->top != -1) {
		b2 = shuzi->data[shuzi->top--];
		a2 = shuzi->data[shuzi->top--];
		e2 = fuhao->data[fuhao->top--];
		shuzi->data[++shuzi->top]=calculate(a2,b2,e2);
	}
	return gettop(shuzi);
	/*while (shuzi->data[shuzi->top] != -1) {
		cout << shuzi->data[shuzi->top] << endl;
		shuzi->top--;
	}*/
	//return 9;
}
int main() {
	string suanshi="(1+5)/3-5";
	//cin >> suanshi;
	int answer=zhongzhuizhuanhouzhui(suanshi);
	cout << suanshi << "=" << answer << endl;
	return 0;
}