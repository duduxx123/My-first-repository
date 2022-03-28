#include<iostream>
#include<string>
#include <fstream>
#include<strstream>
#include <vector>
#include<Windows.h>
#include <conio.h>
using namespace std;

struct kc
{
	char bianhao[10];
	char name[20];
	int xueshi;
	int xuefen;
	char kaixueinf[11];
};
class course
{
public:
	int cnt;    //添加的课程数量
	vector<struct kc> C;
	course();
	void printfc();
	void reinf();//修改
	void deinf();//删除课程
	void getinf();//录入课程信息
	bool filesave(char*temp); //保存文本文件
	bool fileread(char*temp); //读取文本文件
};

course::course() {cnt = 0;}

void course::printfc()
{
	cout << "课程编号，课程名称，课程学时，课程学分，开学时间\n";
	string a;
	ifstream infile;
	infile.open("book.dat", ios::in);
	if (!infile) {
		cerr << "Open error!" << endl; exit(1);
	}
	/*while (infile >> a)   //这玩意遇到空格直接结束了
	{
		cout << a;
		cout << ' ';
	}*/
	while (getline(infile, a))
		cout << a << endl;
	infile.close();

	/*for (int i = 0; i < cnt; i++)
		cout << C.at(i).bianhao << "      " << C.at(i).name <<"      " 
		<< C.at(i).xueshi << "      " << C.at(i).xuefen << "      " << C.at(i).kaixueinf << endl;*/
}

void course::reinf()
{
	char temp[20];
	cout << "请输入课程的编号或者名称" << endl;
	cin >> temp;
	ifstream infile;
	infile.open("book.dat", ios::in);
	if (!infile) {
		cerr << "Open error!" << endl; exit(1);
	}
	infile >> temp;
	infile.close();
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(C.at(i).bianhao, temp) == 0 || strcmp(C.at(i).name, temp) == 0)
			break;
	}
	cout << "查询课程信息为";
	printfc();
	cout << "\n请输入修改后的 课程编号，课程名称，课程学时，课程学分，开学时间（xxxx,x,x）" << endl;
	getinf();
	/*cin >> temp;
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(C.at(i).bianhao, temp) == 0 || strcmp(C.at(i).name, temp) == 0)
			break;
	}
	cout << "查询课程信息为" << C.at(i).bianhao << "      " << C.at(i).name << "      " << C.at(i).xueshi << "      "
		<< C.at(i).xuefen << "      " << C.at(i).kaixueinf << endl;
	cout << "\n请输入修改后的 课程编号，课程名称，课程学时，课程学分，开学时间（xxxx,x,x）" << endl;

	cin >> C.at(i).bianhao;
	cin >> C.at(i).name;
	cin >> C.at(i).xueshi;
	cin >> C.at(i).xuefen;
	cin >> C.at(i).kaixueinf;
	cout << "修改成功" << endl;*/
}

void course::deinf()
{
	char temp[20];
	cout << "请输入课程的编号或者名称" << endl;
	cin >> temp;
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(C.at(i).bianhao, temp) == 0 || strcmp(C.at(i).name, temp) == 0)break;

	}
	if (i == cnt)
	{
		cout << "无此课程" << endl;
		return;
	}
	cout << "删除课程信息为" << C.at(i).bianhao <<"      "<< C.at(i).name<<"      "
	<< C.at(i).xueshi << "      " << C.at(i).xuefen << "      " << C.at(i).kaixueinf << "\n是否确认删除?是输入1，不是输入0\n";
	int Isde = 0;
	cin >> Isde;
	if (Isde)
	{
		C.erase(C.begin() + i);  //参数为迭代器地址
		cnt--;
		cout << "删除成功" << endl;
	}
}
void course::getinf()
{
	int N = 0;
	cout << "请输入要录入的课程数量" << endl;
	cin >> N;
	struct kc a;
	ofstream outfile;
	outfile.open("book.dat", ios::out);
	if (!outfile) {
		cerr << "Open error!" << endl; exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		cout << "请输入 课程编号，课程名称，课程学时，课程学分，开学时间（xxxx.x.x）" << endl;
		cin >> a.bianhao;
		cin >> a.name;
		cin >> a.xueshi;
		cin >> a.xuefen;
		cin >> a.kaixueinf;
		C.push_back(a);
		cnt++;
		outfile << a.bianhao << "  " << a.name << "  " << a.xueshi << "  " << a.xuefen << "  " << a.kaixueinf << endl;
	}
	outfile.close();

	cout << "录入完成" << endl;
}
bool course::filesave(char*temp)
{
	ofstream out;
	out.open(temp, ios::out);
	if (out.is_open() == 0)
		return false;
	out << "课程信息" << endl;
	for (int i = 0; i < cnt; i++)
	{

		out << C.at(i).bianhao << endl;
		out << C.at(i).name << endl;
		out << C.at(i).kaixueinf << endl;
		out << C.at(i).xuefen << endl;
		out << C.at(i).xueshi << endl;
	}
	out << "录入完成" << endl;
	out.close();
	return true;
}
bool course::fileread(char*temp) //读取文本文件
{
	char data[20];
	ifstream in;
	in.open(temp, ios::in);
	if (in.is_open() == 0)return false;
	in >> data;
	if (strcmp("课程信息", data) != 0)
	{
		cout << "不是课程数据文件，打开失败" << endl;
		return false;
	}
	while (1)
	{
		struct kc a;
		in >> a.bianhao;
		if (strcmp(a.bianhao, "录入完成") == 0)break;
		in >> a.name;
		in >> a.kaixueinf;
		in >> a.xuefen;
		in >> a.xueshi;
		C.push_back(a);
		cnt++;
	}
	in.close();

	return true;
}





