#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>
#include "Neighbor.h"
#include <time.h>

#define kMaxKeySize 1024

unsigned char table_c[256] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

enum
{
	XOR = 1,
	GET_LENGTH_AND_KEY,
	EXIT,
};

typedef struct Keys_
{
	char key[50];
	struct Keys_ *next;
}KEY;

KEY *beg, *cur;

init()
{
	beg = (KEY*)malloc(sizeof(KEY));
	beg->key[0] = '\0';
	beg->next = NULL;
	cur = beg;
}

KEY * addElem(char *key_, int size)
{
	KEY *p = (KEY*)malloc(sizeof(KEY));
	cur->next = p;
	for (int i = 0; i < size; i++)
	{
		p->key[i] = key_[i];
	}
	p->key[size] = '\0';
	p->next = NULL;
	return p;
}

void deletelem()
{
	cur = beg->next;
	while (cur != NULL)
	{
		beg->next = cur->next;
		free(cur);
		cur = beg->next;
		//printf("edel\n\n\n");
	}
	cur = beg;
	cur->next = NULL;

}
void search(int number)
{
	cur = beg->next;
	int count = 1;
	while (cur != NULL && number != count)
	{
		count++;
		cur = cur->next;
	}
}

unsigned int keystat[kMaxKeySize][256];
unsigned char password[50];
unsigned char* shifr_text, *lolo;
unsigned char* tmp_shifr_text;
int kSize;
int count_for_Brut = 6;

void xor_cypher()
{
	setlocale(0, "");
	FILE* fin = fopen("input.txt", "rb"), *fout = fopen("output.txt", "wb");


	long long i = 0;

	if (fin == NULL)
	{
		printf("Cant read file!\n");
		return;
	}

	printf("Введите пароль: ");
	getchar();
	gets(password);

	long long length = strlen(password);

	int c = fgetc(fin);
	while (c != EOF)
	{
		c ^= password[i % length];
		i++;
		fputc(c, fout);
		c = fgetc(fin);
	}

	fseek(fin, 0, SEEK_SET);
	fclose(fin);
	fclose(fout);

}

int menu()
{
	int num = 0;
	printf("\nКакие действия Вы желаете выполнить?\n");
	printf("Для совершения действия выберите соответствующую цифру:\n");
	printf("1. Заксорить.\n");
	printf("2. Найти длину ключа и сам ключ. Печать получившегося текста в файл.\n");
	printf("3. Выход.\n");
	if (!scanf("%d", &num))
	{
		fflush(stdin);
		printf("input error.\ntry again: ");
	}
	return (num);
}

float sum_matches(unsigned char split_str[], int size)
{
	int i = 0, count_repit = 0;
	float sum = 0.0;
	//int sizeFor = size - 1;// вынос инварианта
	int sizeFor = size - 1;
	for (i = 0; i < sizeFor; i++)
	{
		if (split_str[i] == split_str[i + 1])
		{
			count_repit++;
		}
		else
		{
			sum += count_repit * (count_repit - 1) / (float)(size * sizeFor);//вынос инваринта
			count_repit = 0;
		}
	}
	return sum;
}

void qsortt(int l, int r, unsigned char a[])
{
	if (l < r)
	{
		int i = l, j = r, t;
		int d = (l + r) / 2;
		int x = a[d];
		do
		{
			while (a[i] < x) i++;
			while (a[j] > x) j--;
			if (i <= j)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		} while (i <= j);
		qsortt(l, j, a);
		qsortt(i, r, a);
	}
}

float split_text(int size_key, unsigned char shifr_text[], int size)
{
	int a = size / size_key + 1;
	unsigned char* split_str = (unsigned char*)malloc(a * sizeof(unsigned char));
	int count = 0;
	float sum = 0.0;
	for (int start = 0; start < size_key; start++)
	{
		for (int i = start; i < size; i += size_key, count++)
		{
			split_str[count] = shifr_text[i];
		}

		qsortt(0, count - 1, split_str);
		sum += sum_matches(split_str, count - 1);
		count = 0;
	}
	free(split_str);
	return sum / (float)size_key;
}

