#include <iostream>
#include <fstream>
using namespace std;
int main(int argab, char *argvab[])//per argumentus
{	
	char ia = *argvab[1];//char masyva i char kintamaji
	int a = ia - '0';//char -> int
	char ib = *argvab[2];//char masyva i char kintamaji
	int b = ib - '0';//char -> int

	ofstream myfile;
	myfile.open("Loginiai_rysiai_CSV.csv");//kreipiamasi/kuriama CSV failas
	myfile << "Tautvydas Kvietkauskas Prifs 18/5 \n";
	myfile << "Pradiniai,duomenys,a ir b:,"<<a<<","<<b<<" \n";

	//-----XOR 1-----------------------------------
	int a_not=~a;
	int b_not=~b;
	int ats1 = ((a_not & b) | (b_not & a)); cout << ats1 << endl;

	myfile << "XOR 1,naudotos,operacijos, not,and,or \n";//Isveda 
	myfile << "Rezultatas," << ats1 << "\n";//Isveda 
	//-----XOR 2-----------------------------------
	int nand1 = ~(a & b);
	int nand2 = ~(a & nand1);
	int nand3 = ~(b & nand1);
	int ats2 = ~(nand2 & nand3); cout << ats2 << endl;

	myfile << "XOR 2,naudotos,operacijos, nand \n";
	myfile << "Rezultatas," << ats2 << "\n";
	//-----XOR 3----------------------------------
	int a_or_b = a | b;
	int a_and_b = a & b;
	int a_and_b_not = ~(a_and_b);
	int ats3 = (a_or_b & a_and_b_not); cout << ats3 << endl;

	myfile << "XOR 3,naudotos,operacijos, not,and,or \n";
	myfile << "Rezultatas," << ats3 << "\n";
	//-----XOR 4-----------------------------------
	int a_not_or_b_not = (a_not | b_not);
	int ats4 = a_or_b & a_not_or_b_not; cout << ats4;

	myfile << "XOR 4,naudotos,operacijos, not,and,or \n";
	myfile << "Rezultatas," << ats4 << "\n";
	
	myfile.close();

	return 0;
}	
//c=~a;// not
//c=a|b;//or
//c=a&b;//and
//c=~(a&b);//nand grieztas neiginys