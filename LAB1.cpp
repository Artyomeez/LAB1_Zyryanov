// LAB1.cpp: определяет точку входа для консольного приложения.
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
	if ((pF=fopen(name1, "rt"))== NULL)  // Открываем файл для чтения в текстовом режиме
    	{
	 	printf("Error open file"); getch(); return 1;
	    }
	if ((pG = fopen(name2, "rt")) == NULL)  // Открываем файл для чтения в текстовом режиме
	{
		printf("Error open file"); getch(); return 1;
	}
	while (!feof(pF))   //Пока не конец файла pF
	{
		fgets(s1, 256, pF);  //Читаем из файла pF строку в s1
		pr = true;    // переменнай pr = истина
		while (!feof(pG))  //Пока не конец файла pG
		{
			fgets(s2, 256, pG);   //Читаем из файла pG строку в s2
			if (strcmp(s1, s2) == 0) pr = false;  //Если строки s1 и s2 совпадают, то  Pr = ложь
		}
		if (pr) printf("%s : %s\n", name1, s1);  //Если pr=истина (т.е. строка s1 не встречается в s2), то печатаем имя 1-го файла и строку s1
		rewind(pG);   //встаем на начало файла pG
	}
	rewind(pF); //Встаем на начало файла pF
	rewind(pG); //встаем на начало файла pG
	printf("\n");  
	while (!feof(pG)) //Пока не конец файла pG
	{
		fgets(s1, 256, pG); //читаем из файла pG строку в s1
		pr = true;
		while (!feof(pF))  // пока не конец файла pF
		{
			fgets(s2, 256, pF);  //читаем строку из файла pF в s2
			if (strcmp(s1, s2) == 0) pr = false; //Если строки s1 и s2 совпадают, то  Pr = ложь
		}
		if (pr) printf("%s : %s\n", name2, s1);//Если pr=истина (т.е. строка s1 не встречается в s2), то печатаем имя 2-го файла и строку s1
		rewind(pF);
	} 
	fclose(pF);
	fclose(pG); 
	getch();
	printf("\nfor exit press any key ");
	return 0;
}