//////////////////student



class student
{
public:
	char yixuankec[256];
	char yanz[10];
	char xuehao[20];
	int kecnt;            //已选课程数目

	student(char *_xuehao = NULL, char *_yanz = NULL);//构造
	void choiceC(char* _bianhao);                              //选课功能
	void checkC();                             //查询功能
	void getkc(int cnt, char* temp);           //返回第cnt个课程的编号
	void setyanz(char *_yanz);                 //设置验证码
	void setxuehao(char *_xuehao);			  //设置学号
	bool xuehaopipei(char *_xuehao);          //学号是否匹配
	bool yanzpipei(char*_yanz);               //验证码是否匹配
};

student::student(char *_xuehao, char *_yanz)
{
	kecnt = 0;
	yixuankec[0] = 0;
	if (_xuehao != NULL)strcpy(xuehao, _xuehao);
	if (_yanz != NULL)strcpy(yanz, _yanz);
}

void student::choiceC(char* _bianhao)                              //选课功能
{
	int i = 0;
	for (i = 0; i < 256; i++)
	{
		if (yixuankec[i] == 0)
		{
			if (kecnt != 0)
			{
				yixuankec[i] = ',';
				i++;
			}
			break;
		}
	}
	strcpy(yixuankec + i, _bianhao);//此处没有判断i是否越界
	kecnt++;
}
void student::checkC()									//查询功能
{
	cout << "学号:" << xuehao << endl;
	cout<<"登陆验证:" << yanz << endl;
	//cout<<"已选课程编号：" << yixuankec << endl;

}
void student::getkc(int cnt, char* temp)
{
	char temp1[10];
	int c = 0;
	for (int i = 0, j = 0; i < 256; i++)
	{
		if (yixuankec[i] != 0 && yixuankec[i] != ',')
		{
			temp1[j] = yixuankec[i];
			j++;
		}
		else //yixuankec[i] == ',' \0
		{
			c++;
			temp1[j] = 0;
			if (c == cnt)
			{
				strcpy(temp, temp1);
				return;
			}
			j = 0;
		}
	}
}

void student::setyanz(char *_yanz)                 //重新设置验证码
{
	strcpy(yanz, _yanz);
	//cout << "设置成功" << endl;
}
void student::setxuehao(char *_xuehao)			  //设置学号
{
	strcpy(xuehao, _xuehao);
	//cout << "申请成功" << endl;
}

bool student::xuehaopipei(char *_xuehao)          //学号是否匹配
{
	if (strcmp(xuehao, _xuehao) == 0)
		return true;
	else return false;
}
bool student::yanzpipei(char*_yanz)              //密码是否匹配
{
	if (strcmp(yanz, _yanz) == 0)
		return true;
	else return false;
}


/////////////Teacher


