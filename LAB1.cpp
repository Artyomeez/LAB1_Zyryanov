// LAB1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	FILE *pF, *pG;
	bool pr;
	char name1[50] = "f.txt";
	char name2[50] = "g.txt";
	char s1[256], s2[256];
	if ((pF=fopen(name1, "rt"))== NULL)  // ��������� ���� ��� ������ � ��������� ������
    	{
	 	printf("Error open file"); getch(); return 1;
	    }
	if ((pG = fopen(name2, "rt")) == NULL)  // ��������� ���� ��� ������ � ��������� ������
	{
		printf("Error open file"); getch(); return 1;
	}
	while (!feof(pF))   //���� �� ����� ����� pF
	{
		fgets(s1, 256, pF);  //������ �� ����� pF ������ � s1
		pr = true;    // ���������� pr = ������
		while (!feof(pG))  //���� �� ����� ����� pG
		{
			fgets(s2, 256, pG);   //������ �� ����� pG ������ � s2
			if (strcmp(s1, s2) == 0) pr = false;  //���� ������ s1 � s2 ���������, ��  Pr = ����
		}
		if (pr) printf("%s : %s\n", name1, s1);  //���� pr=������ (�.�. ������ s1 �� ����������� � s2), �� �������� ��� 1-�� ����� � ������ s1
		rewind(pG);   //������ �� ������ ����� pG
	}
	rewind(pF); //������ �� ������ ����� pF
	rewind(pG); //������ �� ������ ����� pG
	printf("\n");  
	while (!feof(pG)) //���� �� ����� ����� pG
	{
		fgets(s1, 256, pG); //������ �� ����� pG ������ � s1
		pr = true;
		while (!feof(pF))  // ���� �� ����� ����� pF
		{
			fgets(s2, 256, pF);  //������ ������ �� ����� pF � s2
			if (strcmp(s1, s2) == 0) pr = false; //���� ������ s1 � s2 ���������, ��  Pr = ����
		}
		if (pr) printf("%s : %s\n", name2, s1);//���� pr=������ (�.�. ������ s1 �� ����������� � s2), �� �������� ��� 2-�� ����� � ������ s1
		rewind(pF);
	} 
	fclose(pF);
	fclose(pG); 
	getch();
	printf("\nfor exit press any key ");
	return 0;
}

