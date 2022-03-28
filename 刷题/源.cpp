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
	int cnt;    //��ӵĿγ�����
	vector<struct kc> C;
	course();
	void printfc();
	void reinf();//�޸�
	void deinf();//ɾ���γ�
	void getinf();//¼��γ���Ϣ
	bool filesave(char*temp); //�����ı��ļ�
	bool fileread(char*temp); //��ȡ�ı��ļ�
};

course::course() {cnt = 0;}

void course::printfc()
{
	cout << "�γ̱�ţ��γ����ƣ��γ�ѧʱ���γ�ѧ�֣���ѧʱ��\n";
	string a;
	ifstream infile;
	infile.open("book.dat", ios::in);
	if (!infile) {
		cerr << "Open error!" << endl; exit(1);
	}
	/*while (infile >> a)   //�����������ո�ֱ�ӽ�����
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
	cout << "������γ̵ı�Ż�������" << endl;
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
	cout << "��ѯ�γ���ϢΪ";
	printfc();
	cout << "\n�������޸ĺ�� �γ̱�ţ��γ����ƣ��γ�ѧʱ���γ�ѧ�֣���ѧʱ�䣨xxxx,x,x��" << endl;
	getinf();
	/*cin >> temp;
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(C.at(i).bianhao, temp) == 0 || strcmp(C.at(i).name, temp) == 0)
			break;
	}
	cout << "��ѯ�γ���ϢΪ" << C.at(i).bianhao << "      " << C.at(i).name << "      " << C.at(i).xueshi << "      "
		<< C.at(i).xuefen << "      " << C.at(i).kaixueinf << endl;
	cout << "\n�������޸ĺ�� �γ̱�ţ��γ����ƣ��γ�ѧʱ���γ�ѧ�֣���ѧʱ�䣨xxxx,x,x��" << endl;

	cin >> C.at(i).bianhao;
	cin >> C.at(i).name;
	cin >> C.at(i).xueshi;
	cin >> C.at(i).xuefen;
	cin >> C.at(i).kaixueinf;
	cout << "�޸ĳɹ�" << endl;*/
}

