#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include <bitset>
#include<map>
using namespace std;
//----------------------
void dalis1(int nr, int& ilgis, string& binary_reverse)//pavertimas i dvejetaini
{
	int number;
	while (nr > 0)
	{
		if (nr % 2 != 0)number = 1;
		else number = 0; //cout<<number;
		stringstream bin;//int to string
		bin << number;//i string ideda int
		string str = bin.str();//str butina kaip formule, int to string pabaiga
		binary_reverse = binary_reverse + str;//i  stringa prideda po viena simboli
		ilgis = binary_reverse.length();
		nr = nr / 2;
	}
}
void iki7(string binary_reverse, int& ilgis, string& utf_binary)// ilgis <= 7
{
	string binary(binary_reverse.rbegin(), binary_reverse.rend());//string atvirksciai
	utf_binary = binary;
	while (ilgis != 7)
	{
		utf_binary = "0" + utf_binary;//padaro binary tinkanti konv i utf8
		ilgis++;
	}
}
void iki11(string binary_reverse, int& ilgis, string& utf_binary)// ilgis <= 11
{
	string binary(binary_reverse.rbegin(), binary_reverse.rend());//string atvirksciai
	utf_binary = binary;
	while (ilgis != 11)
	{
		utf_binary = "0" + utf_binary;//padaro binary tinkanti konv i utf8
		ilgis++;
	}
}
void iki16(string binary_reverse, int& ilgis, string& utf_binary)// ilgis <= 16
{
	string binary(binary_reverse.rbegin(), binary_reverse.rend());//string atvirksciai
	utf_binary = binary;
	while (ilgis != 16)
	{
		utf_binary = "0" + utf_binary;//padaro binary tinkanti konv i utf8
		ilgis++;
	}
}
void iki21(string binary_reverse, int& ilgis, string& utf_binary)//ilgis <= 21
{
	string binary(binary_reverse.rbegin(), binary_reverse.rend());//string atvirksciai
	utf_binary = binary;
	while (ilgis != 21)
	{
		utf_binary = "0" + utf_binary;//padaro binary tinkanti konv i utf8
		ilgis++;
	}
}
void UTF_binary(string utf_binary, int &ilgis, string& utf_byte_res)
{
	string byte1 = "0xxxxxxx";
	string byte2 = "110xxxxx10xxxxxx";
	string byte3 = "1110xxxx10xxxxxx10xxxxxx";
	string byte4 = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	if(ilgis==7)
	{
		utf_byte_res = byte1;
		int vt = 0;
		for (int i = 0; i < 8; i++)
		{
			if (utf_byte_res[i] == 'x')
			{
				utf_byte_res[i] = utf_binary[vt];
				vt++;
			}
		}
	}
	else if (ilgis == 11)
	{
		utf_byte_res = byte2;
		int vt = 0;
		for (int i = 0; i < 16; i++)
		{
			if (utf_byte_res[i] == 'x')
			{
				utf_byte_res[i] = utf_binary[vt];
				vt++;
			}
		}
	}
	else if (ilgis==16)
	{
		utf_byte_res = byte3;
		int vt = 0;
		for (int i = 0; i < 24; i++)
		{
			if (utf_byte_res[i] == 'x')
			{
				utf_byte_res[i] = utf_binary[vt];
				vt++;
			}
		}
	}
	else
	{
		utf_byte_res = byte4;
		int vt = 0;
		for (int i = 0; i < 32; i++)
		{
			if (utf_byte_res[i] == 'x')
			{
				utf_byte_res[i] = utf_binary[vt];
				vt++;
			}
		}
	}
}
void UTF_8(string utf_byte_res, string& utf_8)
{
	unsigned long long n;
	n= stoull(utf_byte_res, 0, 2);
	stringstream ss;
	ss << hex << n;
	utf_8 = ss.str();//spausdina ta pati pirmo ivesto simbolio ats, nesikeicia 
}
void unicode(int nr, string& result)
{
	stringstream ss;
	ss << hex << nr;
	string res = ss.str();
	int ilg = res.length();
	if (4 - ilg > 0) for (int i = 0; i < 4 - ilg; i++) res = "0" + res;
	result = "u+" + res;
}
void UTF_8_cut(string utf_byte_res,string utf_byte_res_str[4])
{
	int ilgis2 = utf_byte_res.length();
	int reik_ilgis2 = ilgis2 / 8;
	int l; l = 0;
	for (int i = 0; i < reik_ilgis2; i++)
	{
		utf_byte_res_str[i] = utf_byte_res.substr(l, 8);//8 visada, nes kkiek elem rodo
		l = l + 8;
	}
}
void spausd(string& binary_reverse, string result, string utf_8)
{
	string binary(binary_reverse.rbegin(), binary_reverse.rend());//string atvirksciai
	cout << "Dvejetainis " << binary << endl;
	cout <<"Unicode "<< result << endl;
	cout <<"UTF-8 "<< utf_8 << endl;
}
int main()
{
	int nr;
	string binary;
	string binary_reverse;
	string result;
	string utf_binary;
	string utf_byte_res;
	string utf_8;
	int ilgis;
	int dalis = 9;
	string utf_byte_res_str[4];

	while (dalis != 0)
	{	
		 binary ="";
		 binary_reverse ="";
		 result ="";
		 utf_binary = "";
		 utf_byte_res ="";
		 utf_8 ="";
		 ilgis = 0;

		cout << "Iveskite dalies numeri(1 arba 2) arba iseiti (bet koks skaicius)" << endl;
		cout << "Dalies ivedimas"<<endl;
		cin >> dalis;
		if (dalis == 1)
		{
			cout << "Iveskite norima skaiciu"<<endl;
			cin >> nr;
			if (nr == 0) { binary_reverse = "0000"; ilgis = 4; }
			else dalis1(nr, ilgis, binary_reverse);

			unicode(nr, result);

			if (ilgis <= 7) iki7(binary_reverse, ilgis, utf_binary);
			else if (ilgis>= 8 && ilgis <= 11)  iki11(binary_reverse, ilgis, utf_binary);
			else if (ilgis >= 12 && ilgis <= 16) iki16(binary_reverse, ilgis, utf_binary);
			else iki21(binary_reverse, ilgis, utf_binary);

			UTF_binary(utf_binary, ilgis,utf_byte_res);
			UTF_8(utf_byte_res, utf_8);
			spausd(binary_reverse, result, utf_8);
		}
		else if (dalis == 2)//klaus kaip vyksta 2 dalis, pasiruost atsakymus kas is ko verciama, kaip gaunasi utf ir panasiai
		{
			ifstream fi("386intel.txt");
			ifstream fc("CP437.txt");

			ofstream fr("rezultatas.txt");

			map<int, string> CP;
			string line;
			int cpskc;
			unsigned char line_char;

			for (int i = 0; i < 256; i++)
			{
				fc >> cpskc;
				fc >> CP[cpskc];
			}
			
			for (int s = 0; s < 20856; s++)//failo eilutes
			{
				getline(fi, line, '\n');
				int a;
				a = line.length();

				for (int j = 0; j < a; j++)
				{
					binary = "";
					binary_reverse = "";
					result = "";
					utf_binary = "";
					utf_byte_res = "";
					utf_8 = "";
					ilgis = 0;

					line_char = line[j];
					int kk;
					kk = line_char;
					string kk_string;
					kk_string = CP[kk];
					int kk_int;

					kk_int = stoul(kk_string.c_str(), 0, 16);//gaunu tai ka ivesciau ranka
					dalis1(kk_int, ilgis, binary_reverse);

					if (ilgis <= 7) iki7(binary_reverse, ilgis, utf_binary);
					else if (ilgis >= 8 && ilgis <= 11)  iki11(binary_reverse, ilgis, utf_binary);
					else if (ilgis >= 12 && ilgis <= 16) iki16(binary_reverse, ilgis, utf_binary);
					else iki21(binary_reverse, ilgis, utf_binary);
					
					UTF_binary(utf_binary, ilgis, utf_byte_res);

					UTF_8(utf_byte_res, utf_8);

					UTF_8_cut(utf_byte_res, utf_byte_res_str);

					//---Is string dvejetaine sukarpyta keicia i desimtaine
					unsigned long long utf_byte_res_int[4];
					int ilgis2 = utf_byte_res.length();
					int reik_ilgis2 = ilgis2 / 8;
					for (int i = 0; i < reik_ilgis2; i++)utf_byte_res_int[i] = stoll(utf_byte_res_str[i].c_str(), 0, 2);
					//gaunu tai ka ivesciau ranka,"2"nurodo kokiu kodavimu ar 2/8/16 atsiuncia
					//-----------------------------------------------------
					unsigned char rezultatas[4];
					for (int i = 0; i < reik_ilgis2; i++)
					{
						rezultatas[i] = utf_byte_res_int[i];
					}
					for (int i = 0; i < reik_ilgis2; i++)fr << rezultatas[i];
				}
				fr<<endl;
			}
		}
		else { return 0; }//programa baigias
	}
	return 0;
}
/*
-----int to string
#include <sstream>
int a = 10;
stringstream ss;
ss << a;//nezinau ka daro BET REIKALINGAS
string str = ss.str();
cout<<str;
-----Atbuline
string n;
string rn(n.rbegin(), n.rend());
cout<<rn;*/

/*cout << "110xxxxx10xxxxxx -->" << byte2 << endl;
	for (int i = 0; i < 16; i++) { byte2_map[i] = byte2[i]; cout << byte2_map[i]; } cout << endl;
	for (int o = 0; o < 16; o++) { bin_map[o] = byte2_map[o]; cout << byte2_map[o]; } cout << endl;

	int vt = 0;
	for(int i=0;i<16;i++)
	{
	   bin_map[i]=byte2[i];

	   if (bin_map[i] == "x")
	   {
		   bin_map[i] = utf_binary[vt];
		   vt++;
	   }
	   cout<<bin_map[i];
	}*/

/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char buffer[33];
	printf("Enter a number: ");
	scanf("%d", &i);
	itoa(i, buffer, 10);
	printf("decimal: %s\n", buffer);
	itoa(i, buffer, 16);
	printf("hexadecimal: %s\n", buffer);
	itoa(i, buffer, 2);
	printf("binary: %s\n", buffer);
	return 0;
Enter a number: 1148
decimal: 1148
hexadecimal: 47c
binary: 10001111100
}*/