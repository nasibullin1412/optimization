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
		printf("edel\n\n\n");
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

	printf("������� ������: ");
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
	printf("\n����� �������� �� ������� ���������?\n");
	printf("��� ���������� �������� �������� ��������������� �����:\n");
	printf("1. ���������.\n");
	printf("2. ����� ����� ����� � ��� ����. ������ ������������� ������ � ����.\n");
	printf("3. �����.\n");
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
	for (i = 0; i < size - 1; i++)
	{
		if (split_str[i] == split_str[i + 1])
		{
			count_repit++;
		}
		else
		{
			sum += count_repit * (count_repit - 1) / (float)(size * (size - 1));
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
	for (int i = 2; i < size / 2 + 1; i++)//size/2 + 1 �������� �� ����������
	{
		key_long[i] = (split_text(i, shifr_text, size));
		sum_index += key_long[i];
	}
	float max_delta = 0.0;
	int kSize = 0;
	float avverage = sum_index / (float)(size / 2 - 1);
	for (int i = 2; i < size / 2 + 1; i++)// ���� �����
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
unsigned char alphabet[] = " etaoinshrdlcumwfgypbvkxjqzETAOINSHRDLCUMWFGYPBVKXJQZ1234567890!_�;%:?*()-=+&^$#@";

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
		for (int i = 0; i < strlen(neig); i++)// dlina = strlen
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
	for (int j = 0; j < needsize; j++)
	{
		tmp_shifr_text[j] = shifr_text[j] ^ tempkey[j % kSize];
	}
	for (int j = 1; j < needsize - 1; j++)
	{
		unsigned char tmp = tolower(tmp_shifr_text[j]);
		switch (tmp)
		{
		case 'a':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigA_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigA_right);
			break;
		case 'b':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigB_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigB_right);
			break;
		case 'c':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigC_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigC_right);
			break;
		case 'd':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigD_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigD_right);
			break;
		case 'e':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigE_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigE_right);
			break;
		case 'f':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigF_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigF_right);
			break;
		case 'g':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigG_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigG_right);
			break;
		case 'h':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigH_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigH_right);
			break;
		case 'i':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigI_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigI_right);
			break;
		case 'j':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigJ_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigJ_right);
			break;
		case 'k':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigK_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigK_right);
			break;
		case 'l':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigL_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigL_right);
			break;
		case 'm':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigM_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigM_right);
			break;
		case 'n':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigN_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigN_right);
			break;
		case 'o':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigO_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigO_right);
			break;
		case 'p':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigP_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigP_right);
			break;
		case 'q':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigQ_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigQ_right);
			break;
		case 'r':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigR_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigR_right);
			break;
		case 's':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigS_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigS_right);
			break;
		case 't':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigT_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigT_right);
			break;
		case 'u':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigU_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigU_right);
			break;
		case 'v':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigV_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigV_right);
			break;
		case 'w':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigW_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigW_right);
			break;
		case 'x':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigX_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigX_right);
			break;
		case 'y':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigY_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigY_right);
			break;
		case 'z':
			tmp_count_bin += check(tolower(tmp_shifr_text[j - 1]), neigZ_left);
			tmp_count_bin += check(tolower(tmp_shifr_text[j + 1]), neigZ_right);
			break;
		default:
			break;
		}


	}
	return tmp_count_bin;
}

int analysis(unsigned char* tempkey, int sizetext)
{
	int needsize;
	if (sizetext < 100)
	{
		needsize = sizetext;
	}
	else needsize = 100;
	for (int j = 0; j < needsize; j++)
	{
		tmp_shifr_text[j] = shifr_text[j] ^ tempkey[j % kSize];
		//printf("%c", tmp_shifr_text[j]);
	}
	//printf("\n\n");
	for (int j = 1; j < needsize - 1; j++)
	{
		if ((tmp_shifr_text[j] >= '0' && tmp_shifr_text[j] <= '9') || tmp_shifr_text[j] == '%' || tmp_shifr_text[j] == '+' || tmp_shifr_text[j] == '-')
		{
			if (isalpha(tmp_shifr_text[j + 1]) && isalpha(tmp_shifr_text[j - 1]))
			{
				return 0;
			}
		}
		else if (tmp_shifr_text[j] == '>' || tmp_shifr_text[j] == '<')
		{
			if (isalpha(tmp_shifr_text[j - 1]) || isalpha(tmp_shifr_text[j + 1]))
			{
				return 0;
			}
		}
		else if (tmp_shifr_text[j] == '!' || tmp_shifr_text[j] == ',' || tmp_shifr_text[j] == '.' || tmp_shifr_text[j] == '?')
		{
			if (!isalpha(tmp_shifr_text[j - 1]) && !(tmp_shifr_text[j - 1] >= '0' && tmp_shifr_text[j - 1] <= '9'))
			{
				return 0;
			}
			if (tmp_shifr_text[j + 1] != ' ' && tmp_shifr_text[j + 1] != '\n')
			{
				return 0;
			}

		}
		else if (tmp_shifr_text[j] == '&')
		{
			if (!(tmp_shifr_text[j + 1] >= 'A' && tmp_shifr_text[j + 1] <= 'Z'))
			{
				return 0;
			}
			if (!isalpha(tmp_shifr_text[j - 1]))
			{
				return 0;
			}
		}
		else if (tmp_shifr_text[j] == ')')
		{
			if (isalpha(tmp_shifr_text[j + 1]))
			{
				return 0;
			}
		}
		else if (tmp_shifr_text[j] == '(' || tmp_shifr_text[j] == '#')
		{
			if (tmp_shifr_text[j - 1] != ' ')
			{
				return 0;
			}
		}
		else if (tmp_shifr_text[j] == '$')
		{
			if (tmp_shifr_text[j - 1] != ' ')
			{
				return 0;
			}
			if (!(tmp_shifr_text[j + 1] >= '0' && tmp_shifr_text[j + 1] <= '9'))
			{
				return 0;
			}

		}
		else if (tmp_shifr_text[j] == '"' || tmp_shifr_text[j] == '\'')
		{
			if (tmp_shifr_text[j - 1] != ' ' && tmp_shifr_text[j + 1] != ' ')
			{
				return 0;
			}
		}
		else if (isalpha(tmp_shifr_text[j]) && (tmp_shifr_text[j] == tmp_shifr_text[j - 1]) && (tmp_shifr_text[j] == tmp_shifr_text[j + 1]))
		{
			return 0;
		}

	}
	printf("\n\n");
	return 1;

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
	printf("%d. ����������� \"������� �������\" = %d \n", countRecords, currentMax);
	printf("�������������� ����: ");
	for (int j = 0; j < kSize; j++)
	{
		printf("%c", tmp_key[j]);
	}
	printf("\n");
	printf("�����: \n");
	cur = addElem(tmp_key, kSize);
	for (int j = 0; j < needsize; j++)
	{
		printf("%c", tmp_shifr_text[j]);
	}
	printf("\n���������...\n");
	printf("\n");

}

