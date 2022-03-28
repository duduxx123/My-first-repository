#include<stdio.h>
int main()
{
	char ch;
	FILE* pfr = fopen("C:\\l1jh\\k\\test1.txt", "r");
	FILE* pfw = fopen("C:\\l1jh\\k\\test2.txt", "w");
	if (NULL == pfw)
	{
		perror("open file test2.txt");
	}
	if (NULL == pfr)
	{
		perror("open file test1.txt");
	}
	while ((ch = fgetc(pfr)) != EOF)
	{
		fputc(ch, pfw);
	}
	fclose(pfr);
	fclose(pfw);
	pfr = NULL;
	pfw = NULL;
	return 0;
}