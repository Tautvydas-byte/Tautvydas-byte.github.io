#include<iostream>
#include<fstream>
#include<string>
#include<thread>//threadam
//#include <mutex>//lock unlock thread ieina thread, i kitas thread negali ieit vienu metu 
#include <windows.h>//owerwritinam
using namespace std;
struct lentele
{
	string esam_busen[100];
	char esam_simb[100];
	char nauj_simb [100];
	char krypt [100];
	string nauj_busen[100];
	string rodykle;
	string eilute;
	string busena = "0";//rodykle vieta eilute
	int nr;//indeksas busenos
	int ilgis;//eilute simboliu kiekis
	int eil_kiek;//eiluciu-nurodymu kiekis	
};
//---------------------------------
lentele L[1000];
void skaitymas(lentele L[],int y);
void turingas(lentele L[], int y);
void turing_spausd(lentele [], int y);
string stop(lentele L[], int y);
void overwritinimas(int y)
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;//stulpeliai
	Position.Y = y * 2;//eilutes
	SetConsoleCursorPosition(hOut, Position);
}
//mutex mx;//lock unlock liptu 
//---------------------------------
int main()
{
	int n;//kiekis norimu apdoroti failu
	thread t;//kintamasis
	int A[100];//failu kiekis
	int sum = 0;//n kiekis

	cout << "Iveskite kiek norite apdoroti failu: " << endl;
	cin >> n;

	cout << "iveskite failo pavadinima: (pvz.: 2 testas.txt)" << endl;
	for (int i = 0; i < n; i++)
	{
		skaitymas(L,i);//kreipiasi i skaityma
		A[i] = 0;//masyvas, kuris rodo ar failas apdorotas
	}
	system("cls");
	while (sum != n)//kol neapdorojami visi n failai, tol while vyksta
	{
		//system("cls");
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == 0)//jei jis nera apdorotas, jei apdorotas thread nesikreips
			{
			thread t(turingas, L, i);
			t.join();
			if (stop(L, i) == "X") A[i]=1;// jei failas apdorotas pirma karta, tai  1as
			}
		}
		for (int i = 0; i < n; i++) sum = sum + A[i];//apskaiciuoja kiek failu yra apdorota
	}
	system("cls");//istrina galutini ats, kuris nera spausd per funkcija
	for (int i = 0; i < n; i++)
	{
		thread t(turing_spausd, L, i);
		t.join();
	}
	return 0;
}
void skaitymas(lentele L[],int y )
{
	string pavadinimas;
	cin >> pavadinimas;
	ifstream fa(pavadinimas+" testas.txt");

	char es,ns,k;
	string eb, nb;
	//y nurodo jog viskas su butent tuo failu, todel y nekinta niekur nes kol visko nepadaro tol nepasikeicia 
	fa >> L[y].nr; fa.ignore();
	fa >> L[y].eilute; fa.ignore();
	L[y].ilgis = L[y].eilute.length();

	while (fa >> eb >> es >> ns >> k >> nb) L[y].eil_kiek++;
	fa.close();
//-----------------------------------------------------
	ifstream fd(pavadinimas + " testas.txt");
	fd >> L[y].nr; fd.ignore();//Nenaudojam
	fd >> L[y].eilute; fd.ignore();//Nenaudojam

	for (int i = 0; i < L[y].eil_kiek; i++)
	{
		fd >> L[y].esam_busen[i];
		fd >> L[y].esam_simb[i];
		fd >> L[y].nauj_simb[i];
		fd >> L[y].krypt[i];
		fd >> L[y].nauj_busen[i];
		fd.ignore();
	}
	fd.close();
	L[y].rodykle = L[y].eilute;
	for (int j = 0; j < L[y].ilgis; j++) L[y].rodykle[j] = '-';
	L[y].nr--;// nes indeksuojam nuo 0, o skaiciavime 1as
	L[y].rodykle[L[y].nr] = '^';//rodykle atsiduria y failo vietoje nr
}
void turingas(lentele L[], int y)
{
	for (int i = 0; i < L[y].eil_kiek; i++)
	{
		if (L[y].busena == L[y].esam_busen[i] && L[y].esam_simb[i] == L[y].eilute[L[y].nr])
		{
			L[y].eilute[L[y].nr] = L[y].nauj_simb[i];
			L[y].busena = L[y].nauj_busen[i];
			if (L[y].nr == 0 && L[y].krypt[i] == 'L')
			{
				L[y].eilute[L[y].nr] = L[y].nauj_simb[i];
				L[y].busena = "X";
			}
			else
			{
				if (L[y].krypt[i] == 'R')
				{
					L[y].nr++;
					L[y].rodykle[L[y].nr] = '^';
					L[y].rodykle[L[y].nr - 1] = '-';
				}
				else
				{
					L[y].nr--;
					L[y].rodykle[L[y].nr] = '^';
					L[y].rodykle[L[y].nr + 1] = '-';
				}
			}
			break;//nutraukia ciklo veikima kai atranda tinkama eilute
		}
	}
	turing_spausd(L, y);
}
void turing_spausd(lentele L[], int y)
{
	//mx.lock();
	overwritinimas(y);
	cout << L[y].eilute << endl;
	cout << L[y].rodykle << endl;
	//mx.unlock();
}
string stop(lentele L[], int y) { return L[y].busena; }//grazina busena( virs kurios yra rodiklyte