int gl_count = 0;
void BruteForce(unsigned char* key, unsigned char* hu, int size, int number, int sizetext)
{
	if (size == 0)
	{
		//gl_count++;
		//printf("%d\n", gl_count);
		if (strcmp(hu, kk) == 0)
		{
			printf("YES");
		}

		int currentMax = analysis_bin(hu, sizetext);
		if (currentMax > Max)
		{
			/*int needsize = need_size(100, sizetext);

			printf("����������� \"������� �������\" = %d \n", currentMax);
			printf("�������������� ����: ");
			for (int j = 0; j < kSize; j++)
			{
				printf("%c", hu[j]);
			}

			printf("\n");
			printf("�����: \n");
			for (int j = 0; j < needsize; j++)
			{
				printf("%c", tmp_shifr_text[j]);
			}
			printf("\n");*/
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

		/*
		if (analysis(hu, sizetext))
		{
			for (int j = 0; j < kSize; j++)
			{
				printf("%c", hu[j]);
			}
			printf("----KEY!!");
			printf("\n");
			for (int j = 0; j < 100; j++)
			{
				printf("%c", tmp_shifr_text[j]);
			}

		}*/

		return;
	}
	else
	{
		//count_for_Brut
		for (int i = 0; i < count_for_Brut; i++)
		{
			hu[number] = key[number] ^ frequency[i];

			if (is_it_char(hu[number]))
			{
				BruteForce(key, hu, size - 1, number + 1, sizetext);
			}
		}
	}
}

void get_key(unsigned char* text, unsigned int size, unsigned char* key, unsigned int ksize)
{
	//int t = clock();
	memset(keystat, 0, sizeof(keystat));
	unsigned int read = ksize;

	for (unsigned int start = 0; start < size;)
	{
		if (read > (size - start))
			read = (size - start);

		for (unsigned int i = 0; i < read; i++)
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

			for (int j = 0; j < 256; j++)
			{
				if (keystat[i][j] > max)
				{
					max = keystat[i][j];
					v = j;
				}
			}

			key[i] = v;
			//key[i] ^= ' ';
		}
		char temp_key[50] = { 0 };//zapolnit pobache
		kSize = ksize;
		BruteForce(key, temp_key, ksize, 0, size);

		if (ksize)
			break;
	}
	//printf("\n%d", clock()-t);
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
	//for (int i = 0; i < length; i++)
		//printf("%d - %c", key[i], key[i]);
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
	printf("���� �� ������ � ������?(0 - ���, 1 - ��)\n");
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
	printf("������� ������, ������� � ������ ������, ������� ������������ �� ���������:\n");
	char c = '\0';
	scanf("%c", &c);
	scanf("%c", &c);
	int count = 0;
	system("cls");
	while (tmp_shifr_text[count] != c && count < 101)//izmenit
	{
		count++;
	}
	if (count == 101)
	{
		printf("������ �� ������\n");
		return 1;
	}
	int number = count % kSize;
	char sim = key[number];
	for (char i = 0; i < 127; i++)//mozno razvernyt
	{
		if (is_it_char(i))
		{
			key[number] = i;

			int check = analysis_bin(key, sizeText);
			if (Max - check < 5)
			{

				printf("����������� \"������� �������\" = %d \n", check);
				printf("�������������� ����: ");
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
				printf("���������� ����������?(0 - ���, 1 - ��)\n");
				int anser = 0;
				scanf("%d", &anser);
				if (anser)
				{
					return 1;
				}
			}
		}
	}
	key[number] = sim;
	printf("���������� ��������\n");
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
				for (kSize = 2; kSize < maxKsize; kSize++)
				{
					if (kSize < 10)
						count_for_Brut = 7;
					else
					{
						if (kSize == 10)
							count_for_Brut = 6;
						else
						{
							if (kSize <= 12)
								count_for_Brut = 2;
							else
								count_for_Brut = 1;
						}
					}
					get_key(shifr_text, size, key, kSize);
				}
			}
			else
			{
				count_for_Brut = 2;
				get_key(shifr_text, size, key, kSize);
			}
			printf("\nTime: %d\n", clock() - t);
			printf("�������� ����� ���������� ������� �����:\n");
			int number = 0;
			scanf("%d", &number);
			search(number);
			kSize = strlen(cur->key);
			for (i = 0; i < kSize; i++)
			{
				key[i] = cur->key[i];
			}
			for (int j = 0; j < 100; j++)//����� �������
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
	//free(key);
	return 0;
}
