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
int youxianji(int fu) {//获取符号优先级
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
bool isnum(int a) {//判断是否为数字
	char n = a;
	if (n != '+' && n != '-' && n != '*' && n != '/' && n != '(' && n != ')')
		return true;
	else return false;
}
int calculate(int a, int b, int e) {//用于计算
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
bool isnotIllegal(string s) {//判断表达式是否合法
	int flag=0;//记录左括号
	int idx = 0;//记录右括号
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
		cerr << "表达式不正确" << endl;
		return -1000;
	}
	Sta shuzi = new stack;//数字栈
	Sta fuhao = new stack;//符号栈
	shuzi->top = -1;
	fuhao->top = -1;
	int c;
	int x, y;//获取优先级的变量
	for (int i = 0;i < suanshi.length();i++) {
		c=suanshi[i];//懒得打那么多了；
		if (isnum(c))
			push(shuzi, c-'0');
		else {//如果是符号
			if (isEmpty(fuhao) || c=='(')
				push(fuhao, c);
			else {
				if ((char)c == ')') {//遇到右括号，则直接出栈并计算，直到遇到左括号
					int e;//接收符号
					int a, b;//接收数字
					int c;//接收计算结果
					while ((char)fuhao->data[fuhao->top] != '(') {
						pop(fuhao,e);
						pop(shuzi, b);
						pop(shuzi, a);
						c = calculate(a, b, e);
						push(shuzi, c);
					}
					pop(fuhao, e);//弹出左括号
				}else if (youxianji(c) > youxianji(gettop(fuhao)) || (char)gettop(fuhao)=='(')//小于栈顶符号优先级或栈顶是'('
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