class Teacher :public student
{
public:
	Teacher(char *_xuehao = NULL, char *_yanz = NULL);//构造
	void checkC();
	void read(char *zhanghao, char *mima);
};
Teacher::Teacher(char *_xuehao, char *_yanz)
{
	kecnt = 0;
	yixuankec[0] = 0;
	if (_xuehao != NULL)strcpy(xuehao, _xuehao);
	if (_yanz != NULL)strcpy(yanz, _yanz);
}
void Teacher::checkC()									//查询功能
{
	cout << "教师编号:" << xuehao << endl;
	cout << "登陆密码:" << yanz << endl;
	//cout << "学生已选课程编号：" << yixuankec << endl;

}
void Teacher::read(char *zhanghao,char *mima)
{
	//char zhanghao[20];
	//char mima[20];
	//cout << "输入密码" << endl;
	//cin.getline(mima, 20, '\n');
	ofstream outfile;
	outfile.open("zhangh.dat", ios::out);
	if (!outfile) {
		cerr << "Open error!" << endl; exit(1);
	}
	cout << "输入账号:" ;
	cin.ignore();//不知道为什么输入文件的时候会自动加一个换行所以用ignore忽略掉
	cin.getline(zhanghao, 20, '\n');//为什么要按2次回车？？？？？？？？？
	outfile << zhanghao;             //好像是因为C++换行是\n回车是\r但是也解决不了
	outfile.close();

	ofstream outfile1;
	outfile1.open("mima.dat", ios::out);
	if (!outfile1){
		cerr << "Open error!" << endl; exit(1);
	}
	cin.ignore();//不知道为什么输入文件的时候会自动加一个换行
	cout << "输入密码:" ;
	cin.getline(mima, 20, '\n');
	outfile1 << mima;
	outfile1.close();

}


///////////////////main函数