int key_size(unsigned char shifr_text[], int size, float key_long[])
{
	int count_key = 0;
	float sum_index = 0.0;
	int length = size / 2 + 1;
	for (int i = 2; i < length; i++)//size/2 + 1 заменить на переменную
	{
		key_long[i] = (split_text(i, shifr_text, size));
		sum_index += key_long[i];
	}
	float max_delta = 0.0;
	int kSize = 0;
	float avverage = sum_index / (float)(size / 2 - 1);
	for (int i = 2; i < length; i++)// тоже самое
	{
		if ((key_long[i] - avverage) > max_delta)
		{
			kSize = i;
			max_delta = key_long[i] - avverage;
		}
	}
	return kSize;
}

unsigned char frequency[] = " etaoinshrdlcumwfgypbvkxjqz";
unsigned char alphabet[] = " etaoinshrdlcumwfgypbvkxjqzETAOINSHRDLCUMWFGYPBVKXJQZ1234567890!_№;%:?*()-=+&^$#@";


int is_it_char(char c)
{
	if ((c >= '0' && c <= '?') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 32 && c <= 47))
	{
		return 1;
	}
	else return 0;
}

int check(char c, const char* neig)
{
	if (c != ' ')
	{
		for (int i = 0; i < strlen(neig); i++)
		{
			if (c == neig[i])
			{
				if (i < strlen(neig) / 2)
				{
					return 2;
					break;
				}
				else
				{
					return 1;
					break;
				}
			}
		}
		return -1;
	}
	else return 0;
}


int analysis_bin(unsigned char* tempkey, int sizetext)
{
	//memset(tmp_shifr_text, 0, sizetext);
	int needsize = need_size(100, sizetext), tmp_count_bin = 0;
	//int newNeedSize = needsize - needsize % 4;
	int k = 0;
	for (k; k < needsize; k++)//развернуть
	{
		tmp_shifr_text[k] = shifr_text[k] ^ tempkey[k % kSize];
		/*tmp_shifr_text[k + 1] = shifr_text[k + 1] ^ tempkey[(k + 1) % kSize]
		tmp_shifr_text[k + 2] = shifr_text[k + 2] ^ tempkey[(k + 2) % kSize];
		tmp_shifr_text[k + 3] = shifr_text[k + 3] ^ tempkey[(k + 3) % kSize];*/
		/*tmp_shifr_text[k + 4] = shifr_text[k + 4] ^ tempkey[(k + 4) % kSize];
		tmp_shifr_text[k + 5] = shifr_text[k + 5] ^ tempkey[(k + 5) % kSize];
		tmp_shifr_text[k + 6] = shifr_text[k + 6] ^ tempkey[(k + 6) % kSize];
		tmp_shifr_text[k + 7] = shifr_text[k + 7] ^ tempkey[(k + 7) % kSize];
		tmp_shifr_text[k + 8] = shifr_text[k + 8] ^ tempkey[(k + 8) % kSize];
		tmp_shifr_text[k + 9] = shifr_text[k + 9] ^ tempkey[(k + 9) % kSize];*/
	}
	/*for ( k; k < needsize; k++)
	{
		tmp_shifr_text[k] = shifr_text[k] ^ tempkey[k % kSize];
	}*/


	for (int j = 1; j < needsize - 1; j++)
	{
		unsigned char tmp = tolower(tmp_shifr_text[j]);

		
		//ВМЕСТО ВСЕГО СВИЧ.
		if (table_c[tmp])
		{
		tmp_count_bin += table2_left[tmp - 'a'][tolower(tmp_shifr_text[j - 1])];
		tmp_count_bin += table2_right[tmp - 'a'][tolower(tmp_shifr_text[j + 1])];
		}
	}
	return tmp_count_bin;
}


int Max = 0;
char* kk = "helloworld";
int countRecords = 0;

int need_size(int want, int sizetext)
{
	if (sizetext < want)
	{
		return sizetext;
	}
	else return want;
}

void show_result(unsigned char *tmp_key, int want, int sizetext, int currentMax)
{
	int needsize = need_size(want, sizetext);
	countRecords++;
	printf("%d. Коэффициент \"хороших соседей\" = %d \n", countRecords, currentMax);
	printf("Предполагаемый ключ: ");
	for (int j = 0; j < kSize; j++)
	{
		printf("%c", tmp_key[j]);
	}
	printf("\n");
	printf("Текст: \n");
	cur = addElem(tmp_key, kSize);
	for (int j = 0; j < needsize; j++)
	{
		printf("%c", tmp_shifr_text[j]);
	}
	printf("\nПодождите...\n");
	printf("\n");

}

