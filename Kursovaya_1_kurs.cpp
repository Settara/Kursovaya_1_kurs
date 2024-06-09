#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <locale.h>
//Обьявляем тип структуры записи моей базы данных
struct haracter
{
	char fio[100]; //Произвольная строка
	char pol; // m - мужской g - женский, остальные недопустимы
	int voz; //ОТ 0 До 100 лет
	int rost;//От 0 до 250 см
	int ves;// От 0 до 200 кг
	char znak[100]; //Произвольная строка
	char prof[100]; //Произвольная строка
	int flagg[8]; // Массив флагов показывающих какие поля введены для запроса
};
//Обьявляем массив структур для тестовых данных
struct haracter ludi[20];
//Прототип функции f2
void f2(char* file);
int flaaa = 0; //flaaa отвечает за то, чтобы если пользователь выбрал изменить запрос до его создания, он не смог этого сделать
void f11(char* file) // создание файла, т.е. ввод чисел с клавиатуры и запись их в файл
{
	FILE* fp; // fp - файловая переменная для связи программы с файлом
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	int i, f;//Флажок для ESC
	printf("Функция 1.1\n");
	fp = fopen(file, "w"); // создаем и открываем файл в текущей папке для записи в него, связываем этот файл с переменной fp в программе
		do
		{
			while (getchar() != '\n');
			puts("Введите строку\n");
			puts("Образец:Ivanov I.P. M 35 180 79 Lev Programist\n");
			puts("Введите ФИО"); gets_s(chelovek.fio);
			puts("Введите Знак зодиака"); gets_s(chelovek.znak);
			puts("Введите профессию"); gets_s(chelovek.prof);
			puts("Введите Пол"); scanf("%c", &chelovek.pol);
			do {
				puts("Введите Возраст(но не более 150 лет)");
				while (scanf("%d", &chelovek.voz) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите возраст: ");
				}
			} while ((chelovek.voz < 1) || (chelovek.voz > 150));
			do
			{
				puts("Введите Рост(но не более 250 см)");
				while (scanf("%d", &chelovek.rost) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите рост: ");
				}
			} while ((chelovek.rost < 1) || (chelovek.rost > 250));
			do
			{
				puts("Введите Вес(но не более 300 кг)");
				while (scanf("%d", &chelovek.ves) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите вес: ");
				}
			} while ((chelovek.ves < 1) || (chelovek.ves > 300));
			if (fp == NULL)
			{
				printf("Файл не открылся"); // Если файл не открылся, то выход из функции
			}
			else
			{
				fprintf(fp, "%s %s %s ", chelovek.fio, chelovek.znak, chelovek.prof);
				fprintf(fp, "%c ", chelovek.pol);
				fprintf(fp, "%d ", chelovek.voz);
				fprintf(fp, "%d ", chelovek.rost);
				fprintf(fp, "%d ", chelovek.ves);
				fprintf(fp, "\n");
			}
			printf("\nЖелаете ли ввести еще одну строку?\n");
			printf("Любая клавиша - Да, Esc - нет\n");
			f = _getch();
		} while (f != 27);
		//Ввод в файл тестового массива
		/*for (i = 0; i < 5; i++)
		{
		fprintf(fp, "%s %s %s ", ludi[i].fio, ludi[i].znak, ludi[i].prof);
		fprintf(fp, "%c ", ludi[i].pol);
		fprintf(fp, "%d ", ludi[i].voz);
		fprintf(fp, "%d ", ludi[i].rost);
		fprintf(fp, "%d ", ludi[i].ves);
		fprintf(fp, "\n");
		} */
		fclose(fp); // Закрываем файл
}
void f12(char* file) //Функция удаления строки
{
	FILE* fp, * zp; // fp - исходный файл для чтения, zp - вспомогательный файл для записи
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	int udalit, i1;
	int f;//Флажок для ESC
	int res;//Переменная контроля ошибки в сканф
	char temp_f[] = "t.txt";
	printf("Функция 1.2\n");
	printf("Ваш список\n");
	f2(file);
	do
	{
		printf("Введите номер cтроки который хотите удалить\n");
		while (scanf("%d", &udalit) != 1)
		{
			while (getchar() != '\n');
			printf("Ошибка. Введите номер cтроки: ");
		}
		fp = fopen(file, "r");
		zp = fopen(temp_f, "w");
		i1 = 1;
		do
		{
			if (i1 != udalit)
			{
				res = fscanf(fp, "%s ", &chelovek.fio);
				if (res != EOF) fprintf(zp, "%s ", chelovek.fio);
				res = fscanf(fp, "%s ", &chelovek.znak);
				if (res != EOF) fprintf(zp, "%s ", chelovek.znak);
				res = fscanf(fp, "%s ", &chelovek.prof);
				if (res != EOF) fprintf(zp, "%s ", chelovek.prof);
				res = fscanf(fp, "%c ", &chelovek.pol);
				if (res != EOF) fprintf(zp, "%c ", chelovek.pol);
				res = fscanf(fp, "%d ", &chelovek.voz);
				if (res != EOF) fprintf(zp, "%d ", chelovek.voz);
				res = fscanf(fp, "%d ", &chelovek.rost);
				if (res != EOF) fprintf(zp, "%d ", chelovek.rost);
				res = fscanf(fp, "%d ", &chelovek.ves);
				if (res != EOF) fprintf(zp, "%d ", chelovek.ves);
				fprintf(zp, "\n");
			}
			else
			{
				res = fscanf(fp, "%s ", &chelovek.fio);
				res = fscanf(fp, "%s ", &chelovek.znak);
				res = fscanf(fp, "%s ", &chelovek.prof);
				res = fscanf(fp, "%c ", &chelovek.pol);
				res = fscanf(fp, "%d ", &chelovek.voz);
				res = fscanf(fp, "%d ", &chelovek.rost);
				res = fscanf(fp, "%d ", &chelovek.ves);
			}
			i1 = i1 + 1;
		} while (res != EOF);
		//Проверка на существование строки введеной пользователем
		if ((udalit <= 0) || (udalit > ((i1 - 1) - 1))) //Так как прив вводе появляется последняя пустая строка(возрат каретки) мы пишем(i1 - 1) и - 1
			printf("Строки с таким номером не существует\n");
		//Закрываем файлы
		fclose(fp);
		fclose(zp);
		remove(file); // Удаляем исходный файл
		rename(temp_f, file); //Переименовываем временный файл в исходный
		f2(file);
		printf("\nЖелаете ли ввести еще одну строку?\n");
		printf("Любая клавиша - Да, Esc - нет\n");
		f = _getch();
	} while (f != 27);
}
void f13(char* file) //Функция редактирования строки
{
	FILE* fp, * zp; // fp - исходный файл для чтения, zp - вспомогательный файл для записи
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	int udalit, i1;
	int f;//Флажок для ESC
	int res;//Переменная контроля ошибки в сканф
	char temp_f[] = "t.txt";
	printf("Функция 1.3\n");
	printf("Ваш список\n");
	f2(file);
	do
	{
		printf("Введите номер cтроки который хотите отредактировать\n");
		while (scanf("%d", &udalit) != 1)
		{
			while (getchar() != '\n');
			printf("Ошибка. Введите номер cтроки: ");
		}
		i1 = 1;
		fp = fopen(file, "r");
		zp = fopen(temp_f, "w");
		i1 = 1;
		do
		{
			if (i1 != udalit)
			{
				res = fscanf(fp, "%s ", &chelovek.fio);
				if (res != EOF) fprintf(zp, "%s ", chelovek.fio);
				res = fscanf(fp, "%s ", &chelovek.znak);
				if (res != EOF) fprintf(zp, "%s ", chelovek.znak);
				res = fscanf(fp, "%s ", &chelovek.prof);
				if (res != EOF) fprintf(zp, "%s ", chelovek.prof);
				res = fscanf(fp, "%c ", &chelovek.pol);
				if (res != EOF) fprintf(zp, "%c ", chelovek.pol);
				res = fscanf(fp, "%d ", &chelovek.voz);
				if (res != EOF) fprintf(zp, "%d ", chelovek.voz);
				res = fscanf(fp, "%d ", &chelovek.rost);
				if (res != EOF) fprintf(zp, "%d ", chelovek.rost);
				res = fscanf(fp, "%d ", &chelovek.ves);
				if (res != EOF) fprintf(zp, "%d ", chelovek.ves);
				fprintf(zp, "\n");
			}
			else
			{
				res = fscanf(fp, "%s ", &chelovek.fio);
				res = fscanf(fp, "%s ", &chelovek.znak);
				res = fscanf(fp, "%s ", &chelovek.prof);
				res = fscanf(fp, "%c ", &chelovek.pol);
				res = fscanf(fp, "%d ", &chelovek.voz);
				res = fscanf(fp, "%d ", &chelovek.rost);
				res = fscanf(fp, "%d ", &chelovek.ves);
				while (getchar() != '\n');
				puts("Введите строку\n");
				puts("Образец:Ivanov I.P. M 35 180 79 Lev Programist\n");
				puts("Введите ФИО"); gets_s(chelovek.fio);
				puts("Введите Знак зодиака"); gets_s(chelovek.znak);
				puts("Введите профессию"); gets_s(chelovek.prof);
				puts("Введите Пол"); scanf("%c", &chelovek.pol);
				do {
					puts("Введите Возраст(но не более 150 лет)");
					while (scanf("%d", &chelovek.voz) != 1)
					{
						while (getchar() != '\n');
						printf("Ошибка. Введите возраст: ");
					}
				} while ((chelovek.voz < 1) || (chelovek.voz > 150));
				do
				{
					puts("Введите Рост(но не более 250 см)");
					while (scanf("%d", &chelovek.rost) != 1)
					{
						while (getchar() != '\n');
						printf("Ошибка. Введите рост: ");
					}
				} while ((chelovek.rost < 1) || (chelovek.rost > 250));
				do
				{
					puts("Введите Вес(но не более 300 кг)");
					while (scanf("%d", &chelovek.ves) != 1)
					{
						while (getchar() != '\n');
						printf("Ошибка. Введите вес: ");
					}
				} while ((chelovek.ves < 1) || (chelovek.ves > 300));
				fprintf(zp, "%s ", chelovek.fio);
				fprintf(zp, "%s ", chelovek.znak);
				fprintf(zp, "%s ", chelovek.prof);
				fprintf(zp, "%c ", chelovek.pol);
				fprintf(zp, "%d ", chelovek.voz);
				fprintf(zp, "%d ", chelovek.rost);
				fprintf(zp, "%d ", chelovek.ves);
				fprintf(zp, "\n");
			}
			i1 = i1 + 1;
		} while (res != EOF);
		//Проверка на существование строки введеной пользователем
		if ((udalit <= 0) || (udalit > ((i1 - 1) - 1))) //Так как прив вводе появляется последняя пустая строка(возрат каретки) мы пишем(i1 - 1) и - 1
			printf("Строки с таким номером не существует\n");
		//Закрываем файлы
		fclose(fp);
		fclose(zp);
		remove(file); // Удаляем исходный файл
		rename(temp_f, file); //Переименовываем временный файл в исходный
		f2(file);
		printf("\nЖелаете ли отредактировать еще одну строку?\n");
		printf("Любая клавиша - Да, Esc - нет\n");
		f = _getch();
	} while (f != 27);
}
void f2(char* file) // вывод содержимого файла, то есть чтение файла
{
	FILE* fp; // fp - файловая переменная для связи программы с некоторым файлом
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	int res;//Переменная контроля ошибки в сканф
	int i2;
	fp = fopen(file, "r"); // открываем файл для чтения из него, связываем этот файл с переменной fp в программе
	if (fp == NULL)
	{
		printf("Файл не открылся"); // Если файл не открылся, то выход из функции
	}
	else
	{
		i2 = 1;
		printf("\nВаш файл:\n");
		do
		{
			res = fscanf(fp, "%s ", &chelovek.fio);
			if (res != EOF) printf("%10.10s ", chelovek.fio);
			res = fscanf(fp, "%s ", &chelovek.znak);
			if (res != EOF) printf("%10.10s ", chelovek.znak);
			res = fscanf(fp, "%s ", &chelovek.prof);
			if (res != EOF) printf("%10.10s ", chelovek.prof);
			res = fscanf(fp, "%c ", &chelovek.pol);
			if (res != EOF) printf("%c ", chelovek.pol);
			res = fscanf(fp, "%d ", &chelovek.voz);
			if (res != EOF) printf("%d ", chelovek.voz);
			res = fscanf(fp, "%d ", &chelovek.rost);
			if (res != EOF) printf("%d ", chelovek.rost);
			res = fscanf(fp, "%d ", &chelovek.ves);
			if (res != EOF) printf("%3d ", chelovek.ves);
			printf("\n");
			i2 = i2 + 1;
		} while (res != EOF);
	}
	fclose(fp); // Закрываем файл
}
struct haracter f31(char* file, struct haracter zap) //Скоректировать предыдущий запрос
{
	printf("Функция 3.1\n");
	FILE* fp; // fp - исходный файл для чтения
	int res;//Переменная контроля ошибки в сканф
	char temp_f[] = "t.txt";
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	//struct haracter zap;
	int f, metka, flakok, fla, flagokk, i;
	fla = 0;
	fp = fopen(file, "r");
	do
	{
		printf("Выберите поле по которому хотите изменить запрос\n");
		printf("Вам доступны поля:\n");
		if (zap.flagg[1] == 1)
		{
			printf(" Фио ");
		}
		if (zap.flagg[2] == 1)
		{
			printf(" Знак зодиака ");
		}
		if (zap.flagg[3] == 1)
		{
			printf(" Профессия ");
		}
		if (zap.flagg[4] == 1)
		{
			printf(" Пол ");
		}
		if (zap.flagg[5] == 1)
		{
			printf(" Возраст ");
		}
		if (zap.flagg[6] == 1)
		{
			printf(" Рост ");
		}
		if (zap.flagg[7] == 1)
		{
			printf(" Вес ");
		}
		printf("\n");
		do
		{
			printf(" Введите 1 если хотите выбрать ФИО \n Введите 2 если хотите выбрать ЗНАК ЗОДИАКА \n Введите 3 если хотите выбрать ПРОФЕССИЮ \n Введите 4 если хотите выбрать ПОЛ \n Введите 5 если хотите выбрать ВОЗРАСТ \n Введите 6 если хотите выбрать РОСТ \n Введите 7 если хотите ввести ВЕС \n ");
				while (scanf("%d", &metka) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите число от 1 до 7 включительно: ");
				}
		} while ((metka < 1) || (metka > 7));
		flakok = 0;
		if ((metka == 1) && (zap.flagg[1] == 1))
		{
			while (getchar() != '\n');
			printf("Введите ФИО\n");
			gets_s(zap.fio);
			flakok = 1;
		}
		if ((metka == 2) && (zap.flagg[2] == 1))
		{
			while (getchar() != '\n');
			printf("Введите Знак зодиака\n");
			gets_s(zap.znak);
			flakok = 1;
		}
		if ((metka == 3) && (zap.flagg[3] == 1))
		{
			while (getchar() != '\n');
			printf("Введите Профессию\n");
			gets_s(zap.prof);
			flakok = 1;
		}
		if ((metka == 4) && (zap.flagg[4] == 1))
		{
			while (getchar() != '\n');
			printf("Введите Пол\n");
			scanf("%c", &zap.pol);
			flakok = 1;
		}
		if ((metka == 5) && (zap.flagg[5] == 1))
		{
			do
			{
				printf("Введите возраст(но не более 150 лет)\n");
				while (scanf("%d", &zap.voz) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите возраст: ");
				}
			} while ((zap.voz < 1) || (zap.voz > 150));
			while (getchar() != '\n');
			flakok = 1;
		}
		if ((metka == 6) && (zap.flagg[6] == 1))
		{
			do
			{
				printf("Введите рост(но не более 250 см)\n");
				while (scanf("%d", &zap.rost) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите рост: ");
				}
			} while ((zap.rost < 1) || (zap.rost > 250));
			while (getchar() != '\n');
			flakok = 1;
		}
		if ((metka == 7) && (zap.flagg[7] == 1))
		{
			do
			{
				printf("Введите вес(но не более 300 кг)\n");
				while (scanf("%d", &zap.ves) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите вес: ");
				}
			} while ((zap.ves < 1) || (zap.ves > 300));
			while (getchar() != '\n');
			flakok = 1;
		}
		if (flakok == 0) printf("В вашем запросе нет такого поля");
		printf("\nЖелате ли скоректировать другое поле в запросе?\n");
		printf("Люба клавиша - Да, Esc - нет\n");
		f = _getch();
	} while (f != 27);
	printf("Результаты по отредактированому запросу\n");
	do //блок проверки запросов
	{
		flagokk = 0;
		res = fscanf(fp, "%s ", &chelovek.fio);
		if (res != EOF)
		{
			if ((zap.flagg[1] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.fio, chelovek.fio) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%s ", &chelovek.znak);
		if (res != EOF)
		{
			if ((zap.flagg[2] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.znak, chelovek.znak) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%s ", &chelovek.prof);
		if (res != EOF)
		{
			if ((zap.flagg[3] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.prof, chelovek.prof) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%c ", &chelovek.pol);
		if (res != EOF)
		{
			if ((zap.flagg[4] == 1) && (flagokk != 2))
			{
				if (zap.pol == chelovek.pol)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.voz);
		if (res != EOF)
		{
			if ((zap.flagg[5] == 1) && (flagokk != 2))
			{
				if (zap.voz == chelovek.voz)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.rost);
		if (res != EOF)
		{
			if ((zap.flagg[6] == 1) && (flagokk != 2))
			{
				if (zap.rost == chelovek.rost)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.ves);
		if (res != EOF)
		{
			if ((zap.flagg[7] == 1) && (flagokk != 2))
			{
				if (zap.ves == chelovek.ves)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		if (flagokk == 1)
		{
			printf("%s ", chelovek.fio);
			printf("%s ", chelovek.znak);
			printf("%s ", chelovek.prof);
			printf("%c ", chelovek.pol);
			printf("%d ", chelovek.voz);
			printf("%d ", chelovek.rost);
			printf("%d ", chelovek.ves);
			printf("\n");
			fla = 1;
		}
	} while (res != EOF);
	if (fla == 0)
	{
		printf(" По вашему запросу ничего не найдено\n ");
	}
	return zap;
	//Закрываем файлы
	fclose(fp);
}
struct haracter f32(char* file) //Ввести новый запрос
{
	FILE* fp; // fp - исходный файл для чтения
	int res;//Переменная контроля ошибки в сканф
	char temp_f[] = "t.txt";
	struct haracter chelovek; //Обьявляем структуру для записи в файл
	struct haracter zap;
	int flagokk;
	flaaa = 1; //flaaa отвечает за то, чтобы если пользователь выбрал изменить запрос до его создания, он не смог этого сделать
		printf("Функция 3.2\n");
	while (getchar() != '\n');
	int metka, i;
	int f, i4, fla;
	for (i4 = 1; i4 < 8; i4++)
	{
		zap.flagg[i4] = 0; // не делать при изменении запроса
	}
	do
	{
		printf("Выберите поле по которому хотите ввести запрос\n");
		do
		{
			printf(" Введите 1 если хотите выбрать ФИО \n Введите 2 если хотите выбрать ЗНАК ЗОДИАКА \n Введите 3 если хотите выбрать ПРОФЕССИЮ \n Введите 4 если хотите выбрать ПОЛ \n Введите 5 если хотите выбрать ВОЗРАСТ \n Введите 6 если хотите выбрать РОСТ \n Введите 7 если хотите ввести ВЕС \n ");
				while (scanf("%d", &metka) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите число от 1 до 7 включительно: ");
				}
		} while ((metka < 1) || (metka > 7));
		if (metka == 1)
		{
			while (getchar() != '\n');
			printf("Введите ФИО\n");
			gets_s(zap.fio);
			zap.flagg[1] = 1;
		}
		if (metka == 2)
		{
			while (getchar() != '\n');
			printf("Введите знак зодиака\n");
			gets_s(zap.znak);
			zap.flagg[2] = 1;
		}
		if (metka == 3)
		{
			while (getchar() != '\n');
			printf("Введите профессию\n");
			gets_s(zap.prof);
			zap.flagg[3] = 1;
		}
		if (metka == 4)
		{
			while (getchar() != '\n');
			printf("Введите пол\n");
			scanf("%c", &zap.pol);
			zap.flagg[4] = 1;
		}
		if (metka == 5)
		{
			do
			{
				printf("Введите возраст(но не более 150 лет)\n");
				while (scanf("%d", &zap.voz) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите возраст: ");
				}
			} while ((zap.voz < 1) || (zap.voz > 150));
			while (getchar() != '\n');
			zap.flagg[5] = 1;
		}
		if (metka == 6)
		{
			do
			{
				printf("Введите рост(но не более 250 см)\n");
				while (scanf("%d", &zap.rost) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите рост: ");
				}
			} while ((zap.rost < 1) || (zap.rost > 250));
			while (getchar() != '\n');
			zap.flagg[6] = 1;
		}
		if (metka == 7)
		{
			do
			{
				printf("Введите вес(но не более 300 кг)\n");
				while (scanf("%d", &zap.ves) != 1)
				{
					while (getchar() != '\n');
					printf("Ошибка. Введите вес: ");
				}
			} while ((zap.ves < 1) || (zap.ves > 300));
			while (getchar() != '\n');
			zap.flagg[7] = 1;
		}
		printf("\nЖелате ли ввести новое поле в запрос?\n");
		printf("Люба клавиша - Да, Esc - нет\n");
		f = _getch();
	} while (f != 27);
	fla = 0;
	fp = fopen(file, "r");
	do //блок проверки запросов
	{
		flagokk = 0;
		res = fscanf(fp, "%s ", &chelovek.fio);
		if (res != EOF)
		{
			if ((zap.flagg[1] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.fio, chelovek.fio) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%s ", &chelovek.znak);
		if (res != EOF)
		{
			if ((zap.flagg[2] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.znak, chelovek.znak) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%s ", &chelovek.prof);
		if (res != EOF)
		{
			if ((zap.flagg[3] == 1) && (flagokk != 2))
			{
				if (strcmp(zap.prof, chelovek.prof) == 0)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%c ", &chelovek.pol);
		if (res != EOF)
		{
			if ((zap.flagg[4] == 1) && (flagokk != 2))
			{
				if (zap.pol == chelovek.pol)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.voz);
		if (res != EOF)
		{
			if ((zap.flagg[5] == 1) && (flagokk != 2))
			{
				if (zap.voz == chelovek.voz)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.rost);
		if (res != EOF)
		{
			if ((zap.flagg[6] == 1) && (flagokk != 2))
			{
				if (zap.rost == chelovek.rost)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		res = fscanf(fp, "%d ", &chelovek.ves);
		if (res != EOF)
		{
			if ((zap.flagg[7] == 1) && (flagokk != 2))
			{
				if (zap.ves == chelovek.ves)
				{
					flagokk = 1;
				}
				else
				{
					flagokk = 2;
				}
			}
		}
		if (flagokk == 1)
		{
			printf("%s ", chelovek.fio);
			printf("%s ", chelovek.znak);
			printf("%s ", chelovek.prof);
			printf("%c ", chelovek.pol);
			printf("%d ", chelovek.voz);
			printf("%d ", chelovek.rost);
			printf("%d ", chelovek.ves);
			printf("\n");
			fla = 1;
		}
	} while (res != EOF);
	if (fla == 0)
	{
		printf(" По вашему запросу ничего не найдено\n ");
	}
	return zap;
	//Закрываем файлы
	fclose(fp);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	char file_f[] = "f.txt";
	struct haracter zap;
	int a, b, с, i;
	i = 0;
	//Заполняем массив тестовыми данными
	strcpy(ludi[0].fio, "Ivan");
	strcpy(ludi[0].znak, "Vodoley");
	strcpy(ludi[0].prof, "Chistilchik");
	ludi[0].pol = 'm';
	ludi[0].voz = 36;
	ludi[0].rost = 175;
	ludi[0].ves = 88;
	strcpy(ludi[1].fio, "Maksim");
	strcpy(ludi[1].znak, "Ribi");
	strcpy(ludi[1].prof, "Programist");
	ludi[1].pol = 'm';
	ludi[1].voz = 39;
	ludi[1].rost = 197;
	ludi[1].ves = 92;
	strcpy(ludi[2].fio, "Roman");
	strcpy(ludi[2].znak, "Kozerog");
	strcpy(ludi[2].prof, "UristOso");
	ludi[2].pol = 'm';
	ludi[2].voz = 36;
	ludi[2].rost = 163;
	ludi[2].ves = 60;
	strcpy(ludi[3].fio, "Eva");
	strcpy(ludi[3].znak, "Scorpion");
	strcpy(ludi[3].prof, "Uchitel");
	ludi[3].pol = 'g';
	ludi[3].voz = 59;
	ludi[3].rost = 172;
	ludi[3].ves = 103;
	strcpy(ludi[4].fio, "Olga");
	strcpy(ludi[4].znak, "Lev");
	strcpy(ludi[4].prof, "Voenniysostagem");
	ludi[4].pol = 'g';
	ludi[4].voz = 24;
	ludi[4].rost = 164;
	ludi[4].ves = 56;
	do
	{
		do
		{
			printf("Выберите действие в меню\n");
			printf(" 1 - Ввод и коректировка списка\n");
			printf(" 2 - Вывод списка \n");
			printf(" 3 - Обработка запросов по списку\n");
			printf(" 4 - Выход из системы\n");
			while (scanf("%d", &a) != 1)
			{
				while (getchar() != '\n');
				printf("Ошибка. Введите число от 1 до 4 включительно: ");
			}
		} while ((a < 1) || (a > 4));
		if (a == 1)
		{
			do
			{
				printf("Вы попали в меню ввода и коректировки списка\n");
				printf(" 1 - Ввод списка\n");
				printf(" 2 - Удаление отдельной строки списка \n");
				printf(" 3 - Коректировка отдельных полей заданной строки списка\n");
				printf(" 4 - Вернуться в главное меню\n");
				do
				{
					while (scanf("%d", &b) != 1)
					{
						while (getchar() != '\n');
						printf("Ошибка. Введите число от 1 до 4 включительно: ");
					}
				} while ((b < 1) || (b > 4));
				if (b == 1)
				{
					printf("Вы попали в меню ввода отдельной строки списка\n");
					f11(file_f);
				}
				if (b == 2)
				{
					printf("Вы попали в меню Удаление отдельной строки списка\n");
					f12(file_f);
				}
				if (b == 3)
				{
					printf("Коректировка отдельных полей заданной строки списка\n");
					f13(file_f);
				}
			} while (b != 4);
		}
		if (a == 2)
		{
			printf("Ваш спискок:\n");
			f2(file_f);
		}
		if (a == 3)
		{
			do
			{
				printf("Вы попали в меню обработки запросов\n");
				printf(" 1 - Скоректировать предыдущий запрос\n");
				printf(" 2 - Ввести новый запрос \n");
				printf(" 3 - Выйти в главное меню\n");
				do
				{
					scanf("%d", &с);
				} while ((с < 1) || (с > 3));
				if (с == 1)
				{
					printf("Вы попали в режим коректировки запроса\n");
					if (flaaa == 1)
					{
						zap = f31(file_f, zap);
					}
					else printf("Сначала создайте запрос\n");
				}
				if (с == 2)
				{
					printf("Вы попали в режим создания запроса\n");
					zap = f32(file_f);
				}
			} while (с != 3);
		}
	} while (a != 4);
	printf("Вы вышли из системы");
}