#ifndef ENCIPHERMENT
#define ENCIPHERMENT

#include <iostream>
#include <fstream>
#include "tool.h"
#include "password_txt.cpp"

using namespace std;

const int max_number = 512;


int probability;
int two_dimension_probability;
int drection;
int two_dimension_drection;
int read;
int fence_number;
int binarysystem[max_number]{};//存储 一 维加密移动大小的二进制数组
int two_dimension_binarysystem[max_number]{};//存储 二 维加密移动大小的二进制数组
int drectionbinarysystem[max_number]{};//存储方向的二进制数组


char input[max_number];
char out[max_number];
char fence_store[max_number][max_number];//用于存储栅栏加密中间过程的字符顺序调换



int move_probability()
{
	srand(time(0));

	//生成随机数，以便进行加密
	probability = rand() % 25 + 1;
	two_dimension_probability = rand() % 12 + 1;
	//生成移动方向
	drection = rand() % 2;
	//cout << savedrection << endl;

	//判断移动方向
	if (drection == 1) {
		probability = probability;
		two_dimension_probability = two_dimension_probability;
		two_dimension_drection = 1;
	}
	else {
		probability = -probability;
		two_dimension_probability = -two_dimension_probability;
		two_dimension_drection = -1;
	}
	return probability, two_dimension_probability, drection, two_dimension_drection;
}


int inspection_word_code()
{
	while (1)
	{
		//cout << input[read + 2] << endl;
		if (input[read] == 0)
		{
			break;
		}
		else {
			read++;
		}
	}
	cout << read << endl;
	return read;
}


void one_dimensional_encryption()
{
	cin >> input;
	inspection_word_code();
	for (int i = 0; i <= read; i++) {
		for (int forread = 26; forread <= 51; forread++)
		{
			if (input[i] == bigword[forread])
			{
				out[i] = bigword[forread + probability];
			}
			if (input[i] == smallword[forread])
			{
				out[i] = smallword[forread + probability];
			}
			if (input[i] == '?' || input[i] == '!' || input[i] == '@' || input[i] == '#' || input[i] == '$' || input[i] == '%' || input[i] == '^' || input[i] == '&' || input[i] == '*' || input[i] == '(' || input[i] == ')' || input[i] == '-' || input[i] == '_' || input[i] == '+' || input[i] == '=' || input[i] == ',' || input[i] == '.' || input[i] == '/' || input[i] == ';' || input[i] == '[' || input[i] == ']' || input[i] == '>' || input[i] == '<' || input[i] == ':' || input[i] == '"' || input[i] == '{' || input[i] == '}' || input[i] == '|' || input[i] == '`' || input[i] == '~' || input[i] == '·' || input[i] == '，' || input[i] == '。' || input[i] == '《' || input[i] == '》' || input[i] == '？' || input[i] == '；' || input[i] == '：' || input[i] == '’' || input[i] == '‘' || input[i] == '“' || input[i] == '”' || input[i] == '！' || input[i] == '￥' || input[i] == '（' || input[i] == '）' || input[i] == '—')
			{
				out[i] = input[i];
			}
		}
	}
}
void two_dimensional_encryption()
{
	cin >> input;
	inspection_word_code();
	int m = 0;
	while (read)
	{
		for (int j = 13; j <= 25; j++)
		{
			for (int k = 2; k <= 3; k++)
			{
				if (input[m] == two_dimension_bigword[k][j])
				{
					out[m] = two_dimension_bigword[k + two_dimension_drection][j + two_dimension_probability];
				}
				if (input[m] == two_dimension_smallword[k][j])
				{
					out[m] = two_dimension_smallword[k + two_dimension_drection][j + two_dimension_probability];
				}
				if (input[m] == '?' || input[m] == '!' || input[m] == '@' || input[m] == '#' || input[m] == '$' || input[m] == '%' || input[m] == '^' || input[m] == '&' || input[m] == '*' || input[m] == '(' || input[m] == ')' || input[m] == '-' || input[m] == '_' || input[m] == '+' || input[m] == '=' || input[m] == ',' || input[m] == '.' || input[m] == '/' || input[m] == ';' || input[m] == '[' || input[m] == ']' || input[m] == '>' || input[m] == '<' || input[m] == ':' || input[m] == '"' || input[m] == '{' || input[m] == '}' || input[m] == '|' || input[m] == '`' || input[m] == '~' || input[m] == '·' || input[m] == '，' || input[m] == '。' || input[m] == '《' || input[m] == '》' || input[m] == '？' || input[m] == '；' || input[m] == '：' || input[m] == '’' || input[m] == '‘' || input[m] == '“' || input[m] == '”' || input[m] == '！' || input[m] == '￥' || input[m] == '（' || input[m] == '）' || input[m] == '—')
				{
					out[m] = input[m];
				}
			}
		}
		m++;
		read--;
	}
}
void fence_encryption()
{
	cin >> input;
	inspection_word_code();
	for (int z = 0; z <= ((read - 1) / 2); z++)
	{
		for (int x = 0; x <= 1; x++)
		{
			fence_store[x][z] = input[fence_number];
			fence_number++;
		}
	}
	int out_number = 0;
	for (int d = 0; d <= 1; d++)
	{
		for (int e = 0; e <= ((read - 1) / 2); e++)
		{
			out[out_number] = fence_store[d][e];
			out_number++;
		}
	}
}

