#include<iostream>
#include<Windows.h>
#include <random>
using namespace std;
DWORD WINAPI father(LPVOID lpParameter);
DWORD WINAPI son(LPVOID lpParameter);
DWORD WINAPI dau(LPVOID lpParameter);
int panzi;//盘子
HANDLE semaphore1;//盘子空
HANDLE semaphore2;//有苹果
HANDLE semaphore3;//有橘子
HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;
int main() {
	//初始化缓冲区
	panzi = 0;
	//创建信号量
	semaphore1 = CreateSemaphore(NULL, 1, 1, NULL);
	semaphore2 = CreateSemaphore(NULL, 0, 1, NULL);
	semaphore3 = CreateSemaphore(NULL, 0, 1, NULL);
	while (1) {
		//创建线程
		hThread1 = CreateThread(NULL, 0, father, NULL, 0, NULL);
		hThread2 = CreateThread(NULL, 0, dau, NULL, 0, NULL);
		hThread3 = CreateThread(NULL, 0, son, NULL, 0, NULL);
		Sleep(1000);
	}
}
DWORD WINAPI father(LPVOID lpParameter) {
	while (1) {
		//等待缓冲区空
		WaitForSingleObject(semaphore1, INFINITE);
		panzi = rand();
		cout << panzi << endl;
		if (panzi % 2 == 0) {
			//苹果
			printf("爸爸往盘子里放了苹果\n");
			Sleep(1000);
			ReleaseSemaphore(semaphore2, 1, NULL);
		}
		else {
			//橘子
			printf("爸爸往盘子里放了橘子\n");
			Sleep(1000);
			ReleaseSemaphore(semaphore3, 1, NULL);
		}
	}
	return 0;
}
DWORD WINAPI son(LPVOID lpParameter) {
	while (1) {
		WaitForSingleObject(semaphore3, INFINITE);
		printf("儿子吃橘子\n");
		ReleaseSemaphore(semaphore1, 1, NULL);
	}
}
DWORD WINAPI dau(LPVOID lpParameter) {
	while (1) {
		WaitForSingleObject(semaphore2, INFINITE);
		printf("女儿吃苹果\n");
		ReleaseSemaphore(semaphore1, 1, NULL);
	}
}