void BruteForce(unsigned char* key, unsigned char* hu, int size, int number, int sizetext)
{
	if (size == 0)
	{
		
		int currentMax = analysis_bin(hu, sizetext);
		if (currentMax > Max)
		{
			deletelem();
			system("cls");
			countRecords = 0;
			show_result(hu, 100, sizetext, currentMax);

			Max = currentMax;
		}
		
		else if (Max - currentMax <= 2)
		{
			show_result(hu, 100, sizetext, currentMax);
		}
		return;
	}
	else
	{
		//count_for_Brut
		for (int i = 0; i < count_for_Brut; i++)
		{
			hu[number] = key[number] ^ frequency[i];

			if (table_is_it_char[hu[number]])
			{
				BruteForce(key, hu, size - 1, number + 1, sizetext);
			}
		}
	}
}

void get_key(unsigned char* text, unsigned int size, unsigned char* key, unsigned int ksize)
{

	memset(keystat, 0, sizeof(keystat));
	unsigned int read = ksize;

	for (unsigned int start = 0; start < size;)
	{
		//вынести size-start в отдельную переменную. 
		int vs_read = size - start;
		if (read >  vs_read)
			read = vs_read;
	
		int circleRead = read - read % 4;
		int i = 0;
		for (i; i < circleRead; i += 4)
		{
			keystat[i][text[start + i]]++;
			keystat[i + 1][text[start + i + 1]]++;
			keystat[i + 2][text[start + i + 2]]++;
			keystat[i + 3][text[start + i + 3]]++;
		}
		for (i; i < read; i++)
		{
			keystat[i][text[start + i]]++;
		}
		start += ksize;
	}

	for (int i = 0; i < ksize; i++)
	{
		unsigned int prev_max = 0;
		unsigned int max = 0;

		for (unsigned int i = 0; i < ksize; i++)
		{
			unsigned int v = 0;
			unsigned int max = 0;

			for (int j = 0; j < 256; j+=8)
			{
				if (keystat[i][j] > max)
				{
					max = keystat[i][j];
					v = j;
				}
				if (keystat[i][j+1] > max)
				{
					max = keystat[i][j+1];
					v = j+1;
				}
				if (keystat[i][j+2] > max)
				{
					max = keystat[i][j+2];
					v = j+2;
				}
				if (keystat[i][j+3] > max)
				{
					max = keystat[i][j+3];
					v = j+3;
				}
				if (keystat[i][j+4] > max)
				{
					max = keystat[i][j+4];
					v = j+4;
				}
				if (keystat[i][j+5] > max)
				{
					max = keystat[i][j+5];
					v = j+5;
				}
				if (keystat[i][j+6] > max)
				{
					max = keystat[i][j+6];
					v = j+6;
				}
				if (keystat[i][j+7] > max)
				{
					max = keystat[i][j+7];
					v = j+7;
				}
			}

			key[i] = v;
			//key[i] ^= ' ';
		}
		char temp_key[50] = { 0 };
		kSize = ksize;
		BruteForce(key, temp_key, ksize, 0, size);

		if (ksize)
			break;
	}
}

void print(unsigned char* key, int length)
{
	FILE* fin = fopen("output.txt", "rb"), *fout = fopen("finish.txt", "wb");
	long long i = 0;
	if (fin == NULL)
	{
		printf("Cant read file!\n");
		return;
	}

	int c = fgetc(fin);
	while (c != EOF)
	{
		c ^= key[i % length];
		i++;
		fputc(c, fout);
		c = fgetc(fin);
	}
	fseek(fin, 0, SEEK_SET);
	fclose(fin);
	fclose(fout);

}

