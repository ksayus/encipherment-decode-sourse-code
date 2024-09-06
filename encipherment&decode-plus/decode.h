#ifndef DECODE
#define DECODE

#include "tool.h"
#include "encipherment.h"

int lock = 0;
int read_decode = 0;
int unlockdrection = 0;
int module = 0;
int readmodule = 0;
int read_inspection = 0;
int read_inspection_add = 0;
int inspection_binarysystem = 0;

char readout[max_number]{};
char binarysystem_inspection[max_number];

//void inspection_input_deteil()
//{
//
//	//检验输入的文本是否符合标准
//	while (privacy_key)
//	{
//		binarysystem_inspection[inspection_binarysystem] = privacy_key % 2;
//		privacy_key /= 2;
//		//cout << binarysystem[n];
//		inspection_binarysystem++;
//	}
//
//	read_inspection = inspection_binarysystem;
//
//	do {
//		if (input[read_inspection_add] != ' ')
//		{
//			read_inspection--;
//			read_inspection_add++;
//		}
//	} while (input[read_inspection_add] != ' ');
//
//	if (read_inspection > 0)
//	{
//		cout << "输入错误!" << endl;
//		break_quckily();
//	}
//}

int read_inspection_code()
{
	cin >> input;

	//用于读取字符串长度
	while (1) {
		if (input[24 + read] != '-')
		{
			readout[read] = input[24 + read];
			read++;
		}
		else {
			//cout << read << endl;
			break;
		}
	}
	//方向
	if (input[24 + read + 5] == '1')
	{
		unlockdrection = 1;
	}
	else {
		unlockdrection = 0;
	}

	int i = 0;
	//移动大小
	while (1)
	{
		if (input[i] == '-')
		{
			break;
		}
		else {
			if (input[i] == '0')
			{
				lock = lock * 2;
			}
			else {
				lock = lock * 2 + 1;
			}
			i++;
		}
	}

	lock = lock / privacy_key;//利用密钥解密

	//加正负用的，别问，问就是有用
	if (unlockdrection == 0) {
		lock = lock;
		two_dimension_drection = 1;
	}
	else {
		lock = -lock;
		two_dimension_drection = -1;
	}

	//存储模式数字的字符串
	module = input[24 + read + 7];

	//将上面那坨屎换为数字
	if (module == '1')
	{
		readmodule = 1;
	}
	else {
		if (module == '2')
		{
			readmodule = 2;
		}
		else {
			if (module == '3')
			{
				readmodule = 3;
			}
		}
	}

	cout << "你的输入:" << endl << lock << "-" << readout << "-" << unlockdrection << "-" << readmodule << endl;
	cout << read << endl;
	cout << readmodule << endl;

	return read, unlockdrection, lock, two_dimension_drection, readmodule;
}

void one_dimension_decode()
{
	//read_inspection();
	//一维加密
	for (int i = 0; i <= read; i++) {
		for (int forread = 26; forread <= 51; forread++)
		{
			if (readout[i] == bigword[forread])
			{
				out[i] = bigword[forread + lock];
			}
			if (readout[i] == smallword[forread])
			{
				out[i] = smallword[forread + lock];
			}
			if (readout[i] == '?' || readout[i] == '!' || readout[i] == '@' || readout[i] == '#' || readout[i] == '$' || readout[i] == '%' || readout[i] == '^' || readout[i] == '&' || readout[i] == '*' || readout[i] == '(' || readout[i] == ')' || readout[i] == '-' || readout[i] == '_' || readout[i] == '+' || readout[i] == '=' || readout[i] == ',' || readout[i] == '.' || readout[i] == '/' || readout[i] == ';' || readout[i] == '[' || readout[i] == ']' || readout[i] == '>' || readout[i] == '<' || readout[i] == ':' || readout[i] == '"' || readout[i] == '{' || readout[i] == '}' || readout[i] == '|' || readout[i] == '`' || readout[i] == '~' || readout[i] == '·' || readout[i] == '，' || readout[i] == '。' || readout[i] == '《' || readout[i] == '》' || readout[i] == '？' || readout[i] == '；' || readout[i] == '：' || readout[i] == '’' || readout[i] == '‘' || readout[i] == '“' || readout[i] == '”' || readout[i] == '！' || readout[i] == '￥' || readout[i] == '（' || readout[i] == '）' || readout[i] == '—')
			{
				out[i] = readout[i];
			}
		}
	}
}

void two_dimension_decode()
{
	//read_inspection();
	//二维加密
	for (int m = 0; m <= read; m++)
	{
		for (int j = 13; j <= 25; j++)
		{
			for (int k = 2; k <= 3; k++)
			{
				if (readout[m] == two_dimension_bigword[k][j])
				{
					out[m] = two_dimension_bigword[k + two_dimension_drection][j + lock];
				}
				if (readout[m] == two_dimension_smallword[k][j])
				{
					out[m] = two_dimension_smallword[k + two_dimension_drection][j + lock];
				}
				if (readout[m] == '?' || readout[m] == '!' || readout[m] == '@' || readout[m] == '#' || readout[m] == '$' || readout[m] == '%' || readout[m] == '^' || readout[m] == '&' || readout[m] == '*' || readout[m] == '(' || readout[m] == ')' || readout[m] == '-' || readout[m] == '_' || readout[m] == '+' || readout[m] == '=' || readout[m] == ',' || readout[m] == '.' || readout[m] == '/' || readout[m] == ';' || readout[m] == '[' || readout[m] == ']' || readout[m] == '>' || readout[m] == '<' || readout[m] == ':' || readout[m] == '"' || readout[m] == '{' || readout[m] == '}' || readout[m] == '|' || readout[m] == '`' || readout[m] == '~' || readout[m] == '·' || readout[m] == '，' || readout[m] == '。' || readout[m] == '《' || readout[m] == '》' || readout[m] == '？' || readout[m] == '；' || readout[m] == '：' || readout[m] == '’' || readout[m] == '‘' || readout[m] == '“' || readout[m] == '”' || readout[m] == '！' || readout[m] == '￥' || readout[m] == '（' || readout[m] == '）' || readout[m] == '—')
				{
					out[m] = readout[m];
				}
				//cout << two_dimension_bigword[k + two_dimension_drection][j + lock] << endl << two_dimension_smallword[k + two_dimension_drection][j + lock] << endl;

			}
		}
		//cout << input[m] << endl;
		//cout << out[m] << endl;
	}
}

void fence_decode()
{
	//read_inspection();
	//栅栏加密
	int fence_number = 0;
	for (int z = 0; z <= 1; z++)
	{
		for (int x = 0; x <= ((read - 1) / 2); x++)
		{
			fence_store[z][x] = readout[fence_number];
			fence_number++;
		}
	}
	int out_number = 0;
	for (int d = 0; d <= ((read - 1) / 2); d++)
	{
		for (int e = 0; e <= 1; e++)
		{
			out[out_number] = fence_store[e][d];
			out_number++;
		}
	}
}

void out_decode()
{
	ofstream decodeFile;
	decodeFile.open("decode_contect.txt", fstream::app);
	fstream file("decode_contect.txt", ios::out);

	cout << "解密完成!" << endl << "内容:" << endl << out << endl << "移动长度:" << endl << lock << endl << "加密方向:" << endl << unlockdrection << endl << "加密模式:" << endl << readmodule << endl;

	decodeFile << out << endl;

	cout << "文本输出完成!" << endl;
	decodeFile.close();
	cout << "文本文档已关闭!" << endl;

	break_quckily();
}
#endif // !DECODE