void course::deinf()
{
	char temp[20];
	cout << "������γ̵ı�Ż�������" << endl;
	cin >> temp;
	int i = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(C.at(i).bianhao, temp) == 0 || strcmp(C.at(i).name, temp) == 0)break;

	}
	if (i == cnt)
	{
		cout << "�޴˿γ�" << endl;
		return;
	}
	cout << "ɾ���γ���ϢΪ" << C.at(i).bianhao <<"      "<< C.at(i).name<<"      "
	<< C.at(i).xueshi << "      " << C.at(i).xuefen << "      " << C.at(i).kaixueinf << "\n�Ƿ�ȷ��ɾ��?������1����������0\n";
	int Isde = 0;
	cin >> Isde;
	if (Isde)
	{
		C.erase(C.begin() + i);  //����Ϊ��������ַ
		cnt--;
		cout << "ɾ���ɹ�" << endl;
	}
}
void course::getinf()
{
	int N = 0;
	cout << "������Ҫ¼��Ŀγ�����" << endl;
	cin >> N;
	struct kc a;
	ofstream outfile;
	outfile.open("book.dat", ios::out);
	if (!outfile) {
		cerr << "Open error!" << endl; exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		cout << "������ �γ̱�ţ��γ����ƣ��γ�ѧʱ���γ�ѧ�֣���ѧʱ�䣨xxxx.x.x��" << endl;
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

	cout << "¼�����" << endl;
}
bool course::filesave(char*temp)
{
	ofstream out;
	out.open(temp, ios::out);
	if (out.is_open() == 0)
		return false;
	out << "�γ���Ϣ" << endl;
	for (int i = 0; i < cnt; i++)
	{

		out << C.at(i).bianhao << endl;
		out << C.at(i).name << endl;
		out << C.at(i).kaixueinf << endl;
		out << C.at(i).xuefen << endl;
		out << C.at(i).xueshi << endl;
	}
	out << "¼�����" << endl;
	out.close();
	return true;
}
bool course::fileread(char*temp) //��ȡ�ı��ļ�
{
	char data[20];
	ifstream in;
	in.open(temp, ios::in);
	if (in.is_open() == 0)return false;
	in >> data;
	if (strcmp("�γ���Ϣ", data) != 0)
	{
		cout << "���ǿγ������ļ�����ʧ��" << endl;
		return false;
	}
	while (1)
	{
		struct kc a;
		in >> a.bianhao;
		if (strcmp(a.bianhao, "¼�����") == 0)break;
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
	int kecnt;            //��ѡ�γ���Ŀ

	student(char *_xuehao = NULL, char *_yanz = NULL);//����
	void choiceC(char* _bianhao);                              //ѡ�ι���
	void checkC();                             //��ѯ����
	void getkc(int cnt, char* temp);           //���ص�cnt���γ̵ı��
	void setyanz(char *_yanz);                 //������֤��
	void setxuehao(char *_xuehao);			  //����ѧ��
	bool xuehaopipei(char *_xuehao);          //ѧ���Ƿ�ƥ��
	bool yanzpipei(char*_yanz);               //��֤���Ƿ�ƥ��
};

student::student(char *_xuehao, char *_yanz)
{
	kecnt = 0;
	yixuankec[0] = 0;
	if (_xuehao != NULL)strcpy(xuehao, _xuehao);
	if (_yanz != NULL)strcpy(yanz, _yanz);
}

void student::choiceC(char* _bianhao)                              //ѡ�ι���
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
	strcpy(yixuankec + i, _bianhao);//�˴�û���ж�i�Ƿ�Խ��
	kecnt++;
}
void student::checkC()									//��ѯ����
{
	cout << "ѧ��:" << xuehao << endl;
	cout<<"��½��֤:" << yanz << endl;
	//cout<<"��ѡ�γ̱�ţ�" << yixuankec << endl;

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

void student::setyanz(char *_yanz)                 //����������֤��
{
	strcpy(yanz, _yanz);
	//cout << "���óɹ�" << endl;
}
void student::setxuehao(char *_xuehao)			  //����ѧ��
{
	strcpy(xuehao, _xuehao);
	//cout << "����ɹ�" << endl;
}

bool student::xuehaopipei(char *_xuehao)          //ѧ���Ƿ�ƥ��
{
	if (strcmp(xuehao, _xuehao) == 0)
		return true;
	else return false;
}
bool student::yanzpipei(char*_yanz)              //�����Ƿ�ƥ��
{
	if (strcmp(yanz, _yanz) == 0)
		return true;
	else return false;
}


/////////////Teacher


class Teacher :public student
{
public:
	Teacher(char *_xuehao = NULL, char *_yanz = NULL);//����
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
void Teacher::checkC()									//��ѯ����
{
	cout << "��ʦ���:" << xuehao << endl;
	cout << "��½����:" << yanz << endl;
	//cout << "ѧ����ѡ�γ̱�ţ�" << yixuankec << endl;

}
void Teacher::read(char *zhanghao,char *mima)
{
	//char zhanghao[20];
	//char mima[20];
	//cout << "��������" << endl;
	//cin.getline(mima, 20, '\n');
	ofstream outfile;
	outfile.open("zhangh.dat", ios::out);
	if (!outfile) {
		cerr << "Open error!" << endl; exit(1);
	}
	cout << "�����˺�:" ;
	cin.ignore();//��֪��Ϊʲô�����ļ���ʱ����Զ���һ������������ignore���Ե�
	cin.getline(zhanghao, 20, '\n');//ΪʲôҪ��2�λس�������������������
	outfile << zhanghao;             //��������ΪC++������\n�س���\r����Ҳ�������
	outfile.close();

	ofstream outfile1;
	outfile1.open("mima.dat", ios::out);
	if (!outfile1){
		cerr << "Open error!" << endl; exit(1);
	}
	cin.ignore();//��֪��Ϊʲô�����ļ���ʱ����Զ���һ������
	cout << "��������:" ;
	cin.getline(mima, 20, '\n');
	outfile1 << mima;
	outfile1.close();

}


///////////////////main����



int main()
{
	system("color F0");   //�ѽ����ɰ׵׺���
	int quanxiandog = 0;//��ʦ�Ĺ���ԱȨ��
	course A;   //10�ſ�
	student B[10];  //10��ѧ��
	Teacher C[10];//��ʦ
	int stucnt = 0;
	int dengluflag = -1;
	while (1)
	{
		int SW;
		cout << "*****************************************" << endl;
		cout << "��ӭ����ѡ��ϵͳ,��ѡ���Ž��в���" << endl;
		cout << "1.ע��ѧ���˺�" << endl;
		cout << "2.��½ѧ���˺�" << endl;
		cout << "3.ע���ʦ�˺�" << endl;
		cout << "4.��¼��ʦ�˺�" << endl;
		cout << "*****************************************" << endl;
		cin >> SW;
		switch (SW)
		{
		case 1:
			char temp[20];
			cout << "������ע��ѧ���˺�" << endl;
			cin >> temp;
			B[stucnt].setxuehao(temp);
			cout << "�������½��֤����" << endl;
			cin >> temp;
			B[stucnt].setyanz(temp);
			cout << "ע��ɹ�,ע����Ϣ����" << endl;
			B[stucnt].checkC();
			stucnt++;
			system("pause");
			break;
		case 2:
		{
			char temp1[10], ch1;
			int j = 0;
			cout << "������ѧ���˺�" << endl;
			cin >> temp;
		go1:cout << "�������½��֤����" << endl;
			//cin >> temp1;
			while ((ch1 = _getch()) != '\r')  //��getch����ʵ����������
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
						cout << "\n��½�ɹ�" << endl;
						dengluflag = i;
					}
					else
					{
						cout << "\n��֤�����������" << endl;
						j = 0;
						goto go1;
					}
				}
			}
			if (dengluflag < 0)cout << "ѧ�Ų�����" << endl;
			system("pause");
			break;
		}
		case 3:
			char zhanghao[20];
			char mima[20];
			C[stucnt].read(zhanghao, mima);
			cout << "ע��ɹ�" << endl;
			//cout << "�˺�Ϊ:" << zhanghao << endl;
			//cout << "����Ϊ:" << mima << endl;
			C[stucnt].setxuehao(zhanghao);
			C[stucnt].setyanz(mima);
			C[stucnt].checkC();
			stucnt++;
			system("pause");
			break;
			/*char temp2[20];
			cout << "�������ʦ�˺�" << endl;
			cin >> temp2;
			C[stucnt].setxuehao(temp2);
			cout << "�������½��֤����" << endl;
			cin >> temp2;
			C[stucnt].setyanz(temp2);
			cout << "ע��ɹ�,ע����Ϣ����" << endl;
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

			/////////////////////////////////////////////////////̫���˶��Ҳ�����
			
			char temp3[10];
			char ch;
			int i = 0;
			cout << "�������ʦ�˺�" << endl;
			cin >> temp;
		go2:cout << "�������½��֤����" << endl;
			//cin >> temp3;
			while ((ch = _getch()) != '\r')  //��getch����ʵ����������
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
			//for (int i = 0; i < stucnt; i++) //��Ϊ���ͨ����ȡ�ļ�������ע��Ļ�stucnt�Ͳ���+1
			//{
				if (C[stucnt].xuehaopipei(temp) == true)
				{
					if (C[stucnt].yanzpipei(temp3) == true)
					{
						cout << "\n��½�ɹ�" << endl;
						dengluflag = 1;//i
						quanxiandog = 1;
					}
					else
					{
						cout << "��֤�����������" << endl;
						i = 0;
						goto go2;//�ض���
					}
				}
			//}
			if (dengluflag < 0)
				cout << "�˺Ų�����" << endl;
			system("pause");
			break;

		}
		if (dengluflag >= 0)
			while (1)
			{
				system("cls");
				int SW1 = 0;
				cout << "��ӭ��½����ѡ���ܱ��" << endl;
				cout << "1.�γ���Ϣ¼��" << endl;
				cout << "2.�γ���Ϣ�޸�" << endl;
				cout << "3.�γ���Ϣɾ��" << endl;
				cout << "4.�γ���Ϣ���" << endl;
				cout << "5.��ʼѡ��" << endl;
				cout << "6.ѡ�ν����ѯ" << endl;
				cout << "7.�γ���Ϣ����" << endl;
				cout << "8.�˳���½" << endl;
				cin >> SW1;
				switch (SW1)
				{

					char temp[20];
				case 1:
				{
					if (quanxiandog) {
						int a1 = 0;
						system("cls");
						cout << "1.�ֶ�¼��" << endl;
						cout << "2.���ļ���ȡ�γ���Ϣ" << endl;
						cin >> a1;
						if (a1 == 1)A.getinf();
						else
						{
							cout << "������¼���ļ���ַ:";
							char adress1[256];
							cin >> adress1;
							if (A.fileread(adress1) == true)cout << "¼��ɹ�" << endl;
						}
					}else cout << "���Ȩ�޲���" << endl;
					system("pause");
					break;
				}
				case 2:
					if(quanxiandog)
						A.reinf();
					else cout << "���Ȩ�޲���" << endl;
					system("pause");
					break;
				case 3:
					if (quanxiandog)
						A.deinf();
					else cout << "���Ȩ�޲���" << endl;
					system("pause");
					break;
				case 4:
					A.printfc();
					system("pause");
					break;
				case 5:
					if (quanxiandog) {
						cout << "��ʦ�޷�ѡ��" << endl;
						break;
					}
					A.printfc();
					cout << "������Ҫѡ�Ŀγ̱��" << endl;
					cin >> temp;
					B[dengluflag].choiceC(temp);
					cout << "ѡ�γɹ�" << endl;
					system("pause");
					break;
				case 6:
				{
					system("cls");
					int sw = 0;
					int i = 0;
					cout << "1.��ѧ�Ų�ѯѧ��ѡ�����" << endl;
					cout << "2.���γ̲�ѯѧ��ѡ�����" << endl;
					cin >> sw;
					switch (sw)
					{
					case 1:
						cout << "������ѧ��" << endl;
						cin >> temp;
						for (i = 0; i < stucnt; i++)
						{
							if (B[i].xuehaopipei(temp))B[i].checkC();
						}
						system("pause");
						break;
					case 2:
						char temp62[20];
						cout << "�������ѯ�γ̱��" << endl;
						cin >> temp62;
						cout << "ѡ����ſγ̵�ѧ����" << endl;
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
					cout << "�������ļ��ı����ַ��";
					cin >> adress7;
					if (A.filesave(adress7) == true)cout << "����ɹ�";
					else cout << "����ʧ��" << endl;
					break;
				}
				case 8:
					dengluflag = -1;
					break;
				}
				if (dengluflag == -1)
				{
					cout << "�����˳���¼...." << endl;
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