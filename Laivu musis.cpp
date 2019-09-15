#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <map>
using namespace std;
class musis
{ //PRIVATE TIK DEKLARUOTI!!! PRISKIRINETI REIKSMIU NEGALIMA
  private:
  map< int,map<int,char> > PC_laukas;//lentele saugoma masyve PC dvimatis map
  map< int,map<int,char> > PC_laukas_tuscia;//lentele kur zaidejas saudys bet nematys laivu PC isdestytu
  map< int,map<int,char> > zaidejo_laukas;//lentele saugoma masyve zaidejo
    int sk;//skaicius
    char rd;//raide
    char kr;//kryptis skaiciais
    int kr1;//kryptis raidemis
    int taip;
    int tinka;
    int kiek;
    int pataike=0;//kur tada deklaruoti, kad veiktu??
    int pataikePC=0; //kur tada deklaruoti kad veiktu??
    int laivu_kiekis=8;
      int saugo_rd;
      int saugo_sk;
      int lvk;

  public:
  //---------------Zaidejo----Lentele masyve------KONSTRUKTORIUS---------
  musis()
  {
    for(int r=0;r<=11;r++) //lenteles raides sonuose
     {
        for(int j=0;j<=11;j++)//saugau langeliu reiksmes masyve
        {
           zaidejo_laukas[r][j]='O';
           PC_laukas[r][j]='O';
           PC_laukas_tuscia[r][j]='O';
        }
      }
      // LENTELES ISORINE APSAUGA
     for(int j=0;j<=11;j++){
        PC_laukas[-1][j]='/';//virsus ->
        PC_laukas[10][j]='/';}// apacia ->
    for(int r=0;r<=11;r++){
     PC_laukas[r][0]='/';//sonas kaire
     PC_laukas[r][11]='/';}//sonas desine
  }
  //------------ZAIDEJO---------------
  void Mano_lentele()
  {
    cout<<endl;
    cout<<"          Jusu lentele"<<endl;
    for(int s=1;s<=10;s++)//lenteles skaiciai virsuje
    {
      cout<<"  "<<s;
    } cout<<endl;
      for(char r='a';r<='j';r++) //lenteles raides sonuose
      {
        cout<<r<<" ";
        {
          for(int j=1;j<=10;j++)//saugau langeliu reiksmes masyve
          {
            cout<<zaidejo_laukas[r-97][j]<<"  ";//koordinates
          }
        } cout<<endl;
      }cout<<endl;
  }
  //--------------KOmpiuterio bendra/saudymui----------------------------
   void PC_lentele()
  {
    cout<<endl;
    cout<<"      Kompiuterio lentele"<<endl;
    for(int s=1;s<=10;s++)//lenteles skaiciai virsuje
    {
      cout<<"  "<<s;
    } cout<<endl;
      for(char r='a';r<='j';r++) //lenteles raides sonuose
      {
        cout<<r<<" ";
        {
          for(int j=1;j<=10;j++)//saugau langeliu reiksmes masyve
          {
            cout<<PC_laukas[r-97][j]<<"  ";//koordinates
          }
        } cout<<endl;
      }cout<<endl;
  }
//----------------KOmpiuterio 2.0 tuscia rodyti zaidejui be laivu--------
   void PC_lentele_suvis()
  {
    cout<<endl;
    cout<<"  Kompiuterio lentele saudymui"<<endl;
    for(int s=1;s<=10;s++)//lenteles skaiciai virsuje
    {
      cout<<"  "<<s;
    } cout<<endl;
      for(char r='a';r<='j';r++) //lenteles raides sonuose
      {
        cout<<r<<" ";
        {
          for(int j=1;j<=10;j++)//saugau langeliu reiksmes masyve
          {
            cout<<PC_laukas_tuscia[r-97][j]<<"  ";//koordinates
          }
        } cout<<endl;
      }cout<<endl;
  }
//--------------Zaidejo ivedimas kur bus laivai---
void zaidejo_ivedimas_4()
{
 tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
 while(tinka<1)
    {
    cout<<"Ivedimo instrukcija: skaicius (1-10); raide (a-j); kryptis: "<<endl; cout<<"(a-apacia; v-virsus; d-desine; k-kaire)"<<endl;
    cout<<"Iveskite laiva,kuris bus uzpildytas 4 vietomis."<<endl; cout<<"Skaicius raide kryptis PVZ: 3bd"<<endl;
    cout<<"Koordinates: ";cin>>sk>>rd>>kr; cout<<endl;
    if(sk>=1 && sk<=10 && rd>='a' && rd<='j')
        {
        if(kr=='d' && sk<=7)//DESINE
        {
        for(int i=0;i<4;i++) {zaidejo_laukas[rd-97][sk+i]='#';tinka++;}
          for(int i=-1;i<5;i++) {zaidejo_laukas[rd-97+1][sk+i]='*'; zaidejo_laukas[rd-97-1][sk+i]='*'; zaidejo_laukas[rd-97][sk-1]='*'; zaidejo_laukas[rd-97][sk+4]='*';}
        }
          else if(kr=='k' && sk>=4 && sk<=10)//KAIRE
          {
          for(int i=0;i<4;i++) {zaidejo_laukas[rd-97][sk-i]='#';tinka++;}
           for(int i=-1;i<5;i++) {zaidejo_laukas[rd-97+1][sk-i]='*'; zaidejo_laukas[rd-97-1][sk-i]='*'; zaidejo_laukas[rd-97][sk-4]='*'; zaidejo_laukas[rd-97][sk+1]='*';}
          }
            else if(kr=='a' && rd<='g')//AUKSTYN
            {
            for(int i=0;i<4;i++){zaidejo_laukas[rd+i-97][sk]='#';tinka++;}
             for(int i=-1;i<5;i++) {zaidejo_laukas[rd+i-97][sk-1]='*'; zaidejo_laukas[rd-97+i][sk+1]='*';zaidejo_laukas[rd-97-1][sk]='*'; zaidejo_laukas[rd-97+4][sk]='*';}
            }
              else if(kr=='v'&& rd>='d')//VIRSUS
              {
              for(int i=0;i<4;i++){zaidejo_laukas[rd-i-97][sk]='#';tinka++;}
                for(int i=-1;i<5;i++) {zaidejo_laukas[rd-i-97][sk-1]='*'; zaidejo_laukas[rd-97-i][sk+1]='*';zaidejo_laukas[rd-97+1][sk]='*'; zaidejo_laukas[rd-97-4][sk]='*';}
              }
                else cout<<"ISEJOTE IS TERITORIJOS"<<endl;
        }
    else cout<<"Ivestos blogos koordinates"<<endl;
    }

}
void zaidejo_ivedimas_3()
{
    tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
    taip=0;// tikrina ar atitinka, jog ar uzejo ant laivo
    while(tinka<1)
    {
    cout<<"Ivedimo instrukcija: skaicius (1-10); raide (a-j); kryptis: "<<endl; cout<<"(a-apacia; v-virsus; d-desine; k-kaire)"<<endl;
    cout<<"Iveskite laiva,kuris bus uzpildytas 3 vietomis."<<endl; cout<<"Skaicius raide kryptis PVZ: 3bd"<<endl;
    cout<<"Koordinates: ";cin>>sk>>rd>>kr; cout<<endl;
   if(sk>=1 && sk<=10 && rd>='a' && rd<='j')//ar koordinates tinka
   {
    if(kr=='d' && sk<=8)//DESINE
     {
        while (taip<1)
        {
        if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97][sk+2]=='*' || zaidejo_laukas[rd-97][sk+2]=='#')
            {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
         else
         {
         for(int i=0;i<3;i++)zaidejo_laukas[rd-97][sk+i]='#'; taip++; tinka++;
            for(int i=-1;i<4;i++) {zaidejo_laukas[rd-97+1][sk+i]='*'; zaidejo_laukas[rd-97-1][sk+i]='*'; zaidejo_laukas[rd-97][sk-1]='*'; zaidejo_laukas[rd-97][sk+3]='*';}
         }
        }taip=0;
     }
      else if(kr=='k' && sk>=3 && sk<=10)//KAIRE
      {
        while (taip<1)
        {
        if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97][sk-2]=='*' || zaidejo_laukas[rd-97][sk-2]=='#')
            {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
         else
         {
         for(int i=0;i<3;i++)zaidejo_laukas[rd-97][sk-i]='#'; taip++; tinka++;
            for(int i=-1;i<4;i++) {zaidejo_laukas[rd-97+1][sk-i]='*'; zaidejo_laukas[rd-97-1][sk-i]='*'; zaidejo_laukas[rd-97][sk-3]='*'; zaidejo_laukas[rd-97][sk+1]='*';}
         }
        }taip=0;
      }
        else if(kr=='a' && rd<='h')//APACIA
        {
            while (taip<1)
            {
            if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97+3][sk]=='*' || zaidejo_laukas[rd-97+3][sk]=='#')
                {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
             else
             {
             for(int i=0;i<3;i++)zaidejo_laukas[rd+i-97][sk]='#'; taip++; tinka++;
                for(int i=-1;i<4;i++) {zaidejo_laukas[rd-97+i][sk+1]='*'; zaidejo_laukas[rd-97+i][sk-1]='*'; zaidejo_laukas[rd-97-1][sk]='*'; zaidejo_laukas[rd-97+3][sk]='*';}
             }
            }taip=0;
         }
          else if(kr=='v'&& rd>='c')//VIRSUS
          {
            while (taip<1)
            {
            if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97-3][sk]=='*' || zaidejo_laukas[rd-97-3][sk]=='#')
                {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
             else
              {
              for(int i=0;i<3;i++)zaidejo_laukas[rd-i-97][sk]='#';taip++; tinka++;
                for(int i=-1;i<4;i++) {zaidejo_laukas[rd-97-i][sk+1]='*'; zaidejo_laukas[rd-97-i][sk-1]='*'; zaidejo_laukas[rd-97+1][sk]='*'; zaidejo_laukas[rd-97-3][sk]='*';}
              }
             }taip=0;
            }
            else cout<<"ISEJOTE IS TERITORIJOS"<<endl;
    }//ar isvis skaiciai, raides tinka if pabaiga
    else cout<<"Ivestos blogos koordinates"<<endl;
      }//while pabaiga
}
void zaidejo_ivedimas_2()
{
    tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
    taip=0;
    while(tinka<1)
    {
    cout<<"Ivedimo instrukcija: skaicius (1-10); raide (a-j); kryptis: "<<endl; cout<<"(a-apacia; v-virsus; d-desine; k-kaire)"<<endl;
    cout<<"Iveskite laiva,kuris bus uzpildytas 2 vietomis."<<endl; cout<<"Skaicius raide kryptis PVZ: 3bd"<<endl;
    cout<<"Koordinates: ";cin>>sk>>rd>>kr; cout<<endl;

    if(sk>=1 && sk<=10 && rd>='a' && rd<='j')//ar koordinates tinka
    {
    if(kr=='d' && sk<=9)//DESINE
     {
        while (taip<1)
        {
        if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97][sk+2]=='*' || zaidejo_laukas[rd-97][sk+2]=='#')
            {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
         else
         {
         for(int i=0;i<2;i++)zaidejo_laukas[rd-97][sk+i]='#'; taip++; tinka++;
            for(int i=-1;i<3;i++) {zaidejo_laukas[rd-97+1][sk+i]='*'; zaidejo_laukas[rd-97-1][sk+i]='*'; zaidejo_laukas[rd-97][sk-1]='*'; zaidejo_laukas[rd-97][sk+2]='*';}
         }
        }taip=0;
     }
       else if(kr=='k' && sk>=2 && sk<=10)//KAIRE
      {
        while (taip<1)
        {
        if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97][sk-2]=='*' || zaidejo_laukas[rd-97][sk-2]=='#')
            {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
         else
         {
         for(int i=0;i<2;i++)zaidejo_laukas[rd-97][sk-i]='#'; taip++; tinka++;
            for(int i=-1;i<3;i++) {zaidejo_laukas[rd-97+1][sk-i]='*'; zaidejo_laukas[rd-97-1][sk-i]='*'; zaidejo_laukas[rd-97][sk-2]='*'; zaidejo_laukas[rd-97][sk+1]='*';}
         }
        }taip=0;
      }
        else if(kr=='a' && rd<='i')//APACIA
        {
            while (taip<1)
            {
            if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97+2][sk]=='*' || zaidejo_laukas[rd-97+2][sk]=='#')
                {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
             else
             {
             for(int i=0;i<2;i++)zaidejo_laukas[rd+i-97][sk]='#'; taip++; tinka++;
                for(int i=-1;i<3;i++) {zaidejo_laukas[rd-97+i][sk+1]='*'; zaidejo_laukas[rd-97+i][sk-1]='*'; zaidejo_laukas[rd-97-1][sk]='*'; zaidejo_laukas[rd-97+2][sk]='*';}
             }
            }taip=0;
         }
          else if(kr=='v'&& rd>='b')//VIRSUS
          {
            while (taip<1)
            {
            if(zaidejo_laukas[rd-97][sk]=='*' || zaidejo_laukas[rd-97][sk]=='#' || zaidejo_laukas[rd-97-2][sk]=='*' || zaidejo_laukas[rd-97-2][sk]=='#')
                {cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;}
             else
              {
              for(int i=0;i<2;i++)zaidejo_laukas[rd-i-97][sk]='#';taip++; tinka++;
                for(int i=-1;i<3;i++) {zaidejo_laukas[rd-97-i][sk+1]='*'; zaidejo_laukas[rd-97-i][sk-1]='*'; zaidejo_laukas[rd-97+1][sk]='*'; zaidejo_laukas[rd-97-2][sk]='*';}
              }
             }taip=0;
            }
            else cout<<"ISEJOTE IS TERITORIJOS"<<endl;
    }//ar isvis skaiciai, raides tinka if pabaiga
    else cout<<"Ivestos blogos koordinates"<<endl;
      }//while pabaiga
}
void zaidejo_ivedimas_1()
{
    taip=0;
    tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
    while(tinka<1)
    {
    cout<<"Ivedimo instrukcija: skaicius (1-10); raide (a-j)"<<endl;
    cout<<"Iveskite laiva,kuris bus uzpildytas 1 vieta. skaicius raide PVZ: 3b"<<endl;
    cout<<"Koordinates: ";cin>>sk>>rd; cout<<endl;
        if(sk>=1 && sk<=10 && rd>='a' && rd<='j')
        {
            while(taip<1)
            {
                if(zaidejo_laukas[rd-97-1][sk]=='#'|| zaidejo_laukas[rd-97+1][sk]=='#' || zaidejo_laukas[rd-97][sk+1]=='#'
                    || zaidejo_laukas[rd-97][sk-1]=='#' || zaidejo_laukas[rd-97-1][sk-1]=='#' || zaidejo_laukas[rd-97+1][sk-1]=='#'
                    || zaidejo_laukas[rd-97-1][sk+1]=='#'|| zaidejo_laukas[rd-97+1][sk+1]=='#'|| zaidejo_laukas[rd-97][sk]=='#')
                    {
                    cout<<"Uzejote i laivo teritorija!!!"<<endl;taip++;
                    }
                    else
                    {
                        zaidejo_laukas[rd-97][sk]='#';taip++; tinka++;
                        for(int i=-1;i<2;i++)
                        {
                            zaidejo_laukas[rd-97+1][sk+i]='*';
                            zaidejo_laukas[rd-97-1][sk+i]='*';
                            zaidejo_laukas[rd-97][sk-1]='*';
                            zaidejo_laukas[rd-97][sk+1]='*';
                        }
                    }
            }taip=0;
        }else cout<<"Ivestos blogos koordinates"<<endl;
    }
}
//------------KOMPIUTERIO IVEDINEJIMAS-----------
void PC_ivedimas_4()
{
 tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
 while(tinka<1)
    {
    sk=rand()%10+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
    rd=rand()%10+97;
    kr1=rand()%4+1; //krypciai skaiciu priskirt ir random
    if(kr1==1) kr='a';
        else if(kr1==2) kr='v';
            else if (kr1==3) kr='d';
                else if(kr1==4) kr='k';
        {
         if(kr=='d')//DESINE
         {
            if(sk>7)tinka=0;
             else
             {
               for(int i=0;i<4;i++) {PC_laukas[rd-97][sk+i]='#';tinka++;}
               for(int i=-1;i<5;i++) {PC_laukas[rd-97+1][sk+i]='*'; PC_laukas[rd-97-1][sk+i]='*'; PC_laukas[rd-97][sk-1]='*'; PC_laukas[rd-97][sk+4]='*';}
             }
         }
          else if(kr=='k')//KAIRE
          {
            if(sk<4)tinka=0;
             else
             {
               for(int i=0;i<4;i++) {PC_laukas[rd-97][sk-i]='#';tinka++;}
               for(int i=-1;i<5;i++) {PC_laukas[rd-97+1][sk-i]='*'; PC_laukas[rd-97-1][sk-i]='*'; PC_laukas[rd-97][sk-4]='*'; PC_laukas[rd-97][sk+1]='*';}
             }
          }
            else if(kr=='a')//Apacia
            {
              if(rd>='h')tinka=0;
                else
                {
                  for(int i=0;i<4;i++){PC_laukas[rd+i-97][sk]='#';tinka++;}
                  for(int i=-1;i<5;i++) {PC_laukas[rd+i-97][sk-1]='*'; PC_laukas[rd-97+i][sk+1]='*';PC_laukas[rd-97-1][sk]='*'; PC_laukas[rd-97+4][sk]='*';}
                }
            }
               else if(kr=='v')//VIRSUS
               {
                if(rd<='c')tinka=0;
                  else
                  {
                   for(int i=0;i<4;i++){PC_laukas[rd-i-97][sk]='#';tinka++;}
                   for(int i=-1;i<5;i++) {PC_laukas[rd-i-97][sk-1]='*'; PC_laukas[rd-97-i][sk+1]='*';PC_laukas[rd-97+1][sk]='*'; PC_laukas[rd-97-4][sk]='*';}
                  }
               }
         }//krypciu pab
    }//while pab
}//void pab
void PC_ivedimas_3()
{
tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
    while(tinka<1)
    {
    sk=rand()%10+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
    //cout<<sk<<endl;
    rd=rand()%10+97;//cout<<rd<<endl;
    kr1=rand()%4+1; //krypciai skaiciu priskirt ir random
    if(kr1==1) kr='a';
        else if(kr1==2) kr='v';
            else if (kr1==3) kr='d';
                else if(kr1==4) kr='k';//cout<<kr<<endl;
    if(kr=='d')//DESINE
     {
      //JEI NETINKA
      if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97][sk+2]=='*' || PC_laukas[rd-97][sk+2]=='#' || PC_laukas[rd-97][sk+1]=='*' || PC_laukas[rd-97][sk+1]=='#'
       || PC_laukas[rd-97-1][sk-1]=='#' || PC_laukas[rd-97-1][sk-1]=='*' || PC_laukas[rd-97-1][sk+1]=='#' || PC_laukas[rd-97-1][sk+1]=='*' || PC_laukas[rd-97+1][sk+3]=='#' || PC_laukas[rd-97+1][sk+3]=='*' )||sk>8)
      tinka=0;
         else
         {
          for(int i=0;i<3;i++)PC_laukas[rd-97][sk+i]='#';tinka++;
          for(int i=-1;i<4;i++) {PC_laukas[rd-97+1][sk+i]='*'; PC_laukas[rd-97-1][sk+i]='*'; PC_laukas[rd-97][sk-1]='*'; PC_laukas[rd-97][sk+3]='*';}
         }
     }
      else if(kr=='k')//KAIRE
      { //cout<<"esame kairiame if"<<endl;
        if(sk<3||(PC_laukas[rd-97][sk]=='*'||PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97][sk-2]=='#' || PC_laukas[rd-97][sk-1]=='#')){//cout<<"Klaida"<<endl;
        tinka=0;}
         else
         {
          for(int i=0;i<3;i++)PC_laukas[rd-97][sk-i]='#';tinka++;
          for(int i=-1;i<4;i++) {PC_laukas[rd-97+1][sk-i]='*'; PC_laukas[rd-97-1][sk-i]='*'; PC_laukas[rd-97][sk-3]='*'; PC_laukas[rd-97][sk+1]='*';}
         }
      }
        else if(kr=='a')//APACIA
        {
          if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97+3][sk]=='*' || PC_laukas[rd-97+3][sk]=='#' ||PC_laukas[rd-97+2][sk]=='#') || rd>='i')
          tinka=0;
           else
            {
             for(int i=0;i<3;i++)PC_laukas[rd+i-97][sk]='#';tinka++;
             for(int i=-1;i<4;i++) {PC_laukas[rd-97+i][sk+1]='*'; PC_laukas[rd-97+i][sk-1]='*'; PC_laukas[rd-97-1][sk]='*'; PC_laukas[rd-97+3][sk]='*';}
            }
        }
          else if(kr=='v')//VIRSUS
          {
            if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97-3][sk]=='*' || PC_laukas[rd-97-3][sk]=='#' || PC_laukas[rd-97-2][sk]=='*' ||PC_laukas[rd-97-1][sk]=='#') || rd<='b')
            tinka=0;
             else
              {
               for(int i=0;i<3;i++)PC_laukas[rd-i-97][sk]='#';tinka++;
               for(int i=-1;i<4;i++) {PC_laukas[rd-97-i][sk+1]='*'; PC_laukas[rd-97-i][sk-1]='*'; PC_laukas[rd-97+1][sk]='*'; PC_laukas[rd-97-3][sk]='*';}
              }
          }
     }//while pabaiga
}
void PC_ivedimas_2()
{
    tinka=0;
    while(tinka<1)
    {
    sk=rand()%10+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
    rd=rand()%10+97;
    kr1=rand()%4+1; //krypciai skaiciu priskirt ir random
    if(kr1==1) kr='a';
        else if(kr1==2) kr='v';
             else if (kr1==3) kr='d';
                else if(kr1==4) kr='k';
    if(kr=='d')//DESINE 3
     {
        if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97][sk+2]=='*' || PC_laukas[rd-97][sk+2]=='#' || PC_laukas[rd-97][sk+1]=='#') || sk>9 )
        tinka=0;
         else
         {
         for(int i=0;i<2;i++)PC_laukas[rd-97][sk+i]='#';tinka++;
            for(int i=-1;i<3;i++) {PC_laukas[rd-97+1][sk+i]='*'; PC_laukas[rd-97-1][sk+i]='*'; PC_laukas[rd-97][sk-1]='*'; PC_laukas[rd-97][sk+2]='*';}
         }
     }
       else if(kr=='k')//KAIRE 4
       {
        if(sk<2 || (PC_laukas[rd-97][sk]=='*'|| PC_laukas[rd-97][sk]=='#'||PC_laukas[rd-97][sk-1]=='*'||PC_laukas[rd-97][sk-1]=='#'))
            tinka=0;
         else
         {
         for(int i=0;i<2;i++)PC_laukas[rd-97][sk-i]='#';tinka++;
            for(int i=-1;i<3;i++) {PC_laukas[rd-97+1][sk-i]='*'; PC_laukas[rd-97-1][sk-i]='*'; PC_laukas[rd-97][sk-2]='*'; PC_laukas[rd-97][sk+1]='*';}
         }
       }
        else if(kr=='a')//APACIA 1
        {
         if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97+2][sk]=='*' || PC_laukas[rd-97+2][sk]=='#') || rd>='j')
         tinka=0;
          else
          {
          for(int i=0;i<2;i++)PC_laukas[rd+i-97][sk]='#';tinka++;
            for(int i=-1;i<3;i++) {PC_laukas[rd-97+i][sk+1]='*'; PC_laukas[rd-97+i][sk-1]='*'; PC_laukas[rd-97-1][sk]='*'; PC_laukas[rd-97+2][sk]='*';}
          }
         }
          else if(kr=='v')//VIRSUS
          {
            if((PC_laukas[rd-97][sk]=='*' || PC_laukas[rd-97][sk]=='#' || PC_laukas[rd-97-2][sk]=='*' || PC_laukas[rd-97-2][sk]=='#') || rd<='a' )
          tinka=0;
             else
              {
              for(int i=0;i<2;i++)PC_laukas[rd-i-97][sk]='#';tinka++;
                for(int i=-1;i<3;i++) {PC_laukas[rd-97-i][sk+1]='*'; PC_laukas[rd-97-i][sk-1]='*'; PC_laukas[rd-97+1][sk]='*'; PC_laukas[rd-97-2][sk]='*';}
              }
            }
      } //while pabaiga
}
void PC_ivedimas_1()
{
    tinka=0;//tikrina ar atitinka salyga, jei taip tinka=1
    while(tinka<1)
    {
    sk=rand()%10+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
    rd=rand()%10+97;
    if(PC_laukas[rd-97-1][sk]=='#'|| PC_laukas[rd-97+1][sk]=='#' || PC_laukas[rd-97][sk+1]=='#'
    || PC_laukas[rd-97][sk-1]=='#' || PC_laukas[rd-97-1][sk-1]=='#' || PC_laukas[rd-97+1][sk-1]=='#'
    || PC_laukas[rd-97-1][sk+1]=='#'|| PC_laukas[rd-97+1][sk+1]=='#'|| PC_laukas[rd-97][sk]=='#')tinka=0;
        else
        {
        PC_laukas[rd-97][sk]='#';tinka++;
            for(int i=-1;i<2;i++)
            {
            PC_laukas[rd-97+1][sk+i]='*'; PC_laukas[rd-97-1][sk+i]='*';
            PC_laukas[rd-97][sk-1]='*'; PC_laukas[rd-97][sk+1]='*';
            }
        }
     }
}
void saudymas_zmogaus()
{
    tinka=0;
    cout<<endl;
    cout<<"Zaidejo saudymas"<<endl;
    cout<<"Iveskite skaiciu ir raide,PVZ: 3a"<<endl;

    while(tinka<1)
    {
        cout<<"Suvio koordinates: ";cin>>sk>>rd; cout<<endl;
        if(sk>=1 && sk<=10 && rd>='a' && rd<='j')
        {
        if(PC_laukas[rd-97][sk]=='#')
            {
            PC_laukas[rd-97][sk]='+';
            PC_laukas_tuscia[rd-97][sk]='+';
            cout<<"JUS PATAIKETE"<<endl;
              if(PC_laukas[rd-97][sk+1]!='#' && PC_laukas[rd-97][sk-1]!='#' && PC_laukas[rd-97-1][sk]!='#' && PC_laukas[rd-97+1][sk]!='#')
                {
                    cout<<"SUNAIKINOTE LAIVA!!!"<<endl;
                    cout<<"Liko laivu: "; cout<<laivu_kiekis--<<endl;
                }
            tinka++;
            pataike++;
            }
            else if (PC_laukas[rd-97][sk]=='-') cout<<"Pataikete i sauta vieta, bandykite is naujo"<<endl;
                else { PC_laukas[rd-97][sk]='-'; PC_laukas_tuscia[rd-97][sk]='-'; cout<<"JUS NEPATAIKETE"<<endl; tinka++;}

        }else cout<<"Ivestos blogos koordinates, veskite is naujo"<<endl;
    }
}
int graz_pataik()//grazina "pataike++" reiksme ZMOGAUS
{
    return pataike;
}
void saudymas_PC()
{//JOG SAUTU APLINK PATAIKYTA
  tinka=0;

  saugo_sk=0;
  saugo_rd=0;
    while(tinka<1)
    {  sk=rand()%10+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
  rd=rand()%10+97;//sugeneruos 10 raidziu nuo a iki j, 10 kaip intevalas kompui
        if(zaidejo_laukas[rd-97][sk]=='#')
        {
        zaidejo_laukas[rd-97][sk]='+';
        cout<<"KOMPIUTERIS PATAIKE"<<endl;

        saugo_rd=rd-97; //cout<<saugo_rd<<endl;
        saugo_sk=sk; //cout<<saugo_sk<<endl;
            //tinka++;
             pataikePC++;
        tinka++;
        PC_saudo_aplink();
        }
        else {zaidejo_laukas[rd-97][sk]='-';cout<<"KOMPIUTERIS NEPATAIKE"<<endl;tinka++;}
        //if(zaidejo_laukas[rd-97][sk]=='-' || zaidejo_laukas[rd-97][sk]=='+')tinka=0;//nesauna i sauta vieta; veikia
    }
}
void PC_saudo_aplink()
{ tinka=0;
 //sk=rand()%4+1;//sugeneruos 10skaiciu nuo 1 iki 10, 10 kaip intevalas kompui
  //rd=rand()%4+97;//sugeneruos 10 raidziu nuo a iki j, 10 kaip intevalas kompui
  lvk=1;
    cout<<"Saugo RD"<<saugo_rd<<endl;
    cout<<"saugo SK"<<saugo_sk<<endl;
    while (tinka<1)
    {
        if(zaidejo_laukas[saugo_rd-1][saugo_sk]=='#')
        {
            zaidejo_laukas[saugo_rd-lvk][saugo_sk]='+';
            //saudymas_PC();//cout<<lvk<<endl;
            lvk++; cout<<lvk<<endl;
        }
        else if(zaidejo_laukas[saugo_rd+1][saugo_sk]=='#')
        {
            zaidejo_laukas[saugo_rd+lvk][saugo_sk]='+';
            //saudymas_PC();//cout<<lvk<<endl;
            lvk++;cout<<lvk<<endl;
        }
        else if(zaidejo_laukas[saugo_rd][saugo_sk+1]=='#')
        {
            zaidejo_laukas[saugo_rd][saugo_sk+lvk]='+';
            //saudymas_PC();//cout<<lvk<<endl;
            lvk++;cout<<lvk<<endl;
        }
        else if(zaidejo_laukas[saugo_rd][saugo_sk-1]=='#')
        {
            zaidejo_laukas[saugo_rd][saugo_sk-lvk]='+';
            //saudymas_PC();//cout<<lvk<<endl;
            lvk++;cout<<lvk<<endl;
        }
    }lvk=1;

}
int graz_pataikPC()//grazina "pataike++" reiksme PC
{
    return pataikePC;
}
};
int main()
{
  srand (time(NULL)); // veikia visoj programoj ir generuoja vis kitokius skaicius, nes kitaip generuotu tuos pacius sk
  musis A;
//------------------Lenteles-----------------------------
{//sutraukta

  cout<<"-----LAIVU MUSIS-----"<<endl;
    cout<<"         _~"<<endl;
    cout<<"      _~ )_)_~"<<endl;
    cout<<"      )_))_))_)"<<endl;
    cout<<"      _!__!__!_ "<<endl;
    cout<<"      \\______t/"<<endl;
    cout<<"    ~~~~~~~~~~~~~"<<endl;

  A.Mano_lentele();
  cout<<endl;
  A.PC_lentele();
  cout<<endl;
    //A.PC_lentele_suvis();
    cout<<endl;
}
//--------------ZAIDEJO IVEDIMAS-------------------------
{//sutraukta
  A.zaidejo_ivedimas_4();A.Mano_lentele();//laivas po 4 skyles x1
    A.zaidejo_ivedimas_3();A.Mano_lentele();//laivas po 3 skyles x2
    A.zaidejo_ivedimas_3();A.Mano_lentele();
      A.zaidejo_ivedimas_2();A.Mano_lentele();//laivas po 2 skyles x2
      A.zaidejo_ivedimas_2();A.Mano_lentele();
        //A.zaidejo_ivedimas_1();A.Mano_lentele();//laivas po 1 skyle x4
        //A.zaidejo_ivedimas_1();A.Mano_lentele();
        //A.zaidejo_ivedimas_1();A.Mano_lentele();
        //A.zaidejo_ivedimas_1();A.Mano_lentele();
}
//----------------PC IVEDIMAS----------------------------
{//sutraukta
A.PC_ivedimas_4();//A.PC_lentele();
   A.PC_ivedimas_3(); //A.PC_lentele();
   A.PC_ivedimas_3(); //A.PC_lentele();
    A.PC_ivedimas_2();//A.PC_lentele();
    A.PC_ivedimas_2();//A.PC_lentele();
        A.PC_ivedimas_1();//A.PC_lentele();
        A.PC_ivedimas_1();//A.PC_lentele();
        A.PC_ivedimas_1();//A.PC_lentele();
        A.PC_ivedimas_1();A.PC_lentele();
        //A.PC_lentele_suvis();
}
//-----------------SAUDYMAS------------------------------
while ( A.graz_pataik() <18 || A.graz_pataikPC() <18 )
{
    A.saudymas_zmogaus(); A.PC_lentele();
    //A.PC_lentele_suvis();

    A.saudymas_PC();A.PC_saudo_aplink();  A.Mano_lentele();
    if(A.graz_pataik()==18)
        {
            cout<<"ZAIDIMAS BAIGTAS"<<endl;
            cout<<"LAIMEJOTE!!!"<<endl;
            break;
        }
        else if(A.graz_pataikPC()==18)
        {
            cout<<"ZAIDIMAS BAIGTAS"<<endl;
            cout<<"LAIMEJO KOMPIUTERIS!!!"<<endl;
            break;
        }
}
return 0;
}
