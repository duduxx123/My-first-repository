# 数据结构学习 树的同构
## C++代码
``` C++
#include<iostream>
#include<string>
using namespace std;
#define Null -1
typedef struct TreeNode Tree;
struct TreeNode {
    char element;
    int left;
    int right;
}T1[10], T2[10];
int findhead(Tree T[], int num)
{
    int find[10] = { 0 };
    if (num == 0)
        return Null;
    for (int i = 0;i < num;i++) {
        if (T[i].left != -1)
            find[T[i].left] = 1;
        if (T[i].right != -1)
            find[T[i].right] = 1;
    }
    for (int i = 0;i < num;i++)
        if (!find[i])
            return i;
}
int buildtree(Tree T[], int num)//返回树的头结点
{
    char cl, cr;
    for (int i = 0;i < num;i++) {
        getchar();
        scanf("%c %c %c", &T[i].element, &cl, &cr);
        if (cl == '-')
            T[i].left = -1;
        else T[i].left = cl - '0';
        if (cr == '-')
            T[i].right = -1;
        else T[i].right = cr - '0';
    }
    int head = findhead(T, num);
    return head;
}
int Isomorphic(int R1, int R2)
{
    if (R1 == Null && R2 == Null)
        return 1;
    if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
        return 0;
    if (T1[R1].element != T2[R2].element)
        return 0;
    if (T1[R1].left == Null && T2[R2].left == Null)
        return Isomorphic(T1[R1].right, T2[R2].right);
    if ((T1[R1].left != Null && T2[R2].left != Null) && (T1[T1[R1].left].element == T2[T2[R2].left].element))
        return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
    else return (Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));
}
int main()
{
    int num1, num2;
    cin >> num1;
    int R1, R2;//储存树的头结点
    R1 = buildtree(T1, num1);
    cin >> num2;
    R2 = buildtree(T2, num2);
    if (Isomorphic(R1, R2))
        cout << "Yes";
    else cout << "No";
}

```