void out_word(int choosemodule)
{
	ofstream enciphermentFile;
	enciphermentFile.open("encipherment_contect.txt", fstream::app);
	fstream file("encipherment_contect.txt", ios::out);

	int n = 0, b = 0, c = 0;
	//cout << probability << endl;
	//cout << drection << endl;

	//将包含移动方向的移动大小数（probability or two_dimension_probability）化为正整数
	if (probability < 0)
	{
		probability = -probability;
	}
	if (two_dimension_probability < 0)
	{
		two_dimension_probability = -two_dimension_probability;
	}

	probability = probability * privacy_key;
	two_dimension_probability = two_dimension_probability * privacy_key;

	cout << "加密后为:";

	//将包含移动方向的移动大小数（probability）转化为二进制
	while (probability)
	{
		binarysystem[n] = probability % 2;
		probability /= 2;
		//cout << binarysystem[n];
		n++;
	}

	//将包含移动方向的移动大小数（two_dimension_binarysystem）转化为二进制
	while (two_dimension_probability)
	{
		two_dimension_binarysystem[b] = two_dimension_probability % 2;
		two_dimension_probability /= 2;
		//cout << binarysystem[n];
		b++;
	}

	//根据开始选择的模式判断输出的二进制数组（binarysystem or two_dimension_binarysystem）
	if (choosemodule == 1)
	{
		for (int k = 22; k >= 0; k--)
		{
			cout << binarysystem[k];
			enciphermentFile << binarysystem[k];
		}
	}
	else {
		if (choosemodule == 2)
		{
			for (int k = 22; k >= 0; k--)
			{
				cout << two_dimension_binarysystem[k];
				enciphermentFile << two_dimension_binarysystem[k];
			}
		}
		else {
			if (choosemodule == 3)
			{
				for (int k = 22; k >= 0; k--)
				{
					cout << "0";
					enciphermentFile << "0";
				}
			}
		}
	}
	//cout << binarysystem << endl;
	cout << "-" << out << "-";
	enciphermentFile << "-" << out << "-";
	if (choosemodule == 1 || choosemodule == 2)
	{
		if (drection == 1)
		{
			cout << "00001";
			enciphermentFile << "00001";
		}
		else {
			cout << "00000";
			enciphermentFile << "00000";
		}
	}
	else {
		cout << "00000";
		enciphermentFile << "00000";
	}
	cout << "-" << choosemodule << endl;
	enciphermentFile << "-" << choosemodule << endl;
	//cout << drectionbinarysystem << endl;

	cout << "文本输出完成!" << endl;
	enciphermentFile.close();
	cout << "文本文档已关闭!" << endl;

	break_quckily();
}
#endif // !ENCIPHERMENT