int correct(char *key, int sizeText)
{
	printf("Есть ли ошибка в тексте?(0 - нет, 1 - да)\n");
	int menu = -1;
	while (menu < 0)
	{
		scanf("%d", &menu);
		if (menu < 0)
		{
			char c = '\0';
			while (c != '\n')
			{
				c = getc(stdin);
			}
		}
		if (menu != 0 && menu != 1)
		{
			menu = -1;
		}
	}
	if (menu == 0)
	{
		return 0;
	}
	printf("Введите символ, начиная с начала текста, который дешефрирован не правильно:\n");
	char c = '\0';
	scanf("%c", &c);
	scanf("%c", &c);
	int count = 0;
	system("cls");
	while (tmp_shifr_text[count] != c && count < 101)
	{
		count++;
	}
	if (count == 101)
	{
		printf("Символ не найден\n");
		return 1;
	}

	int number = count % kSize;
	char sim = key[number];
	for (char i = 0; i < 127; i++)
	{
		//
		if (is_it_char(i))
		{
			key[number] = i;

			int check = analysis_bin(key, sizeText);
			if (Max - check < 5)
			{
				printf("Коэффициент \"хороших соседей\" = %d \n", check);
				printf("Предполагаемый ключ: ");
				for (int j = 0; j < kSize; j++)
				{
					printf("%c", key[j]);
				}
				printf("\n");
				for (int j = 0; j < 100; j++)
				{
					printf("%c", tmp_shifr_text[j]);
				}
				printf("\n");
				if (Max < check)
				{
					Max = check;
				}
				printf("Правильная дешифровка?(0 - Нет, 1 - Да)\n");
				int anser = 0;
				scanf("%d", &anser);
				if (anser)
				{
					return 1;
				}
			}
		}
	}
	//строчка ниже лишняя. у тебя с начала char sim = key[number];, и если ничего не найдено, ты делаешь обратное присваивание. зачем?
	key[number] = sim;
	printf("Невозможно заменить\n");
	return 1;

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	init();

	FILE* fin = fopen("output.txt", "rb");

	if (fin == NULL)
	{
		printf("Can't read file!\n");
		return 0;
	}

	fseek(fin, 0, SEEK_END);
	int size = ftell(fin);
	fseek(fin, 0, SEEK_SET);
	
	//unsigned char* shifr_text = (unsigned char*)malloc(size * sizeof(unsigned char));

	shifr_text = (unsigned char*)malloc(size * sizeof(unsigned char));
	tmp_shifr_text = (unsigned char*)malloc(size * sizeof(unsigned char));

	unsigned int c = fgetc(fin), i = 0;

	while (c != EOF)
	{
		shifr_text[i] = c;
		i++;
		c = fgetc(fin);
	}
	fclose(fin);

	int t = 0;
	float* keys_long = (float*)calloc(size / 2 + 1, sizeof(float));
	kSize = key_size(shifr_text, size, keys_long);
	int maxKsize = 0;
	
	if (keys_long[kSize] < 0.045)
	{
		maxKsize = 13;
	}
	else
	{
		maxKsize = kSize;
	}

	if (size > 300)
	{
		count_for_Brut = 5;
	}
	unsigned char key[50] = { 0 };
	
	int n = menu();
	while (n != 4)
	{
		switch (n)
		{
		case XOR:
			xor_cypher();
			return 0;
		case GET_LENGTH_AND_KEY:
			if (maxKsize)
			{
				t = clock();
				count_for_Brut = 7;
				get_key(shifr_text, size, key, 2);
				get_key(shifr_text, size, key, 3);
				get_key(shifr_text, size, key, 4);
				get_key(shifr_text, size, key, 5);
				get_key(shifr_text, size, key, 6);
				get_key(shifr_text, size, key, 7);
				get_key(shifr_text, size, key, 8);
				get_key(shifr_text, size, key, 9);

				count_for_Brut = 6;
				get_key(shifr_text, size, key, 10);

				count_for_Brut = 2;
				get_key(shifr_text, size, key, 11);
				get_key(shifr_text, size, key, 12);

			}
			else
			{
				count_for_Brut = 2;
				get_key(shifr_text, size, key, kSize);
			}
			printf("\nTime: %d\n", clock() - t);
			printf("Выбирите более подходящий вариант ключа:\n");
			int number = 0;
			scanf("%d", &number);
			search(number);
			kSize = strlen(cur->key);
			for (i = 0; i < kSize; i++)
			{
				key[i] = cur->key[i];
			}
			for (int j = 0; j < 100; j++)
			{
				tmp_shifr_text[j] = shifr_text[j] ^ key[j % kSize];
			}
			while (correct(key, size));

		case EXIT:
			system("pause");
			exit(0);
		}
		n = menu();
	}
	
	free(shifr_text);
	free(tmp_shifr_text);

	return 0;
}