int main()
{
	system("color F0");   //把界面变成白底黑字
	int quanxiandog = 0;//教师的管理员权限
	course A;   //10门课
	student B[10];  //10个学生
	Teacher C[10];//老师
	int stucnt = 0;
	int dengluflag = -1;
	while (1)
	{
		int SW;
		cout << "*****************************************" << endl;
		cout << "欢迎来到选课系统,请选择编号进行操作" << endl;
		cout << "1.注册学生账号" << endl;
		cout << "2.登陆学生账号" << endl;
		cout << "3.注册教师账号" << endl;
		cout << "4.登录教师账号" << endl;
		cout << "*****************************************" << endl;
		cin >> SW;
		switch (SW)
		{
		case 1:
			char temp[20];
			cout << "请输入注册学号账号" << endl;
			cin >> temp;
			B[stucnt].setxuehao(temp);
			cout << "请输入登陆验证密码" << endl;
			cin >> temp;
			B[stucnt].setyanz(temp);
			cout << "注册成功,注册信息如下" << endl;
			B[stucnt].checkC();
			stucnt++;
			system("pause");
			break;
		case 2:
		{
			char temp1[10], ch1;
			int j = 0;
			cout << "请输入学号账号" << endl;
			cin >> temp;
		go1:cout << "请输入登陆验证密码" << endl;
			//cin >> temp1;
			while ((ch1 = _getch()) != '\r')  //用getch函数实现密码隐藏
			{
				if (ch1 == '\b' && j > 0)
				{
					cout << "\b \b";
					--j;
				}
				else if (ch1 != '\b')
				{
					temp1[j++] = ch1;
					cout << '*';
				}
			}
			temp1[j] = '\0';
			for (int i = 0; i < stucnt; i++)
			{
				if (B[i].xuehaopipei(temp) == true)
				{
					if (B[i].yanzpipei(temp1) == true)
					{
						cout << "\n登陆成功" << endl;
						dengluflag = i;
					}
					else
					{
						cout << "\n验证密码错误，重试" << endl;
						j = 0;
						goto go1;
					}
				}
			}
			if (dengluflag < 0)cout << "学号不存在" << endl;
			system("pause");
			break;
		}
		case 3:
			char zhanghao[20];
			char mima[20];
			C[stucnt].read(zhanghao, mima);
			cout << "注册成功" << endl;
			//cout << "账号为:" << zhanghao << endl;
			//cout << "密码为:" << mima << endl;
			C[stucnt].setxuehao(zhanghao);
			C[stucnt].setyanz(mima);
			C[stucnt].checkC();
			stucnt++;
			system("pause");
			break;
			/*char temp2[20];
			cout << "请输入教师账号" << endl;
			cin >> temp2;
			C[stucnt].setxuehao(temp2);
			cout << "请输入登陆验证密码" << endl;
			cin >> temp2;
			C[stucnt].setyanz(temp2);
			cout << "注册成功,注册信息如下" << endl;
			C[stucnt].checkC();
			stucnt++;
			system("pause");
			break;*/
		case 4:
			ifstream infile;
			infile.open("zhangh.dat", ios::in|ios::_Nocreate);
			if (!infile) {
				cerr << "error";
				exit(1);
			}
			infile >> C[stucnt].xuehao;
			//cout << C[stucnt].xuehao << endl;
			infile.close();

			ifstream infile1;
			infile1.open("mima.dat", ios::in | ios::_Nocreate);
			if (!infile1) {
				cerr << "error";
				exit(1);
			}
			infile1 >> C[stucnt].yanz;
			infile1.close();

			/////////////////////////////////////////////////////太密了都找不到了
			
			char temp3[10];
			char ch;
			int i = 0;
			cout << "请输入教师账号" << endl;
			cin >> temp;
		go2:cout << "请输入登陆验证密码" << endl;
			//cin >> temp3;
			while ((ch = _getch()) != '\r')  //用getch函数实现密码隐藏
			{
				if (ch == '\b' && i > 0)
				{
					cout << "\b \b";
					--i;
				}
				else if (ch != '\b')
				{
					temp3[i++] = ch;
					cout << '*';
				}
			}
			temp3[i] = '\0';
			//cout << "\n" << temp3;
			//for (int i = 0; i < stucnt; i++) //因为如果通过读取文件而不是注册的话stucnt就不会+1
			//{
				if (C[stucnt].xuehaopipei(temp) == true)
				{
					if (C[stucnt].yanzpipei(temp3) == true)
					{
						cout << "\n登陆成功" << endl;
						dengluflag = 1;//i
						quanxiandog = 1;
					}
					else
					{
						cout << "验证密码错误，重试" << endl;
						i = 0;
						goto go2;//重定义
					}
				}
			//}
			if (dengluflag < 0)
				cout << "账号不存在" << endl;
			system("pause");
			break;

		}
		if (dengluflag >= 0)
			while (1)
			{
				system("cls");
				int SW1 = 0;
				cout << "欢迎登陆，请选择功能编号" << endl;
				cout << "1.课程信息录入" << endl;
				cout << "2.课程信息修改" << endl;
				cout << "3.课程信息删除" << endl;
				cout << "4.课程信息浏览" << endl;
				cout << "5.开始选课" << endl;
				cout << "6.选课结果查询" << endl;
				cout << "7.课程信息保存" << endl;
				cout << "8.退出登陆" << endl;
				cin >> SW1;
				switch (SW1)
				{

					char temp[20];
				case 1:
				{
					if (quanxiandog) {
						int a1 = 0;
						system("cls");
						cout << "1.手动录入" << endl;
						cout << "2.从文件读取课程信息" << endl;
						cin >> a1;
						if (a1 == 1)A.getinf();
						else
						{
							cout << "请输入录入文件地址:";
							char adress1[256];
							cin >> adress1;
							if (A.fileread(adress1) == true)cout << "录入成功" << endl;
						}
					}else cout << "你的权限不足" << endl;
					system("pause");
					break;
				}
				case 2:
					if(quanxiandog)
						A.reinf();
					else cout << "你的权限不足" << endl;
					system("pause");
					break;
				case 3:
					if (quanxiandog)
						A.deinf();
					else cout << "你的权限不足" << endl;
					system("pause");
					break;
				case 4:
					A.printfc();
					system("pause");
					break;
				case 5:
					if (quanxiandog) {
						cout << "教师无法选课" << endl;
						break;
					}
					A.printfc();
					cout << "请输入要选的课程编号" << endl;
					cin >> temp;
					B[dengluflag].choiceC(temp);
					cout << "选课成功" << endl;
					system("pause");
					break;
				case 6:
				{
					system("cls");
					int sw = 0;
					int i = 0;
					cout << "1.按学号查询学生选课情况" << endl;
					cout << "2.按课程查询学生选课情况" << endl;
					cin >> sw;
					switch (sw)
					{
					case 1:
						cout << "请输入学号" << endl;
						cin >> temp;
						for (i = 0; i < stucnt; i++)
						{
							if (B[i].xuehaopipei(temp))B[i].checkC();
						}
						system("pause");
						break;
					case 2:
						char temp62[20];
						cout << "请输入查询课程编号" << endl;
						cin >> temp62;
						cout << "选择此门课程的学号有" << endl;
						for (int i = 0; i < stucnt; i++)
						{
							for (int j = 1; j <= B[i].kecnt; j++)
							{
								char temp1[20];
								B[i].getkc(j, temp1);
								if (strcmp(temp1, temp62) == 0)cout << B[i].xuehao << ",";
							}
						}
						cout << endl;
						break;
					}
					system("pause");
					break;
				}
				case 7:
				{
					char adress7[256];
					cout << "请输入文件的保存地址：";
					cin >> adress7;
					if (A.filesave(adress7) == true)cout << "保存成功";
					else cout << "保存失败" << endl;
					break;
				}
				case 8:
					dengluflag = -1;
					break;
				}
				if (dengluflag == -1)
				{
					cout << "正在退出登录...." << endl;
					break;
				}
				Sleep(500);
				system("cls");
			}
		Sleep(1000);
		system("cls");
	}



	system("pause");
	return 0;
}
