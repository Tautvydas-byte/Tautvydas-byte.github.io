#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int V[256];//dvejetainis(char) -> int masyvas
	char h;//h=V[i] unsigned char desimtainis, o char tik dvejetaines pavidalu
	int R[16];//registrai
	string res[256];
	string y;//y registras
	string x;//x registras
	int k = 0;
	int c = 0;//sasiuvini i
	int Rx = 0;
	int Ry = 0;
	int a = 0;
	int e = 0;
	int d = 0;
	unsigned char simb;
	unsigned int simbolis;
	int pozymis = 0;
	unsigned char result;
	//------------------------NUSKAITYMAS BIN--------------------------------------
	streampos size;
	char* B; //string B = char* B, tipo char rodykle veikia kaip string
	ifstream binf;
	binf.open("decryptor.bin", ios::binary | ios::ate);
	size = binf.tellg();
	B = new char[size];//string tipo, isskiria atminti
	binf.seekg(0, ios::beg);//nustato pozicija faile. 0 - failo vieta
	binf.read(B, size); //i vieta dedam visa faila, i string ikisam duomenis
	binf.close();
	//-------------------CHAR -> INT -> HEX string----------------------------------------
	for (int i= 0; i < size; i++)
	{
		h = B[i];
		V[i] = h;//simbolio int skaitine reiksme= kaip char(a=65)
	}
	for (int i = 0; i < size; i++)
	{
		stringstream ss;
		ss << hex <<uppercase<< V[i];//didziosios raides lowercase mazosios
		res[i] = ss.str();
		if (res[i].length() != 2) res[i] = "0" + res[i];//jog butu prideta 0
	}
	//------------------------------------------------
	ifstream failas("q1_encr.txt");
	ofstream ats("Atsakymas.txt");
	while (1)
	{	
		//---YX string -> Y ir X int
		y = res[c+1].substr(0,1);//subtr (vieta,kiek elementu)
		x = res[c+1].substr(1,1);
		Ry = stoi(y, NULL, 16);//16 -> 10 is sesioliktainio i desimtaini
		Rx = stoi(x, NULL, 16);
		//------------------------------------------
			if (res[c] == "01") { R[Rx] = R[Rx] + 1; }
			else if (res[c] == "02") { R[Rx] = R[Rx] - 1; }
			else if (res[c] == "03") { R[Rx] = R[Ry]; }
			else if (res[c] == "04") { R[0] = V[c + 1]; }
			else if (res[c] == "05") { R[Rx] = R[Rx] << 1; }
			else if (res[c] == "06") { R[Rx] = R[Rx] >> 1; }
			else if (res[c] == "07") 
			{
				if (V[c + 1] > size)//230>32
				{
					e = trunc(V[c + 1] / size);//trunc(230/32) = ~7
					d = V[c + 1] - e * size;//230-7*32 = 230-224 = 6

					if (c + d >= size) //28+6>=32
					{
						c = c + d - size - 2; // 28+6-32-2 = 34-32-2 = 2-2=0
					}
					else c = c + d-2;
				}
				else if (V[c + 1]<size && V[c + 1] + c>size)//230<32 ir 230+28>32
				{
					c = V[c + 1] + c - size - 2;
				}
				else c = c + V[c + 1] - 2;
			}
			else if (res[c] == "08") {}
			else if (res[c] == "09") {}
			else if (res[c] == "0A") 
			{
				if (pozymis == 1){ c = V[c + 1] + c - 2;}//0A vieta yra 4, 26(1A) + 4(c->OA) - 2nes apacioj pliusinam c=c+2
			}
			else if (res[c] == "0B") { cout << endl;  cout << "Virtuali masina baigia darba"; break; }
			else if (res[c] == "0C") { R[Rx] = R[Rx] + R[Ry]; }
			else if (res[c] == "0D") { R[Rx] = R[Rx] - R[Ry]; }
			else if (res[c] == "0E") { R[Rx] = R[Rx] ^ R[Ry]; }
			else if (res[c] == "0F") { R[Rx] = R[Rx] | R[Ry]; }
			else if (res[c] == "10")
			{
				failas >> simb;
				if (!failas.eof())
				{
					simbolis = simb;// //simbolio int skaitine reiksme = char(a=65)
					R[Rx] = simbolis;
				}
				else pozymis = 1;				
			}
			else if (res[c] == "11")
			{
				result = R[Rx];
				ats << result;
				cout << result;
			}
			k++;
			c = c + 2;
	}
	return 0;
}